#include "StdAfx.h"
cUser User;
sAddTab AddTab[OBJ_MAX];

int cUser::GetPlayerIndex(char *Name)
{			 
	for(int i = OBJ_MIN; i <= OBJ_MAX; i++)
	{  	 
		OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(i);	 
		if(gObj->Connected < PLAYER_PLAYING) 
			continue; 	   
		if(!strcmp(gObj->Name, Name)) 
			return i;
	}
	return -1;
}

char* cUser::GetMapName(int MapId)
{
	switch (MapId)
	{
	case -1:
		return "All Maps";
	case MAP_INDEX_RORENCIA:
		return "Lorencia";
	case 1:
		return "Dungeon";
	case 2:
		return "Devais";
	case 3:
		return "Noria";
	case 4:
		return "Lost Tower";
	case 5:
		return "Null";
	case 6:
		return "Arena";
	case 7:
		return "Atlans";
	case 8:
		return "Tarkan";
	case 9:
		return "Devil Square";
	case 10:
		return "Icarus";
	case 30:
		return "Valley of Loren";
	case 31:
		return "Land of Trial";
	case 32:
		return "Devil Square";
	case 33:
		return "Aida";
	case 34:
		return "Crywolf";
	case 35:
		return "Null";
	case 36:
		return "Kalima";
	case 37:
		return "Kantru1";
	case 38:
		return "Kantru2";
	case 39:
		return "Kantru3";
	case 40:
		return "Silent";
	case 41:
		return "Barracks";
	case 42:
		return "Refuge";
	case 43:
		return "Null";
	case 44:
		return "Null";
	case 51:
		return "Elbeland";
	case 52:
		return "Blood Castle";
	case 53:
		return "Chaos Castle";
	case 56:
		return "Swamp of Calmness";
	case 57:
		return "Raklion";
	case 58:
		return "Raklion Boss";
	case 62:
		return "Santa Town";
	case 63:
		return "Vulcanus";
	case 64:
		return "Coliseum";
	case MAP_INDEX_ROREN_MARKET:
		return "Loren Market";
	if (MapId >= 11 && MapId <= 17)
		return "Blood Castle";
	if (MapId >= 18 && MapId <= 23)
		return "Chaos Castle";
	if (MapId >= 24 && MapId <= 29)
		return "Kalima";
	if (MapId >= 45 && MapId <= 50)
		return "Illusion Temple";
	if (MapId >= MAP_INDEX_DOPPELGANGER_1 && MapId <= MAP_INDEX_DOPPELGANGER_4)
		return "Doppelganger";
	if (MapId >= MAP_INDEX_PARTYDUNGEON_DAYOFWEEK1 && MapId <= MAP_INDEX_PARTYDUNGEON_DAYOFWEEK4)
		return "ImperialGuardian";
	}
	return "Unknown";
}