#include "stdafx.h"
#include "ItemMove.h"
#include "Offset.h"
#include "Protect.h"
#include "Shop.h"
#include "Util.h"

void InitItemMove() // OK
{
	MemorySet(0x005CA4E6,0x90,0x02); // Item Move Inventory -> Interface

	MemorySet(0x005CA560,0x90,0x02); // Item Move Interface -> Inventory

	SetCompleteHook(0xE8,0x005CA504,&AutoMoveItem);
}

void RightClickMove() // OK
{
	if(gProtect.m_MainInfo.ItemMoveRightClicSwitch == 0)
	{
		return;
	}

	if(*(DWORD*)0x07B06C0C > 0 || EquipmentItem || MouseLButtonPush || !MouseRButtonPush || !CheckWindow(WINDOWS_INVENTORY))
	{
		return;
	}

	DWORD lpItem = 0;

	if(ItemTarget)
	{
		lpItem = ItemTarget;
	}
	else if(*(DWORD*)0x07672F1C == 1)
	{
		lpItem = PickedItem;
	}

	if(lpItem == 0)
	{
		return;
	}

	BYTE SourceSlot = -1;

	BYTE TargetSlot = -1;

	if(SlotType == 0 && InventorySlot < INVENTORY_WEAR_SIZE)
	{
		STRUCT_DECRYPT

		SourceSlot = (BYTE)InventorySlot;

		if(*(DWORD*)MAIN_CURRENT_MAP == 10 || *(DWORD*)MAIN_CURRENT_MAP == 39)
		{
			if(SourceSlot == 7 && GetItemEquipedIndex(8) != GET_ITEM(13,3) && GetItemEquipedIndex(8) != GET_ITEM(13,4) && GetItemEquipedIndex(8) != GET_ITEM(13,37))
			{
				return;
			}

			if(SourceSlot == 8 && (GetItemEquipedIndex(8) == GET_ITEM(13,3) || GetItemEquipedIndex(8) == GET_ITEM(13,4) || GetItemEquipedIndex(8) == GET_ITEM(13,37)) && GetItemEquipedIndex(7) == 0xFFFF)
			{
				return;
			}
		}

		DWORD ItemStruct = GetItemEquiped(SourceSlot);

		TargetSlot = GetInventoryEmptySlot(*(WORD*)ItemStruct);

		if(TargetSlot != 0xFF)
		{
			memcpy(&PickedItem,(const void *)ItemStruct,0x44);

			*(WORD*)(ItemStruct) = -1;
			*(DWORD*)(ItemStruct + 2) = 0;
			*(BYTE*)(ItemStruct + 23) = 0;
			*(BYTE*)(ItemStruct + 24) = 0;

			InventoryBackup = (DWORD)InventoryMap;

			PointerSlot = SourceSlot;

			DeleteEquippingEffect(*(DWORD*)MAIN_VIEWPORT_STRUCT);

			ItemTarget = 0;
			ItemSelect = -1;
			SlotType = 0;
			InventorySlot = SourceSlot + INVENTORY_WEAR_SIZE;

			if(SourceSlot == 8)
			{
				DeleteBugOrPet(*(DWORD*)MAIN_VIEWPORT_STRUCT);
			}
			else if(SourceSlot == 1 && (WORD)PickedItem == GET_ITEM(13,5))
			{
				DeletePetRaven(*(DWORD*)MAIN_VIEWPORT_STRUCT);
			}
			else if (SourceSlot == 7 && ((WORD)PickedItem == GET_ITEM(12,39) || (WORD)PickedItem == GET_ITEM(12,40) || (WORD)PickedItem == GET_ITEM(13,30)))
			{
				DeleteWingEffect(*(DWORD*)MAIN_VIEWPORT_STRUCT,*(DWORD*)MAIN_VIEWPORT_STRUCT,0);
			}

			SendRequestEquipmentItem(0,SourceSlot,0,TargetSlot);

			MouseRButtonPush = false;
		}

		STRUCT_ENCRYPT
	}
	else
	{
		if(CheckWindow(WINDOWS_TRADE) || CheckWindow(WINDOWS_CHAOS_MIX) || CheckWindow(WINDOWS_SENIOR_MIX) || CheckWindow(WINDOWS_REFINERY) || CheckWindow(WINDOWS_WAREHOUSE))
		{
			return;
		}

		SourceSlot = *(BYTE*)(lpItem + 56) + 8 * *(BYTE*)(lpItem + 57) + INVENTORY_WEAR_SIZE;

		TargetSlot = GetInventoryWearSlot(*(WORD*)lpItem);

		if(TargetSlot != 0xFF)
		{
			memcpy(&PickedItem,&InventoryMap[34*(SourceSlot-INVENTORY_WEAR_SIZE)],0x44);		
			InventoryBackup = (DWORD)InventoryMap;

			PointerSlot = SourceSlot;
			PointerDeleteItem(SourceSlot,InventoryMap,8);

			ItemTarget = 0;
			ItemSelect = -1;
			SlotType = 0;

			SendRequestEquipmentItem(0,SourceSlot,0,TargetSlot);

			MouseRButtonPush = false;
		}
	}
}

