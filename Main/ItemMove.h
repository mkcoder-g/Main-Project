#pragma once

#include "Protocol.h"

void InitItemMove();
void RightClickMove();
bool AutoMoveItem(int x,int y,DWORD inventory,int width,int height);
BYTE InventoryRectCheck(int x,int y,int width,int height);
BYTE GetInventoryEmptySlot(int ItemIndex);
BYTE GetInventoryWearSlot(int ItemIndex);