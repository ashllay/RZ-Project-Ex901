#include "StdAfx.h"
#include "Configs.h"
#include "Prodef.h"
#include "Utilits.h"
#include "Fixes.h"

cConfigs Configs;

void cConfigs::LoadAtHook()
{
	//this->LoadConfigsInGS();
	*(unsigned char*) CLOSE_TIME = GetInt(0, 6, 6,"Common","CloseClientTime",RZCommon);
}

void cConfigs::LoadAll()
{
	this->LoadAtHook();
	this->LoadCommands();
	this->ChangeShopsPath();
}

void cConfigs::LoadFixes()
{
#ifdef _GS
	//BloodCasle Time
	//int bloodtime = 200 * GetPrivateProfileInt("Events","BCTimeRemain", 60, RZEvents);            
	//*(unsigned int *) GS_BLOODREMAIN = bloodtime;                
	//*(unsigned int *) GS_BLOODREMAIN2 = bloodtime;                    
	//*(unsigned int *) GS_BLOODREMAIN3 = bloodtime;

	//remain ChaosCastle:
	//int iCcT = 70000 * (GetPrivateProfileIntA("Events","CCTimeRemain",30,RZEvents));
	//DWORD dCcT = iCcT;
	//*(unsigned int *) GS_CCTimeRemain = dCcT;

//#define GS_CCTimeRemain (0x00B5F099+4)
//	int iCcT = 70000 * (GetPrivateProfileIntA("Events","CCTimeRemain",30,".\\JHNgs.ini"));
//	DWORD dCcT = iCcT;
//	*(unsigned int *) GS_CCTimeRemain = dCcT;
	//chaos castle
	*(unsigned char*) oCcMinPlayers = GetInt(0, 2, 2,"Events","CcMinPlayers",RZEvents);
	//doppel
	//*(unsigned char*) oDoppelminParty0 = GetInt(0, 4, 4,"Doppelganger","MinPlayersOnParty",RZEvents);
	unsigned char MinPlayersOnParty = GetInt(0, 5, 5,"Doppelganger","MinPlayersOnParty",RZEvents);//	=	GetPrivateProfileInt("Doppelganger", "MinPlayersOnParty",2,RZEvents);
	*(unsigned char*) oDoppelminParty0 = MinPlayersOnParty;
	*(unsigned char*) oDoppelminParty1 = MinPlayersOnParty;
	*(unsigned char*) oDoppelminParty2 = MinPlayersOnParty;
#else
//	disablecslogs		= GetInt(0, 1, 0,"Common", "DisableCSlogs", RZCGS);
#endif 
	//UseCustomCashShop	= GetInt(0, 1, 1, "CustomCashShop", "Active", RZCommon);

	PersonalIDFix		= GetInt(0, 1, 1, "Bypasseres", "PersonalIDBypasser", RZCommon);
	GuildIDFix			= GetInt(0, 1, 1, "Bypasseres", "GuildIDBypasser", RZCommon);
	AllowExeAnc			= GetInt(0, 1, 1, "SpecialItem", "AllowExeAnc", RZItems);	
	AllowJohAnc			= GetInt(0, 1, 1, "SpecialItem", "AllowJohAnc", RZItems);
	AllowExeSock		= GetInt(0, 1, 1, "SpecialItem", "AllowExeSock", RZItems);
	MaxLifeOpt			= GetInt(0, 1, 1, "SpecialItem", "MaxLifeOpt", RZItems);
	FixPotionsMax		= GetInt(0, 1, 1, "Common", "Use255potions", RZItems);
	

	*(unsigned char*) GS_SOUL_RATE_NORMAL = GetChar(0,100,60,"JewelRates","SoulSuccessRateNormal",RZItems);
	*(unsigned char*) GS_SOUL_RATE_SPECIAL = GetChar(0,100,50,"JewelRates","SoulSuccessRateSpecial",RZItems);
	*(unsigned char*) GS_SOUL_RATE_SOCKET = GetChar(0,100,40,"JewelRates","SoulSuccessRateSocket",RZItems);
	*(unsigned char*) GS_SOUL_LUCK_ADD = GetChar(0,100,20,"JewelRates","SoulSuccessRateLuck",RZItems);
	*(unsigned char*) GS_JOL_FAIL_RATE = GetChar(0,100,50,"JewelRates","LifeFailRate",RZItems);

}

