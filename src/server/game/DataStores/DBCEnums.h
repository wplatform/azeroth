/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DBCENUMS_H
#define DBCENUMS_H

#include "Define.h"
#include <array>

#pragma pack(push, 1)

struct DBCPosition2D
{
    float X;
    float Y;
};

struct DBCPosition3D
{
    float X;
    float Y;
    float Z;
};

#pragma pack(pop)

enum LevelLimit
{
    // Client expected level limitation, like as used in DBC item max levels for "until max player level"
    // use as default max player level, must be fit max level for used client
    // also see MAX_LEVEL and STRONG_MAX_LEVEL define
    DEFAULT_MAX_LEVEL = 110,

    // client supported max level for player/pets/etc. Avoid overflow or client stability affected.
    // also see GT_MAX_LEVEL define
    MAX_LEVEL = 110,

    // Server side limitation. Base at used code requirements.
    // also see MAX_LEVEL and GT_MAX_LEVEL define
    STRONG_MAX_LEVEL = 255,
};

enum BattlegroundBracketId                                  // bracketId for level ranges
{
    BG_BRACKET_ID_FIRST          = 0,
    BG_BRACKET_ID_LAST           = 11,

    // must be max value in PvPDificulty slot + 1
    MAX_BATTLEGROUND_BRACKETS
};

enum AreaTeams
{
    AREATEAM_NONE  = 0,
    AREATEAM_ALLY  = 2,
    AREATEAM_HORDE = 4,
    AREATEAM_ANY   = AREATEAM_ALLY+AREATEAM_HORDE
};

enum AchievementFaction
{
    ACHIEVEMENT_FACTION_HORDE           = 0,
    ACHIEVEMENT_FACTION_ALLIANCE        = 1,
    ACHIEVEMENT_FACTION_ANY             = -1
};

enum AchievementFlags
{
    ACHIEVEMENT_FLAG_COUNTER               = 0x00000001,    // Just count statistic (never stop and complete)
    ACHIEVEMENT_FLAG_HIDDEN                = 0x00000002,    // Not sent to client - internal use only
    ACHIEVEMENT_FLAG_PLAY_NO_VISUAL        = 0x00000004,    // Client does not play achievement earned visual
    ACHIEVEMENT_FLAG_SUMM                  = 0x00000008,    // Use summ criteria value from all requirements (and calculate max value)
    ACHIEVEMENT_FLAG_MAX_USED              = 0x00000010,    // Show max criteria (and calculate max value ??)
    ACHIEVEMENT_FLAG_REQ_COUNT             = 0x00000020,    // Use not zero req count (and calculate max value)
    ACHIEVEMENT_FLAG_AVERAGE               = 0x00000040,    // Show as average value (value / time_in_days) depend from other flag (by def use last criteria value)
    ACHIEVEMENT_FLAG_BAR                   = 0x00000080,    // Show as progress bar (value / max vale) depend from other flag (by def use last criteria value)
    ACHIEVEMENT_FLAG_REALM_FIRST_REACH     = 0x00000100,    //
    ACHIEVEMENT_FLAG_REALM_FIRST_KILL      = 0x00000200,    //
    ACHIEVEMENT_FLAG_UNK3                  = 0x00000400,    // ACHIEVEMENT_FLAG_HIDE_NAME_IN_TIE
    ACHIEVEMENT_FLAG_HIDE_INCOMPLETE       = 0x00000800,    // hide from UI if not completed
    ACHIEVEMENT_FLAG_SHOW_IN_GUILD_NEWS    = 0x00001000,    // Shows in guild news
    ACHIEVEMENT_FLAG_SHOW_IN_GUILD_HEADER  = 0x00002000,    // Shows in guild news header
    ACHIEVEMENT_FLAG_GUILD                 = 0x00004000,    //
    ACHIEVEMENT_FLAG_SHOW_GUILD_MEMBERS    = 0x00008000,    //
    ACHIEVEMENT_FLAG_SHOW_CRITERIA_MEMBERS = 0x00010000,    //
    ACHIEVEMENT_FLAG_ACCOUNT               = 0x00020000,
    ACHIEVEMENT_FLAG_UNK5                  = 0x00040000,
    ACHIEVEMENT_FLAG_HIDE_ZERO_COUNTER     = 0x00080000,    // statistic is hidden from UI if no criteria value exists
    ACHIEVEMENT_FLAG_TRACKING_FLAG         = 0x00100000,    // hidden tracking flag, sent to client in all cases except completion announcements
};

uint32 constexpr ACHIVEMENT_CATEGORY_PET_BATTLES = 15117;

enum AreaFlags
{
    AREA_FLAG_SNOW                  = 0x00000001,                // snow (only Dun Morogh, Naxxramas, Razorfen Downs and Winterspring)
    AREA_FLAG_UNK1                  = 0x00000002,                // Razorfen Downs, Naxxramas and Acherus: The Ebon Hold (3.3.5a)
    AREA_FLAG_UNK2                  = 0x00000004,                // Only used for areas on map 571 (development before)
    AREA_FLAG_SLAVE_CAPITAL         = 0x00000008,                // city and city subzones
    AREA_FLAG_UNK3                  = 0x00000010,                // can't find common meaning
    AREA_FLAG_SLAVE_CAPITAL2        = 0x00000020,                // slave capital city flag?
    AREA_FLAG_ALLOW_DUELS           = 0x00000040,                // allow to duel here
    AREA_FLAG_ARENA                 = 0x00000080,                // arena, both instanced and world arenas
    AREA_FLAG_CAPITAL               = 0x00000100,                // main capital city flag
    AREA_FLAG_CITY                  = 0x00000200,                // only for one zone named "City" (where it located?)
    AREA_FLAG_OUTLAND               = 0x00000400,                // expansion zones? (only Eye of the Storm not have this flag, but have 0x00004000 flag)
    AREA_FLAG_SANCTUARY             = 0x00000800,                // sanctuary area (PvP disabled)
    AREA_FLAG_NEED_FLY              = 0x00001000,                // Respawn alive at the graveyard without corpse
    AREA_FLAG_UNUSED1               = 0x00002000,                // Unused in 3.3.5a
    AREA_FLAG_OUTLAND2              = 0x00004000,                // expansion zones? (only Circle of Blood Arena not have this flag, but have 0x00000400 flag)
    AREA_FLAG_OUTDOOR_PVP           = 0x00008000,                // pvp objective area? (Death's Door also has this flag although it's no pvp object area)
    AREA_FLAG_ARENA_INSTANCE        = 0x00010000,                // used by instanced arenas only
    AREA_FLAG_UNUSED2               = 0x00020000,                // Unused in 3.3.5a
    AREA_FLAG_CONTESTED_AREA        = 0x00040000,                // On PvP servers these areas are considered contested, even though the zone it is contained in is a Horde/Alliance territory.
    AREA_FLAG_UNK6                  = 0x00080000,                // Valgarde and Acherus: The Ebon Hold
    AREA_FLAG_LOWLEVEL              = 0x00100000,                // used for some starting areas with area_level <= 15
    AREA_FLAG_TOWN                  = 0x00200000,                // small towns with Inn
    AREA_FLAG_REST_ZONE_HORDE       = 0x00400000,                // Warsong Hold, Acherus: The Ebon Hold, New Agamand Inn, Vengeance Landing Inn, Sunreaver Pavilion (Something to do with team?)
    AREA_FLAG_REST_ZONE_ALLIANCE    = 0x00800000,                // Valgarde, Acherus: The Ebon Hold, Westguard Inn, Silver Covenant Pavilion (Something to do with team?)
    AREA_FLAG_COMBAT                = 0x01000000,                // "combat" area (Script_GetZonePVPInfo), used
    AREA_FLAG_INSIDE                = 0x02000000,                // used for determinating spell related inside/outside questions in Map::IsOutdoors
    AREA_FLAG_OUTSIDE               = 0x04000000,                // used for determinating spell related inside/outside questions in Map::IsOutdoors
    AREA_FLAG_CAN_HEARTH_AND_RESURRECT = 0x08000000,             // Can Hearth And Resurrect From Area
    AREA_FLAG_NO_FLY_ZONE           = 0x20000000,                // Marks zones where you cannot fly
    AREA_FLAG_UNK9                  = 0x40000000
};

enum AreaFlags2
{
    AREA_FLAG_2_DONT_SHOW_SANCTUARY = 0x00000200,                // Hides sanctuary status from zone text color (Script_GetZonePVPInfo)
    AREA_FLAG_2_CAN_ENABLE_WAR_MODE = 0x00001000,                // Allows enabling war mode
};

enum AreaMountFlags
{
    AREA_MOUNT_FLAG_GROUND_ALLOWED      = 0x1,
    AREA_MOUNT_FLAG_FLYING_ALLOWED      = 0x2,
    AREA_MOUNT_FLAG_FLOAT_ALLOWED       = 0x4,
    AREA_MOUNT_FLAG_UNDERWATER_ALLOWED  = 0x8
};

enum ArtifactCategory : uint32
{
    ARTIFACT_CATEGORY_PRIMARY = 1,
    ARTIFACT_CATEGORY_FISHING = 2
};

enum ArtifactPowerFlag : uint8
{
    ARTIFACT_POWER_FLAG_GOLD                        = 0x01,
    ARTIFACT_POWER_FLAG_NO_LINK_REQUIRED            = 0x02,
    ARTIFACT_POWER_FLAG_FINAL                       = 0x04,
    ARTIFACT_POWER_FLAG_SCALES_WITH_NUM_POWERS      = 0x08,
    ARTIFACT_POWER_FLAG_DONT_COUNT_FIRST_BONUS_RANK = 0x10,
    ARTIFACT_POWER_FLAG_MAX_RANK_WITH_TIER          = 0x20,

    ARTIFACT_POWER_FLAG_FIRST                       = ARTIFACT_POWER_FLAG_NO_LINK_REQUIRED | ARTIFACT_POWER_FLAG_DONT_COUNT_FIRST_BONUS_RANK,
};

