#pragma once

#include "NiTypes.h"
#include "GameForms.h"
#include "GameBSExtraData.h"
#include "AltarSync.h"
#include "obse64_common/Utilities.h"

class NiNode;
class BaseProcess;
class MagicItem;

// 8
class TESChildCell
{
public:
	virtual TESObjectCELL * GetChildCell();

//	void	** _vtbl;	// 0
};

static_assert(sizeof(TESChildCell) == 0x8);

// 138
class TESObjectREFR : public TESForm
{
public:
	TESObjectREFR();
	virtual ~TESObjectREFR();

	virtual void Unk_3C();
	virtual void Unk_3D();
	virtual void Unk_3E();
	virtual void Unk_3F();
	virtual void Unk_40();
	virtual void Unk_41();
	virtual void Unk_42();
	virtual void Unk_43();
	virtual void Unk_44();
	virtual void Unk_45();
	virtual void Unk_46();
	virtual void Unk_47();
	virtual bool EquipObject(TESBoundObject* object, int count = 1, BaseExtraList* extraList = nullptr, bool preventUnequip = false); // 48
	virtual void Unk_49();
	virtual void Unk_4A();
	virtual void Unk_4B();
	virtual void Unk_4C();
	virtual void Unk_4D();
	virtual void Unk_4E();
	virtual void Unk_4F();
	virtual void Unk_50();
	virtual void Unk_51();
	virtual void Unk_52();
	virtual void Unk_53();
	virtual bool Unk_54();
	virtual void Unk_55();
	virtual void Unk_56();
	virtual void Unk_57();
	virtual void Unk_58();
	virtual void Unk_59();
	virtual void Unk_5A();
	virtual int Unk_5B(/* No args */);
	virtual void Unk_5C();
	virtual void Unk_5D();
	virtual void Unk_5E();
	virtual void Unk_5F();
	virtual void Unk_60();
	virtual void Unk_61();
	virtual TESForm * GetBaseForm();
	virtual void Unk_63();
	virtual void Unk_64();
	virtual void Unk_65();
	virtual void Unk_66();
	virtual void Unk_67();
	virtual void Unk_68();
	virtual void Unk_69();
	virtual void Unk_6A();
	virtual void Unk_6B();
	virtual bool Unk_6C();
	virtual void Unk_6D();
	virtual void Unk_6E();
	virtual void Unk_6F();
	virtual void Unk_70();
	virtual void Unk_71();
	virtual void Unk_72();
	virtual void Unk_73();
	virtual void Unk_74();
	virtual void Unk_75();
	virtual void Unk_76();

	TESChildCell	childCell;		// 30
	IVPairableItem	pairableItem;	// 38 new in altar

	TESForm			* baseForm;		// 50
	NiPoint3		rotation;		// 58
	NiPoint3		position;		// 64
	float			scale;			// 70
	u32				pad74;			// 74
	NiNode			* niNode;		// 78
	TESObjectCELL	* parentCell;	// 80
	BaseExtraList	extraList;		// 88

	// new in altar
	u8	unkA8[0x138 - 0x0A8];
};

static_assert(sizeof(TESObjectREFR) == 0x138);

// 148
class MobileObject : public TESObjectREFR
{
public:
	virtual ~MobileObject();

	virtual void Unk_77();
	virtual void Unk_78();
	virtual void Unk_79();
	virtual void Unk_7A();
	virtual void Unk_7B();
	virtual void Unk_7C();
	virtual void Unk_7D();
	virtual void Unk_7E();
	virtual void Unk_7F();
	virtual void Unk_80();
	virtual void Unk_81();
	virtual void Unk_82();
	virtual void Unk_83();
	virtual void Unk_84();
	virtual void Unk_85();
	virtual void Unk_86();
	virtual void Unk_87();
	virtual void Unk_88();
	virtual void Unk_89();
	virtual void Unk_8A();
	virtual void Unk_8B();
	virtual void Unk_8C();
	virtual void Unk_8D();
	virtual void Unk_8E();
	virtual void Unk_8F();

