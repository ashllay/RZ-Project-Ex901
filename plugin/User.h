#include "Prodef.h"
#pragma once
#ifndef USER_H
#define USER_H

#ifdef _GS
//strings connect : [%d][%s]
#define OBJECT_BASE     (*(CHAR**)0x0C937E8C)//.10
#define OBJECT_SIZE		0x4DE0//10
#define OBJ_MIN			9000
#define OBJ_MAX			10000
#define	OBJMAXUSER		1000
#define	oVirtualProtect	0x00FA6FFE
#else
#define OBJECT_BASE     (*(CHAR**)0x0A93DBD8)
#define OBJECT_SIZE		0x4DF0
#define OBJ_MIN			6400
#define OBJ_MAX			7400
#define	oVirtualProtect	0x01022FFE
#endif

#define OBJECT_POINTER(aIndex)((aIndex * OBJECT_SIZE) + OBJECT_BASE)
//#define POBJ(aIndex)((aIndex * OBJECT_SIZE) + OBJECT_BASE)

#define OBJECT_TABINDEX(lpObj) ((lpObj - OBJECT_BASE) / OBJECT_SIZE)
//#define OBJMAX_RANGE(aIndex)((aIndex < 0) ? false : (aIndex > (OBJ_MAX - 1)) ? false : true )
#define OBJMAX_RANGE(aIndex)(((aIndex) < 0)?FALSE:((aIndex) > OBJ_MAX-1)?FALSE:TRUE)
#define BC_MAP_RANGE(value) ( ( value == MAP_INDEX_BLOODCASTLE8 ) ? TRUE : ( value < MAP_INDEX_BLOODCASTLE1 ) ? FALSE : ( value > MAP_INDEX_BLOODCASTLE7) ? FALSE : TRUE )

#define CS_CLASS                    0
#define CS_GET_CLASS(x)             ((x) <<5 ) & 0xE0
#define CS_GET_CHANGEUP(x)          (((x)&0x07) )
#define CS_SET_CLASS(x)             (((x)<<5)& 0xE0 )
#define CS_SET_CHANGEUP(x)          (((x) << 4) & 0x10 )
#define CS_SET_3RD_CHANGEUP(x)      (((x) << 3) & 8 )
#define DBI_GET_TYPE(x)             (((x)&((MAX_TYPE_ITEMS-1)<<8))>>4 )
#define DBI_GET_LEVEL(x)            (((x)>>3)& MAX_ITEM_LEVEL )

#define CS_SET_WING1(x)             (((x) & 0x03 ) << 2 )

namespace CLASS
{
	enum INDEX 
	{
		DARK_WIZARD=0,
		DARK_KNIGHT=1,
		FAIRY_ELF=2,
		MAGIC_GLADIATOR=3,
		DARK_LORD=4,
		SUMMONER=5,
		RAGE_FIGHTER=6
	};
};

typedef struct BUFF_EFFECT_DATA
{
    unsigned char BuffIndex;
    unsigned char BuffEffectType;
    unsigned char ItemType;
    unsigned char ItemIndex;
    char BuffName[20];
    unsigned char BuffType;
    unsigned char NoticeType;
    unsigned char ClearType;
    char BuffDescript[100];
} *PBUFF_EFFECT_DATA;