#define MAX_ARTIFACT_TIER 1

#define BATTLE_PET_SPECIES_MAX_ID 2164

enum ChrSpecializationFlag
{
    CHR_SPECIALIZATION_FLAG_CASTER                  = 0x01,
    CHR_SPECIALIZATION_FLAG_RANGED                  = 0x02,
    CHR_SPECIALIZATION_FLAG_MELEE                   = 0x04,
    CHR_SPECIALIZATION_FLAG_UNKNOWN                 = 0x08,
    CHR_SPECIALIZATION_FLAG_DUAL_WIELD_TWO_HANDED   = 0x10,     // used for CUnitDisplay::SetSheatheInvertedForDualWield
    CHR_SPECIALIZATION_FLAG_PET_OVERRIDE_SPEC       = 0x20,
    CHR_SPECIALIZATION_FLAG_RECOMMENDED             = 0x40,
};

enum class CriteriaFailEvent : uint8
{
    None                                = 0,
    Death                               = 1,    // Death
    Hours24WithoutCompletingDailyQuest  = 2,    // 24 hours without completing a daily quest
    LeaveBattleground                   = 3,    // Leave a battleground
    LoseRankedArenaMatchWithTeamSize    = 4,    // Lose a ranked arena match with team size {#Team Size}
    LoseAura                            = 5,    // Lose aura "{Spell}"
    GainAura                            = 6,    // Gain aura "{Spell}"
    GainAuraEffect                      = 7,    // Gain aura effect "{SpellAuraNames.EnumID}"
    CastSpell                           = 8,    // Cast spell "{Spell}"
    BeSpellTarget                       = 9,    // Have spell "{Spell}" cast on you
    ModifyPartyStatus                   = 10,   // Modify your party status
    LosePetBattle                       = 11,   // Lose a pet battle
    BattlePetDies                       = 12,   // Battle pet dies
    DailyQuestsCleared                  = 13,   // Daily quests cleared
    SendEvent                           = 14,   // Send event "{GameEvents}" (player-sent/instance only)

    Count
};

enum class CriteriaStartEvent : uint8
{
    None                            = 0, // - NONE -
    ReachLevel                      = 1, // Reach level {#Level}
    CompleteDailyQuest              = 2, // Complete daily quest "{QuestV2}"
    StartBattleground               = 3, // Start battleground "{Map}"
    WinRankedArenaMatchWithTeamSize = 4, // Win a ranked arena match with team size {#Team Size}
    GainAura                        = 5, // Gain aura "{Spell}"
    GainAuraEffect                  = 6, // Gain aura effect "{SpellAuraNames.EnumID}"
    CastSpell                       = 7, // Cast spell "{Spell}"
    BeSpellTarget                   = 8, // Have spell "{Spell}" cast on you
    AcceptQuest                     = 9, // Accept quest "{QuestV2}"
    KillNPC                         = 10, // Kill NPC "{Creature}"
    KillPlayer                      = 11, // Kill player
    UseItem                         = 12, // Use item "{Item}"
    SendEvent                       = 13, // Send event "{GameEvents}" (player-sent/instance only)
    BeginScenarioStep               = 14, // Begin scenario step "{#Step}" (for use with "Player on Scenario" modifier only)

    Count
};

enum class CriteriaFlags : uint8
{
    FailAchievement         = 0x01, // Fail Achievement
    ResetOnStart            = 0x02, // Reset on Start
    ServerOnly              = 0x04, // Server Only
    AlwaysSaveToDB          = 0x08, // Always Save to DB (Use with Caution)
    AllowCriteriaDecrement  = 0x10, // Allow criteria to be decremented
    IsForQuest              = 0x20  // Is For Quest
};

DEFINE_ENUM_FLAG(CriteriaFlags);