void cConfigs::LoadCommands()
{	
#ifdef _GS
	//OfflineTrade.Configs.Enabled		= GetInt(0, 1,									1,		"OffTrade",	"OffTradeEnabled",				RZCmd);		
	//OfflineTrade.Configs.LevelReq		= GetInt(0, Commands.MaxLvl,					0,		"OffTrade",	"OffTradeLevelReq",				RZCmd);			   	
	//OfflineTrade.Configs.PriceZen 		= GetInt(0, 2000000000,							10000,	"OffTrade",	"OffTradeZen",					RZCmd);
#endif
	//		SetChar		//
	Commands.IsSetChar					= GetInt(0, 1,					1,		"SetChar",		"SetCharEnabled",				RZCmd);
	//		SetZen		//
	Commands.IsSetZen					= GetInt(0, 1,					1,		"SetZen",		"SetZenEnabled",				RZCmd);
	//		status		//
	Commands.IsStatus					= GetInt(0, 1,					1,		"Status",		"StatusEnabled",				RZCmd); 
	//		skin		//
	Commands.SkinEnabled				= GetInt(0, 1,					1,		"Skin",			"SkinEnabled",					RZCmd);
	//		Reload		//
	Commands.IsReload					= GetInt(0,	1,					1,		"Reload",			"ReloadEnabled",					RZCmd);
	//		setpk
	Commands.IsSetPK					= GetInt(0, 1,					1,		"SetPK",		"SetPKEnabled",					RZCmd);  
	//		gmove		//
	Commands.IsGmove					= GetInt(0,	1,					1,		"Gmove",		"GmoveEnabled",					RZCmd);	 
	//		drop		//
	Commands.IsDrop						= GetInt(0,	1,					1,		"Drop",			"DropEnabled",					RZCmd);
	//		gg			//																	 	
	Commands.IsGg						= GetInt(0, 1,					1,		"GPost",		"GgEnabled",					RZCmd);	
	//		post		//	 
	Commands.IsPost						= GetInt(0, 1,									1,		"Post",			"PostEnabled",					RZCmd); 
	Commands.PostLvl					= GetInt(0, Commands.MaxLvl,					1,		"Post",			"PostLevelReq",					RZCmd);				  
	Commands.PostPriceZen				= GetInt(0, 2000000000,							10000,	"Post",			"PostPriceZen",					RZCmd);		 											
	Commands.PostColor					= GetInt(1, 3,									1,		"Post",			"PostColor",					RZCmd);  
	Commands.PostDelay					= GetInt(0,	32767,								60,		"Post",			"PostDelay",					RZCmd);
	Commands.AddPointEnabled			= GetInt(0, 1,									1,		"AddCommand",	"AddPointEnabled",				RZCmd);
	Commands.AddPointLevelReq			= GetInt(0, Commands.MaxLvl,					0,		"AddCommand",	"AddPointLevelReq",				RZCmd);			   	
	Commands.AddPriceZen				= GetInt(0, 2000000000,							10000,	"AddCommand",	"AddPriceZen",					RZCmd);		 
	Commands.MaxAddedStats				= GetInt(0, 65000,								0,		"AddCommand",	"MaxAddedStats",				RZCmd);
}

