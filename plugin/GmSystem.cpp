#include "StdAfx.h"
cGmSystem GmSystem;


void cGmSystem::ResetConfig()
{
	Config.IsGMSystem	= 0;
	Config.IsGMInDB		= 0;

	GMCount = 0;
	for (int i=0; i<255; i++)
	{
		GM[i].IsAdmin	= 0;
		GM[i].Name[0]	= NULL;
		GM[i].Drop		= 0;
		GM[i].Gg		= 0;
		GM[i].SetZen	= 0;
		GM[i].Status	= 0;
		GM[i].Gmove		= 0;
		GM[i].SetPK		= 0;	 
		GM[i].PkClear	= 0;	
		GM[i].BanPlayer	= 0;
		GM[i].Reload	= 0;
		GM[i].Skin		= 0;	 
		GM[i].BanPost	= 0;
		GM[i].Voskl		= 0;
		GM[i].Disconnect= 0;
		GM[i].Trace		= 0;
		GM[i].DisableChat = 0;
	}
}

void cGmSystem::Load()
{
	ResetConfig();
	Config.IsGMSystem	= Configs.GetInt(0, 1, 0, "GMSystem", "IsGMSystem",RZGM);		
	if(!Config.IsGMSystem)return;
	Config.IsGMInDB		= Configs.GetInt(0, 1, 0, "GMSystem", "IsGMInDB",RZGM);

	FILE *file;

	file = fopen(RZGM,"r");

	if (file == NULL)
	{
		Config.IsGMSystem = 0;
		MessageBox(NULL,"[X] [GMSystem]\tCan't Find GMSystem.txt","Error",0);
		//MessageBox(NULL,"File Missing.","Error",MB_OK);
		//LogAddFuncColor(2,"[X] [GMSystem]\tCan`t Find %s",RZGM);
		return;
	}

	char Buff[256];
	int Flag = 0;

	while (!feof(file))
	{
		fgets(Buff,256,file);

		if(Utilits.IsBadFileLine(Buff, Flag))
			continue;

		if (Flag == 1)
		{
			int n[15];
			char GetGMName[11];
			int isAdmin;

			sscanf(Buff, "%d %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&isAdmin, &GetGMName, &n[0], &n[1], &n[2], &n[3], &n[4], &n[5],  &n[6], &n[7], &n[8], &n[9], &n[10], &n[11], &n[12], &n[13], &n[14]);
			GM[GMCount].IsAdmin		= isAdmin;
			sprintf(GM[GMCount].Name,"%s",GetGMName);
			GM[GMCount].Drop		= n[0];
			GM[GMCount].Gg			= n[1];
			GM[GMCount].SetZen		= n[2];
			GM[GMCount].Status		= n[3];
			GM[GMCount].Gmove		= n[4];
			GM[GMCount].SetPK		= n[5];		 
			GM[GMCount].PkClear		= n[6];	 	
			GM[GMCount].BanPlayer	= n[7];   
			GM[GMCount].Reload		= n[8];
			GM[GMCount].Skin		= n[9];			 
			GM[GMCount].BanPost		= n[10];
			GM[GMCount].Voskl		= n[11];  
			GM[GMCount].Disconnect	= n[12];
			GM[GMCount].Trace		= n[13];
			GM[GMCount].DisableChat = n[14];
			GMCount++;
		}
	}

	fclose(file);	
	//Log.ConsoleOutPut(1, c_Magenta, t_GM, "[+] [GMSystem]\tLoad successfully. Total GMs: %d", GMCount);
	LogAddFuncColor(3,"[+] [GMSystem]\tLoad successfully. Total GMs: %d", GMCount);
}


int cGmSystem::IsCommand(Commands Cmd, char Character[11])
{	
	switch (Cmd)
	{
	case NONE:
		return 1;
	}
	if(IsGMBD(Character))
	{
		if (Config.IsGMSystem)
		{
			for(int x=0; x < GMCount; x++)
				if(!strcmp(GM[x].Name, Character))
				{
					switch (Cmd)
					{
					case cDrop:
						return GM[x].Drop;
					case cGg:
						return GM[x].Gg;
					case cSetZen:
						return GM[x].SetZen;
					case cStatus:
						return GM[x].Status;
					case cGmove:
						return GM[x].Gmove;	 
					case cSetPK:
						return GM[x].SetPK;	   
					case cPkClear:
						return GM[x].PkClear;		 
					case cBanPlayer:
						return GM[x].BanPlayer;
					case cReload:
						return GM[x].Reload;
					case cSkin:
						return GM[x].Skin;	  	
					case cBanPost:
						return GM[x].BanPost;
					case cVoskl:
						return GM[x].Voskl;		
					case cDisconnect:
						return GM[x].Disconnect;
					case cTrace:
						return GM[x].Trace;
					case cDisableChat:
						return GM[x].DisableChat;
					}
				}
				return 0; 
		}
		else
			return 1;
	}
	else
		return 0;
}

int cGmSystem::IsAdmin(char Character[11])
{	
	if(IsGMBD(Character))
	{
		if (Config.IsGMSystem)
		{
			for(int x=0; x < GMCount; x++)
				if(!strcmp(GM[x].Name, Character))
				{
					switch (GM[x].IsAdmin)
					{
					case 0: 
						return 0;
					case 1: 
						return 1;
					case 2:
						return 2;					
					}
				}
				return 0; 
		}
		else
			return 2;
	}
	else return 0;
}					  

bool cGmSystem::IsGMBD(char Character[11])
{
	if(Config.IsGMInDB == 0)
		return true;
	for(int i = OBJ_MIN; i <= OBJ_MAX; i++)
	{  	 
		OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(i);
		if(gObj->Connected < PLAYER_PLAYING) continue;
		if(!strcmp(gObj->Name, Character) && (gObj->Authority == 32 || gObj->Authority == 8))
			return true;
	}
	return false;
}

bool cGmSystem::IsGMBD(int aIndex)
{
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	if(gObj->Connected < PLAYER_PLAYING) 
		return false;
	if((gObj->Authority == 32 || gObj->Authority == 8))
		return true;

	return false;
}