enum class CriteriaType : uint8
{
    KillCreature                                   = 0,   // Kill NPC "{Creature}"
    WinBattleground                                = 1,   // Win battleground "{Map}"
    CompleteResearchProject                        = 2,   /*NYI*/ // Complete research project "{ResearchProject}"
    CompleteAnyResearchProject                     = 3,   /*NYI*/ // Complete any research project
    FindResearchObject                             = 4,   /*NYI*/ // Find research object "{GameObjects}"
    ReachLevel                                     = 5,   // Reach level
    ExhaustAnyResearchSite                         = 6,   /*NYI*/ // Exhaust any research site
    SkillRaised                                    = 7,   // Skill "{SkillLine}" raised
    EarnAchievement                                = 8,   // Earn achievement "{Achievement}"
    CompleteQuestsCount                            = 9,   // Count of complete quests (quest count)
    CompleteAnyDailyQuestPerDay                    = 10,  // Complete any daily quest (per day)
    CompleteQuestsInZone                           = 11,  // Complete quests in "{AreaTable}"
    CurrencyGained                                 = 12,  // Currency "{CurrencyTypes}" gained
    DamageDealt                                    = 13,  // Damage dealt
    CompleteDailyQuest                             = 14,  // Complete daily quest
    ParticipateInBattleground                      = 15,  // Participate in battleground "{Map}"
    DieOnMap                                       = 16,  // Die on map "{Map}"
    DieAnywhere                                    = 17,  // Die anywhere
    DieInInstance                                  = 18,  // Die in an instance which handles at most {#Max Players} players
    RunInstance                                    = 19,  /*NYI*/ // Run an instance which handles at most {#Max Players} players
    KilledByCreature                               = 20,  // Get killed by "{Creature}"
    CompleteInternalCriteria                       = 21,  /*NYI*/ // Designer Value{`Uses Record ID}
    CompleteAnyChallengeMode                       = 22,  /*NYI*/ // Complete any challenge mode
    KilledByPlayer                                 = 23,  // Die to a player
    MaxDistFallenWithoutDying                      = 24,  // Maximum distance fallen without dying
    EarnChallengeModeMedal                         = 25,  /*NYI*/ // Earn a challenge mode medal of "{#Challenge Mode Medal (OBSOLETE)}" (OBSOLETE)
    DieFromEnviromentalDamage                      = 26,  // Die to "{$Env Damage}" environmental damage
    CompleteQuest                                  = 27,  // Complete quest "{QuestV2}"
    BeSpellTarget                                  = 28,  // Have the spell "{Spell}" cast on you
    CastSpell                                      = 29,  // Cast the spell "{Spell}"
    TrackedWorldStateUIModified                    = 30,  // Tracked WorldStateUI value "{WorldStateUI}" is modified
    PVPKillInArea                                  = 31,  // Kill someone in PVP in "{AreaTable}"
    WinArena                                       = 32,  // Win arena "{Map}"
    ParticipateInArena                             = 33,  /*NYI*/ // Participate in arena "{Map}"
    LearnOrKnowSpell                               = 34,  // Learn or Know spell "{Spell}"
    EarnHonorableKill                              = 35,  // Earn an honorable kill
    AcquireItem                                    = 36,  // Acquire item "{Item}"
    WinAnyRankedArena                              = 37,  // Win a ranked arena match (any arena)
    EarnTeamArenaRating                            = 38,  /*NYI*/ // Earn a team arena rating of {#Arena Rating}
    EarnPersonalArenaRating                        = 39,  // Earn a personal arena rating of {#Arena Rating}
    AchieveSkillStep                               = 40,  // Achieve a skill step in "{SkillLine}"
    UseItem                                        = 41,  // Use item "{Item}"
    LootItem                                       = 42,  // Loot "{Item}" via corpse, pickpocket, fishing, disenchanting, etc.
    RevealWorldMapOverlay                          = 43,  // Reveal world map overlay "{WorldMapOverlay}"
    EarnTitle                                      = 44,  /*NYI*/ // Deprecated PVP Titles
    BankSlotsPurchased                             = 45,  // Bank slots purchased
    ReputationGained                               = 46,  // Reputation gained with faction "{Faction}"
    TotalExaltedFactions                           = 47,  // Total exalted factions
    GotHaircut                                     = 48,  // Got a haircut
    EquipItemInSlot                                = 49,  // Equip item in slot "{$Equip Slot}"
    RollNeed                                       = 50,  // Roll need and get {#Need Roll}
    RollGreed                                      = 51,  // Roll greed and get {#Greed Roll}
    DeliverKillingBlowToClass                      = 52,  // Deliver a killing blow to a {ChrClasses}
    DeliverKillingBlowToRace                       = 53,  // Deliver a killing blow to a {ChrRaces}
    DoEmote                                        = 54,  // Do a "{EmotesText}" emote
    HealingDone                                    = 55,  // Healing done
    DeliveredKillingBlow                           = 56,  // Delivered a killing blow
    EquipItem                                      = 57,  // Equip item "{Item}"
    CompleteQuestsInSort                           = 58,  /*NYI*/ // Complete quests in "{QuestSort}"
    MoneyEarnedFromSales                           = 59,  // Sell items to vendors
    MoneySpentOnRespecs                            = 60,  // Money spent on respecs
    TotalRespecs                                   = 61,  // Total respecs
    MoneyEarnedFromQuesting                        = 62,  // Money earned from questing
    MoneySpentOnTaxis                              = 63,  // Money spent on taxis
    KilledAllUnitsInSpawnRegion                    = 64,  /*NYI*/ // Killed all units in spawn region "{SpawnRegion}"
    MoneySpentAtBarberShop                         = 65,  // Money spent at the barber shop
    MoneySpentOnPostage                            = 66,  // Money spent on postage
    MoneyLootedFromCreatures                       = 67,  // Money looted from creatures
    UseGameobject                                  = 68,  // Use Game Object "{GameObjects}"
    GainAura                                       = 69,  // Gain aura "{Spell}"
    KillPlayer                                     = 70,  // Kill a player (no honor check)
    CompleteChallengeMode                          = 71,  /*NYI*/ // Complete a challenge mode on map "{Map}"
    CatchFishInFishingHole                         = 72,  // Catch fish in the "{GameObjects}" fishing hole
    PlayerTriggerGameEvent                         = 73,  /*NYI*/ // Player will Trigger game event "{GameEvents}"
    Login                                          = 74,  // Login (USE SPARINGLY!)
    LearnSpellFromSkillLine                        = 75,  // Learn spell from the "{SkillLine}" skill line
    WinDuel                                        = 76,  // Win a duel
    LoseDuel                                       = 77,  // Lose a duel
    KillAnyCreature                                = 78,  // Kill any NPC
    CreatedItemsByCastingSpellWithLimit            = 79,  /*NYI*/ // Created items by casting a spell (limit 1 per create...)
    MoneyEarnedFromAuctions                        = 80,  // Money earned from auctions
    BattlePetAchievementPointsEarned               = 81,  /*NYI*/ // Battle pet achievement points earned
    ItemsPostedAtAuction                           = 82,  // Number of items posted at auction
    HighestAuctionBid                              = 83,  // Highest auction bid
    AuctionsWon                                    = 84,  // Auctions won
    HighestAuctionSale                             = 85,  // Highest coin value of item sold
    MostMoneyOwned                                 = 86,  // Most money owned
    TotalReveredFactions                           = 87,  // Total revered factions
    TotalHonoredFactions                           = 88,  // Total honored factions
    TotalFactionsEncountered                       = 89,  // Total factions encountered
    LootAnyItem                                    = 90,  // Loot any item
    ObtainAnyItem                                  = 91,  // Obtain any item
    AnyoneTriggerGameEventScenario                 = 92,  /*NYI*/ // Anyone will Trigger game event "{GameEvents}" (Scenario Only)
    RollAnyNeed                                    = 93,  // Roll any number on need
    RollAnyGreed                                   = 94,  // Roll any number on greed
    ReleasedSpirit                                 = 95,  /*NYI*/ // Released Spirit
    AccountKnownPet                                = 96,  /*NYI*/ // Account knows pet "{Creature}" (Backtracked)
    DefeatDungeonEncounterWhileElegibleForLoot     = 97,  /*NYI*/ // Defeat Encounter "{DungeonEncounter}" While Eligible For Loot
    // UNUSED 18{}                                 = 98,  // Unused
    // UNUSED 19{}                                 = 99,  // Unused
    // UNUSED 20{}                                 = 100, // Unused
    HighestDamageDone                              = 101, // Highest damage done in 1 single ability
    HighestDamageTaken                             = 102, // Most damage taken in 1 single hit
    TotalDamageTaken                               = 103, // Total damage taken
    HighestHealCast                                = 104, // Largest heal cast
    TotalHealReceived                              = 105, // Total healing received
    HighestHealReceived                            = 106, // Largest heal received
    AbandonAnyQuest                                = 107, // Abandon any quest
    BuyTaxi                                        = 108, // Buy a taxi
    GetLootByType                                  = 109, // Get loot via "{$Loot Acquisition}"
    LandTargetedSpellOnTarget                      = 110, // Land targeted spell "{Spell}" on a target
    // UNUSED 21{}                                 = 111, // Unused
    LearnTradeskillSkillLine                       = 112, // Learn tradeskill skill line "{SkillLine}"
    HonorableKills                                 = 113, // Honorable kills (number in interface, won't update except for login)
    AcceptSummon                                   = 114, // Accept a summon
    EarnAchievementPoints                          = 115, // Earn achievement points
    RollDisenchant                                 = 116, /*NYI*/ // Roll disenchant and get {#Disenchant Roll}
    RollAnyDisenchant                              = 117, /*NYI*/ // Roll any number on disenchant
    CompletedLFGDungeon                            = 118, /*NYI*/ // Completed an LFG dungeon
    CompletedLFGDungeonWithStrangers               = 119, // Completed an LFG dungeon with strangers
    KickInitiatorInLFGDungeon                      = 120, /*NYI*/ // Kicked in an LFG dungeon (initiator)
    KickVoterInLFGDungeon                          = 121, /*NYI*/ // Kicked in an LFG dungeon (voter)
    KickTargetInLFGDungeon                         = 122, /*NYI*/ // Kicked in an LFG dungeon (target)
    AbandonedLFGDungeon                            = 123, /*NYI*/ // Abandoned an LFG dungeon
    MoneySpentOnGuildRepair                        = 124, /*NYI*/ // Guild repair amount spent
    GuildAttainedLevel                             = 125, /*NYI*/ // Guild attained level
    CreatedItemsByCastingSpell                     = 126, /*NYI*/ // Created items by casting a spell
    FishInAnyPool                                  = 127, /*NYI*/ // Fish in any pool
    GuildBankTabsPurchased                         = 128, /*NYI*/ // Guild bank tabs purchased
    EarnGuildAchievementPoints                     = 129, /*NYI*/ // Earn guild achievement points
    WinAnyBattleground                             = 130, /*NYI*/ // Win any battleground
    ParticipateInAnyBattleground                   = 131, /*NYI*/ // Participate in any battleground
    EarnBattlegroundRating                         = 132, /*NYI*/ // Earn a battleground rating
    GuildTabardCreated                             = 133, /*NYI*/ // Guild tabard created
    CompleteQuestsCountForGuild                    = 134, /*NYI*/ // Count of complete quests for guild (Quest count)
    HonorableKillsForGuild                         = 135, /*NYI*/ // Honorable kills for Guild
    KillAnyCreatureForGuild                        = 136, /*NYI*/ // Kill any NPC for Guild
    GroupedTankLeftEarlyInLFGDungeon               = 137, /*NYI*/ // Grouped tank left early in an LFG dungeon
    CompleteGuildChallenge                         = 138, /*NYI*/ // Complete a "{$Guild Challenge}" guild challenge
    CompleteAnyGuildChallenge                      = 139, /*NYI*/ // Complete any guild challenge
    MarkedAFKInBattleground                        = 140, /*NYI*/ // Marked AFK in a battleground
    RemovedAFKInBattleground                       = 141, /*NYI*/ // Removed for being AFK in a battleground
    StartAnyBattleground                           = 142, /*NYI*/ // Start any battleground (AFK tracking)
    CompleteAnyBattleground                        = 143, /*NYI*/ // Complete any battleground (AFK tracking)
    MarkedSomeoneAFKInBattleground                 = 144, /*NYI*/ // Marked someone for being AFK in a battleground
    CompletedLFRDungeon                            = 145, /*NYI*/ // Completed an LFR dungeon
    AbandonedLFRDungeon                            = 146, /*NYI*/ // Abandoned an LFR dungeon
    KickInitiatorInLFRDungeon                      = 147, /*NYI*/ // Kicked in an LFR dungeon (initiator)
    KickVoterInLFRDungeon                          = 148, /*NYI*/ // Kicked in an LFR dungeon (voter)
    KickTargetInLFRDungeon                         = 149, /*NYI*/ // Kicked in an LFR dungeon (target)
    GroupedTankLeftEarlyInLFRDungeon               = 150, /*NYI*/ // Grouped tank left early in an LFR dungeon
    CompleteAnyScenario                            = 151, /*NYI*/ // Complete a Scenario
    CompleteScenario                               = 152, /*NYI*/ // Complete scenario "{Scenario}"
    EnterAreaTriggerWithActionSet                  = 153, /*NYI*/ // Enter area trigger "{AreaTriggerActionSet}"
    LeaveAreaTriggerWithActionSet                  = 154, /*NYI*/ // Leave area trigger "{AreaTriggerActionSet}"
    LearnedNewPet                                  = 155, // (Account Only) Learned a new pet
    UniquePetsOwned                                = 156, // (Account Only) Unique pets owned
    AccountObtainPetThroughBattle                  = 157, /*NYI*/ // (Account Only) Obtain a pet through battle
    WinPetBattle                                   = 158, /*NYI*/ // Win a pet battle
    LosePetBattle                                  = 159, /*NYI*/ // Lose a pet battle
    BattlePetReachLevel                            = 160, // (Account Only) Battle pet has reached level {#Level}
    PlayerObtainPetThroughBattle                   = 161, /*NYI*/ // (Player) Obtain a pet through battle
    ActivelyEarnPetLevel                           = 162, // (Player) Actively earn level {#Level} with a pet by a player
    EnterArea                                      = 163, /*NYI*/ // Enter Map Area "{AreaTable}"
    LeaveArea                                      = 164, /*NYI*/ // Leave Map Area "{AreaTable}"
    DefeatDungeonEncounter                         = 165, /*NYI*/ // Defeat Encounter "{DungeonEncounter}"
    PlaceAnyGarrisonBuilding                       = 166, /*NYI*/ // Garrison Building: Place any
    PlaceGarrisonBuilding                          = 167, // Garrison Building: Place "{GarrBuilding}"
    ActivateAnyGarrisonBuilding                    = 168, // Garrison Building: Activate any
    ActivateGarrisonBuilding                       = 169, /*NYI*/ // Garrison Building: Activate "{GarrBuilding}"
    UpgradeGarrison                                = 170, /*NYI*/ // Garrison: Upgrade Garrison to Tier "{#Tier:2,3}"
    StartAnyGarrisonMissionWithFollowerType        = 171, /*NYI*/ // Garrison Mission: Start any with FollowerType "{GarrFollowerType}"
    StartGarrisonMission                           = 172, /*NYI*/ // Garrison Mission: Start "{GarrMission}"
    SucceedAnyGarrisonMissionWithFollowerType      = 173, /*NYI*/ // Garrison Mission: Succeed any with FollowerType "{GarrFollowerType}"
    SucceedGarrisonMission                         = 174, /*NYI*/ // Garrison Mission: Succeed "{GarrMission}"
    RecruitAnyGarrisonFollower                     = 175, /*NYI*/ // Garrison Follower: Recruit any
    RecruitGarrisonFollower                        = 176, // Garrison Follower: Recruit "{GarrFollower}"
    AcquireGarrison                                = 177, /*NYI*/ // Garrison: Acquire a Garrison
    LearnAnyGarrisonBlueprint                      = 178, /*NYI*/ // Garrison Blueprint: Learn any
    LearnGarrisonBlueprint                         = 179, /*NYI*/ // Garrison Blueprint: Learn "{GarrBuilding}"
    LearnAnyGarrisonSpecialization                 = 180, /*NYI*/ // Garrison Specialization: Learn any
    LearnGarrisonSpecialization                    = 181, /*NYI*/ // Garrison Specialization: Learn "{GarrSpecialization}"
    CollectGarrisonShipment                        = 182, /*NYI*/ // Garrison Shipment of type "{CharShipmentContainer}" collected
    ItemLevelChangedForGarrisonFollower            = 183, /*NYI*/ // Garrison Follower: Item Level Changed
    LevelChangedForGarrisonFollower                = 184, /*NYI*/ // Garrison Follower: Level Changed
    LearnToy                                       = 185, /*NYI*/ // Learn Toy "{Item}"
    LearnAnyToy                                    = 186, /*NYI*/ // Learn Any Toy
    QualityUpgradedForGarrisonFollower             = 187, /*NYI*/ // Garrison Follower: Quality Upgraded
    LearnHeirloom                                  = 188, /*NYI*/ // Learn Heirloom "{Item}"
    LearnAnyHeirloom                               = 189, /*NYI*/ // Learn Any Heirloom
    EarnArtifactXP                                 = 190, /*NYI*/ // Earn Artifact XP
    AnyArtifactPowerRankPurchased                  = 191, /*NYI*/ // Artifact Power Ranks Purchased
    LearnTransmog                                  = 192, /*NYI*/ // Learn Transmog "{ItemModifiedAppearance}"
    LearnAnyTransmog                               = 193, /*NYI*/ // Learn Any Transmog
    HonorLevelIncrease                             = 194, // (Player) honor level increase
    PrestigeLevelIncrease                          = 195, /*NYI*/ // (Player) prestige level increase
    ActivelyReachLevel                             = 196, // Actively level to level {#Level}
    CompleteResearchAnyGarrisonTalent              = 197, /*NYI*/ // Garrison Talent: Complete Research Any
    CompleteResearchGarrisonTalent                 = 198, /*NYI*/ // Garrison Talent: Complete Research "{GarrTalent}"
    LearnAnyTransmogInSlot                         = 199, // Learn Any Transmog in Slot "{$Equip Slot}"
    RecruitAnyGarrisonTroop                        = 200, /*NYI*/ // Recruit any Garrison Troop
    StartResearchAnyGarrisonTalent                 = 201, /*NYI*/ // Garrison Talent: Start Research Any
    StartResearchGarrisonTalent                    = 202, /*NYI*/ // Garrison Talent: Start Research "{GarrTalent}"
    CompleteAnyWorldQuest                          = 203, /*NYI*/ // Complete Any Quest
    EarnLicense                                    = 204, /*NYI*/ // Earn License "{BattlePayDeliverable}" (does NOT work for box level)
    CollectTransmogSetFromGroup                    = 205, // (Account Only) Collect a Transmog Set from Group "{TransmogSetGroup}"
    ParagonLevelIncreaseWithFaction                = 206, /*NYI*/ // (Player) paragon level increase with faction "{Faction}"
    PlayerHasEarnedHonor                           = 207, /*NYI*/ // Player has earned honor
    KillCreatureScenario                           = 208, /*NYI*/ // Kill NPC "{Creature}" (scenario criteria only, do not use for player)
    ArtifactPowerRankPurchased                     = 209, /*NYI*/ // Artifact Power Rank of "{ArtifactPower}" Purchased
    ChooseAnyRelicTalent                           = 210, /*NYI*/ // Choose any Relic Talent
    ChooseRelicTalent                              = 211, /*NYI*/ // Choose Relic Talent "{ArtifactPower}"
    EarnExpansionLevel                             = 212, /*NYI*/ // Earn Expansion Level "{$Expansion Level}"
    AccountHonorLevelReached                       = 213, /*NYI*/ // (Account Only) honor level {#Level} reached
    EarnArtifactXPForAzeriteItem                   = 214, // Earn Artifact experience for Azerite Item
    AzeriteLevelReached                            = 215, // Azerite Level {#Azerite Level} reached
    MythicPlusCompleted                            = 216, /*NYI*/ // Mythic Plus Completed
    ScenarioGroupCompleted                         = 217, /*NYI*/ // Scenario Group Completed
    CompleteAnyReplayQuest                         = 218, // Complete Any Replay Quest
    BuyItemsFromVendors                            = 219, // Buy items from vendors
    SellItemsToVendors                             = 220, // Sell items to vendors
    ReachMaxLevel                                  = 221, /*NYI*/ // Reach Max Level
    MemorizeSpell                                  = 222, /*NYI*/ // Memorize Spell "{Spell}"
    LearnTransmogIllusion                          = 223, /*NYI*/ // Learn Transmog Illusion
    LearnAnyTransmogIllusion                       = 224, /*NYI*/ // Learn Any Transmog Illusion
    EnterTopLevelArea                              = 225, // Enter Top Level Map Area "{AreaTable}"
    LeaveTopLevelArea                              = 226, /*NYI*/ // Leave Top Level Map Area "{AreaTable}"
    SocketGarrisonTalent                           = 227, /*NYI*/ // Socket Garrison Talent {GarrTalent}
    SocketAnySoulbindConduit                       = 228, /*NYI*/ // Socket Any Soulbind Conduit
    ObtainAnyItemWithCurrencyValue                 = 229, /*NYI*/ // Obtain Any Item With Currency Value "{CurrencyTypes}"
    MythicPlusRatingAttained                       = 230, /*NYI*/ // (Player) Mythic+ Rating "{#DungeonScore}" attained
    SpentTalentPoint                               = 231, /*NYI*/ // (Player) spent talent point

