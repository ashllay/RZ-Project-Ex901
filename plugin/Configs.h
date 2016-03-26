#ifndef CONFIGS_H
#define CONFIGS_H

class cConfigs
{
private:				

public:			 
	void LoadFixes();	
	void ChangeShopsPath();
	void LoadConfigsInGS();
	void LoadCommands();
	void LoadAll();
	void LoadAtHook();
	long GetInt(long Min, long Max, long Default, LPCSTR BlockName, LPCSTR ConfigName, LPCSTR FolderName);
	char GetChar(long Min, long Max, unsigned char Default, LPCSTR BlockName, LPCSTR ConfigName, LPCSTR FolderName);
	
	int FixPotionsMax;
	int AllowExeAnc;
	int AllowJohAnc;
	int AllowExeSock;
	int MaxLifeOpt;

	//int	UseCustomCashShop;
	int	PersonalIDFix;
	int	GuildIDFix;
		//commands
	struct sCommands
	{
		int MaxLvl; 
		int IsGg;
		int IsPost;

		int PostLvl;
		DWORD MaxAddedStats;

		DWORD PostPriceZen;
		int PostColor;  
		int PostDelay;

		int IsDrop;
		int IsReload;
		int IsGmove; 
		int IsSetPK;
		int IsOnline; 
		int IsStatus;
		int IsSetChar; 
		int IsSetZen;

		int SkinEnabled;

		int AddPointEnabled;
		int AddPointLevelReq;  
		DWORD AddPriceZen; 
		//int AddPricePCPoint;
		int AddPriceWCoin;
	}Commands;
};
extern cConfigs Configs;
#endif