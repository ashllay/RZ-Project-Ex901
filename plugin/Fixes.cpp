#include "StdAfx.h"

cFixes Fixes;
cFixes::cFixes(){}
cFixes::~cFixes(){}

void cFixes::Load()
{
	this->ASMFixes();
	this->Crack();
}

void cFixes::Crack()
{
	const char DATA_PATH[] = { "..\\Data\\" };
	const char SERVER_INFO[] = { "Data\\ServerInfo.dat" };
#ifdef _GS_CS
	Utilits.SetByte(oCommonjmp,JMP);
#endif
	//Change Data Folder Path
	memcpy((int*)oDataPath0,DATA_PATH,sizeof(DATA_PATH));
#if(_GS_CS)
	Utilits.SetByte(oDataPath1,0xB0);
	Utilits.SetByte(oDataPath2,0xB0);
	Utilits.SetByte(oDataPath3,0xB0);
#else
	Utilits.SetByte(oDataPath1,0x10);

	BYTE DataPath[] = { 0x68, 0x10, 0x4A };
	memcpy((int*) oDataPath2,DataPath,sizeof(DataPath));
	memcpy((int*) oDataPath3,DataPath,sizeof(DataPath));
#endif
	//Change ServerInfo.dat
	memcpy((int*)oServerInfoPath0,SERVER_INFO,sizeof(SERVER_INFO));
}