enum eBuffEffectIndex
{
    BUFFTYPE_NONE=0,
    BUFFTYPE_ATTACK_POWER_INC=1,
    BUFFTYPE_DEFENSE_POWER_INC=2,
    BUFFTYPE_ATTDEF_POWER_INC=3,
    BUFFTYPE_MELEE_DEFENSE_INC=4,
    BUFFTYPE_CRITICAL_DMG_INC=5,
    BUFFTYPE_INFINITY_ARROW=6,
    BUFFTYPE_AG_RECOVERY_INC=7,
    BUFFTYPE_HP_INC=8,
    BUFFTYPE_MANA_INC=9,
    BUFFTYPE_BLESS_POTION=10,
    BUFFTYPE_SOUL_POTION=11,
    BUFFTYPE_MAGIC_CANCEL=12,
    BUFFTYPE_CASTLE_DOOR_STATE=13,
    BUFFTYPE_CASTLE_DEFENSE_MARK=14,
    BUFFTYPE_CASTLE_ATTACK_MARK=15,
    BUFFTYPE_CASTLE_ATTACK_MARK_2=16,
    BUFFTYPE_CASTLE_ATTACK_MARK_3=17,
    BUFFTYPE_INVISABLE=18,
    BUFFTYPE_DARKLORD_CASTLE_SKILL=19,
    BUFFTYPE_CASTLE_CROWN_STATE=20,
    BUFFTYPE_CRYWOLF_CONTRACT_ENABLE=21,
    BUFFTYPE_CRYWOLF_CONTRACT_DISABLE=22,
    BUFFTYPE_CRYWOLF_CONTRACT=23,
    BUFFTYPE_CRYWOLF_CONTRACT_TRY=24,
    BUFFTYPE_CRYWOLF_OCCUPATION=25,
    BUFFTYPE_CRYWOLF_CONTRACT_HERO=26,
    BUFFTYPE_CRYWOLF_NPC_INVISABLE=27,
    BUFFTYPE_GM_MARK=28,
    BUFFTYPE_PCBANG_POINT_MARK1=29,
    BUFFTYPE_PCBANG_POINT_MARK2=30,
    BUFFTYPE_PCBANG_POINT_MARK3=31,
    BUFFTYPE_TEMPLE_QUICKNESS=32,
    BUFFTYPE_TEMPLE_SUBLIMATION=33,
    BUFFTYPE_TEMPLE_PROTECTION=34,
    BUFFTYPE_HALLOWEEN_BLESS=35,
    BUFFTYPE_HALLOWEEN_ANGER=36,
    BUFFTYPE_HALLOWEEN_CRY=37,
    BUFFTYPE_HALLOWEEN_FOOD=38,
    BUFFTYPE_HALLOWEEN_DRINK=39,
    BUFFTYPE_PCS_MARK1=40,
    BUFFTYPE_PCS_MARK2=41,
    BUFFTYPE_PCS_MARK3=42,
    BUFFTYPE_PCS_MARK4=43,
    BUFFTYPE_PCS_SCROLL_HASTE=44,
    BUFFTYPE_PCS_SCROLL_DEFENSE=45,
    BUFFTYPE_PCS_SCROLL_ANGER=46,
    BUFFTYPE_PCS_SCROLL_MAGIC=47,
    BUFFTYPE_PCS_SCROLL_HEALTH=48,
    BUFFTYPE_PCS_SCROLL_MANA=49,
    BUFFTYPE_PCS_MEDICINE_STRENGTH=50,
    BUFFTYPE_PCS_MEDICINE_DEXTERITY=51,
    BUFFTYPE_PCS_MEDICINE_VITALITY=52,
    BUFFTYPE_PCS_MEDICINE_ENERGY=53,
    BUFFTYPE_PCS_MEDICINE_LEADERSHIP=54,
    BUFFTYPE_POISON=55,
    BUFFTYPE_FREEZE=56,
    BUFFTYPE_STONE=57,
    BUFFTYPE_DEFENSE_POWER_DEC=58,
    BUFFTYPE_ATTACK_POWER_DEC=59,
    BUFFTYPE_MAGIC_POWER_DEC=60,
    BUFFTYPE_STUN=61,
    BUFFTYPE_MONSTER_MAGIC_DEFENSE=62,
    BUFFTYPE_MONSTER_MAGIC_IMMUNE=63,
    BUFFTYPE_MONSTER_MELEE_IMMUNE=64,
    BUFFTYPE_RESTRICTION=65,
    BUFFTYPE_CRYWOLF_STATUE_LV1=66,
    BUFFTYPE_CRYWOLF_STATUE_LV2=67,
    BUFFTYPE_CRYWOLF_STATUE_LV3=68,
    BUFFTYPE_CRYWOLF_STATUE_LV4=69,
    BUFFTYPE_CRYWOLF_STATUE_LV5=70,
    BUFFTYPE_DAMAGE_REFLECT=71,
    BUFFTYPE_SLEEP=72,
    BUFFTYPE_BLIND=73,
    BUFFTYPE_BLOODDOT=74,
    BUFFTYPE_FIREDOT=75,
    BUFFTYPE_CURSED_ATTACK_DOWN=76,
    BUFFTYPE_CURSED_DEFENSE_DOWN=77,
    BUFFTYPE_CHERRYBLOSSOM_DRINK=78,
    BUFFTYPE_CHERRYBLOSSOM_DUMPLING=79,
    BUFFTYPE_CHERRYBLOSSOM_PETAL=80,
    BUFFTYPE_BERSERKER=81,
    BUFFTYPE_MAGIC_POWER_INC=82,
    BUFFTYPE_FLAMESTRKE=83,
    BUFFTYPE_GIGANTICSTORM=84,
    BUFFTYPE_LIGHTNINGSHOCK=85,
    BUFFTYPE_COLD=86,
    BUFFTYPE_PCS_MARK5=87,
    BUFFTYPE_PCS_MARK6=88,
    BUFFTYPE_PCS_SCROLL_CRITICAL=89,
    BUFFTYPE_PCS_SCROLL_EXCELLENT=90,
    BUFFTYPE_CHRISTMAS_BLESS=91,
    BUFFTYPE_SANTA_HEAL=92,
    BUFFTYPE_SANTA_PROTECT=93,
    BUFFTYPE_SANTA_POWER=94,
    BUFFTYPE_SANTA_GUARD=95,
    BUFFTYPE_SANTA_SPEED=96,
    BUFFTYPE_SANTA_LUCKY=97,
    BUFFTYPE_CHARM_GUARDIAN=99,
    BUFFTYPE_CHARM_PROTECTITEM=100,
    BUFFTYPE_PCS_MARK1_FOR_MASTER=101,
    BUFFTYPE_PCS_MARK2_FOR_MASTER=102,
    BUFFTYPE_OBSERVER=98,
    BUFFTYPE_GLORYOFGLADIATOR=103,
    BUFFTYPE_ASCENSION=105,
    BUFFTYPE_PK_PENALTY=106,
    BUFFTYPE_FIRST_FATIGUE=107,
    BUFFTYPE_SECOND_FATIGUE=108,
    BUFFTYPE_PARTY_EXP_INCREASE_SCROLL=112,
    BUFFTYPE_MAX_AG_INCREASE_AURA=113,
    BUFFTYPE_MAX_SD_INCREASE_AURA=114,
    BUFFTYPE_REVITALIZATION_1=115,
    BUFFTYPE_REVITALIZATION_2=116,
    BUFFTYPE_REVITALIZATION_3=117,
    BUFFTYPE_REVITALIZATION_4=118,
    BUFFTYPE_PCS_MARK2_FOR_CASHITEM=119,
    BUFFTYPE_HACKTOOL_USE_PENALTY=120,
    BUFFTYPE_CASHITEM_SCROLL_HEALINGSCLOLL=121,
    BUFFTYPE_SCULPT_HAWK=122,
    BUFFTYPE_SCULPT_SHEEP=123,
    BUFFTYPE_CHARM_ORC=124,
    BUFFTYPE_CHARM_MAPLE=125,
    BUFFTYPE_CHARM_GOLDEN_ORC=126,
    BUFFTYPE_CHARM_GOLDEN_MAPLE=127,
    BUFFTYPE_ARTIFACT_HORSESHOE=128,
    BUFFTYPE_ENEMY_DEFENSE_IGNORANCE_RATE_INCREASE=129,
    BUFFTYPE_VITALITY_INCREASE=130,
    BUFFTYPE_DEFENSE_SUCCESS_RATE_INCREASE=131,
    BUFFTYPE_DEFENSE_SUCCESS_RATE_DECREASE=132,
    BUFFTYPE_IMMUNE=133,
    BUFFTYPE_IRONDEFENSE=134,
    BUFFTYPE_SKILLFULL_SWELLIFE=135,
    BUFFTYPE_MASTERY_SWELLIFE=136,
    BUFFTYPE_MISSING_BLOOD=137,
    BUFFTYPE_INC_MAGICPOWER=138,
    BUFFTYPE_MASTERY_INC_MAGICPOPWER=139,
    BUFFTYPE_MASTERY_MAGICDEFENSE=140,
    BUFFTYPE_REDUCE_ATTACK_SPEED=141,
    BUFFTYPE_BLESS=142,
    BUFFTYPE_STRENGTHEN_INFINITY_ARROW=143,
    BUFFTYPE_MLS_BLIND=144,
    BUFFTYPE_MASTERY_DRAINLIFE=145,
    BUFFTYPE_ICE_HARDEN=146,
    BUFFTYPE_EARTHPRISON=147,
    BUFFTYPE_CRITICALDAMAGE_RATE_INC=148,
    BUFFTYPE_CRITICALDAMATE_EXDAMAGE_INC=149,
    BUFFTYPE_STRENGTHEN_BERSERKER=150,
    BUFFTYPE_SKILLFUL_BERSERKER=151,
    BUFFTYPE_MASTERY_BERSERKER=152,
    BUFFTYPE_STRENGTHEN_INC_BLOCK_RATE=153,
    BUFFTYPE_MASTERY_INC_BLOCK_RATE=154,
    BUFFTYPE_INC_VITAL_MONK=155,
    BUFFTYPE_STRENGTHEN_IGNORE_ENEMY_DEFENSE=156,
    BUFFTYPE_FIREATTACK=157,
    BUFFTYPE_ICEATTACK=158,
    BUFFTYPE_POISONARROW=159,
    BUFFTYPE_STRENGTHEN_POISONARROW=160,
    BUFFTYPE_STRENGTHEN_BLESS=161,
    BUFFTYPE_STRENGTHEN_WEAKNESS=162,
    BUFFTYPE_STRENGTHEN_ENERVATION=163,
    BUFFTYPE_DEC_DEFENSE=164,
    BUFFTYPE_STRENGTHEN_IRONDEFENSE=165,
    BUFFTYPE_BLOOD_HOWLING=166,
    BUFFTYPE_STRENGTHEN_BLOOD_HOWLING=167,
    BUFFTYPE_MASTERY_IGNORE_ENEMY_DEFENSE=168,
    BUFFTYPE_DEBUFF_IGNORE_ENEMY_DEFENSE=169,
    BUFFTYPE_PENTAGRAM_HALF_SD=174,
    BUFFTYPE_PENTAGRAM_HALF_MP=175,
    BUFFTYPE_PENTAGRAM_HALF_ATTACKSPEED=176,
    BUFFTYPE_PENTAGRAM_HALF_HP=177,
    BUFFTYPE_PENTAGRAM_STUN=178,
    BUFFTYPE_PENTAGRAM_REDUCE_MOVE=186,
    BUFFTYPE_SKILL_ATTACK_POWER_INC=179,
    BUFFTYPE_DEFENSE_INC=180,
    BUFFTYPE_CRITICAL_RATE_INC=181,
    BUFFTYPE_POEWR_MAGICPOWER_INC=182,
    BUFFTYPE_DAMAGE_DEC=183,
    BUFFTYPE_ARCA_BATTLE_PENALTY=184,
    BUFFTYPE_ARCA_BATTLE_REWARD=187,
    BUFFTYPE_EXPUP_CHARM1=190,
    BUFFTYPE_EXPUP_CHARM2=191,
    BUFFTYPE_EXPUP_CHARM3=192,
    BUFFTYPE_EXPUP_MARK1=193,
    BUFFTYPE_EXPUP_MARK2=194,
    BUFFTYPE_BLESSINGOFLIGHT=195,
    BUFFTYPE_FENRIR=208,
    BUFFTYPE_DARKHORSE=207,
    BUFFTYPE_DINORANT=206,
    BUFFTYPE_UNIRIA=205,
    BUFFTYPE_END=206
};