	BaseProcess	* process;	// 138
	float		unk140;		// 140
	u32			pad144;		// 144
};

static_assert(sizeof(MobileObject) == 0x148);

enum
{
    kActorValue_Strength,
    kActorValue_Intelligence,
    kActorValue_Willpower,
    kActorValue_Agility,
    kActorValue_Speed,
    kActorValue_Endurance,
    kActorValue_Personality,
    kActorValue_Luck,
    kActorValue_Health,
    kActorValue_Magicka,
    kActorValue_Fatigue,
    kActorValue_Encumbrance,
    kActorValue_Armorer,
    kActorValue_Athletics,
    kActorValue_Blade,
    kActorValue_Block,
    kActorValue_Blunt,
    kActorValue_HandToHand,
    kActorValue_HeavyArmor,
    kActorValue_Alchemy,
    kActorValue_Alteration,
    kActorValue_Conjuration,
    kActorValue_Destruction,
    kActorValue_Illusion,
    kActorValue_Mysticism,
    kActorValue_Restoration,
    kActorValue_Acrobatics,
    kActorValue_LightArmor,
    kActorValue_Marksman,
    kActorValue_Mercantile,
    kActorValue_Security,
    kActorValue_Sneak,
    kActorValue_Speechcraft,
    kActorValue_Aggression,
    kActorValue_Confidence,
    kActorValue_Energy,
    kActorValue_Responsibility,
    kActorValue_Bounty,
    kActorValue_Fame,
    kActorValue_Infamy,
    kActorValue_MagickaMultiplier,
    kActorValue_NightEyeBonus,
    kActorValue_AttachBonus,
    kActorValue_DefendBonus,
    kActorValue_CastingPenalty,
    kActorValue_Blindness,
    kActorValue_Chameleon,
    kActorValue_Invisibility,
    kActorValue_Paralysis,
    kActorValue_Silence,
    kActorValue_Confusion,
    kActorValue_DetectItemRange,
    kActorValue_SpellAbsorbChance,
    kActorValue_SpellReflectChance,
    kActorValue_SwimSpeedMultiplier,
    kActorValue_WaterBreathing,
    kActorValue_WaterWalking,
    kActorValue_StuntedMagicka,
    kActorValue_DetectLifeRange,
    kActorValue_ReflectDamage,
    kActorValue_Telekinesis,
    kActorValue_ResistFire,
    kActorValue_ResistFrost,
    kActorValue_ResistDisease,
    kActorValue_ResistMagic,
    kActorValue_ResistNormalWeapons,
    kActorValue_ResistParalysis,
    kActorValue_ResistPoison,
    kActorValue_ResistShock,
    kActorValue_Vampirism,
    kActorValue_Darkness,
    kActorValue_ResistWaterDamage,

    kActorValue_NumActorValues,
};

// 318
class Actor : public MobileObject
{
public:
	virtual ~Actor();