bool AutoMoveItem(int x,int y,DWORD inventory,int width,int height) // OK
{
	if(CheckWindow(WINDOWS_TRADE))
	{
		return ((bool(*)(int,int,DWORD,int,int))0x005CBD50)(275,271,0x07670878,8,4);
	}
	else if (CheckWindow(WINDOWS_CHAOS_MIX) || CheckWindow(WINDOWS_SENIOR_MIX) || CheckWindow(WINDOWS_REFINERY))
	{
		return ((bool(*)(int,int,DWORD,int,int))0x005CBD50)(275,110,0x07AF47D0,8,4);
	}
	else if (CheckWindow(WINDOWS_WAREHOUSE))
	{
		return ((bool(*)(int,int,DWORD,int,int))0x005CBD50)(x,y,inventory,width,height);
	}
	
	return false;
}

BYTE InventoryRectCheck(int x,int y,int width,int height) // OK
{
	int slot = ((y*8)+x)+INVENTORY_WEAR_SIZE;

	if(((x+width) > 8 || (y+height) > 8))
	{
		return 0xFF;
	}

	for(int sy=0;sy < height;sy++)
	{
		for(int sx=0;sx < width;sx++)
		{
			if(InventoryMap[34*(((sy+y)*8)+(sx+x))] != 0xFFFF)
			{
				return 0xFF;
			}
		}
	}

	return slot;
}

BYTE GetInventoryEmptySlot(int ItemIndex) // OK
{
	ITEM_INFO* lpItemInfo = GetItemInfo(ItemIndex);

	for(int y=0;y < 8;y++)
	{
		for(int x=0;x < 8;x++)
		{
			if(InventoryMap[34*((y*8)+x)] == 0xFFFF)
			{
				if(InventoryRectCheck(x,y,lpItemInfo->Width,lpItemInfo->Height) != 0xFF)
				{
					return ((y*8)+x)+INVENTORY_WEAR_SIZE;
				}
			}
		}
	}

	return -1;
}

BYTE GetInventoryWearSlot(int ItemIndex) // OK
{
	int slot = 0xFF;

	STRUCT_DECRYPT

	ITEM_INFO* lpItemInfo = GetItemInfo(ItemIndex);

	BYTE Class = ((*(BYTE*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x0B)) & 7);

	BYTE ChangeUp = GetChangeUp(*(BYTE*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x0B));

	WORD ItemR = GetItemEquipedIndex(0);
	WORD ItemL = GetItemEquipedIndex(1);
	WORD RingR = GetItemEquipedIndex(10);
	WORD RingL = GetItemEquipedIndex(11);

	if(lpItemInfo->Slot >= 0 && lpItemInfo->Slot < INVENTORY_WEAR_SIZE)
	{
		if(lpItemInfo->TwoHand == 0)
		{
			if(lpItemInfo->Slot == 0 && ItemR != 0xFFFF && ItemL == 0xFFFF)
			{
				ITEM_INFO* lpItemRight = GetItemInfo(ItemR);

				if(lpItemRight->TwoHand == 0)
				{
					slot = 1;
				}
			}
			else if(lpItemInfo->Slot == 1 && ItemL != 0xFFFF && ItemR == 0xFFFF)
			{
				ITEM_INFO* lpItemLeft = GetItemInfo(ItemL);

				if(lpItemLeft->TwoHand == 0)
				{
					slot = 1;
				}
			}
			else if(lpItemInfo->Slot == 10 && RingR != 0xFFFF && RingL == 0xFFFF)
			{
				slot = 11;
			}
		}

		if(GetItemEquipedIndex(lpItemInfo->Slot) == 0xFFFF)
		{
			slot = lpItemInfo->Slot;
		}
	}

	STRUCT_ENCRYPT

	bool bEquipable = false;

	if(lpItemInfo->RequireClass[Class])
	{
		bEquipable = true;
	}
	else if(Class == 3 && lpItemInfo->RequireClass[0] && lpItemInfo->RequireClass[1])
	{
		bEquipable = true;
	}

	if(lpItemInfo->RequireClass[Class] > ChangeUp)
	{
		bEquipable = false;
	}

	if(bEquipable == true)
	{
		bEquipable = false;

		if(lpItemInfo->Slot == slot)
		{
			bEquipable = true;
		}
		else if(lpItemInfo->Slot == 0 && slot == 1)
		{
			if((Class == 1 || Class == 3) && lpItemInfo->TwoHand == 0)
			{
				bEquipable = true;
			}
		}
		else if(lpItemInfo->Slot == 10 && slot == 11)
		{
			bEquipable = true;
		}

		if(Class == 2)
		{
			if(lpItemInfo->Slot == 0 && ItemL != GET_ITEM(4,7) && (ItemL >= GET_ITEM(4,0) && ItemL < GET_ITEM(5,0)) && ItemIndex != GET_ITEM(4,15))
			{
				bEquipable = false;
			}
		}
	
		if(Class == 3 && lpItemInfo->Slot == 2)
		{
			bEquipable = false;
		}
	}

	return ((bEquipable) ? slot : 0xFF);
}