#ifndef Logger_H
#define Logger_H

#define	CONSOLE_FOLDER	"CONSOLE"

class CConsole
{
public:
	CConsole();
	~CConsole();
	void Init();
	int StdIn(char* Buffer);
	HANDLE Handle(BOOL Input);
	
	void Log(const char* Format, ...);
	void LogTD(const char* Format, ...);
	void WriteToFile(const char* Format);

private:
	DWORD PID;
	CRITICAL_SECTION m_CritConsole;
	FILE* LogFile;
	char LogFileName[260];
	char ServerName[50];
};
extern CConsole Console;

#endif