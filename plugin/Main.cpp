#include "StdAfx.h"


void External_GameMainInit(HWND hWnd)
{
	GameMainInit(hWnd);
	//User Ex Init
	UserEx.Init();
	//GmSystem
	GmSystem.Load();
	//Load CashShop
#if(COMPILE_CASHSHOP==1)
#endif
	LogAddFuncColor(3,"Compile Date: %s %s", __DATE__, __TIME__);
	ThreadInit();
}

void InitAllHooks()
{
	Utilits.HookThis((DWORD)&External_GameMainInit,oGameMainInit);
	Hooks.LoadAll();
	Configs.LoadAll();
	Fixes.Load();
#if ( DebugConsole == 1)
	Console.Init();
#endif
}

extern "C" __declspec(dllexport)void Init()
{
	DWORD OldProtect;
	if(VirtualProtect(LPVOID(0x401000),oVirtualProtect,PAGE_EXECUTE_READWRITE,&OldProtect))
	{
		InitAllHooks();
		//MessageBox(NULL,"Trust Me I'm Working", "Test", NULL);
	}
}

int APIENTRY DllMain(HINSTANCE hInst, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{	
	case DLL_PROCESS_ATTACH:
		{
			Init();
		}
		break;
	case DLL_PROCESS_DETACH:{
		}
		break;	
	}
	return true;
}
