#ifndef FIXES_H
#define FIXES_H
#pragma  once

class cFixes
{
public:
	cFixes();
	~cFixes();
	void Load();
	void ASMFixes();
	void Crack();
public:
//	void ShopExeHook();
};
extern cFixes Fixes;

#ifdef _GS
//-----------------------------------------------------------//
//#				Crack do Gameserver				# //
//-----------------------------------------------------------//
#define oDataPath0			0x00FE4A10//
#define oDataPath1			0x00B39814//
#define oDataPath2			0x00B39823//
#define oDataPath3			0x00B39832//
#define oServerInfoPath0	0x00FE4BAC//
//-----------------------------------------------------------//
//				Debug logs
//-----------------------------------------------------------//
#define	oCGClientMsg		0x008520C0//ok
#define	oGuarditBreach		0x00895930//ok
#define	g_bAbilityDebug0	0x00AC5539//

#define	g_bAbilityDebug2	0x00A9930C
#define	oShieldLog			0x00A7E161//5nop

#define	oAttackPacketLog	0x0084BD3B
#define	oMagicAttackLog		0x00879D84//
#define	oDebugOutput		0x00A7D500
#define	oDecrypt1			0x0097F77B
#define	oTestMessagebox		0x00B41647
#define	oNpcTalkLog			0x00B7EF27
#define	og_AccessoryOptionFlag0	0x00A98D89
#define	og_AccessoryOptionFlag1	0x00A98E53

#define	oMuunLog0			0x00CF200E
#define	oMuunLog1			0x00CF9056
#define	oMuunLog2			0x00CF90BC
#define	oMuunLog3			0x00CFC1C1
#define	oMuunLog4			0x00CFDF4E

#define	oStrangeLog0		0x00A98841
#define	oStrangeLog1		0x00AA099B
#define	oStrangeLog2		0x00D25F1A
#define	oStrangeLog3		0x00CF946D

#define	oXMasDebugMsg		0x00907F60

#define	og_bAbilityDebug	0x00AC552F
#define	og_nDebugViewFlag	0x00B2DB29
#define	og_AccessoryOptionFlag	0x00B2EA4E
//-----------------------------------------------------------//
//				Fixes
//-----------------------------------------------------------//
#define	oCheckSum0			0x00A79CB0
#define	oCheckSum1			0x0088C020

#define	oGMMoveMkey			0x00B28543

#define	oPersonalID			0x00852A4A
#define	oGuildID0			0x00872DDE
#define	oGuildID1			0x00872C14
#define	oAllowExAnc			0x00B0A1B0//??
#define	oAllowExSock		0x00B0A252//??
#define	oAllowJOHAnc		0x00BA56B5//??

#define	oAppointItemDrop	0x00800396//fixed

#define	oJOLOpt0			0x00A1AA01
#define	oJOLOpt1			0x008378F1
#define	oJOLOpt2			0x00B15A6D
#define	oJOLOpt3			0x00A72067
#define	oJOLOpt4			0x00A1AA37

#define	oGSClose0			0x00B41636
#define	oGSClose1			0x00A1EBC1
#define	oGSClose2			0x00A1731A
#define	oGSClose3			0x00B1037E
		//Remove Potion Limit
#define oMaxPot0			0x00837D53
#define oMaxPot1			0x00A1AD83
#define oMaxPot2			0x00A1AF19
#define oMaxPot3			0x00A1AD81
#define oMaxPot4			0x00A1ADCD
#define oMaxPot5			0x00A1AE10
#define oMaxPot6			0x00A1AE77
#define oMaxPot7			0x00A1AEC8
#define oMaxPot8			0x00A1AF5D
#define oMaxPot9			0x00837D51
	// Invalid Socket FIX
#define	oInvalidSocket0		0x0098174F
#define	oInvalidSocket1		0x009818DB
	// Disable Crash Dump File
#define	oCrashDump			0x00A13BB0
#else
//-----------------------------------------------------------//
//#				Crack do Gameserver				# //
//-----------------------------------------------------------//
#define oDataPath0			0x010666B0//ok
#define oDataPath1			0x00B81CA4//ok
#define oDataPath2			0x00B81CB3//ok
#define oDataPath3			0x00B81CC2//ok

