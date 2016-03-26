#include "Stdafx.h"
//#include "Definitions.h"
#include "Console.h"

CConsole Console;

CConsole::CConsole()
{
	SYSTEMTIME SysTime;
	GetLocalTime(&SysTime);

	GetPrivateProfileString("GameServerInfo","ServerName","",this->ServerName,50,".\\Data\\ServerInfo.dat");

	wsprintf(this->LogFileName, "%s\\%s_%04d-%02d-%02d.txt",
		CONSOLE_FOLDER,this->ServerName,SysTime.wYear,SysTime.wMonth,SysTime.wDay);

	CreateDirectory(CONSOLE_FOLDER, NULL);
	InitializeCriticalSection(&this->m_CritConsole);
}

CConsole::~CConsole()
{
	DeleteCriticalSection(&this->m_CritConsole);
}

void __stdcall ConsoleCore(PVOID pVoid)
{
	AllocConsole();

#ifdef _GS
		char * Title = "GameServer N";
#else
		char * Title = "GameServer CS";
#endif

	SetConsoleTitle(Title);

	while(true)
	{
		Sleep(100);
	}
}

void CConsole::Init()
{
	CreateThread(0,0,(LPTHREAD_START_ROUTINE)ConsoleCore,0,0,&this->PID); 
	Sleep(100);
	
	this->Log("---------------------------------------------------");
	this->Log(" Ex901 - GameServer ");
	//this->Log(" Plugin Version - %s",PLUGIN_VERSION);
	this->Log("---------------------------------------------------");
}

void CConsole::Log(const char* Format, ...)
{
	char Message[1024];
	DWORD dwBytesWritten;
	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);

	va_list pArguments;
	va_start(pArguments,Format);
	vsprintf(Message,Format,pArguments);
	va_end(pArguments);

	char OutputMsg[2048];
	sprintf(OutputMsg,"%s\n", Message);
	WriteFile(Handle,OutputMsg,strlen(OutputMsg),&dwBytesWritten,NULL);

	this->WriteToFile(OutputMsg);
}

void CConsole::LogTD(const char* Format, ...)
{
	SYSTEMTIME t;
	GetLocalTime(&t);

	char Message[1024];
	DWORD dwBytesWritten;
	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);

	va_list pArguments;
	va_start(pArguments,Format);
	vsprintf(Message,Format,pArguments);
	va_end(pArguments);

	char CurrDate[11] = {0};
	sprintf(CurrDate, "%02d:%02d:%02d", t.wHour, t.wMinute, t.wSecond);

	char OutputMsg[2048];
	sprintf(OutputMsg,"%s %s\n",CurrDate,Message);
	WriteFile(Handle,OutputMsg,strlen(OutputMsg),&dwBytesWritten,NULL);

	this->WriteToFile(OutputMsg);
}

void CConsole::WriteToFile(const char* Format)
{
	EnterCriticalSection(&this->m_CritConsole);

	if((this->LogFile = fopen(this->LogFileName,"a+")) == 0)
	{
		LeaveCriticalSection(&this->m_CritConsole);	
	}
	else
	{
		fprintf(this->LogFile , Format);
		fclose(this->LogFile);
		LeaveCriticalSection(&this->m_CritConsole);
	}
}

extern CConsole Console;