    MythicPlusDisplaySeasonEnded                   = 234, /*NYI*/ // {DisplaySeason}

    WinRatedSoloShuffleRound                       = 239, /*NYI*/
    ParticipateInRatedSoloShuffleRound             = 240, /*NYI*/

    ReputationAmountGained                         = 243, /*NYI*/ // Gain reputation amount with {FactionID}; accumulate, not highest

    FulfillAnyCraftingOrder                        = 245, /*NYI*/
    FulfillCraftingOrderType                       = 246, /*NYI*/ // {CraftingOrderType}

    PerksProgramMonthComplete                      = 249, /*NYI*/
    Count
};

enum class CriteriaTreeFlags : uint16
{
    ProgressBar                 = 0x0001, // Progress Bar
    DoNotDisplay                = 0x0002, // Do Not Display
    IsDate                      = 0x0004, // Is a Date
    IsMoney                     = 0x0008, // Is Money
    ToastOnComplete             = 0x0010, // Toast on Complete
    UseObjectsDescription       = 0x0020, // Use Object's Description
    ShowFactionSpecificChild    = 0x0040, // Show faction specific child
    DisplayAllChildren          = 0x0080, // Display all children
    AwardBonusRep               = 0x0100, // Award Bonus Rep (Hack!!)
    AllianceOnly                = 0x0200, // Treat this criteria or block as Alliance
    HordeOnly                   = 0x0400, // Treat this criteria or block as Horde
    DisplayAsFraction           = 0x0800, // Display as Fraction
    IsForQuest                  = 0x1000  // Is For Quest
};

DEFINE_ENUM_FLAG(CriteriaTreeFlags);

enum class CriteriaTreeOperator : uint8
{
    Complete        = 0, // Complete
    NotComplete     = 1, // Not Complete
    CompleteAll     = 4, // Complete All
    Sum             = 5, // Sum Of Criteria Is
    Highest         = 6, // Highest Criteria Is
    StartedAtLeast  = 7, // Started At Least
    CompleteAtLeast = 8, // Complete At Least
    ProgressBar     = 9  // Progress Bar
};

enum class CharBaseSectionVariation : uint8
{
    Skin           = 0,
    Face           = 1,
    FacialHair     = 2,
    Hair           = 3,
    Underwear      = 4,
    CustomDisplay1 = 5,
    CustomDisplay2 = 6,
    CustomDisplay3 = 7,

    Count
};

enum CharSectionFlags
{
    SECTION_FLAG_PLAYER = 0x01,
    SECTION_FLAG_DEATH_KNIGHT = 0x04,
    SECTION_FLAG_DEMON_HUNTER = 0x20
};

enum CharSectionType
{
    SECTION_TYPE_SKIN_LOW_RES = 0,
    SECTION_TYPE_FACE_LOW_RES = 1,
    SECTION_TYPE_FACIAL_HAIR_LOW_RES = 2,
    SECTION_TYPE_HAIR_LOW_RES = 3,
    SECTION_TYPE_UNDERWEAR_LOW_RES = 4,
    SECTION_TYPE_SKIN = 5,
    SECTION_TYPE_FACE = 6,
    SECTION_TYPE_FACIAL_HAIR = 7,
    SECTION_TYPE_HAIR = 8,
    SECTION_TYPE_UNDERWEAR = 9,
    SECTION_TYPE_CUSTOM_DISPLAY_1_LOW_RES = 10,
    SECTION_TYPE_CUSTOM_DISPLAY_1 = 11,
    SECTION_TYPE_CUSTOM_DISPLAY_2_LOW_RES = 12,
    SECTION_TYPE_CUSTOM_DISPLAY_2 = 13,
    SECTION_TYPE_CUSTOM_DISPLAY_3_LOW_RES = 14,
    SECTION_TYPE_CUSTOM_DISPLAY_3 = 15,

    SECTION_TYPE_MAX
};

enum Curves
{
    CURVE_ID_ARTIFACT_RELIC_ITEM_LEVEL_BONUS = 1718
};

