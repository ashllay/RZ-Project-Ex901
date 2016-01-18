#ifndef CONFIGS_H
#define CONFIGS_H

class cConfigs
{
private:				

public:			 
	void LoadFixes();	
	void LoadConfigsInGS();
	void LoadAll();
	void LoadAtHook();
	long GetInt(long Min, long Max, long Default, LPCSTR BlockName, LPCSTR ConfigName, LPCSTR FolderName);
	char GetChar(long Min, long Max, unsigned char Default, LPCSTR BlockName, LPCSTR ConfigName, LPCSTR FolderName);
	
	int FixPotionsMax;
	int AllowExeAnc;
	int AllowJohAnc;
	int AllowExeSock;
	int MaxLifeOpt;

	int	PersonalIDFix;
	int	GuildIDFix;

};
extern cConfigs Configs;
#endif