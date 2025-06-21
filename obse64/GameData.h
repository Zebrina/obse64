#pragma once

#include "GameForms.h"
#include "GameTypes.h"
#include "NiTypes.h"
#include "obse64_common/Utilities.h"

// form data and io

class TESForm;
class TESObject;
class TESObjectCELL;

class TESRegionList;
class TESRegionDataManager;

// 
class TESFile
{
public:
};

// 20
struct TESObjectListHead
{
	// linked list of everything?

	u32			count;	// 00
	u32			pad04;	// 04
	TESObject	* first;	// 08
	TESObject	* last;	// 10
	void *		unk18;	// 18
};

// 1860
class TESDataHandler
{
public:
	TESObjectListHead	* allObjects;			// 0000

	// todo: check types
	BSSimpleList <TESForm *>	formListPackages;	    // 0008
	BSSimpleList <TESForm *>	formListWorldSpaces;	// 0018
	BSSimpleList <TESForm *>	formListClimates;	    // 0028
	BSSimpleList <TESForm *>	formListWeathers;	    // 0038
	BSSimpleList <TESForm *>	formListEnchantments;	// 0048
	BSSimpleList <TESForm *>	formListSpells;	        // 0058
	BSSimpleList <TESForm *>	formListHairs;	        // 0068
	BSSimpleList <TESForm *>	formListEyes;	        // 0078
	BSSimpleList <TESForm *>	formListRaces;	        // 0088
	BSSimpleList <TESForm *>	formListLandTextures;	// 0098
	BSSimpleList <TESForm *>	formListClasses;	    // 00A8
	BSSimpleList <TESForm *>	formListFactions;	    // 00B8
	BSSimpleList <TESForm *>	formListScripts;	    // 00C8
	BSSimpleList <TESForm *>	formListSounds;	        // 00D8
	BSSimpleList <TESForm *>	formListGlobals;	    // 00E8
	BSSimpleList <TESForm *>	formListDialogues;	    // 00F8
	BSSimpleList <TESForm *>	formListQuests;	        // 0108
	BSSimpleList <TESForm *>	formListBirthsigns;	    // 0118
	BSSimpleList <TESForm *>	formListCombatStyles;	// 0128
	BSSimpleList <TESForm *>	formListLoadScreens;	// 0138
	BSSimpleList <TESForm *>	formListWaterForms;	    // 0148
	BSSimpleList <TESForm *>	formListEffectShaders;	// 0158
	BSSimpleList <TESForm *>	formListANIO;           // 0168
	
	TESRegionList	* regionList;	// 0178

	NiTLargeArray <TESObjectCELL *>	interiorCells;	// 0180

	u8	skills[0xB0 * 21];	// 01A0 - TESSkill array

	BSSimpleList <TESForm *>	formList1010;	// 1010
	u32	nextFormID;								// 1020
	u32	pad1024;								// 1024

	void						* unk1028;				// 1028
	BSSimpleList <TESFile *>	modList;				// 1030
	u32							unk1040;				// 1040
	u32							pad1044;				// 1044
	TESFile						* modsByID[0xFF];		// 1048
	u8							unk1840[8];				// 1840 - u8 flags?
	TESRegionDataManager		* regionDataManager;	// 1848
	void						* unk1850;				// 1850
	u8							unk1858;				// 1858
	u8							pad1859[7];				// 1859

	static TESDataHandler * GetSingleton();

	MEMBER_FN_PREFIX(TESDataHandler);
	DEFINE_MEMBER_FN(UnkInit, void, 0x0662B9C0);

    // iterator support.

    class iterator
    {
    public:
        TESObject* operator*() { return object_; }
        TESObject* operator->() { return object_; }

        bool operator==(const iterator other) const { return other.object_ == object_; }
        bool operator!=(const iterator other) const { return !(other == *this); }

        iterator operator++()
        {
            object_ = object_->objectListNext;
            return *this;
        }

    private:
        friend class TESDataHandler;

        iterator(TESObject* object) : object_(object) {}

        TESObject* object_;
    };

    iterator begin() { return iterator{ allObjects->first }; }
    iterator end() { return iterator{ nullptr }; }

    class const_iterator
    {
    public:
        const TESObject* operator*() { return object_; }
        const TESObject* operator->() { return object_; }

        bool operator==(const const_iterator other) const { return other.object_ == object_; }
        bool operator!=(const const_iterator other) const { return !(other == *this); }

        const_iterator operator++()
        {
            object_ = object_->objectListNext;
            return *this;
        }

    private:
        friend class TESDataHandler;

        const_iterator(const TESObject* object) : object_(object) {}

        const TESObject* object_;
    };

    const_iterator begin() const { return const_iterator{ allObjects->first }; }
    const_iterator end() const { return const_iterator{ nullptr }; }
};

static_assert(sizeof(TESDataHandler) == 0x1860);