enum Difficulty : uint8
{
    DIFFICULTY_NONE                 = 0,
    DIFFICULTY_NORMAL               = 1,
    DIFFICULTY_HEROIC               = 2,
    DIFFICULTY_10_N                 = 3,
    DIFFICULTY_25_N                 = 4,
    DIFFICULTY_10_HC                = 5,
    DIFFICULTY_25_HC                = 6,
    DIFFICULTY_LFR                  = 7,
    DIFFICULTY_MYTHIC_KEYSTONE      = 8,
    DIFFICULTY_40                   = 9,
    DIFFICULTY_3_MAN_SCENARIO_HC    = 11,
    DIFFICULTY_3_MAN_SCENARIO_N     = 12,
    DIFFICULTY_NORMAL_RAID          = 14,
    DIFFICULTY_HEROIC_RAID          = 15,
    DIFFICULTY_MYTHIC_RAID          = 16,
    DIFFICULTY_LFR_NEW              = 17,
    DIFFICULTY_EVENT_RAID           = 18,
    DIFFICULTY_EVENT_DUNGEON        = 19,
    DIFFICULTY_EVENT_SCENARIO       = 20,
    DIFFICULTY_MYTHIC               = 23,
    DIFFICULTY_TIMEWALKING          = 24,
    DIFFICULTY_WORLD_PVP_SCENARIO   = 25,
    DIFFICULTY_5_MAN_SCENARIO_N     = 26,
    DIFFICULTY_20_MAN_SCENARIO_N    = 27,
    DIFFICULTY_PVEVP_SCENARIO       = 29,
    DIFFICULTY_EVENT_SCENARIO_6     = 30,
    DIFFICULTY_WORLD_PVP_SCENARIO_2 = 32,
    DIFFICULTY_TIMEWALKING_RAID     = 33,
    DIFFICULTY_PVP                  = 34,

    MAX_DIFFICULTY
};

enum DifficultyFlags
{
    DIFFICULTY_FLAG_HEROIC          = 0x01,
    DIFFICULTY_FLAG_DEFAULT         = 0x02,
    DIFFICULTY_FLAG_CAN_SELECT      = 0x04, // Player can select this difficulty in dropdown menu
    DIFFICULTY_FLAG_CHALLENGE_MODE  = 0x08,

    DIFFICULTY_FLAG_LEGACY          = 0x20,
    DIFFICULTY_FLAG_DISPLAY_HEROIC  = 0x40, // Controls icon displayed on minimap when inside the instance
    DIFFICULTY_FLAG_DISPLAY_MYTHIC  = 0x80  // Controls icon displayed on minimap when inside the instance
};

enum SpawnMask
{
    SPAWNMASK_CONTINENT = (1 << DIFFICULTY_NONE), // any maps without spawn modes

    SPAWNMASK_DUNGEON_NORMAL    = (1 << DIFFICULTY_NORMAL),
    SPAWNMASK_DUNGEON_HEROIC    = (1 << DIFFICULTY_HEROIC),
    SPAWNMASK_DUNGEON_ALL       = (SPAWNMASK_DUNGEON_NORMAL | SPAWNMASK_DUNGEON_HEROIC),

    SPAWNMASK_RAID_10MAN_NORMAL = (1 << DIFFICULTY_10_N),
    SPAWNMASK_RAID_25MAN_NORMAL = (1 << DIFFICULTY_25_N),
    SPAWNMASK_RAID_NORMAL_ALL   = (SPAWNMASK_RAID_10MAN_NORMAL | SPAWNMASK_RAID_25MAN_NORMAL),

    SPAWNMASK_RAID_10MAN_HEROIC = (1 << DIFFICULTY_10_HC),
    SPAWNMASK_RAID_25MAN_HEROIC = (1 << DIFFICULTY_25_HC),
    SPAWNMASK_RAID_HEROIC_ALL   = (SPAWNMASK_RAID_10MAN_HEROIC | SPAWNMASK_RAID_25MAN_HEROIC),

    SPAWNMASK_RAID_ALL          = (SPAWNMASK_RAID_NORMAL_ALL | SPAWNMASK_RAID_HEROIC_ALL)
};

enum class ExpectedStatType : uint8
{
    CreatureHealth          = 0,
    PlayerHealth            = 1,
    CreatureAutoAttackDps   = 2,
    CreatureArmor           = 3,
    PlayerMana              = 4,
    PlayerPrimaryStat       = 5,
    PlayerSecondaryStat     = 6,
    ArmorConstant           = 7,
    None                    = 8,
    CreatureSpellDamage     = 9
};

enum FactionTemplateFlags
{
    FACTION_TEMPLATE_ENEMY_SPAR             = 0x00000020,   // guessed, sparring with enemies?
    FACTION_TEMPLATE_FLAG_PVP               = 0x00000800,   // flagged for PvP
    FACTION_TEMPLATE_FLAG_CONTESTED_GUARD   = 0x00001000,   // faction will attack players that were involved in PvP combats
    FACTION_TEMPLATE_FLAG_HOSTILE_BY_DEFAULT= 0x00002000
};

enum FactionMasks
{
    FACTION_MASK_PLAYER   = 1,                              // any player
    FACTION_MASK_ALLIANCE = 2,                              // player or creature from alliance team
    FACTION_MASK_HORDE    = 4,                              // player or creature from horde team
    FACTION_MASK_MONSTER  = 8                               // aggressive creature from monster team
    // if none flags set then non-aggressive creature
};

enum class FriendshipReputationFlags : int32
{
    NoFXOnReactionChange                            = 0x01,
    NoLogTextOnRepGain                              = 0x02,
    NoLogTextOnReactionChange                       = 0x04,
    ShowRepGainandReactionChangeForHiddenFaction    = 0x08,
    NoRepGainModifiers                              = 0x10
};

DEFINE_ENUM_FLAG(FriendshipReputationFlags);

enum class GlobalCurve : int32
{
    CritDiminishing = 0,
    MasteryDiminishing = 1,
    HasteDiminishing = 2,
    SpeedDiminishing = 3,
    AvoidanceDiminishing = 4,
    VersatilityDoneDiminishing = 5,
    LifestealDiminishing = 6,
    DodgeDiminishing = 7,
    BlockDiminishing = 8,
    ParryDiminishing = 9,

    VersatilityTakenDiminishing = 11,

    ContentTuningPvpItemLevelHealthScaling = 13,
    ContentTuningPvpLevelDamageScaling = 14,
    ContentTuningPvpItemLevelDamageScaling = 15,
};

#define MAX_ITEM_PROTO_FLAGS 4
#define MAX_ITEM_PROTO_ZONES 2
#define MAX_ITEM_PROTO_SOCKETS 3
#define MAX_ITEM_PROTO_STATS  10

enum MapTypes                                               // Lua_IsInInstance
{
    MAP_COMMON          = 0,                                // none
    MAP_INSTANCE        = 1,                                // party
    MAP_RAID            = 2,                                // raid
    MAP_BATTLEGROUND    = 3,                                // pvp
    MAP_ARENA           = 4,                                // arena
    MAP_SCENARIO        = 5                                 // scenario
};

enum MapFlags
{
    MAP_FLAG_CAN_TOGGLE_DIFFICULTY  = 0x0100,
    MAP_FLAG_FLEX_LOCKING           = 0x8000, // All difficulties share completed encounters lock, not bound to a single instance id
                                              // heroic difficulty flag overrides it and uses instance id bind
    MAP_FLAG_GARRISON               = 0x4000000
};


enum GlyphSlotType
{
    GLYPH_SLOT_MAJOR = 0,
    GLYPH_SLOT_MINOR = 1,
    GLYPH_SLOT_PRIME = 2
};

enum ItemEnchantmentType
{
    ITEM_ENCHANTMENT_TYPE_NONE                              = 0,
    ITEM_ENCHANTMENT_TYPE_COMBAT_SPELL                      = 1,
    ITEM_ENCHANTMENT_TYPE_DAMAGE                            = 2,
    ITEM_ENCHANTMENT_TYPE_EQUIP_SPELL                       = 3,
    ITEM_ENCHANTMENT_TYPE_RESISTANCE                        = 4,
    ITEM_ENCHANTMENT_TYPE_STAT                              = 5,
    ITEM_ENCHANTMENT_TYPE_TOTEM                             = 6,
    ITEM_ENCHANTMENT_TYPE_USE_SPELL                         = 7,
    ITEM_ENCHANTMENT_TYPE_PRISMATIC_SOCKET                  = 8,
    ITEM_ENCHANTMENT_TYPE_ARTIFACT_POWER_BONUS_RANK_BY_TYPE = 9,
    ITEM_ENCHANTMENT_TYPE_ARTIFACT_POWER_BONUS_RANK_BY_ID   = 10,
    ITEM_ENCHANTMENT_TYPE_BONUS_LIST_ID                     = 11,
    ITEM_ENCHANTMENT_TYPE_BONUS_LIST_CURVE                  = 12,
    ITEM_ENCHANTMENT_TYPE_ARTIFACT_POWER_BONUS_RANK_PICKER  = 13
};

enum ItemExtendedCostFlags
{
    ITEM_EXT_COST_FLAG_REQUIRE_GUILD                = 0x01,
    ITEM_EXT_COST_CURRENCY_REQ_IS_SEASON_EARNED_1   = 0x02,
    ITEM_EXT_COST_CURRENCY_REQ_IS_SEASON_EARNED_2   = 0x04,
    ITEM_EXT_COST_CURRENCY_REQ_IS_SEASON_EARNED_3   = 0x08,
    ITEM_EXT_COST_CURRENCY_REQ_IS_SEASON_EARNED_4   = 0x10,
    ITEM_EXT_COST_CURRENCY_REQ_IS_SEASON_EARNED_5   = 0x20,
};

