#include "StdAfx.h"

gHooks Hooks;


void gHooks::LoadAll()
{
	Hooks.Hook_DataSend();
	Hooks.Hook_ProtocolCore();
	Hooks.ChangeGSStyle();
}
void gHooks::Hook_DataSend()
{
	Utilits.HookThis((DWORD)&DataSendEx,oDataSend);
}

void gHooks::Hook_ProtocolCore()
{
	Utilits.HookThis((DWORD)&ProtocolCoreEx,oProtocolCore);
}

void gHooks::ChangeGSStyle()
{
#ifdef _GS
	BYTE CBText[] = {"RZ GameServer"};	
#else
	BYTE CBText[] = {"RZ GameServerCS"};
#endif
	memcpy((int*)oBarText,CBText,sizeof(CBText));
	//change colors
	DWORD Color;
	Color = (RGB(54,54,54));//cor texto da bar
	*(unsigned int*) GREENBARTEXTCOLOR= Color;
	Color = (RGB(29, 115,190));//cor da bar
	*(unsigned int*) GREENBAR= Color;
}