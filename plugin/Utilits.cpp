#include "StdAfx.h"
#include "Utilits.h"

cUtilits Utilits;

void cUtilits::HookThis(DWORD dwMyFuncOffset, DWORD dwJmpOffset)
{
	*(DWORD*)(dwJmpOffset + 1) = dwMyFuncOffset-(dwJmpOffset+5);
}

DWORD cUtilits::SetHook(const LPVOID dwMyFuncOffset, const LPVOID dwJmpOffset, const BYTE cmd)
{
    BYTE btBuf[5];
    // ----
    DWORD dwShift   = (ULONG_PTR)dwMyFuncOffset - ( (ULONG_PTR)dwJmpOffset + 5 );
    // ----
    btBuf[0] = cmd;
    // ----
    memcpy( (LPVOID) & btBuf[1], (LPVOID) & dwShift, sizeof(ULONG_PTR));
    // ----
    return WriteMemory(dwJmpOffset, (LPVOID) btBuf, sizeof(btBuf));
}

void cUtilits::SetNop(DWORD dwOffset, int Size)
{
	for(int n=0; n < Size; n++)
		*(BYTE*)(dwOffset+n) = 0x90;
}

void cUtilits::SetRetn(DWORD dwOffset)
{
	*(BYTE*)(dwOffset) = 0xC3;
}

void cUtilits::SetRRetn(DWORD dwOffset)
{
	*(BYTE*)(dwOffset)=0xC3;
	*(BYTE*)(dwOffset+1)=0x90;
	*(BYTE*)(dwOffset+2)=0x90;
	*(BYTE*)(dwOffset+3)=0x90;
	*(BYTE*)(dwOffset+4)=0x90;
}

void cUtilits::SetByte(DWORD dwOffset, BYTE btValue)
{
	*(BYTE*)(dwOffset) = btValue;
}

//new
DWORD cUtilits::WriteMemory(const LPVOID lpAddress, const LPVOID lpBuf, const UINT uSize)
{
	DWORD dwErrorCode   = 0;
	DWORD dwOldProtect  = 0;
	int iRes = VirtualProtect(lpAddress, uSize, PAGE_EXECUTE_READWRITE, & dwOldProtect);
	if ( iRes == 0 )
	{
		dwErrorCode = GetLastError();
		return dwErrorCode;
	}
	memcpy(lpAddress, lpBuf, uSize);
	DWORD dwBytes   = 0;
	iRes = VirtualProtect(lpAddress, uSize, dwOldProtect, & dwBytes);
	if ( iRes == 0 )
	{
		dwErrorCode = GetLastError();
		return dwErrorCode;
	}
	return 0x00;
}
// -------------------------------------------------------------------
DWORD cUtilits::SetRange(const LPVOID dwAddress, const USHORT wCount, const BYTE btValue)
{
	BYTE * lpBuf	= new BYTE[wCount];
	// ----
	memset(lpBuf, btValue, wCount);
	// ----
	return Utilits.WriteMemory( dwAddress, (LPVOID) lpBuf, wCount);
}
DWORD cUtilits::SetJmp(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress)
{
	BYTE btBuf[5];
	DWORD dwShift	= (ULONG_PTR)dwJMPAddress - (ULONG_PTR)dwEnterFunction - 5;

	btBuf[0]	= 0xE9;
	memcpy( (LPVOID) & btBuf[1], (LPVOID) & dwShift, sizeof(ULONG_PTR));

	return Utilits.WriteMemory(dwEnterFunction, (LPVOID) btBuf, sizeof(btBuf));
}
void cUtilits::HookExactOffset(DWORD Function, DWORD ToHook, BYTE Type)
{
	*(BYTE*)ToHook = Type;
	*(DWORD*)(ToHook+1) = Function;
}
//------------------------------------------------------------------------//
bool cUtilits::IsBadFileLine(char *FileLine, int &Flag)
{
	if(Flag == 0)
	{
		if(isdigit(FileLine[0]))
		{
			Flag = FileLine[0] - 48;
			return true;
		}
	}
	else if(Flag < 0 || Flag > 9)
	{
		Flag = 0;
	}

	if(!strncmp(FileLine, "end", 3))
	{
		Flag = 0;
		return true;
	}

	if(FileLine[0] == '/' || FileLine[0] == '\n')
		return true;

	for(UINT i = 0; i < strlen(FileLine); i++)
	{
		if(isalnum(FileLine[i]))
			return false;
	}
	return true;
}