enum ItemBonusType
{
    ITEM_BONUS_ITEM_LEVEL                       = 1,
    ITEM_BONUS_STAT                             = 2,
    ITEM_BONUS_QUALITY                          = 3,
    ITEM_BONUS_NAME_SUBTITLE                    = 4,              // Text under name
    ITEM_BONUS_SUFFIX                           = 5,
    ITEM_BONUS_SOCKET                           = 6,
    ITEM_BONUS_APPEARANCE                       = 7,
    ITEM_BONUS_REQUIRED_LEVEL                   = 8,
    ITEM_BONUS_DISPLAY_TOAST_METHOD             = 9,
    ITEM_BONUS_REPAIR_COST_MULTIPLIER           = 10,
    ITEM_BONUS_SCALING_STAT_DISTRIBUTION        = 11,
    ITEM_BONUS_DISENCHANT_LOOT_ID               = 12,
    ITEM_BONUS_SCALING_STAT_DISTRIBUTION_FIXED  = 13,
    ITEM_BONUS_ITEM_LEVEL_CAN_INCREASE          = 14,             // Displays a + next to item level indicating it can warforge
    ITEM_BONUS_RANDOM_ENCHANTMENT               = 15,             // Responsible for showing "<Random additional stats>" or "+%d Rank Random Minor Trait" in the tooltip before item is obtained
    ITEM_BONUS_BONDING                          = 16,
    ITEM_BONUS_RELIC_TYPE                       = 17,
    ITEM_BONUS_OVERRIDE_REQUIRED_LEVEL          = 18
};

enum ItemLimitCategoryMode
{
    ITEM_LIMIT_CATEGORY_MODE_HAVE       = 0,                      // limit applied to amount items in inventory/bank
    ITEM_LIMIT_CATEGORY_MODE_EQUIP      = 1                       // limit applied to amount equipped items (including used gems)
};

enum ItemSetFlags
{
    ITEM_SET_FLAG_LEGACY_INACTIVE = 0x01,
};

enum ItemSpecStat
{
    ITEM_SPEC_STAT_INTELLECT        = 0,
    ITEM_SPEC_STAT_AGILITY          = 1,
    ITEM_SPEC_STAT_STRENGTH         = 2,
    ITEM_SPEC_STAT_SPIRIT           = 3,
    ITEM_SPEC_STAT_HIT              = 4,
    ITEM_SPEC_STAT_DODGE            = 5,
    ITEM_SPEC_STAT_PARRY            = 6,
    ITEM_SPEC_STAT_ONE_HANDED_AXE   = 7,
    ITEM_SPEC_STAT_TWO_HANDED_AXE   = 8,
    ITEM_SPEC_STAT_ONE_HANDED_SWORD = 9,
    ITEM_SPEC_STAT_TWO_HANDED_SWORD = 10,
    ITEM_SPEC_STAT_ONE_HANDED_MACE  = 11,
    ITEM_SPEC_STAT_TWO_HANDED_MACE  = 12,
    ITEM_SPEC_STAT_DAGGER           = 13,
    ITEM_SPEC_STAT_FIST_WEAPON      = 14,
    ITEM_SPEC_STAT_GUN              = 15,
    ITEM_SPEC_STAT_BOW              = 16,
    ITEM_SPEC_STAT_CROSSBOW         = 17,
    ITEM_SPEC_STAT_STAFF            = 18,
    ITEM_SPEC_STAT_POLEARM          = 19,
    ITEM_SPEC_STAT_THROWN           = 20,
    ITEM_SPEC_STAT_WAND             = 21,
    ITEM_SPEC_STAT_SHIELD           = 22,
    ITEM_SPEC_STAT_RELIC            = 23,
    ITEM_SPEC_STAT_CRIT             = 24,
    ITEM_SPEC_STAT_HASTE            = 25,
    ITEM_SPEC_STAT_BONUS_ARMOR      = 26,
    ITEM_SPEC_STAT_CLOAK            = 27,
    ITEM_SPEC_STAT_WARGLAIVES       = 28,
    ITEM_SPEC_STAT_RELIC_IRON       = 29,
    ITEM_SPEC_STAT_RELIC_BLOOD      = 30,
    ITEM_SPEC_STAT_RELIC_SHADOW     = 31,
    ITEM_SPEC_STAT_RELIC_FEL        = 32,
    ITEM_SPEC_STAT_RELIC_ARCANE     = 33,
    ITEM_SPEC_STAT_RELIC_FROST      = 34,
    ITEM_SPEC_STAT_RELIC_FIRE       = 35,
    ITEM_SPEC_STAT_RELIC_WATER      = 36,
    ITEM_SPEC_STAT_RELIC_LIFE       = 37,
    ITEM_SPEC_STAT_RELIC_WIND       = 38,
    ITEM_SPEC_STAT_RELIC_HOLY       = 39,

    ITEM_SPEC_STAT_NONE             = 40
};

enum MapDifficultyFlags : uint8
{
    MAP_DIFFICULTY_FLAG_CANNOT_EXTEND   = 0x10
};

enum MountCapabilityFlags
{
    MOUNT_CAPABILITY_FLAG_GROUND                = 0x1,
    MOUNT_CAPABILITY_FLAG_FLYING                = 0x2,
    MOUNT_CAPABILITY_FLAG_FLOAT                 = 0x4,
    MOUNT_CAPABILITY_FLAG_UNDERWATER            = 0x8,
    MOUNT_CAPABIILTY_FLAG_IGNORE_RESTRICTIONS   = 0x20,
};

enum MountFlags
{
    MOUNT_FLAG_SELF_MOUNT               = 0x02,                   // Player becomes the mount himself
    MOUNT_FLAG_FACTION_SPECIFIC         = 0x04,
    MOUNT_FLAG_PREFERRED_SWIMMING       = 0x10,
    MOUNT_FLAG_PREFERRED_WATER_WALKING  = 0x20,
    MOUNT_FLAG_HIDE_IF_UNKNOWN          = 0x40
};

enum class PhaseEntryFlags : uint16
{
    ReadOnly                = 0x001,
    InternalPhase           = 0x002,
    Normal                  = 0x008,
    Cosmetic                = 0x010,
    Personal                = 0x020,
    Expensive               = 0x040,
    EventsAreObservable     = 0x080,
    UsesPreloadConditions   = 0x100,
    UnshareablePersonal     = 0x200,
    ObjectsAreVisible       = 0x400,
};

DEFINE_ENUM_FLAG(PhaseEntryFlags);

// PhaseUseFlags fields in different db2s
enum PhaseUseFlagsValues : uint8
{
    PHASE_USE_FLAGS_NONE            = 0x0,
    PHASE_USE_FLAGS_ALWAYS_VISIBLE  = 0x1,
    PHASE_USE_FLAGS_INVERSE         = 0x2,

    PHASE_USE_FLAGS_ALL             = PHASE_USE_FLAGS_ALWAYS_VISIBLE | PHASE_USE_FLAGS_INVERSE
};

enum class PlayerConditionLfgStatus : uint8
{
    InLFGDungeon            = 1,
    InLFGRandomDungeon      = 2,
    InLFGFirstRandomDungeon = 3,
    PartialClear            = 4,
    StrangerCount           = 5,
    VoteKickCount           = 6,
    BootCount               = 7,
    GearDiff                = 8
};

enum PrestigeLevelInfoFlags : uint8
{
    PRESTIGE_FLAG_DISABLED  = 0x01                      // Prestige levels with this flag won't be included to calculate max prestigelevel.
};

enum QuestPackageFilter
{
    QUEST_PACKAGE_FILTER_LOOT_SPECIALIZATION    = 0,    // Players can select this quest reward if it matches their selected loot specialization
    QUEST_PACKAGE_FILTER_CLASS                  = 1,    // Players can select this quest reward if it matches their class
    QUEST_PACKAGE_FILTER_UNMATCHED              = 2,    // Players can select this quest reward if no class/loot_spec rewards are available
    QUEST_PACKAGE_FILTER_EVERYONE               = 3     // Players can always select this quest reward
};

enum ScenarioStepFlags
{
    SCENARIO_STEP_FLAG_BONUS_OBJECTIVE      = 0x1,
    SCENARIO_STEP_FLAG_HEROIC_ONLY          = 0x2
};

enum class SkillLineFlags : uint16
{
    AlwaysShownInUI                                 = 0x0001,
    NeverShownInUI                                  = 0x0002,
    FirstTierIsSelfTaught                           = 0x0004,
    GrantedIncrementallyByCharacterUpgrade          = 0x0008,
    AutomaticRank                                   = 0x0010,
    InheritParentRankWhenLearned                    = 0x0020,
    ShowsInSpellTooltip                             = 0x0040,
    AppearsInMiscTabOfSpellbook                     = 0x0080,
    // unused                                       = 0x0100,
    IgnoreCategoryMods                              = 0x0200,
    DisplaysAsProficiency                           = 0x0400,
    PetsOnly                                        = 0x0800,
    UniqueBitfield                                  = 0x1000,
    RacialForThePurposeOfPaidRaceOrFactionChange    = 0x2000,
    ProgressiveSkillUp                              = 0x4000,
    RacialForThePurposeOfTemporaryRaceChange        = 0x8000,
};

DEFINE_ENUM_FLAG(SkillLineFlags);

enum AbilytyLearnType
{
    SKILL_LINE_ABILITY_LEARNED_ON_SKILL_VALUE  = 1, // Spell state will update depending on skill value
    SKILL_LINE_ABILITY_LEARNED_ON_SKILL_LEARN  = 2, // Spell will be learned/removed together with entire skill
    SKILL_LINE_ABILITY_REWARDED_FROM_QUEST     = 4  // Learned as quest reward, also re-learned if missing
};

enum class SkillLineAbilityFlags
{
    CanFallbackToLearnedOnSkillLearn            = 0x80, // The skill is rewarded from a quest if player started on exile's reach
};

DEFINE_ENUM_FLAG(SkillLineAbilityFlags);

enum SkillRaceClassInfoFlags
{
    SKILL_FLAG_NO_SKILLUP_MESSAGE       = 0x2,
    SKILL_FLAG_ALWAYS_MAX_VALUE         = 0x10,
    SKILL_FLAG_UNLEARNABLE              = 0x20,     // Skill can be unlearned
    SKILL_FLAG_INCLUDE_IN_SORT          = 0x80,     // Spells belonging to a skill with this flag will additionally compare skill ids when sorting spellbook in client
    SKILL_FLAG_NOT_TRAINABLE            = 0x100,
    SKILL_FLAG_MONO_VALUE               = 0x400     // Skill always has value 1 - clientside display flag, real value can be different
};