	virtual void Unk_90();
	virtual void Unk_91();
	virtual void Unk_92();
	virtual void Unk_93();
	virtual void Unk_94();
	virtual void Unk_95();
	virtual void Unk_96();
	virtual void Unk_97();
	virtual void Unk_98();
	virtual void Unk_99();
	virtual void Unk_9A();
	virtual void Unk_9B();
	virtual void Unk_9C();
	virtual void Unk_9D();
	virtual void Unk_9E();
	virtual void Unk_9F();
	virtual void Unk_A0();
	virtual void Unk_A1();
	virtual void Unk_A2();
	virtual void Unk_A3();
	virtual void Unk_A4();
	virtual void Unk_A5();
	virtual void Unk_A6();
	virtual void Unk_A7();
	virtual void Unk_A8();
	virtual void Unk_A9();
	virtual void Unk_AA();
	virtual void Unk_AB();
	virtual void Unk_AC();
	virtual void Unk_AD();
	virtual void Unk_AE();
	virtual void Unk_AF();
	virtual void Unk_B0();
	virtual void Unk_B1();
	virtual void Unk_B2();
	virtual void ModActorValue(uint8_t actorValue, float amount, u32 unk3 = 0); // B3
	virtual void Unk_B4();
	virtual void Unk_B5();
	virtual void Unk_B6();
	virtual void Unk_B7();
	virtual void Unk_B8();
	virtual void Unk_B9();
	virtual void Unk_BA();
	virtual void Unk_BB();
	virtual bool UnequipObject(TESBoundObject* object, int count = 1, BaseExtraList* extraList = nullptr, bool unk4 = false, bool unk5 = false); // BC
	virtual void Unk_BD();
	virtual void Unk_BE();
	virtual void Unk_BF();
	virtual void Unk_C0();
	virtual void Unk_C1();
	virtual void Unk_C2();
	virtual void Unk_C3();
	virtual void Unk_C4();
	virtual void Unk_C5();
	virtual void Unk_C6();
	virtual void Unk_C7();
	virtual void Unk_C8();
	virtual void Unk_C9();
	virtual void Unk_CA();
	virtual void Unk_CB();
	virtual void Unk_CC();
	virtual void Unk_CD();
	virtual void Unk_CE();
	virtual void Unk_CF();
	virtual void Unk_D0();
	virtual void Unk_D1();
	virtual void Unk_D2();
	virtual void Unk_D3();
	virtual void Unk_D4();
	virtual void Unk_D5();
	virtual void Unk_D6();
	virtual void Unk_D7();
	virtual void Unk_D8();
	virtual void Unk_D9();
	virtual void Unk_DA();
	virtual void Unk_DB();
	virtual void Unk_DC();
	virtual void Unk_DD();
	virtual void Unk_DE();
	virtual void Unk_DF();
	virtual void Unk_E0();
	virtual void Unk_E1();
	virtual void Unk_E2();
	virtual void Unk_E3();
	virtual void Unk_E4();
	virtual void Unk_E5();
	virtual void Unk_E6();
	virtual void Unk_E7();
	virtual void Unk_E8();
	virtual void Unk_E9();
	virtual void Unk_EA();
	virtual void Unk_EB();
	virtual void Unk_EC();
	virtual void Unk_ED();
	virtual void Unk_EE();
	virtual void Unk_EF();
	virtual void Unk_F0();
	virtual void Unk_F1();
	virtual void Unk_F2();
	virtual void Unk_F3();
	virtual void Unk_F4();
	virtual void Unk_F5();
	virtual void Unk_F6();
	virtual void Unk_F7();
	virtual void Unk_F8();
	virtual void Unk_F9();
	virtual void Unk_FA();
	virtual void Unk_FB();
	virtual void Unk_FC();
	virtual void Unk_FD();
	virtual void Unk_FE();
	virtual void Unk_FF();
	virtual void Unk_100();
	virtual void Unk_101();
	virtual void Unk_102();
	virtual void Unk_103();
	virtual void Unk_104();
	virtual void Unk_105();
	virtual void Unk_106();
	virtual void Unk_107();
	virtual void Unk_108();
	virtual void Unk_109();
	virtual void Unk_10A();
	virtual void Unk_10B();
	virtual void Unk_10C();
	virtual void Unk_10D();
	virtual void Unk_10E();
	virtual void Unk_10F();

	u64	unk148[(0x318 - 0x148) / 8];

    MEMBER_FN_PREFIX(Actor);
    // Inventory menu => ..., false, false
    // Hotkey wheel => ..., true, false,
    DEFINE_MEMBER_FN(EquipItem, void, 0x065A7F60, TESBoundObject* object, int count, ExtraDataList* extraList, bool ignoreEnchantment, bool preventUnequip);
    // Inventory menu => ..., true, false, false
    // Hotkey wheel => ..., false, false, false
    DEFINE_MEMBER_FN(UnquipItem, void, 0x065C93F0, TESBoundObject* object, int count, ExtraDataList* extraList, bool unk4, bool unk5, bool unk6);
    DEFINE_MEMBER_FN(AddObjectEnchantment, void, 0x065EDD80, TESBoundObject* object, ExtraDataList* extraList);
    DEFINE_MEMBER_FN(RemoveObjectEnchantment, void, 0x06600EB0, TESBoundObject* object, ExtraDataList* extraList);
};