enum MAP_INDEX
{
    MAP_INDEX_RORENCIA=0,
    MAP_INDEX_DUNGEON=1,
    MAP_INDEX_DEVIAS=2,
    MAP_INDEX_NORIA=3,
    MAP_INDEX_LOSTTOWER=4,
    MAP_INDEX_RESERVED=5,
    MAP_INDEX_BATTLESOCCER=6,
    MAP_INDEX_ATHLANSE=7,
    MAP_INDEX_TARKAN=8,
    MAP_INDEX_DEVILSQUARE=9,
    MAP_INDEX_ICARUS=10,
    MAP_INDEX_BLOODCASTLE1=11,
    MAP_INDEX_BLOODCASTLE2=12,
    MAP_INDEX_BLOODCASTLE3=13,
    MAP_INDEX_BLOODCASTLE4=14,
    MAP_INDEX_BLOODCASTLE5=15,
    MAP_INDEX_BLOODCASTLE6=16,
    MAP_INDEX_BLOODCASTLE7=17,
    MAP_INDEX_CHAOSCASTLE1=18,
    MAP_INDEX_CHAOSCASTLE2=19,
    MAP_INDEX_CHAOSCASTLE3=20,
    MAP_INDEX_CHAOSCASTLE4=21,
    MAP_INDEX_CHAOSCASTLE5=22,
    MAP_INDEX_CHAOSCASTLE6=23,
    MAP_INDEX_KALIMA1=24,
    MAP_INDEX_KALIMA2=25,
    MAP_INDEX_KALIMA3=26,
    MAP_INDEX_KALIMA4=27,
    MAP_INDEX_KALIMA5=28,
    MAP_INDEX_KALIMA6=29,
    MAP_INDEX_CASTLESIEGE=30,
    MAP_INDEX_CASTLEHUNTZONE=31,
    MAP_INDEX_DEVILSQUARE2=32,
    MAP_INDEX_AIDA=33,
    MAP_INDEX_CRYWOLF_FIRSTZONE=34,
    MAP_INDEX_CRYWOLF_SECONDZONE=35,
    MAP_INDEX_KALIMA7=36,
    MAP_INDEX_KANTURU1=37,
    MAP_INDEX_KANTURU2=38,
    MAP_INDEX_KANTURU_BOSS=39,
    MAP_INDEX_GM_MAP=40,
    MAP_INDEX_3RD_CHANGEUP_QUEST=41,
    MAP_INDEX_3RD_CHANGEUP_BOSS_QUEST=42,
    MAP_INDEX_ILLUSION_TEMPLE1=45,
    MAP_INDEX_ILLUSION_TEMPLE2=46,
    MAP_INDEX_ILLUSION_TEMPLE3=47,
    MAP_INDEX_ILLUSION_TEMPLE4=48,
    MAP_INDEX_ILLUSION_TEMPLE5=49,
    MAP_INDEX_ILLUSION_TEMPLE6=50,
    MAP_INDEX_ELBELAND=51,
    MAP_INDEX_BLOODCASTLE8=52,
    MAP_INDEX_CHAOSCASTLE7=53,
    MAP_INDEX_SWAMP_OF_CALMNESS=56,
    MAP_INDEX_RAKLION_FIELD=57,
    MAP_INDEX_RAKLION_BOSS=58,
    MAP_INDEX_XMASEVENT=62,
    MAP_INDEX_VULCANUS=63,
    MAP_INDEX_PKFIELD=64,
    MAP_INDEX_DOPPELGANGER_1=65,
    MAP_INDEX_DOPPELGANGER_2=66,
    MAP_INDEX_DOPPELGANGER_3=67,
    MAP_INDEX_DOPPELGANGER_4=68,
    MAP_INDEX_PARTYDUNGEON_DAYOFWEEK1=69,
    MAP_INDEX_PARTYDUNGEON_DAYOFWEEK2=70,
    MAP_INDEX_PARTYDUNGEON_DAYOFWEEK3=71,
	MAP_INDEX_PARTYDUNGEON_DAYOFWEEK4=72,
    MAP_INDEX_ROREN_MARKET=79,
    MAP_INDEX_KARUTAN_1=80,
    MAP_INDEX_KARUTAN_2=81,
    MAP_INDEX_ACHERON=91,
    MAP_INDEX_ARCABATTLE=92,
	MAP_INDEX_DEVENTER=95,
    MAP_INDEX_ARCABATTLE_DEVENTER=96,
    MAP_INDEX_CCF=97,
    MAP_INDEX_ITL1=98,
    MAP_INDEX_ITL2=99,
    MAP_INDEX_URUK_MOUNTAIN=100,
    MAP_INDEX_URUK_MOUNTAIN2=101,
    MAP_INDEX_DSF=102
};
typedef struct ComboSkillData
{
    unsigned long dwTime;
    short Skill[3];
    int ProgressIndex;
} *PComboSkillData;

typedef struct tagActionState
{
    unsigned long Rest: 1;
    unsigned long Attack: 1;
    unsigned long Move: 1;
    unsigned long Escape: 1;
    unsigned long Emotion: 4;
    unsigned long EmotionCount: 8;
} *PtagActionState;

typedef struct EFFECTLIST
{
    unsigned char BuffIndex;
    unsigned char EffectCategory;
    unsigned char EffectType1;
    unsigned char EffectType2;
    int EffectValue1;
    int EffectValue2;
    unsigned long EffectSetTime;
    int EffectDuration;
} *PEFFECTLIST;
typedef struct _MASTERLEVEL_PASSIVE_SKILL_OPTION
{
    float iMpsAttackSuccessRate;
    float iMpBlockingSuccessRate;
    float iMpsPVPAttackDmgRate;
    float iMpsPVPBlockingRate;
    float iMpsDownDur1;
    unsigned char btMpsDownDur1Level;
    float iMpsDownDur2;
    float fMpsDownDur3;
    float iMpsResistancePoison;
    float iMpsResistanceThunder;
    float iMpsResistanceIce;
    float iMpsAutoRecoverLife;
    float iMpsAutoRecoverMana;
    float iMpsAutoRecoverAG;
    float iMpsAddPhysicDamage;
    float iMpsAddDamage;
    float iMpsHwoHandSwordAddDamage;
    float iMpsSwordAddDamage;
    float iMpsScultAddDamage;
    float iMpsSpearAddDamage;
    float iMpsTowHandsPvPAttack;
    float iMpsAddAttackSpeed;
    float iMpsIgnoreEnemyDefence;
    float iMpsAddDoubleDamage;
    float iMpsAddSturn;
    float iMpsMaxManaRate;
    float iMpsAddMagicDamage;
    float iMpsTwoHandsMagicPower;
    float iMpsStaffMagicPower;
    float iMpsIncShield;
    float iMpsStaffAttackSpeed;
    float iMpsTwoHandsStaffManAttack;
    float iMpsShieldBlockRate;
    float iMpsBowAddDamage;
    float iMpsBowAddAttackSpeed;
    float iMpsTwoHandsBowAddDamage;
    float iMpsTwoHandsBowManAttack;
    float iMpsElfAddShield;
    float iMpsElfShieldBlockRate;
    float iMpsElfAddPhysicDamage;
    float iMpsCallMonHp;
    float iMpsCallMonDefense;
    float iMpsCallMonAttack;
    float iMpsIncMagicpower;
    float iMpsIncDamageFireProper;
    float iMpsIncDamageWindProper;
    float iMpsIncDamageThunderProper;
    float iMpsIncDotDamage;
    float iMpsAddSturn2;
    float iMpsAddSpring;
    float iMpsAddMagicPowerStick;
    float iMpsAddCurseMagicBook;
    float iMpsAddManAttackStick;
    float iMpsAddAttackSpeedMagicBook;
    float iMpsIncPercentBerserker1;
    float iMpsIncPercentBerserker2;
    float iMpsIncValueBerserker3;
    float iMpsIncMinMagicDamage;
    float iMpsIncDarkHorseDefense;
    float iMpsAddForceWaveDamage;
    float iMpsAddDarkSpiritDamage;
    float iMpsAddCriticalDamageRate;
    float iMpsAddExcellentDamageRate;
    float iMpsAddCeptorDamage;
    float iMpsIncCeptorManAttack;
    float iMpsAddShieldDefense;
    float iMpsAddShieldBlockingRage;
    float iMpsAddPetAttack;
    float iMpsAddControlAttack;
    float iMpsAddMinAttack;
    float iMpsAddMaxAttack;
    float iMpsCriticalRateInc;
    float iMpsAddBlockingRate_Monk;
    float iMpsMonkWeaponDamage;
    float iMpsMonkDoubleDamage;
    float iMpsMonkAddVitalToDefense;
    int iMpsPlusZen;
    float iMpsDefence;
    float iMpsMaxHP;
    float iMpsMaxBP;
    float iMpsMaxMana;
    float iMpsMonsterDieGetMana;
    float iMpsMonsterDieGetLife;
    float iMpsMonsterDieGetSD;
    float iMpsPlusExp;
    float iMpsMaxSD;
    float iMpsSDSpeed;
    float iMpsMaxAttackDamage;
    float iMpsMinAttackDamage;
    float iMpsDecreaseMana;
    float iMpsMaxMagicDamage;
    float iMpsMinMagicDamage;
    float iMpsPetDurDownSpeed;
    float iMpsMaxAttackMagicDamage;
    float iMpsMinAttackMagicDamage;
    float iMpsImmuneRate;
    float iMpsIncSetItemDefense;
    float iMpsReturnEnemyAttack;
    float iMpsIncEnergyStat;
    float iMpsIncVitalStat;
    float iMpsIncDexStat;
    float iMpsIncPowerStat;
    float iMpsAddWingDamageBlock;
    float iMpsAddWingDefense;
    float iMpsAddWingDamage;
    float iMpsIncLeadershipStat;
    float iMpsIncCriticalDamageRate;
    float iMpsRecoverManaRate;
    float iMpsRecoverHPRate;
    float iMpsIncExcellentDamageRate;
    float iMpsIncDoubleDamageRate;
    float iMpsIncIgnoreEnemyBlock;
    float iMpsRecoverSDRate;
    float iMpsIncTripleDamageRate;
    float iMpsComboDamage;
    float iMpsIncMaxBP;
    float iMpsMasManaRate_Wizard;
    float iMpsIncMaxMagicDamage;
    float iMpsIncExcellentDamageRate_Darkload;
    float iMpsIncDamageBloodHowling;
    float iMpsIncDarkSpiritAttackSpeed;
    float iMpsIncDarkSpiritDoubleDamaeRate;
    float iMpsDarkSpiritIgnoreEnemyDefens;
    float iMpsDownDur1_Monk;
    unsigned char btMpsDownDur1Level_Monk;
    float iMpsPVPBlockingRate_Monk;
    float iMpsMaxSD_Monk;
    float iMpsAutoRecoverMana_Monk;
    float iMpsResistancePoison_Monk;
    float iMpsDownDur2_Monk;
    float iMpsSDSpeed_Monk;
    float iMpsAutoRecoverLife_Monk;
    float iMpsResistanceThunder_Monk;
    float iMpsDefence_Monk;
    float iMpsAutoRecoverAG_Monk;
    float iMpsResistanceIce_Monk;
    float fMpsDownDur3_Monk;
    float iMpBlockingSuccessRate_Monk;
    float iMpsImmuneRate_Monk;
    float iMpsIncSetItemDefense_Monk;
    float iMpsReturnEnemyAttack_Monk;
    float iMpsIncEnergyStat_Monk;
    float iMpsIncVitalStat_Monk;
    float iMpsIncDexStat_Monk;
    float iMpsIncPowerStat_Monk;
    float iMpsAttackSuccessRate_Monk;
    float iMpsMaxHP_Monk;
    float iMpsMaxMana_Monk;
    float iMpsMaxBP_Monk;
    float iMpsPVPAttackDmgRate_Monk;
    float iMpsDecreaseMana_Monk;
    float iMpsMonsterDieGetSD_Monk;
    float iMpsMonsterDieGetLife_Monk;
    float iMpsAddMinAttack_Monk;
    float iMpsMonsterDieGetMana_Monk;
    float iMpsAddMaxAttack_Monk;
    float iMpsIncCriticalDamageRate_Monk;
    float iMpsRecoverManaRate_Monk;
    float iMpsRecoverHPRate_Monk;
    float iMpsIncExcellentDamageRate_Monk;
    float iMpsIncDoubleDamageRate_Monk;
    float iMpsIncIgnoreEnemyBlock_Monk;
    float iMpsRecoverSDRate_Monk;
    float iMpsIncTripleDamageRate_Monk;
} MASTERLEVEL_PASSIVE_SKILL_OPTION, *PMASTERLEVEL_PASSIVE_SKILL_OPTION;