enum SpellCategoryFlags
{
    SPELL_CATEGORY_FLAG_COOLDOWN_SCALES_WITH_WEAPON_SPEED   = 0x01, // unused
    SPELL_CATEGORY_FLAG_COOLDOWN_STARTS_ON_EVENT            = 0x04,
    SPELL_CATEGORY_FLAG_COOLDOWN_EXPIRES_AT_DAILY_RESET     = 0x08
};

#define MAX_SPELL_EFFECTS 32
#define MAX_EFFECT_MASK 0xFFFFFFFF

#define MAX_SPELL_AURA_INTERRUPT_FLAGS 2

enum class SpellItemEnchantmentFlags : uint16
{
    Soulbound               = 0x001,
    DoNotLog                = 0x002,
    MainhandOnly            = 0x004,
    AllowEnteringArena      = 0x008,
    DoNotSaveToDB           = 0x010,
    ScaleAsAGem             = 0x020,
    DisableInChallengeModes = 0x040,
    DisableInProvingGrounds = 0x080,
    AllowTransmog           = 0x100,
    HideUntilCollected      = 0x200,
};

DEFINE_ENUM_FLAG(SpellItemEnchantmentFlags);

enum SpellProcsPerMinuteModType
{
    SPELL_PPM_MOD_HASTE         = 1,
    SPELL_PPM_MOD_CRIT          = 2,
    SPELL_PPM_MOD_CLASS         = 3,
    SPELL_PPM_MOD_SPEC          = 4,
    SPELL_PPM_MOD_RACE          = 5,
    SPELL_PPM_MOD_ITEM_LEVEL    = 6,
    SPELL_PPM_MOD_BATTLEGROUND  = 7
};

constexpr std::size_t MAX_POWERS_PER_SPELL = 4;

enum class SpellShapeshiftFormFlags : int32
{
    Stance                      = 0x00000001,
    NotToggleable               = 0x00000002,   // player cannot cancel the aura giving this shapeshift
    PersistOnDeath              = 0x00000004,
    CanInteractNPC              = 0x00000008,   // if the form does not have SHAPESHIFT_FORM_IS_NOT_A_SHAPESHIFT then this flag must be present to allow NPC interaction
    DontUseWeapon               = 0x00000010,

    CanUseEquippedItems         = 0x00000040,   // if the form does not have SHAPESHIFT_FORM_IS_NOT_A_SHAPESHIFT then this flag allows equipping items without ITEM_FLAG_USABLE_WHEN_SHAPESHIFTED
    CanUseItems                 = 0x00000080,   // if the form does not have SHAPESHIFT_FORM_IS_NOT_A_SHAPESHIFT then this flag allows using items without ITEM_FLAG_USABLE_WHEN_SHAPESHIFTED
    DontAutoUnshift             = 0x00000100,   // clientside
    ConsideredDead              = 0x00000200,
    CanOnlyCastShapeshiftSpells = 0x00000400,   // prevents using spells that don't have any shapeshift requirement
    StanceCancelsAtFlightmaster = 0x00000800,
    NoEmoteSounds               = 0x00001000,
    NoTriggerTeleport           = 0x00002000,
    CannotChangeEquippedItems   = 0x00004000,

    CannotUseGameObjects        = 0x00010000
};

DEFINE_ENUM_FLAG(SpellShapeshiftFormFlags);

enum class SpellVisualEffectNameType : uint32
{
    Model                           = 0,
    Item                            = 1,
    Creature                        = 2,
    UnitItemMainHand                = 3,
    UnitItemOffHand                 = 4,
    UnitItemRanged                  = 5,
    UnitAmmoBasic                   = 6,
    UnitAmmoPreferred               = 7,
    UnitItemMainHandIgnoreDisarmed  = 8,
    UnitItemOffHandIgnoreDisarmed   = 9,
    UnitItemRangedIgnoreDisarmed    = 10
};

class TaxiMask
{
public:
    using value_type = uint8;

    TaxiMask();

    value_type& operator[](size_t i) { return _data[i]; }
    value_type const& operator[](size_t i) const { return _data[i]; }

    size_t size() const { return _data.size(); }
    value_type const* data() const { return _data.data(); }

    decltype(auto) begin() { return _data.begin(); }
    decltype(auto) end() { return _data.end(); }

private:
    std::vector<value_type> _data;
};

enum TotemCategoryType
{
    TOTEM_CATEGORY_TYPE_KNIFE           = 1,
    TOTEM_CATEGORY_TYPE_TOTEM           = 2,
    TOTEM_CATEGORY_TYPE_ROD             = 3,
    TOTEM_CATEGORY_TYPE_PICK            = 21,
    TOTEM_CATEGORY_TYPE_STONE           = 22,
    TOTEM_CATEGORY_TYPE_HAMMER          = 23,
    TOTEM_CATEGORY_TYPE_SPANNER         = 24
};

enum class TransmogIllusionFlags : int32
{
    HideUntilCollected              = 0x1,
    PlayerConditionGrantsOnLogin    = 0x2,
};

DEFINE_ENUM_FLAG(TransmogIllusionFlags);

// SummonProperties.dbc, col 1
enum SummonPropGroup
{
    SUMMON_PROP_GROUP_UNKNOWN1       = 0,                   // 1160 spells in 3.0.3
    SUMMON_PROP_GROUP_UNKNOWN2       = 1,                   // 861 spells in 3.0.3
    SUMMON_PROP_GROUP_PETS           = 2,                   // 52 spells in 3.0.3, pets mostly
    SUMMON_PROP_GROUP_CONTROLLABLE   = 3,                   // 13 spells in 3.0.3, mostly controllable
    SUMMON_PROP_GROUP_UNKNOWN3       = 4                    // 86 spells in 3.0.3, taxi/mounts
};

// SummonProperties.dbc, col 3
enum SummonPropType
{
    SUMMON_PROP_TYPE_UNKNOWN         = 0,                   // different summons, 1330 spells in 3.0.3
    SUMMON_PROP_TYPE_SUMMON          = 1,                   // generic summons, 49 spells in 3.0.3
    SUMMON_PROP_TYPE_GUARDIAN        = 2,                   // summon guardian, 393 spells in 3.0.3
    SUMMON_PROP_TYPE_ARMY            = 3,                   // summon army, 5 spells in 3.0.3
    SUMMON_PROP_TYPE_TOTEM           = 4,                   // summon totem, 169 spells in 3.0.3
    SUMMON_PROP_TYPE_CRITTER         = 5,                   // critter/minipet, 195 spells in 3.0.3
    SUMMON_PROP_TYPE_DK              = 6,                   // summon DRW/Ghoul, 2 spells in 3.0.3
    SUMMON_PROP_TYPE_BOMB            = 7,                   // summon bot/bomb, 4 spells in 3.0.3
    SUMMON_PROP_TYPE_PHASING         = 8,                   // something todo with DK prequest line, 2 spells in 3.0.3
    SUMMON_PROP_TYPE_SIEGE_VEH       = 9,                   // summon different vehicles, 14 spells in 3.0.3
    SUMMON_PROP_TYPE_DRAKE_VEH       = 10,                  // summon drake (vehicle), 3 spells
    SUMMON_PROP_TYPE_LIGHTWELL       = 11,                  // summon lightwell, 6 spells in 3.0.3
    SUMMON_PROP_TYPE_JEEVES          = 12,                  // summon Jeeves, 1 spell in 3.3.5a
    SUMMON_PROP_TYPE_LASHTAIL        = 13                   // Lashtail Hatchling, 1 spell in 4.2.2
};

enum class SummonPropertiesFlags : uint32
{
    None                              = 0x00000000,
    AttackSummoner                    = 0x00000001, // NYI
    HelpWhenSummonedInCombat          = 0x00000002, // NYI
    UseLevelOffset                    = 0x00000004, // NYI
    DespawnOnSummonerDeath            = 0x00000008, // NYI
    OnlyVisibleToSummoner             = 0x00000010,
    CannotDismissPet                  = 0x00000020, // NYI
    UseDemonTimeout                   = 0x00000040, // NYI
    UnlimitedSummons                  = 0x00000080, // NYI
    UseCreatureLevel                  = 0x00000100,
    JoinSummonerSpawnGroup            = 0x00000200, // NYI
    DoNotToggle                       = 0x00000400, // NYI
    DespawnWhenExpired                = 0x00000800, // NYI
    UseSummonerFaction                = 0x00001000,
    DoNotFollowMountedSummoner        = 0x00002000, // NYI
    SavePetAutocast                   = 0x00004000, // NYI
    IgnoreSummonerPhase               = 0x00008000, // Wild Only
    OnlyVisibleToSummonerGroup        = 0x00010000,
    DespawnOnSummonerLogout           = 0x00020000, // NYI
    CastRideVehicleSpellOnSummoner    = 0x00040000, // NYI
    GuardianActsLikePet               = 0x00080000, // NYI
    DontSnapSessileToGround           = 0x00100000, // NYI
    SummonFromBattlePetJournal        = 0x00200000,
    UnitClutter                       = 0x00400000, // NYI
    DefaultNameColor                  = 0x00800000, // NYI
    UseOwnInvisibilityDetection       = 0x01000000, // NYI. Ignore Owner's Invisibility Detection
    DespawnWhenReplaced               = 0x02000000, // NYI. Totem Slots Only
    DespawnWhenTeleportingOutOfRange  = 0x04000000, // NYI
    SummonedAtGroupFormationPosition  = 0x08000000, // NYI
    DontDespawnOnSummonerDeath        = 0x10000000, // NYI
    UseTitleAsCreatureName            = 0x20000000, // NYI
    AttackableBySummoner              = 0x40000000, // NYI
    DontDismissWhenEncounterIsAborted = 0x80000000  // NYI
};

