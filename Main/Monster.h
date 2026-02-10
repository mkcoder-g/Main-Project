#pragma once

#define MONSTER_BASE_MODEL 408

void InitMonster();
DWORD CreateMonster(int type,int x,int y,int key);
void OnlyNpcChatProcess(DWORD c,DWORD o);