typedef struct _GUILD_INFO_STRUCT
{
    int Number;
    char Name[9];
    unsigned char Mark[32];
    unsigned char Count;
    unsigned char TotalCount;
    char Names[11];
    short Index[80];
    unsigned char Use[80];
    char pServer[80];
    char TargetGuildName[9];
    short TargetIndex[80];
    struct _GUILD_INFO_STRUCT * lpTargetGuildNode;
    unsigned char WarDeclareState;
    unsigned char WarState;
    unsigned char WarType;
    unsigned char BattleGroundIndex;
    unsigned char BattleTeamCode;
    unsigned char PlayScore;
    int TotalScore;
    char Notice[60];
    int GuildStatus[80];
    unsigned char btGuildType;
    int iGuildUnion;
    int iGuildRival;
    int iTimeStamp;
    char szGuildRivalName[9];
    struct _GUILD_INFO_STRUCT * back;
    struct _GUILD_INFO_STRUCT * next;
} GUILD_INFO_STRUCT, *PGUILD_INFO_STRUCT;

typedef struct VIEWPORT_STRUCT
{
    char state;
    short number;
    unsigned char type;
    short index;
    int dis;
} *PVIEWPORT_STRUCT;
typedef struct VIEWPORT_PLAYER_STRUCT
{
    char state;
    short number;
    unsigned char type;
    short index;
    int dis;
} *PVIEWPORT_PLAYER_STRUCT;
typedef struct HITDAMAGE_STRUCT
{
    short number;
    int HitDamage;
    unsigned long LastHitTime;
} *PHITDAMAGE_STRUCT;
struct tagInterfaceState
{
	unsigned long Use: 2;
	unsigned long State: 4;
	unsigned long Type: 10;
};

typedef struct _tagMUUN_EFFECT_LIST
{
    int nIndex;
    int nMuunItemNum;
    unsigned char nCategory;
    bool bOptEnable;
    unsigned char nOptType;
    int nOptValue;
    bool bAddOptEnable;
    unsigned char nAddOptType;
    int nAddOptValue;
    unsigned long nSetTime;
    int nDuration;
    class CMuunInfo * pCMuunInfo;
    int nTotalVal;
    int nSkillDelayTime;
    unsigned long nTickTime;
    bool bSkillUsed;
    int nTargetIndex;
} tagMUUN_EFFECT_LIST, *PtagMUUN_EFFECT_LIST;

typedef struct PSHOP_ITEMVALUE_INFO
{
    int nPShopItemInvenNum;
    unsigned long wItemSerial;
    int nMoney;
    short sBlessJewelValue;
    short sSoulJewelValue;
    short sChaosJewelValue;
} *PPSHOP_ITEMVALUE_INFO;
typedef struct QUEST_INFO_MOSNTER_KILLCOUNT
{
    int iQuestMonIndex;
    int iKillCount;
} *PQUEST_INFO_MOSNTER_KILLCOUNT;

typedef struct _GG_VERSION25
{
    unsigned long dwGGVer;
    unsigned short wYear;
    unsigned short wMonth;
    unsigned short wDay;
    unsigned short wNum;
} GG_VERSION25, *PGG_VERSION25;

typedef struct _GG_AUTH_DATA25
{
    unsigned long dwIndex;
    unsigned long dwValue1;
    unsigned long dwValue2;
    unsigned long dwValue3;
} GG_AUTH_DATA25, *PGG_AUTH_DATA25;

typedef class CCSAuth25
{
    struct _GG_AUTH_PROTOCOL25 * m_pProtocol;
    unsigned long m_bPrtcRef;
    unsigned long m_dwUserFlag;
    struct _GG_VERSION25 m_GGVer;
    struct _GG_AUTH_DATA25 m_AuthQueryTmp;
    int m_bNewProtocol;
    int m_bActive;
    struct _GG_AUTH_DATA25 m_AuthQuery;
    struct _GG_AUTH_DATA25 m_AuthAnswer;
} *PCCSAuth25;

typedef class TDurMagicKeyChecker
{
    unsigned long m_dwDurationTime[60];
    unsigned char m_btValidCount[60];
} *PTDurMagicKeyChecker;
typedef class CSkillDelay
{
    unsigned long LastSkillUseTime[700];
} *PCSkillDelay;
typedef class TMonsterSkillElementInfo
{
    int m_iSkillElementDefense;
    int m_iSkillElementDefenseTime;
    int m_iSkillElementAttack;
    int m_iSkillElementAttackTime;
    int m_iSkillElementAutoHP;
    int m_iSkillElementAutoHPCycle;
    int m_iSkillElementAutoHPTime;
    int m_iSkillElementAutoMP;
    int m_iSkillElementAutoMPCycle;
    int m_iSkillElementAutoMPTime;
    int m_iSkillElementAutoAG;
    int m_iSkillElementAutoAGCycle;
    int m_iSkillElementAutoAGTime;
    int m_iSkillElementImmuneNumber;
    int m_iSkillElementImmuneTime;
    int m_iSkillElementResistNumber;
    int m_iSkillElementResistTime;
    int m_iSkillElementModifyStat;
    int m_iSkillElementModifyStatType;
    int m_iSkillElementModifyStatTime;
    int m_iSkillElementImmuneAllTime;
} *PTMonsterSkillElementInfo;

typedef class TMonsterAIAgroInfo
{
    int m_iUserIndex;
    int m_iAgroValue;
} *PTMonsterAIAgroInfo;

typedef class TMonsterAIAgro
{
    class TMonsterAIAgroInfo m_Agro[100];
} *PTMonsterAIAgro;

typedef struct PCBANG_POINT_INFO
{
    int bIsDataLoadSuccess;
    unsigned char btCurrentRule;
    short nCurrentAppRuleTime;
    short nCurrentAppRulePoint;
    int nPCBangPoint;
    int bIsSuccessFirstRuleTime;
    unsigned long dwCheckRuleTime;
    short nResetYear;
    short nResetMonth;
    short nResetDay;
    short nResetHour;
} *PPCBANG_POINT_INFO;