#define oServerInfoPath0	0x0106684C//ok
#define	oCommonjmp			0x00B85CEF
//-----------------------------------------------------------//
//				Debug logs
//-----------------------------------------------------------//
#define	oCGClientMsg		0x0087CC30//ok
#define	oGuarditBreach		0x008C5890//ok
#define	g_bAbilityDebug0	0x00B0F479//ok
#define	g_bAbilityDebug2	0x00AE26A3//ok
#define	oShieldLog			0x00AC74A1//5nop//ok
#define	oAttackPacketLog	0x0087688B//ok
#define	oMagicAttackLog		0x008A4BE4//ok
#define	oDebugOutput		0x00C08510//ok
#define	oDecrypt1			0x009C6E5B//ok
#define	oTestMessagebox		0x00B89CA1//ok
#define	oNpcTalkLog			0x00BFC7D7//ok
#define	og_AccessoryOptionFlag0	0x00AE2120//ok
#define	og_AccessoryOptionFlag1	0x00AE21EA//ok
#define	oMuunLog0			0x00D6C89E//ok
#define	oMuunLog1			0x00D738E6//ok
#define	oMuunLog2			0x00D7394C//ok
#define	oMuunLog3			0x00D76A51//ok
#define	oMuunLog4			0x00D7895E//ok
#define	oStrangeLog0		0x00AE1BD8//ok
#define	oStrangeLog1		0x00AE9E8E//ok
#define	oStrangeLog2		0x00DA092A//ok
#define	oStrangeLog3		0x00D73CFD//ok
#define	oXMasDebugMsg		0x00937DD0//ok
#define	og_bAbilityDebug	0x00B0F46F//ok
#define	og_nDebugViewFlag	0x00B75FF8//ok
#define	og_AccessoryOptionFlag	0x00B76F1D//ok
#define	oAppointItemDrop	0x00829DD6//ok
//-----------------------------------------------------------//
//				Fixes
//-----------------------------------------------------------//
#define	oCheckSum0			0x00AC2EA0//ok
#define	oCheckSum1			0x008B70C0//ok
//--
#define	oGMMoveMkey			0x00B70A73//ok
//--
#define	oPersonalID			0x0087D5BA//ok
#define	oGuildID0			0x0089D90B//ok
#define	oGuildID1			0x0089D6E5//ok
//--
#define	oAllowExAnc			0x00B52810//ok
#define	oAllowExSock		0x00B528B2//ok
#define	oAllowJOHAnc		0x00C23945//ok
//--
#define	oJOLOpt0			0x00A622A1//ok
#define	oJOLOpt1			0x00860DA1//ok
#define	oJOLOpt2			0x00B5E0CD//ok
#define	oJOLOpt3			0x00ABB2D7//ok
#define	oJOLOpt4			0x00A622D7//ok
//--
#define	oGSClose0			0x00B89C90//ok
#define	oGSClose1			0x00A665AA//ok
#define	oGSClose2			0x00A5EB4A//ok
#define	oGSClose3			0x00B589DE//ok
		//Remove Potion Limit
#define oMaxPot0			0x0080E313//ok
#define oMaxPot1			0x009D36A3//ok
#define oMaxPot2			0x00A627B9//ok
#define oMaxPot3			0x00A62621//ok
#define oMaxPot4			0x00A6266D//ok
#define oMaxPot5			0x00A626B0//ok
#define oMaxPot6			0x00A62717//ok
#define oMaxPot7			0x00A62768//ok
#define oMaxPot8			0x00A627FD//ok
#define oMaxPot9			0x00861201//ok
	// Invalid Socket FIX
#define	oInvalidSocket0		0x009C8E2F//ok
#define	oInvalidSocket1		0x009C8FBB//ok
	// Disable Crash Dump File
#define	oCrashDump			0x00A5B2A0//ok
#endif
#endif // !FIXES_H