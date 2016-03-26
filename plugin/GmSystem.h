#ifndef GMSYSTEM_H
#define GMSYSTEM_H

#include "StdAfx.h"

class cGmSystem
{
public:
	struct GMSystem
	{
		char Name[12];
		int Drop;
		int Gg;
		int SetZen;
		int Status;
		int Gmove;
		int SetPK;
		int PkClear;  	 
		int BanPlayer;
		int Reload;
		int Skin;
		int BanPost;
		int Voskl;
		int Disconnect;
		int Trace;	 
		int IsAdmin;
		int DisableChat;
	};

	enum Commands 
	{	
		NONE = -1,
		cDrop,
		cGg,
		cSetZen,
		cStatus,
		cGmove,
		cSetPK,
		cPkClear,
		cBanPlayer,
		cReload,
		cSkin,
		cBanPost,
		cVoskl,
		cDisconnect,
		cTrace,
		cDisableChat
	};

	struct sConfig
	{	  
		int IsGMSystem;
		int IsGMInDB;
	};	

	//Structures
	sConfig Config;
	GMSystem GM[255];
	int GMCount;

	void ResetConfig();	
	void Load();
	int IsCommand(Commands, char[11]);
	int IsAdmin(char[11]);
	bool IsGMBD(char[11]);
	bool IsGMBD(int aIndex);
};
extern cGmSystem GmSystem;

#endif