#define MAX_TALENT_TIERS 7
#define MAX_TALENT_COLUMNS 3
#define MAX_PVP_TALENT_TIERS 6
#define MAX_PVP_TALENT_COLUMNS 3

enum TaxiNodeFlags
{
    TAXI_NODE_FLAG_ALLIANCE             = 0x01,
    TAXI_NODE_FLAG_HORDE                = 0x02,
    TAXI_NODE_FLAG_USE_FAVORITE_MOUNT   = 0x10
};

enum TaxiPathNodeFlags
{
    TAXI_PATH_NODE_FLAG_TELEPORT    = 0x1,
    TAXI_PATH_NODE_FLAG_STOP        = 0x2
};

enum VehicleSeatFlags
{
    VEHICLE_SEAT_FLAG_HAS_LOWER_ANIM_FOR_ENTER                         = 0x00000001,
    VEHICLE_SEAT_FLAG_HAS_LOWER_ANIM_FOR_RIDE                          = 0x00000002,
    VEHICLE_SEAT_FLAG_DISABLE_GRAVITY                                  = 0x00000004, // Passenger will not be affected by gravity
    VEHICLE_SEAT_FLAG_SHOULD_USE_VEH_SEAT_EXIT_ANIM_ON_VOLUNTARY_EXIT  = 0x00000008,
    VEHICLE_SEAT_FLAG_UNK5                                             = 0x00000010,
    VEHICLE_SEAT_FLAG_UNK6                                             = 0x00000020,
    VEHICLE_SEAT_FLAG_UNK7                                             = 0x00000040,
    VEHICLE_SEAT_FLAG_UNK8                                             = 0x00000080,
    VEHICLE_SEAT_FLAG_UNK9                                             = 0x00000100,
    VEHICLE_SEAT_FLAG_HIDE_PASSENGER                                   = 0x00000200, // Passenger is hidden
    VEHICLE_SEAT_FLAG_ALLOW_TURNING                                    = 0x00000400, // needed for CGCamera__SyncFreeLookFacing
    VEHICLE_SEAT_FLAG_CAN_CONTROL                                      = 0x00000800, // Lua_UnitInVehicleControlSeat
    VEHICLE_SEAT_FLAG_CAN_CAST_MOUNT_SPELL                             = 0x00001000, // Can cast spells with SPELL_AURA_MOUNTED from seat (possibly 4.x only, 0 seats on 3.3.5a)
    VEHICLE_SEAT_FLAG_UNCONTROLLED                                     = 0x00002000, // can override !& VEHICLE_SEAT_FLAG_CAN_ENTER_OR_EXIT
    VEHICLE_SEAT_FLAG_CAN_ATTACK                                       = 0x00004000, // Can attack, cast spells and use items from vehicle
    VEHICLE_SEAT_FLAG_SHOULD_USE_VEH_SEAT_EXIT_ANIM_ON_FORCED_EXIT     = 0x00008000,
    VEHICLE_SEAT_FLAG_UNK17                                            = 0x00010000,
    VEHICLE_SEAT_FLAG_UNK18                                            = 0x00020000, // Needs research and support (28 vehicles): Allow entering vehicles while keeping specific permanent(?) auras that impose visuals (states like beeing under freeze/stun mechanic, emote state animations).
    VEHICLE_SEAT_FLAG_HAS_VEH_EXIT_ANIM_VOLUNTARY_EXIT                 = 0x00040000,
    VEHICLE_SEAT_FLAG_HAS_VEH_EXIT_ANIM_FORCED_EXIT                    = 0x00080000,
    VEHICLE_SEAT_FLAG_PASSENGER_NOT_SELECTABLE                         = 0x00100000,
    VEHICLE_SEAT_FLAG_UNK22                                            = 0x00200000,
    VEHICLE_SEAT_FLAG_REC_HAS_VEHICLE_ENTER_ANIM                       = 0x00400000,
    VEHICLE_SEAT_FLAG_IS_USING_VEHICLE_CONTROLS                        = 0x00800000, // Lua_IsUsingVehicleControls
    VEHICLE_SEAT_FLAG_ENABLE_VEHICLE_ZOOM                              = 0x01000000,
    VEHICLE_SEAT_FLAG_CAN_ENTER_OR_EXIT                                = 0x02000000, // Lua_CanExitVehicle - can enter and exit at free will
    VEHICLE_SEAT_FLAG_CAN_SWITCH                                       = 0x04000000, // Lua_CanSwitchVehicleSeats
    VEHICLE_SEAT_FLAG_HAS_START_WARITING_FOR_VEH_TRANSITION_ANIM_ENTER = 0x08000000,
    VEHICLE_SEAT_FLAG_HAS_START_WARITING_FOR_VEH_TRANSITION_ANIM_EXIT  = 0x10000000,
    VEHICLE_SEAT_FLAG_CAN_CAST                                         = 0x20000000, // Lua_UnitHasVehicleUI
    VEHICLE_SEAT_FLAG_UNK2                                             = 0x40000000, // checked in conjunction with 0x800 in CastSpell2
    VEHICLE_SEAT_FLAG_ALLOWS_INTERACTION                               = 0x80000000
};

enum VehicleSeatFlagsB
{
    VEHICLE_SEAT_FLAG_B_NONE                     = 0x00000000,
    VEHICLE_SEAT_FLAG_B_USABLE_FORCED            = 0x00000002,
    VEHICLE_SEAT_FLAG_B_TARGETS_IN_RAIDUI        = 0x00000008,           // Lua_UnitTargetsVehicleInRaidUI
    VEHICLE_SEAT_FLAG_B_EJECTABLE                = 0x00000020,           // ejectable
    VEHICLE_SEAT_FLAG_B_USABLE_FORCED_2          = 0x00000040,
    VEHICLE_SEAT_FLAG_B_USABLE_FORCED_3          = 0x00000100,
    VEHICLE_SEAT_FLAG_B_PASSENGER_MIRRORS_ANIMS  = 0x00010000,           // Passenger forced to repeat all vehicle animations
    VEHICLE_SEAT_FLAG_B_KEEP_PET                 = 0x00020000,
    VEHICLE_SEAT_FLAG_B_USABLE_FORCED_4          = 0x02000000,
    VEHICLE_SEAT_FLAG_B_CAN_SWITCH               = 0x04000000,
    VEHICLE_SEAT_FLAG_B_VEHICLE_PLAYERFRAME_UI   = 0x80000000            // Lua_UnitHasVehiclePlayerFrameUI - actually checked for flagsb &~ 0x80000000
};

// CurrencyTypes.dbc
enum CurrencyTypes
{
    CURRENCY_TYPE_JUSTICE_POINTS        = 395,
    CURRENCY_TYPE_VALOR_POINTS          = 396,
    CURRENCY_TYPE_APEXIS_CRYSTALS       = 823,
};

enum WorldMapTransformsFlags
{
    WORLD_MAP_TRANSFORMS_FLAG_DUNGEON   = 0x04
};

enum class WorldStateExpressionValueType : uint8
{
    Constant    = 1,
    WorldState  = 2,
    Function    = 3
};

enum class WorldStateExpressionLogic : uint8
{
    None    = 0,
    And     = 1,
    Or      = 2,
    Xor     = 3,
};

enum class WorldStateExpressionComparisonType : uint8
{
    None            = 0,
    Equal           = 1,
    NotEqual        = 2,
    Less            = 3,
    LessOrEqual     = 4,
    Greater         = 5,
    GreaterOrEqual  = 6,
};

enum class WorldStateExpressionOperatorType : uint8
{
    None            = 0,
    Sum             = 1,
    Substraction    = 2,
    Multiplication  = 3,
    Division        = 4,
    Remainder       = 5,
};

enum WorldStateExpressionFunctions
{
    WSE_FUNCTION_NONE = 0,
    WSE_FUNCTION_RANDOM,
    WSE_FUNCTION_MONTH,
    WSE_FUNCTION_DAY,
    WSE_FUNCTION_TIME_OF_DAY,
    WSE_FUNCTION_REGION,
    WSE_FUNCTION_CLOCK_HOUR,
    WSE_FUNCTION_OLD_DIFFICULTY_ID,
    WSE_FUNCTION_HOLIDAY_START,
    WSE_FUNCTION_HOLIDAY_LEFT,
    WSE_FUNCTION_HOLIDAY_ACTIVE,
    WSE_FUNCTION_TIMER_CURRENT_TIME,
    WSE_FUNCTION_WEEK_NUMBER,
    WSE_FUNCTION_UNK13,
    WSE_FUNCTION_UNK14,
    WSE_FUNCTION_DIFFICULTY_ID,
    WSE_FUNCTION_WAR_MODE_ACTIVE,
    WSE_FUNCTION_UNK17,
    WSE_FUNCTION_UNK18,
    WSE_FUNCTION_UNK19,
    WSE_FUNCTION_UNK20,
    WSE_FUNCTION_UNK21,
    WSE_FUNCTION_WORLD_STATE_EXPRESSION,
    WSE_FUNCTION_KEYSTONE_AFFIX,
    WSE_FUNCTION_UNK24,
    WSE_FUNCTION_UNK25,
    WSE_FUNCTION_UNK26,
    WSE_FUNCTION_UNK27,
    WSE_FUNCTION_KEYSTONE_LEVEL,
    WSE_FUNCTION_UNK29,
    WSE_FUNCTION_UNK30,
    WSE_FUNCTION_UNK31,
    WSE_FUNCTION_UNK32,
    WSE_FUNCTION_MERSENNE_RANDOM,
    WSE_FUNCTION_UNK34,
    WSE_FUNCTION_UNK35,
    WSE_FUNCTION_UNK36,
    WSE_FUNCTION_UI_WIDGET_DATA,
    WSE_FUNCTION_TIME_EVENT_PASSED,

    WSE_FUNCTION_MAX,
};

#endif
