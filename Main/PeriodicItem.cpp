#include "stdafx.h"
#include "PeriodicItem.h"
#include "CustomMessage.h"
#include "Offset.h"
#include "ItemMove.h"
#include "ItemToolTip.h"
#include "Util.h"
#include <ctime>

DWORD m_PeriodicInfo[76];

void RenderPeriodicTipText() // OK
{
	if(pMouseOnZone(450, 0, 190, 433, 1))
	{
		DWORD lpItem = 0;

		if(ItemTarget)
		{
			lpItem = ItemTarget;
		}
		else if(*(DWORD*)0x07672F1C == 1)
		{
			lpItem = PickedItem;
		}

		if(lpItem != 0)
		{
			int SourceSlot = -1;

			if(SlotType == 0 && InventorySlot < INVENTORY_WEAR_SIZE)
			{
				SourceSlot = InventorySlot;
			}
			else 
			{
				SourceSlot = *(BYTE*)(lpItem + 56) + 8 * *(BYTE*)(lpItem + 57) + INVENTORY_WEAR_SIZE;
			}

			if(m_PeriodicInfo[SourceSlot] > 0)
			{
				tm ExpireTime;
	
				_tzset();

				time_t msgTime = m_PeriodicInfo[SourceSlot];

				if(localtime_s(&ExpireTime,&msgTime) == 0) 
				{
					char buff[32] = {0};
					strftime(buff,sizeof(buff),gCustomMessage.GetMessage(24),&ExpireTime);
					AddTipText(gCustomMessage.GetMessage(25),3,1);
					AddTipText(buff,1,0);
				}
			}
		}
	}
}

void GCPeriodicItemInit() // OK
{
	for(int n = 0;n < 76; n++)
	{
		m_PeriodicInfo[n] = 0;
	}
}

void GCPeriodicItemRecv(PMSG_PERIODIC_ITEM_RECV* lpMsg) // OK
{
	if(lpMsg->sourceslot != 0xFFFF)
	{
		m_PeriodicInfo[lpMsg->sourceslot] = 0;
	}

	m_PeriodicInfo[lpMsg->targetslot] = lpMsg->time;
}

void GCPeriodicItemDeleteRecv(PMSG_PERIODIC_ITEM_DELETE_RECV* lpMsg) // OK
{
	int slot = lpMsg->slot;

	if(slot >= 0 && slot < INVENTORY_WEAR_SIZE)
	{
		STRUCT_DECRYPT

		DWORD ItemStruct = GetItemEquiped(slot);

		WORD ItemIndex = *(WORD*)(ItemStruct);

		*(WORD*)(ItemStruct) = -1;
		*(DWORD*)(ItemStruct + 2) = 0;
		*(BYTE*)(ItemStruct + 23) = 0;
		*(BYTE*)(ItemStruct + 24) = 0;

		STRUCT_ENCRYPT

		DeleteEquippingEffect(*(DWORD*)MAIN_VIEWPORT_STRUCT);

		if(slot == 8)
		{
			DeleteBugOrPet(*(DWORD*)MAIN_VIEWPORT_STRUCT);
		}
		else if(slot == 1 && ItemIndex == GET_ITEM(13,5))
		{
			DeletePetRaven(*(DWORD*)MAIN_VIEWPORT_STRUCT);
		}
		else if (slot == 7 && (ItemIndex == GET_ITEM(12,39) || ItemIndex == GET_ITEM(12,40) || ItemIndex == GET_ITEM(13,30)))
		{
			DeleteWingEffect(*(DWORD*)MAIN_VIEWPORT_STRUCT,*(DWORD*)MAIN_VIEWPORT_STRUCT,0);
		}
	}

	m_PeriodicInfo[slot] = 0;
}