void cFixes::ASMFixes()
{

	//Configs.LoadFixes();
//==========================================================================
//-- Degbug Logs
//==========================================================================
	//Disable DebugOutput
	Utilits.SetRetn(oDebugOutput);
	//"error-L1 : HackCheck [%s][%s] 0x%x 0x%x"
	Utilits.SetRetn(oCGClientMsg);
	//"[Security][Breach] Account[%s] Character[%s] Code[%d]"
	Utilits.SetRetn(oGuarditBreach);
	// Fuck crap message about test
	Utilits.SetNop(oTestMessagebox,5);
	//Decrypt1> ALG: %d, ENC: %d, DEC: %d, Serial: %d
	Utilits.SetNop(oDecrypt1,6);
	//[Shield] ݯ֥ %d µС:%d
	Utilits.SetNop(oShieldLog,5);
	//[TEST2] C => S Attack Packet
	Utilits.SetNop(oAttackPacketLog,6);
	//[CGMagicAttack] : Magic : %d
	Utilits.SetNop(oMagicAttackLog,6);
	//NpcTalk NPCNumber %d
	Utilits.SetNop(oNpcTalkLog,6);
	//00AC552F     C705 84FB5809 0 MOV DWORD PTR DS:[g_bAbilityDebug],1
	Utilits.SetByte(og_bAbilityDebug+6,0x00);
	//00A7D500    55              PUSH EBP   ; GameServer_2008.DebugOutput(aIndex,msg)
	//Utilits.SetByte(0x00A7D500,0xC3);
	//00B2DB29    A3 40F85809     MOV DWORD PTR DS:[g_nDebugViewFlag],EAX ( -> 0)
	Utilits.SetByte(og_nDebugViewFlag+5,0x00);
	//00B2EA4E    C705 ACFB5809 0 MOV DWORD PTR DS:[g_AccessoryOptionFlag],0 (-> 1)
	Utilits.SetByte(og_AccessoryOptionFlag+6,0x01);
	//Muun Logs
	Utilits.SetNop(oMuunLog0,5);
	Utilits.SetNop(oMuunLog1,5);
	Utilits.SetNop(oMuunLog2,5);
	Utilits.SetNop(oMuunLog3,5);
	Utilits.SetNop(oMuunLog4,5);
	//MsgOutput(lpTargetObj->m_Index, "[ӯгЭȭ - ڦ߮؂] %d", v22);
	Utilits.SetNop(oStrangeLog0,5);
	//j__sprintf(&v259, "đ յۭȮؼ %.2f ==> އf յۭȮؼ %.2f", v261, v262);
	Utilits.SetNop(oStrangeLog1,5);
	//_wsprintfA(message, "[ƫȕ|e üߩ ܳƂ: %d (1:üߩܳƂ/0:۱üߩܳƂ]", lpObj->m_JoinUnityBattile);
	Utilits.SetNop(oStrangeLog2,5);
	Utilits.SetNop(oStrangeLog3,5);
	//CXMasAttackEvent::_SendDebugMsg
	Utilits.SetRetn(oXMasDebugMsg);
	//Debug Message on gs close
	BYTE GSCloseH[25] = { 0x90, 0x90, 0x90, 0x90, 0x90, 
		0x90, 0x90, 0x90, 0x90, 0x90, 
		0x90, 0x90, 0x90, 0x90, 0x90, 
		0x90, 0x90, 0x90, 0x90, 0x90,
		0x90, 0x90, 0x90, 0x90, 0x90};
	memcpy((int*) oGSClose0,GSCloseH,sizeof(GSCloseH));
	Utilits.SetByte(oGSClose1,0xEB);
	Utilits.SetByte(oGSClose2,0xEB);
	Utilits.SetByte(oGSClose3+5,0x00);
	//AppointItemDrop.txt Reload Error 	
	Utilits.SetByte(oAppointItemDrop,0xEB);
//==========================================================================
	//disable CheckSum
	Utilits.SetRetn(oCheckSum0);
	Utilits.SetRetn(oCheckSum1);

	Utilits.SetNop(oInvalidSocket0,2);	// Invalid Socket FIX
	Utilits.SetByte(oInvalidSocket1,0xEB);	//
	//--
	//==========================================================================
	//-- GM Move "M" Key
	//==========================================================================
	BYTE GMMoveM[6] = { 0xE9, 0xD7, 0x01, 0x00, 0x00, 0x90 };
	memcpy((int*) oGMMoveMkey,GMMoveM,sizeof(GMMoveM));
	if (Configs.FixPotionsMax)
	{
		//Remove Potion Limit
		Utilits.SetByte(oMaxPot3,0xEB); //Inventory (Potions, Scrolls, Etc)
		Utilits.SetByte(oMaxPot4,0xEB);
		Utilits.SetByte(oMaxPot5,0xEB);
		//Utilits.SetByte(0x005399B1,0xEB);
		Utilits.SetByte(oMaxPot6,0xEB);
		Utilits.SetByte(oMaxPot7,0xEB);
		Utilits.SetByte(oMaxPot8,0xEB);
		Utilits.SetByte(oMaxPot9,0xEB); //Warehouse
		//
		BYTE PotionsMaxh[6] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
		memcpy((int*) oMaxPot0,PotionsMaxh,sizeof(PotionsMaxh));
		memcpy((int*) oMaxPot1,PotionsMaxh,sizeof(PotionsMaxh));
		Utilits.SetByte(oMaxPot2,0xEB);
	}
	// Personal ID
	if (Configs.PersonalIDFix)
		Utilits.SetNop(oPersonalID, 5);// Personal ID Fix//04

	// Guild ID
	if (Configs.GuildIDFix)
	{
		Utilits.SetNop(oGuildID0, 2);// Guild ID Fix//04
		Utilits.SetNop(oGuildID1, 6);// Guild ID Fix//04
	}
	// Allow Excellent Ancient
	if (Configs.AllowExeAnc)
		Utilits.SetByte(oAllowExAnc,JMP);//gs04

	// Allow Exelent Socket   
	if (Configs.AllowExeSock)
		Utilits.SetByte(oAllowExSock,JMP);//gs04

	// Allow Jewel of Harmony Ancient
	if (Configs.AllowJohAnc)
		Utilits.SetByte(oAllowJOHAnc,JMP);//gs04

	if (Configs.MaxLifeOpt)
	{
		//Options +28
		Utilits.SetNop(oJOLOpt0,2); //Inventory
		Utilits.SetNop(oJOLOpt1,2); //Warehouse
		Utilits.SetNop(oJOLOpt2,2); //ItemByteConvert3
		Utilits.SetByte(oJOLOpt3+2,0x07); //Use Jewel of Life
		Utilits.SetByte(oJOLOpt4+2,0x07);
	}
	// Fix Crash Dump File//gs*/
	Utilits.SetRetn(oCrashDump);
}