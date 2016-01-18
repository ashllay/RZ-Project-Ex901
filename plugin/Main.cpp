#include "StdAfx.h"

void External_GameMainInit(HWND hWnd)
{
	GameMainInit(hWnd);
	LogAddFuncColor(3,"Compile Date: %s %s", __DATE__, __TIME__);
}
void InitAllHooks()
{
	Utilits.HookThis((DWORD)&External_GameMainInit,oGameMainInit);
	Hooks.LoadAll();
	Configs.LoadAll();
	Fixes.Load();
#if ( DebugConsole == 1)
	InitConsole();
#endif
}

extern "C"__declspec(dllexport) void Init()
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