typedef struct JEWELOFHARMONY_ITEM_EFFECT
{
    short HJOpAddMinAttackDamage;
    short HJOpAddMaxAttackDamage;
    short HJOpRequireStr;
    short HJOpRequireDex;
    short HJOpAddAttackDamage;
    short HJOpAddCriticalDamage;
    short HJOpAddSkillAttack;
    short HJOpAddAttackSuccessRatePVP;
    short HJOpDecreaseSDRate;
    short HJOpAddIgnoreSDRate;
    short HJOpAddMagicPower;
    short HJOpAddDefense;
    short HJOpAddMaxAG;
    short HJOpAddMaxHP;
    short HJOpAddRefillHP;
    short HJOpAddRefillMP;
    short HJOpAddDefenseSuccessRatePvP;
    short HJOpAddDamageDecrease;
    short HJOpAddSDRate;
} *PJEWELOFHARMONY_ITEM_EFFECT;

typedef struct ITEMOPTION_FOR380ITEM_EFFECT
{
    short OpAddAttackSuccessRatePVP;
    short OpAddDamage;
    short OpAddDefenseSuccessRatePvP;
    short OpAddDefense;
    short OpAddMaxHP;
    short OpAddMaxSD;
    short OpRefillOn;
    short OpAddRefillSD;
} *PITEMOPTION_FOR380ITEM_EFFECT;

typedef class MWeeklyTimer
{
    int m_iWakeYear;
    int m_iWakeMonth;
    int m_iWakeDay;
    int m_iWakeHour;
    int m_iCheckDayOfWeek;
    int m_iCheckHour;
    void ( * m_pfnWakeCallBack)(class MWeeklyTimer *,void *);
    int m_bActive;
    struct _SYSTEMTIME m_kOldLocalTime;
    void * m_pArg;
} *PMWeeklyTimer;

typedef struct SOCKET_OPTION_LIST
{
    unsigned char m_SocketOptionIndex;
    unsigned char m_SocketOptionValueType;
    unsigned short m_SocketOptionValue;
    unsigned char m_SocketOptionCount;
} *PSOCKET_OPTION_LIST;

typedef class Timer
{
    unsigned long m_iWakeTick;
    bool m_bOnceWake;
    bool m_bActive;
} *PTimer;

typedef class PacketStatistics
{
    class Timer m_kTimer;
    unsigned long m_iCheckDuration;
    int m_iPacketCount;
    int m_iEncryptPacketCount;
    unsigned int m_iPacketTotalSize;
} *PPacketStatistics;

typedef struct HACKTOOL_USE_INFO
{
    unsigned char btUseType;
    unsigned char btCheckType;
    unsigned short wHacktoolIndex;
} *PHACKTOOL_USE_INFO;
typedef struct tagMOVE_MAPSERVER_AUTINFO
{
    char szCharName[12];
    int iJoinAuthCode1;
    int iJoinAuthCode2;
    int iJoinAuthCode3;
    int iJoinAuthCode4;
} *PtagMOVE_MAPSERVER_AUTINFO;

typedef struct _tagGENS_INFO
{
    int iInfluence;
    char szKillUserName[11];
    int iKillUserCnt[10];
    int iKillUserTotCnt;
    int bBattleZoneEnable;
    int iContributePoint;
    unsigned long dwPkTime;
    int iGensRanking;
    int iGensClass;
    unsigned long dwGensPlayTime;
} tagGENS_INFO, *PtagGENS_INFO;

typedef struct CHARACTERNAMEOFUBF
{
    char szCharacterName[11];
    char szCharacterNameOfUBF[11];
    unsigned short nServerCodeOfHomeWorld;
} *PCHARACTERNAMEOFUBF;

typedef class CNAMECOVERT
{
    struct CHARACTERNAMEOFUBF m_perCharacterInfo[5];
} *PCNAMECOVERT;

typedef struct PENTAGRAMJEWEL_INFO
{
    unsigned char btJewelPos;
    unsigned char btJewelIndex;
    unsigned char btMainAttribute;
    unsigned char btItemType;
    unsigned short wItemIndex;
    unsigned char btLevel;
    unsigned char btRank1OptionNum;
    unsigned char btRank1Level;
    unsigned char btRank2OptionNum;
    unsigned char btRank2Level;
    unsigned char btRank3OptionNum;
    unsigned char btRank3Level;
    unsigned char btRank4OptionNum;
    unsigned char btRank4Level;
    unsigned char btRank5OptionNum;
    unsigned char btRank5Level;
} *PPENTAGRAMJEWEL_INFO;

typedef struct tagDAMAGE_STATISTICS
{
    int bDamageStatistics;
    int iDamageStatisticsTime;
    int iDamageStatisticsSecond;
    int iDamagePrintTime;
    unsigned long dwAccumDamage;
} *PtagDAMAGE_STATISTICS;

struct CItem
{
    unsigned long m_Number;
    char m_serial;
    short m_Type;
    short m_Level;
    unsigned char m_Part;
    unsigned char m_Class;
    bool m_TwoHand;
    unsigned char m_AttackSpeed;
    unsigned char m_WalkSpeed;
    unsigned short m_DamageMin;
    unsigned short m_DamageMax;
    unsigned char m_SuccessfulBlocking;
    unsigned short m_Defense;
    unsigned short m_MagicDefense;
    unsigned char m_Speed;
    unsigned short m_DamageMinOrigin;
    unsigned short m_DefenseOrigin;
    unsigned short m_Magic;
    unsigned short m_Curse;
    float m_Durability;
    unsigned short m_DurabilitySmall;
    float m_BaseDurability;
    unsigned char m_SpecialNum;
    unsigned short m_Special[8];
    unsigned char m_SpecialValue[8];
    unsigned short m_RequireStrength;
    unsigned short m_RequireDexterity;
    unsigned short m_RequireEnergy;
    unsigned short m_RequireLevel;
    unsigned short m_RequireVitality;
    unsigned short m_RequireLeaderShip;
    unsigned short m_Leadership;
    unsigned char m_RequireClass[7];
    unsigned char m_Resistance[7];
    int m_Value;
    unsigned long m_SellMoney;
    unsigned long m_BuyMoney;
    int m_iPShopValue;
    short m_sPShopBlessJewelValue;
    short m_sPShopSoulJewelValue;
    short m_sPShopChaosJewelValue;
    bool m_bItemExist;
    int m_OldSellMoney;
    int m_OldBuyMoney;
    unsigned char m_Option1;
    unsigned char m_Option2;
    unsigned char m_Option3;
    unsigned char m_NewOption;
    float m_DurabilityState[4];
    float m_CurrentDurabilityState;
    unsigned char m_SkillChange;
    unsigned char m_QuestItem;
    unsigned char m_SetOption;
    unsigned char m_SetAddStat;
    unsigned char m_IsValidItem;
    unsigned char m_SkillResistance[7];
    int m_IsLoadPetItemInfo;
    int m_PetItem_Level;
    __int64 m_PetItem_Exp;
    unsigned char m_JewelOfHarmonyOption;
    unsigned short m_HJOpStrength;
    unsigned short m_HJOpDexterity;
    unsigned char m_ItemOptionEx;
    unsigned char m_BonusSocketOption;
    unsigned char m_SocketOption[5];
    unsigned char m_ImproveDurabilityRate;
    unsigned char m_PeriodItemOption;
};