static_assert(sizeof(Actor) == 0x318);

// 328
class Character : public Actor
{
public:
	virtual ~Character();

	u64	unk318[(0x328 - 0x318) / 8];
};

static_assert(sizeof(Character) == 0x328);

// B70
class PlayerCharacter : public Character
{
public:
    struct ActorValueMods
    {
        union
        {
            float indexed[kActorValue_NumActorValues];
            struct {
                float strength;
                float intelligence;
                float willpower;
                float agility;
                float speed;
                float endurance;
                float personality;
                float luck;
                float health;
                float magicka;
                float fatigue;
                float encumbrance;
                float armorer;
                float athletics;
                float blade;
                float block;
                float blunt;
                float handToHand;
                float heavyArmor;
                float alchemy;
                float alteration;
                float conjuration;
                float destruction;
                float illusion;
                float mysticism;
                float restoration;
                float acrobatics;
                float lightArmor;
                float marksman;
                float mercantile;
                float security;
                float sneak;
                float speechcraft;
                float aggression;
                float confidence;
                float energy;
                float responsibility;
                float bounty;
                float fame;
                float infamy;
                float magickaMultiplier;
                float nightEyeBonus;
                float attachBonus;
                float defendBonus;
                float castingPenalty;
                float blindness;
                float chameleon;
                float invisibility;
                float paralysis;
                float silence;
                float confusion;
                float detectItemRange;
                float spellAbsorbChance;
                float spellReflectChance;
                float swimSpeedMultiplier;
                float waterBreathing;
                float waterWalking;
                float stuntedMagicka;
                float detectLifeRange;
                float reflectDamage;
                float telekinesis;
                float resistFire;
                float resistFrost;
                float resistDisease;
                float resistMagic;
                float resistNormalWeapons;
                float resistParalysis;
                float resistPoison;
                float resistShock;
                float vampirism;
                float darkness;
                float resistWaterDamage;
            };
        };
    };

    static_assert(sizeof(ActorValueMods) == (kActorValue_NumActorValues * sizeof(float)));

	virtual ~PlayerCharacter();

    u64 unk328;
    float calculatedArmor;                  // 330 (Setting this to -1 will cause it to be recalculated.)
    u32 unk334;
	u64 unk338[(0x474 - 0x338) / 8];
    u32 unk470;
    ActorValueMods actorValueTempMod;       // 474
    ActorValueMods actorValuePermanentMod;  // 594
    float healthMissing;                    // 6B4
    float magickaMissing;                   // 6B8
    float fatigueMissing;                   // 6BC
    ActorValueMods actorValueDamage;        // 6C0
    u64 unk6B[(0x830 - 0x7CC) / 8];
	u32 unk840;
	int timesTrainedThisLevel;              // 844
	u64 unk838[(0x944 - 0x838) / 8];
	u32 unk950;
	int timesTrainedTotal;                  // 954
	u64 unk98C[(0xB80 - 0x958) / 8];

	static PlayerCharacter * Get();

	MEMBER_FN_PREFIX(PlayerCharacter);
	DEFINE_MEMBER_FN(GetActiveMagicItem, MagicItem *, 0x065F6ED0);
	DEFINE_MEMBER_FN(SetActiveSpell, void, 0x06604B40, MagicItem *);
};

static_assert(sizeof(PlayerCharacter) == 0xB80);
static_assert(offsetof(PlayerCharacter, calculatedArmor) == 0x330);
static_assert(offsetof(PlayerCharacter, actorValueTempMod) == 0x474);
static_assert(offsetof(PlayerCharacter, actorValuePermanentMod) == 0x594);
static_assert(offsetof(PlayerCharacter, healthMissing) == 0x6B4);
static_assert(offsetof(PlayerCharacter, actorValueDamage) == 0x6C0);
static_assert(offsetof(PlayerCharacter, timesTrainedThisLevel) == 0x844);
static_assert(offsetof(PlayerCharacter, timesTrainedTotal) == 0x954);
