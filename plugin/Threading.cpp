#include "StdAfx.h"

DWORD MainTick()  	
{
	while(true)
	{
		int Temp_All = 0;
		int Temp_Gms = 0;

		for(int i=OBJ_MIN; i<=OBJ_MAX; i++)
		{
			OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(i);	

			// # PLAYER  LOGGED # //
			if(gObj->Connected < PLAYER_LOGGED) 
				continue;
			if(GmSystem.IsGMBD(i))
				Temp_Gms++;
			else
				Temp_All++;
			// # PLAYER PLAYING # //
			if(gObj->Connected < PLAYER_PLAYING) 
				continue;				
			if(AddTab[gObj->m_Index].POST_Delay > 0)
				AddTab[gObj->m_Index].POST_Delay--;
			//offtrade
			/*if(AddTab[gObj->m_Index].OfflineTrade != true)
				User.OnlineTimeTick(gObj);*/
		}
		Sleep(1000);
	}
	return 1;	
}

void ThreadInit()
{
	DWORD ThreadID;
	HANDLE hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)MainTick, NULL, 0, &ThreadID);//False	2	1173	V513	Use _beginthreadex/_endthreadex functions instead of CreateThread/ExitThread functions.	IA Julia 1.x.x	lite.cpp	148	False
	if ( hThread == 0 )
	{
		LogAddFuncColor(3,"CreateThread() failed with error %d", GetLastError());
		return;
	}
	CloseHandle(hThread);
}