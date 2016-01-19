#ifndef UTILITS_H
#define UTILITS_H

enum ASM
{
	JMP			= 0xEB,
	JE			= 0x74,
	JNE			= 0x75,
	JGE			= 0x7D,
	NOP			= 0x90,
	CALL		= 0xE8,
	PUSH_EAX	= 0x50,
	PUSH		= 0x68,
	RETN		= 0xC3,
};

class cUtilits
{
public:
	void HookThis(DWORD dwMyFuncOffset, DWORD dwJmpOffset);
	void SetNop(DWORD dwOffset, int Size);
	void SetRetn(DWORD dwOffset);
	void SetRRetn(DWORD dwOffset);
	void SetByte(DWORD dwOffset, BYTE btValue);
	DWORD SetHook(const LPVOID dwMyFuncOffset, const LPVOID dwJmpOffset, const BYTE cmd);
	DWORD WriteMemory(const LPVOID lpAddress, const LPVOID lpBuf, const UINT uSize);
	DWORD SetRange(const LPVOID dwAddress, const USHORT wCount, const BYTE btValue);
	DWORD SetJmp(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress);
	void HookExactOffset(DWORD Function, DWORD ToHook, BYTE Type);
	bool IsBadFileLine(char *FileLine, int &Flag);
};
extern cUtilits Utilits;
#endif