void cConfigs::ChangeShopsPath()
{
	char * Shop0_Path = "Shops\\shop0.txt";
	Utilits.HookExactOffset((DWORD)Shop0_Path,oShop0_Path,0x68);
	char * Shop1_Path = "Shops\\shop1.txt";
	Utilits.HookExactOffset((DWORD)Shop1_Path,oShop1_Path,0x68);
	char * Shop2_Path = "Shops\\shop2.txt";
	Utilits.HookExactOffset((DWORD)Shop2_Path,oShop2_Path,0x68);
	char * Shop3_Path = "Shops\\shop3.txt";
	Utilits.HookExactOffset((DWORD)Shop3_Path,oShop3_Path,0x68);
	char * Shop4_Path = "Shops\\shop4.txt";
	Utilits.HookExactOffset((DWORD)Shop4_Path,oShop4_Path,0x68);
	char * Shop5_Path = "Shops\\shop5.txt";
	Utilits.HookExactOffset((DWORD)Shop5_Path,oShop5_Path,0x68);
	char * Shop6_Path = "Shops\\shop6.txt";
	Utilits.HookExactOffset((DWORD)Shop6_Path,oShop6_Path,0x68);
	char * Shop7_Path = "Shops\\shop7.txt";
	Utilits.HookExactOffset((DWORD)Shop7_Path,oShop7_Path,0x68);
	char * Shop8_Path = "Shops\\shop8.txt";
	Utilits.HookExactOffset((DWORD)Shop8_Path,oShop8_Path,0x68);
	char * Shop9_Path = "Shops\\shop9.txt";
	Utilits.HookExactOffset((DWORD)Shop9_Path,oShop9_Path,0x68);
	char * Shop10_Path = "Shops\\shop10.txt";
	Utilits.HookExactOffset((DWORD)Shop10_Path,oShop10_Path,0x68);
	char * Shop11_Path = "Shops\\shop11.txt";
	Utilits.HookExactOffset((DWORD)Shop11_Path,oShop11_Path,0x68);
	char * Shop12_Path = "Shops\\shop12.txt";
	Utilits.HookExactOffset((DWORD)Shop12_Path,oShop12_Path,0x68);
	char * Shop13_Path = "Shops\\shop13.txt";
	Utilits.HookExactOffset((DWORD)Shop13_Path,oShop13_Path,0x68);
	char * Shop14_Path = "Shops\\shop14.txt";
	Utilits.HookExactOffset((DWORD)Shop14_Path,oShop14_Path,0x68);
	char * Shop15_Path = "Shops\\shop15.txt";
	Utilits.HookExactOffset((DWORD)Shop15_Path,oShop15_Path,0x68);
	char * Shop16_Path = "Shops\\shop16.txt";
	Utilits.HookExactOffset((DWORD)Shop16_Path,oShop16_Path,0x68);
	char * Shop17_Path = "Shops\\shop17.txt";
	Utilits.HookExactOffset((DWORD)Shop17_Path,oShop17_Path,0x68);
	char * Shop18_Path = "Shops\\shop18.txt";
	Utilits.HookExactOffset((DWORD)Shop18_Path,oShop18_Path,0x68);
	char * Shop19_Path = "Shops\\shop19.txt";
	Utilits.HookExactOffset((DWORD)Shop19_Path,oShop19_Path,0x68);
	char * Shop20_Path = "Shops\\shop20.txt";
	Utilits.HookExactOffset((DWORD)Shop20_Path,oShop20_Path,0x68);
	char * Shop21_Path = "Shops\\shop21.txt";
	Utilits.HookExactOffset((DWORD)Shop21_Path,oShop21_Path,0x68);
	char * Shop22_Path = "Shops\\shop22.txt";
	Utilits.HookExactOffset((DWORD)Shop22_Path,oShop22_Path,0x68);
	char * Shop23_Path = "Shops\\shop23.txt";
	Utilits.HookExactOffset((DWORD)Shop23_Path,oShop23_Path,0x68);
	char * Shop24_Path = "Shops\\shop24.txt";
	Utilits.HookExactOffset((DWORD)Shop24_Path,oShop24_Path,0x68);
	char * Shop25_Path = "Shops\\shop25.txt";
	Utilits.HookExactOffset((DWORD)Shop25_Path,oShop25_Path,0x68);

	/*char * DataServerIp2[256];
	GetPrivateProfileStringA("Common", "DataServer2", "127.0.0.1", (LPSTR)DataServerIp2, sizeof(DataServerIp2), RZCommon);
	Utilits.HookExactOffset((WORD) DataServerIp2,0x00B52173, 0x68);*/
}

long cConfigs::GetInt(long Min, long Max, long Default, LPCSTR BlockName, LPCSTR ConfigName, LPCSTR FolderName)
{
	long lResult;

	WIN32_FIND_DATAA wfd;
	if (FindFirstFileA(FolderName, &wfd) == INVALID_HANDLE_VALUE)
	{
		lResult = Default;
	}
	else
		lResult = GetPrivateProfileInt(BlockName, ConfigName, -100500, FolderName);

	if(lResult == -100500)
	{	   
		lResult = Default;
	}

	if(lResult < Min || lResult > Max)
	{
		lResult = Default;
	} 
	return lResult;
}

char cConfigs::GetChar(long Min, long Max, unsigned char Default, LPCSTR BlockName, LPCSTR ConfigName, LPCSTR FolderName)
{
	unsigned char cResult;

	WIN32_FIND_DATAA wfd;
	if (FindFirstFileA(FolderName, &wfd) == INVALID_HANDLE_VALUE)
	{				
		cResult = Default;
	}
	else
		cResult = GetPrivateProfileInt(BlockName, ConfigName, -100500, FolderName);

	if(cResult == -100500)
	{	   
		cResult = Default;
	}

	if(cResult < Min || cResult > Max)
	{
		cResult = Default;
	} 
	return cResult;
}