struct OBJECTSTRUCT
{
    int m_Index;
    int Connected;
    char LoginMsgSnd;
    char LoginMsgCount;
    char CloseCount;
    char CloseType;
    int bEnableDelCharacter;
    struct _PER_SOCKET_CONTEXT * PerSocketContext;
    unsigned int m_socket;
    char Ip_addr[16];
    int UserNumber;
    int DBNumber;
    int PcBangGuid;
    unsigned char GenerableClass;
    unsigned long AutoSaveTime;
    unsigned long ConnectCheckTime;
    unsigned long CheckTick;
    unsigned char CheckSpeedHack;
    unsigned long CheckTick2;
    unsigned char CheckTickCount;
    unsigned long SaveTimeForStatics;
    int iPingTime;
    unsigned char m_TimeCount;
    unsigned long m_dwPKTimer;
    short CheckSumTableNum;
    unsigned long CheckSumTime;
    unsigned short Type;
    unsigned char Live;
    char CharacterPos;
    char AccountID[11];
    char Name[11];
    char LastJoominNumber[13];
    unsigned char PlusStatQuestClear;
    unsigned char ComboSkillquestClear;
    struct ComboSkillData comboSkill;
    unsigned short Class;
    unsigned char DbClass;
    unsigned char ChangeUP;
    unsigned char ThirdChangeUp;
    short Level;
    int LevelUpPoint;
    int iFruitPoint;
    unsigned long Experience;
    unsigned long NextExp;
    short m_nMasterLevel;
    __int64 m_i64MasterLevelExp;
    __int64 m_i64NextMasterLevelExp;
    int m_iMasterLevelPoint;
    int m_iUseMasterLevelPoint;
    int m_bMasterLevelDBLoad;
    int Money;
    short Strength;
    short Dexterity;
    short Vitality;
    short Energy;
    float Life;
    float MaxLife;
    int m_iScriptMaxLife;
    float FillLife;
    float FillLifeMax;
    float Mana;
    float MaxMana;
    unsigned short Leadership;
    unsigned short AddLeadership;
    unsigned short ChatLitmitTime;
    unsigned char ChatLimitTimeSec;
    unsigned char FillLifeCount;
    short AddStrength;
    short AddDexterity;
    short AddVitality;
    short AddEnergy;
    int BP;
    int MaxBP;
    int AddBP;
    float VitalityToLife;
    float EnergyToMana;
    char m_PK_Count;
    char m_PK_Level;
    int m_PK_Time;
    short X;
    short Y;
    unsigned char Dir;
    unsigned char MapNumber;
    int AddLife;
    int AddMana;
    int iShield;
    int iMaxShield;
    int iAddShield;
    int iFillShieldMax;
    int iFillShield;
    int iFillShieldCount;
    unsigned long dwShieldAutoRefillTimer;
    unsigned char DamageMinus;
    unsigned char DamageReflect;
    short MonsterDieGetMoney;
    unsigned char MonsterDieGetLife;
    unsigned char MonsterDieGetMana;
    unsigned char StartX;
    unsigned char StartY;
    short m_OldX;
    short m_OldY;
    short TX;
    short TY;
    short MTX;
    short MTY;
    int PathCount;
    int PathCur;
    char PathStartEnd;
    short PathOri[15];
    short PathX[15];
    short PathY[15];
    char PathDir[15];
    unsigned long PathTime;
    char m_MoveGateNumber;
    short m_siDieRegenX;
    short m_siDieRegenY;
    short m_siDieRegenMapIndex;
    short m_siMoveX;
    short m_siMoveY;
    short m_siMoveMapIndex;
    unsigned long Authority;
    unsigned long Penalty;
    unsigned char m_cAccountItemBlock;
    struct tagActionState m_ActState;
    unsigned char m_ActionNumber;
    unsigned long m_State;
    char m_StateSub;
    unsigned char m_Rest;
    char m_ViewState;
    unsigned char m_BuffEffectCount;
    struct EFFECTLIST m_BuffEffectList[32];
    unsigned long m_LastMoveTime;
    unsigned long m_LastAttackTime;
    unsigned char m_FriendServerOnline;
    int m_DetectSpeedHackTime;
    unsigned long m_SumLastAttackTime;
    unsigned long m_DetectCount;
    int m_DetectedHackKickCount;
    int m_SpeedHackPenalty;
    unsigned char m_AttackSpeedHackDetectedCount;
    unsigned long m_PacketCheckTime;
    unsigned char m_ShopTime;
    unsigned long m_TotalAttackTime;
    int m_TotalAttackCount;
    unsigned long TeleportTime;
    char Teleport;
    char KillerType;
    char DieRegen;
    char RegenOk;
    unsigned char RegenMapNumber;
    unsigned char RegenMapX;
    unsigned char RegenMapY;
    unsigned long RegenTime;
    unsigned long MaxRegenTime;
    short m_PosNum;
    unsigned long LifeRefillTimer;
    unsigned long CurActionTime;
    unsigned long NextActionTime;
    unsigned long DelayActionTime;
    char DelayLevel;
    char m_PoisonType;
    char m_IceType;
    char m_ImmuneToMagicCount;
    char m_ImmuneToHarmCount;
    char m_iMonsterBattleDelay;
    char m_cKalimaGateExist;
    int m_iKalimaGateIndex;
    char m_cKalimaGateEnterCount;
    class OBJECTSTRUCT * lpAttackObj;
    short m_SkillNumber;
    unsigned long m_SkillTime;
    bool m_bAttackerKilled;
    char m_ManaFillCount;
    char m_LifeFillCount;
    int SelfDefense[7];
    unsigned long SelfDefenseTime[7];
    unsigned long MySelfDefenseTime;
    char m_Drink;
    int m_SkillAttack2;
    char m_SkillAttackTime2;
    int PartyNumber;
    int PartyTargetUser;
    int GuildNumber;
    struct _GUILD_INFO_STRUCT * lpGuild;
    char GuildName[11];
    int GuildStatus;
    int iGuildUnionTimeStamp;
    int m_RecallMon;
    int m_Change;
    short TargetNumber;
    short TargetShopNumber;
    short ShopNumber;
    short LastAttackerID;
    int m_AttackDamageMin;
    int m_AttackDamageMax;
    int m_MagicDamageMin;
    int m_MagicDamageMax;
    int m_AttackDamageLeft;
    int m_AttackDamageRight;
    int m_AttackDamageMaxLeft;
    int m_AttackDamageMinLeft;
    int m_AttackDamageMaxRight;
    int m_AttackDamageMinRight;
    int m_AttackRating;
    int m_AttackSpeed;
    int m_MagicSpeed;
    int m_Defense;
    int m_MagicDefense;
    int m_SuccessfulBlocking;
    int m_Curse;
    int m_CurseDamgeMin;
    int m_CurseDamgeMax;
    short m_MoveSpeed;
    short m_MoveRange;
    short m_AttackRange;
    short m_AttackType;
    short m_ViewRange;
    short m_Attribute;
    short m_ItemRate;
    short m_MoneyRate;
    int m_CriticalDamage;
    int m_ExcelentDamage;
    class CMagicInf * m_lpMagicBack;
    class CMagicInf * Magic;
    char MagicCount;
    int UseMagicNumber;
    unsigned long UseMagicTime;
    char UseMagicCount;
    short OSAttackSerial;
    unsigned char SASCount;
    unsigned long SkillAttackTime;
    struct _MASTERLEVEL_PASSIVE_SKILL_OPTION m_MPSkillOpt;
    int m_nSoulBarrierDefence;
    short m_nSoulBarrierManaRate;
    unsigned char CharSet[18];
    unsigned char m_Resistance[7];
    unsigned char m_AddResistance[7];
    int FrustrumX[4];
    int FrustrumY[4];
    struct VIEWPORT_STRUCT VpPlayer[75];
    struct VIEWPORT_PLAYER_STRUCT VpPlayer2[75];
    int VPCount;
    int VPCount2;
    int m_bBlind;
    struct HITDAMAGE_STRUCT sHD[40];
    short sHDCount;
    struct tagInterfaceState m_IfState;
    unsigned long m_InterfaceTime;
    class CItem * pInventory;
    unsigned char * pInventoryMap;
    char * pInventoryCount;
    char pTransaction;
    class CItem * Inventory1;
    unsigned char * InventoryMap1;
    char InventoryCount1;
    class CItem * Inventory2;
    unsigned char * InventoryMap2;
    char InventoryCount2;
    class CItem * Trade;
    unsigned char * TradeMap;
    int TradeMoney;
    unsigned char TradeOk;
    class CItem * pWarehouse;
    unsigned char * pWarehouseMap;
    char WarehouseCount;
    short WarehousePW;
    unsigned char WarehouseLock;
    unsigned char WarehouseUnfailLock;
    int WarehouseMoney;
    int WarehouseSave;
    class CItem * pChaosBox;
    unsigned char * pChaosBoxMap;
    int ChaosMoney;
    int ChaosSuccessRate;
    int ChaosLock;
    class CItem * pEventInventory;
    unsigned char * pEventInventoryMap;
    class CItem * pEventInventory1;
    unsigned char * pEventInventoryMap1;
    class CItem * pEventInventory2;
    unsigned char * pEventInventoryMap2;
    bool EventInventoryLoad;
    unsigned short m_wMuunItem;
    class CItem * pMuunInventory;
    class CItem * pMuunInventory1;
    class CItem * pMuunInventory2;
    bool bMuunInventoryLoad;
    int m_iMuunItmePeriodDataIndex;
    struct _tagMUUN_EFFECT_LIST m_MuunEffectList[2];
    unsigned long dwCheckMuunItemTime;
    unsigned short m_wMuunSubItem;
    unsigned short m_wMuunRideItem;
    unsigned long m_Option;
    int m_nEventScore;
    int m_nEventExp;
    int m_nEventMoney;
    unsigned char m_bDevilSquareIndex;
    unsigned char m_bDevilSquareAuth;
    char m_cBloodCastleIndex;
    char m_cBloodCastleSubIndex;
    int m_iBloodCastleEXP;
    bool m_bBloodCastleComplete;
    char m_cChaosCastleIndex;
    char m_cChaosCastleSubIndex;
    int m_iChaosCastleBlowTime;
    char m_cKillUserCount;
    char m_cKillMonsterCount;
    bool m_bCCF_UI_Using;
    unsigned char m_byCCF_CanEnter;
    int m_nCCF_CertiTick;
    int m_nCCF_UserIndex;
    int m_nCCF_BlowTime;
    unsigned char m_byKillUserCount;
    unsigned char m_byKillMobCount;
    bool m_bCCF_Quit_Msg;
    int m_iDuelUserReserved;
    int m_iDuelUserRequested;
    int m_iDuelUser;
    unsigned char m_btDuelScore;
    int m_iDuelTickCount;
    bool m_bPShopOpen;
    bool m_bPShopTransaction;
    bool m_bPShopItemChange;
    bool m_bPShopRedrawAbs;
    char m_szPShopText[36];
    bool m_bPShopWantDeal;
    int m_iPShopDealerIndex;
    char m_szPShopDealerName[10];
    struct _RTL_CRITICAL_SECTION m_critPShopTrade;
    int m_iVpPShopPlayer[75];
    unsigned short m_wVpPShopPlayerCount;
    struct PSHOP_ITEMVALUE_INFO m_PShopItemValueInfo;
    unsigned char IsInBattleGround;
    unsigned char HaveWeaponInHand;
    short EventChipCount;
    int MutoNumber;
    int UseEventServer;
    unsigned char LoadWareHouseInfo;
    int iStoneCount;
    int m_bQuestMonKillDBLoad;
    int m_iQuestMonKillDBIndex;
    struct QUEST_INFO_MOSNTER_KILLCOUNT m_QuestMonKillInfo[5];
    unsigned char m_Quest[50];
    unsigned char m_SendQuestInfo;
    int m_SkyBossMonSheildLinkIndex;
    int m_SkyBossMonSheild;
    int m_SkyBossMonSheildTime;
    int m_MaxLifePower;
    int m_PacketChecksumTime;
    int m_CheckLifeTime;
    unsigned char m_MoveOtherServer;
    char BackName[11];
    char m_BossGoldDerconMapNumber;
    unsigned char m_InWebzen;
    char m_LastTeleportTime;
    unsigned char m_ClientHackLogCount;
    int m_iPlayTimeLimit;
    unsigned long m_dwPlayTick;
    int m_nShotDownNotice;
    unsigned char m_btFatiguePercent;
    unsigned char m_iMinusPlayTime;
    int m_iNoticePlayTimeH;
    unsigned long m_dwNoticePlayTick;
    int m_bIsInMonsterHerd;
    int m_bIsMonsterAttackFirst;
    class MonsterHerd * m_lpMonsterHerd;
    class CCSAuth25 NPggCSAuth;
    bool m_bSentGGAuth;
    bool m_bSentGGAuthAgain;
    bool m_bCheckGGAuth;
    unsigned long m_dwNPGGMapSvrMoveTime;
    unsigned long m_NPggCheckSumSendTime;
    int fSkillFrustrumX[4];
    int fSkillFrustrumY[4];
    unsigned char SkillHellFire2State;
    unsigned char SkillHellFire2Count;
    unsigned long SkillHellFire2Time;
    unsigned char SkillStrengthenHellFire2State;
    unsigned char SkillStrengthenHellFire2Count;
    unsigned long SkillStrengthenHellFire2Time;
    unsigned char m_ReqWarehouseOpen;
    int m_NotAttackAreaCount;
    short SetOpAddSkillAttack;
    short SetOpAddExDamage;
    short SetOpAddExDamageSuccessRate;
    short SetOpAddCriticalDamage;
    short SetOpAddCriticalDamageSuccessRate;
    short SetOpIncAGValue;
    short SetOpAddDamage;
    short SetOpAddMinAttackDamage;
    short SetOpAddMaxAttackDamage;
    short SetOpAddAttackDamage;
    short SetOpAddDefence;
    short SetOpAddDefenceRate;
    short SetOpAddMagicPower;
    unsigned char SetOpIgnoreDefense;
    unsigned char SetOpDoubleDamage;
    unsigned char SetOpTwoHandSwordImproveDamage;
    unsigned char SetOpImproveSuccessAttackRate;
    unsigned char SetOpReflectionDamage;
    unsigned char SetOpImproveSheldDefence;
    unsigned char SetOpDecreaseAG;
    unsigned char SetOpImproveItemDropRate;
    unsigned char IsFullSetItem;
    int m_bMacroStart;
    unsigned short m_wGage;
    int m_nUseMacroMinute;
    unsigned long m_dwMacroTick;
    class TDurMagicKeyChecker DurMagicKeyChecker;
    unsigned short SkillRecallParty_Time;
    unsigned char SkillRecallParty_MapNumber;
    unsigned char SkillRecallParty_X;
    unsigned char SkillRecallParty_Y;
    bool bIsChaosMixCompleted;
    unsigned char SkillLongSpearChange;
    class CSkillDelay SkillDelay;
    int iObjectSecTimer;
    bool m_bMapSvrMoveQuit;
    bool m_bMapSvrMoveReq;
    unsigned long m_dwMapSvrQuitTick;
    short m_sPrevMapSvrCode;
    short m_sDestMapNumber;
    unsigned char m_btDestX;
    unsigned char m_btDestY;
#ifdef _GS_CS
    union
    {
        struct
        {
            unsigned char m_btCsNpcExistVal1;
            unsigned char m_btCsNpcExistVal2;
            unsigned char m_btCsNpcExistVal3;
            unsigned char m_btCsNpcExistVal4;
        };
        int m_iCsNpcExistVal;
    };
    unsigned char m_btCsNpcType;
    unsigned char m_btCsGateOpen;
    int m_iCsGateLeverLinkIndex;
    unsigned char m_btCsNpcDfLevel;
    unsigned char m_btCsNpcRgLevel;
    unsigned char m_btCsJoinSide;
    bool m_bCsGuildInvolved;
#endif
    bool m_bIsCastleNPCUpgradeCompleted;
    unsigned char m_btWeaponState;
    int m_iWeaponUser;
    unsigned char m_btKillCount;
    int m_iAccumulatedDamage;
    #ifdef _GS_CS
    unsigned char m_btLifeStoneCount;
    unsigned char m_btCreationState;
    int m_iCreatedActivationTime;
#endif
    int m_iAccumulatedCrownAccessTime;
    class TMonsterSkillElementInfo m_MonsterSkillElementInfo;
    int m_iBasicAI;
    int m_iCurrentAI;
    int m_iCurrentAIState;
    int m_iLastAIRunTime;
    int m_iGroupNumber;
    int m_iSubGroupNumber;
    int m_iGroupMemberGuid;
    int m_iRegenType;
    class TMonsterAIAgro m_Agro;
    int m_iLastAutomataRuntime;
    int m_iLastAutomataDelay;
    int m_iCrywolfMVPScore;
    int m_bPCBangUser;
    int m_bPCBangCouponUser;
    int m_bPCBangFreeChaosCastleUser;
    long m_lFreeKalimaTime;
    long m_lLifeIncTime;
    unsigned char m_btLifeInc;
    unsigned long m_dwLastCheckTick;
    int m_iAutoRecuperationTime;
    float m_fInfinityArrowIncRate;
    int m_iSkillDistanceErrorCount;
    unsigned long m_dwSkillDistanceErrorTick;
    struct JEWELOFHARMONY_ITEM_EFFECT m_JewelOfHarmonyEffect;
    struct ITEMOPTION_FOR380ITEM_EFFECT m_ItemOptionExFor380;
#ifndef _GS_CS
    int m_bKanturuEntranceByNPC;
#endif
    unsigned short m_wItemEffectType;
    int m_iItemEffectValidTime;
    unsigned short m_wCashPoint;
    int m_bPCBangPointUser;
    struct PCBANG_POINT_INFO m_PCBangPointInfo;
    class MWeeklyTimer m_kWeeklyTimer;
    int m_iIllusionTempleIndex;
    int m_nITLIndex;
    bool m_bITL_SchedeulInfoSend;
    bool m_bITL_GuildRankInfoSend;
    bool m_bITL_TournamentInfoSend;
    int m_nITLRelicsTick;
    bool m_bGettingRelics;
    bool m_bRegisteringRelics;
    unsigned short m_wITLNpcType;
    unsigned char m_byStoneState;
    unsigned char m_byEnterITLCount;
    bool m_bEnterCountLoad;
    unsigned char m_byEnterITLUserCount;
    int m_nITR_Index;
    int m_nITR_RelicsTick;
    bool m_bITR_GettingRelics;
    bool m_bITR_RegisteringRelics;
    unsigned short m_wITR_NpcType;
    unsigned char m_byITR_StoneState;
    int m_bSkillKeyRecv;
    int m_iPeriodItemEffectIndex;
    unsigned char m_bCharCardSummoner;
    struct SOCKET_OPTION_LIST m_SeedOptionList[35];
    struct SOCKET_OPTION_LIST m_BonusOptionList[7];
    struct SOCKET_OPTION_LIST m_SetOptionList[2];
    unsigned short m_btRefillHPSocketOption;
    unsigned short m_btRefillMPSocketOption;
    unsigned short m_wSocketOptionMonsterDieGetHp;
    unsigned short m_wSocketOptionMonsterDieGetMana;
    unsigned char m_btAGReduceRate;
    int m_iPeriodDataIndex;
    class PacketStatistics m_kRecvPacketStatistics;
    unsigned char m_bGMSummon;
    unsigned long m_dwHacktoolCheckTerm;
    struct HACKTOOL_USE_INFO m_HacktoolUseInfo[20];
    unsigned long m_dwUseHacktoolList[10];
    unsigned long m_dwMapMoveKeyValue;
    short m_nZoneIndex;
    int m_nLuckyCoinCount;
    unsigned char m_btCharacterSlotCount;
    struct tagMOVE_MAPSERVER_AUTINFO m_MoveMapSvrAuthInfo;
    class UserQuestInfo * m_UserQuestInfo;
    int m_bDBQuestLoad;
    struct _tagGENS_INFO m_strGens_Info;
    unsigned long m_dwMileageUpdateTimer;
    unsigned char m_btSculptPos;
    unsigned char m_btCharmPos;
    unsigned char m_btArtifactPos;
    unsigned char m_btExpUpCharmPos;
    unsigned char m_btSkillComplete;
    unsigned char m_btDarkSideTargetNum;
    unsigned short m_wDarkSideTargetList[5];
    unsigned int MathAuthenElapsed;
    unsigned char m_btExtendedInvenCount;
    unsigned char m_btExtendedInvenCountAtDB;
    unsigned char m_btExtendedWarehouseCount;
    unsigned char m_btExtendedWarehouseCountAtDB;
    int m_nRoomIndex;
    int m_nTargetPartyArrIndex;
    bool m_bIsOpenWarehouse;
    int m_iPentagramMainAttribute;
    int m_iRuby_1RankAddDamage;
    int m_iRuby_2RankOptionNum;
    int m_iRuby_2RankAddAttackRelationshipRate;
    int m_iRuby_3RankOptionNum;
    int m_iRuby_3RankAddDamage;
    int m_iRuby_4RankOptionNum;
    int m_iRuby_4RankAddDamage;
    int m_iRuby_5RankOptionNum;
    int m_iRuby_5RankCriticalDamageRate;
    int m_iSapph_1RankAddDefense;
    int m_iSapph_2RankOptionNum;
    int m_iSapph_2RankAddDefenseRelationshipRate;
    int m_iSapph_3RankOptionNum;
    int m_iSapph_3RankAddDefense;
    int m_iSapph_4RankOptionNum;
    int m_iSapph_4RankAddDefense;
    int m_iSapph_5RankOptionNum;
    int m_iSapph_5RankMinusTargetDamageRate;
    int m_iEme_1RankAddAttackRate;
    int m_iEme_2RankOptionNum;
    int m_iEme_2RankAddAttackRelationshipRate;
    int m_iEme_3RankOptionNum;
    int m_iEme_3RankAddDamage;
    int m_iEme_4RankOptionNum;
    int m_iEme_4RankAddDamage;
    int m_iEme_5RankOptionNum;
    int m_iEme_5RankAddDamageRate;
    int m_iTopa_1RankOptionNum;
    int m_iTopa_1RankAddDefenseSuccessRate;
    int m_iTopa_2RankOptionNum;
    int m_iTopa_2RankAddAttackRelationshipRate;
    int m_iTopa_3RankOptionNum;
    int m_iTopa_3RankAddDefense;
    int m_iTopa_4RankOptionNum;
    int m_iTopa_4RankAddDefense;
    int m_iTopa_5RankOptionNum;
    int m_iTopa_5RankDamageAbsorbRate;
    int m_iOnyx_1RankSlowMoveSkillRate;
    int m_iOnyx_2RankAddStrength;
    int m_iOnyx_2RankAddDexterity;
    int m_iOnyx_2RankAddEnergy;
    int m_iOnyx_2RankAddVitality;
    int m_iOnyx_3RankAddMaxLife;
    int m_iOnyx_3RankAddMaxMana;
    int m_iOnyx_3RankAddMaxAG;
    int m_iOnyx_3RankAddMaxSD;
    int m_iOnyx_4RankOptionNum;
    int m_iOnyx_4RankAddExllentDamageRate;
    int m_iOnyx_5RankHalfValueSkillRate;
    int m_iPentagram_AddAttack;
    int m_iPentagramSet_AddDefense;
    int m_iPentagramSet_AddZenRate;
    int m_iPentagramSet_AddShieldDefense;
    int m_iPentagramSet_AddSkillAttack;
    int m_iPentagramSet_AddDoubleDamageRate;
    int m_iPentagramSet_IgnoreDefenseRate;
    int m_iPentagramSet_AddExellentDamage;
    int m_iPentagramSet_AddExllentDamageRate;
    int m_iPentagramSet_AddCriticalDamageRate;
    int m_iPentagramSet_AddMaxSDRate;
    int m_iPentagramSet_AddMaxAG;
    int m_iPentagramSet_AddDamageTwoHandArm;
    int m_iPentagramSet_AttackRelationship_Fire;
    int m_iPentagramSet_DefenseRelationship_Fire;
    int m_iPentagramSet_AttackRelationship_Water;
    int m_iPentagramSet_DefenseRelationship_Water;
    int m_iPentagramSet_AttackRelationship_Earth;
    int m_iPentagramSet_DefenseRelationship_Earth;
    int m_iPentagramSet_AttackRelationship_Wind;
    int m_iPentagramSet_DefenseRelationship_Wind;
    int m_iPentagramSet_AttackRelationship_Dark;
    int m_iPentagramSet_DefenseRelationship_Dark;
    int m_iPentagramSet_AddStrength;
    int m_iPentagramSet_AddDexterity;
    int m_iPentagramSet_AddVitality;
    int m_iPentagramSet_AddEnergy;
    int m_iPentagramSet_AddLife;
    int m_iPentagramSet_AddMana;
    int m_iPentagramAttributePattern;
    int m_iPentagramDefense;
    int m_iPentagramAttackMin;
    int m_iPentagramAttackMax;
    int m_iPentagramAttackRating;
    int m_iPentagramDefenseRating;
    class CItem * pPentagramMixBox;
    unsigned char * pPentagramMixBoxMap;
    int PentagramMixMoney;
    int PentagramMixSuccessRate;
    int m_PentagramMixLock;
    bool m_bIsPentagramMixCompleted;
    int m_iPentagramDamageMax;
    int m_iPentagramDamageMin;
    int m_iPentagramDamageOrigin;
    struct PENTAGRAMJEWEL_INFO m_PentagramJewelInfo_Inven[250];
    struct PENTAGRAMJEWEL_INFO m_PentagramJewelInfo_Warehouse[250];
    bool m_isAddPentaAttack;
    bool m_isAddPentaDefense;
    bool m_isAddCriPentaDamage;
    bool m_isChangePentaDefense;
    bool m_isChangePentaAttack;
    bool m_isAddResistByStrongRelationship;
    bool m_isAddResistByPentaAttack;
    int m_bUsePartyMatching;
    int m_bPartyMatchingLeader;
    int m_nServerChannel;
    int m_nPartyMatchingIndex;
    int m_nPartyMatchingMemberCount;
    int m_bUseGuildMatching;
    int m_bIsMining;
    int m_bSendMemberPos;
    int m_bSendNpcPos;
    int m_Resistance_Stun;
    int m_Resistance_Double;
    int m_Resistance_Perfect;
    int m_Resistance_SD;
    int m_Resistance_Excellent;
    int m_Resistance_Critical;
    int m_dwTestTick;
    unsigned char m_EnableUseChangeSkin;
    class CMuRummyInfo * m_pCMuRummyInfo;
    unsigned long m_Disappear_NewYearMonster;
    unsigned char m_btExpType;
    int m_nDSFIndex;
    unsigned long m_Disappear_Monster;
    int m_bIsHelpMon;
    int m_SummonCharDBNum;
    int m_nRecallMonIndex[3];
    int m_nBossIndexLordSilvester;
    int m_nPhaseLoadSilvester;
    int m_JoinUnityBattile;
    int m_nServerCodeOfHomeWorld;
    char m_RealNameOfUBF[11];
    class CNAMECOVERT m_NameConvertOfUBF;
    unsigned char m_btInvenPetPos;
    unsigned short m_wInvenPet;
    struct tagDAMAGE_STATISTICS m_DamageStatistics;
};  
typedef OBJECTSTRUCT * LPOBJ;//extern OBJECTSTRUCT* lpObj;

typedef CItem* LPOBJITEM;
//extern OBJECTSTRUCT			* gObj;

//custom struct
typedef	struct sAddTab
{
	int		POST_Delay;
}sAddTab;
extern sAddTab AddTab[OBJ_MAX];
//end of custom struct
class cUser
{
public:
	//private:
	int	 GetPlayerIndex(char *Name);
	char* GetMapName(int MapId);
};
extern cUser User;

#endif