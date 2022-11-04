/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef _UPDATEFIELDS_H
#define _UPDATEFIELDS_H

enum EObjectFields
{
    OBJECT_FIELD_GUID                                   = 0x000, // Size: 2, Flags: PUBLIC
    OBJECT_FIELD_DATA                                   = 0x002, // Size: 2, Flags: PUBLIC
    OBJECT_FIELD_TYPE                                   = 0x004, // Size: 1, Flags: PUBLIC
    OBJECT_FIELD_ENTRY                                  = 0x005, // Size: 1, Flags: DYNAMIC
    OBJECT_FIELD_DYNAMIC_FLAGS                          = 0x006, // Size: 1, Flags: DYNAMIC, 0x100
    OBJECT_FIELD_SCALE_X                                = 0x007, // Size: 1, Flags: PUBLIC
    OBJECT_END                                          = 0x008
};

enum EItemFields
{
    ITEM_FIELD_OWNER                                         = OBJECT_END + 0x00, // Size: 2, Flags: UF_FLAG_PUBLIC
    ITEM_FIELD_CONTAINED                                     = OBJECT_END + 0x02, // Size: 2, Flags: UF_FLAG_PUBLIC
    ITEM_FIELD_CREATOR                                       = OBJECT_END + 0x04, // Size: 2, Flags: UF_FLAG_PUBLIC
    ITEM_FIELD_GIFTCREATOR                                   = OBJECT_END + 0x06, // Size: 2, Flags: UF_FLAG_PUBLIC
    ITEM_FIELD_STACK_COUNT                                   = OBJECT_END + 0x08, // Size: 1, Flags: UF_FLAG_OWNER
    ITEM_FIELD_DURATION                                      = OBJECT_END + 0x09, // Size: 1, Flags: UF_FLAG_OWNER
    ITEM_FIELD_SPELL_CHARGES                                 = OBJECT_END + 0x0A, // Size: 5, Flags: UF_FLAG_OWNER
    ITEM_FIELD_FLAGS                                         = OBJECT_END + 0x0F, // Size: 1, Flags: UF_FLAG_PUBLIC
    ITEM_FIELD_ENCHANTMENT_1_1                               = OBJECT_END + 0x10,
    ITEM_FIELD_ENCHANTMENT_1_3                               = OBJECT_END + 0x12,
    ITEM_FIELD_ENCHANTMENT_2_1                               = OBJECT_END + 0x13,
    ITEM_FIELD_ENCHANTMENT_2_3                               = OBJECT_END + 0x15,
    ITEM_FIELD_ENCHANTMENT_3_1                               = OBJECT_END + 0x16,
    ITEM_FIELD_ENCHANTMENT_3_3                               = OBJECT_END + 0x18,
    ITEM_FIELD_ENCHANTMENT_4_1                               = OBJECT_END + 0x19,
    ITEM_FIELD_ENCHANTMENT_4_3                               = OBJECT_END + 0x1B,
    ITEM_FIELD_ENCHANTMENT_5_1                               = OBJECT_END + 0x1C,
    ITEM_FIELD_ENCHANTMENT_5_3                               = OBJECT_END + 0x1E,
    ITEM_FIELD_ENCHANTMENT_6_1                               = OBJECT_END + 0x1F,
    ITEM_FIELD_ENCHANTMENT_6_3                               = OBJECT_END + 0x21,
    ITEM_FIELD_ENCHANTMENT_7_1                               = OBJECT_END + 0x22,
    ITEM_FIELD_ENCHANTMENT_7_3                               = OBJECT_END + 0x24,
    ITEM_FIELD_ENCHANTMENT_8_1                               = OBJECT_END + 0x25,
    ITEM_FIELD_ENCHANTMENT_8_3                               = OBJECT_END + 0x27,
    ITEM_FIELD_ENCHANTMENT_9_1                               = OBJECT_END + 0x28,
    ITEM_FIELD_ENCHANTMENT_9_3                               = OBJECT_END + 0x2A,
    ITEM_FIELD_ENCHANTMENT_10_1                              = OBJECT_END + 0x2B,
    ITEM_FIELD_ENCHANTMENT_10_3                              = OBJECT_END + 0x2D,
    ITEM_FIELD_ENCHANTMENT_11_1                              = OBJECT_END + 0x2E,
    ITEM_FIELD_ENCHANTMENT_11_3                              = OBJECT_END + 0x30,
    ITEM_FIELD_ENCHANTMENT_12_1                              = OBJECT_END + 0x31,
    ITEM_FIELD_ENCHANTMENT_12_3                              = OBJECT_END + 0x33,
    ITEM_FIELD_ENCHANTMENT_13_1                              = OBJECT_END + 0x34,
    ITEM_FIELD_ENCHANTMENT_13_3                              = OBJECT_END + 0x36,
    ITEM_FIELD_PROPERTY_SEED                                 = OBJECT_END + 0x37, // Size: 1, Flags: UF_FLAG_PUBLIC
    ITEM_FIELD_RANDOM_PROPERTIES_ID                          = OBJECT_END + 0x38, // Size: 1, Flags: UF_FLAG_PUBLIC
    ITEM_FIELD_DURABILITY                                    = OBJECT_END + 0x39, // Size: 1, Flags: UF_FLAG_OWNER
    ITEM_FIELD_MAXDURABILITY                                 = OBJECT_END + 0x3A, // Size: 1, Flags: UF_FLAG_OWNER
    ITEM_FIELD_CREATE_PLAYED_TIME                            = OBJECT_END + 0x3B, // Size: 1, Flags: UF_FLAG_PUBLIC
    ITEM_FIELD_MODIFIERS_MASK                                = OBJECT_END + 0x3C, // Size: 1, Flags: UF_FLAG_OWNER
    ITEM_END                                                 = OBJECT_END + 0x3D,
};

enum ItemDynamicFields
{
    ITEM_DYNAMIC_MODIFIERS                           = 0x0,
    ITEM_DYNAMIC_END                                 = 0x1
};

enum EContainerFields
{
    CONTAINER_FIELD_SLOT_1                           = ITEM_END + 0x0,
    CONTAINER_FIELD_NUM_SLOTS                        = ITEM_END + 0x48,
    CONTAINER_END                                    = ITEM_END + 0x49,
};

enum EUnitFields
{
    UNIT_FIELD_CHARM                                         = OBJECT_END + 0x00, // Size: 2, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_SUMMON                                        = OBJECT_END + 0x02, // Size: 2, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_CRITTER                                       = OBJECT_END + 0x04, // Size: 2, Flags: UF_FLAG_PRIVATE
    UNIT_FIELD_CHARMEDBY                                     = OBJECT_END + 0x06, // Size: 2, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_SUMMONEDBY                                    = OBJECT_END + 0x08, // Size: 2, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_CREATEDBY                                     = OBJECT_END + 0x0A, // Size: 2, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_DEMON_CREATOR                                 = OBJECT_END + 0x0C, // Size: 2, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_TARGET                                        = OBJECT_END + 0x0E, // Size: 2, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_BATTLE_PET_COMPANION_GUID                     = OBJECT_END + 0x10, // Size: 2, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_CHANNEL_OBJECT                                = OBJECT_END + 0x12, // Size: 2, Flags: UF_FLAG_PUBLIC, UF_FLAG_URGENT
    UNIT_CHANNEL_SPELL                                       = OBJECT_END + 0x14, // Size: 1, Flags: UF_FLAG_PUBLIC, UF_FLAG_URGENT
    UNIT_FIELD_SUMMONED_BY_HOME_REALM                        = OBJECT_END + 0x15, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_BYTES_0                                       = OBJECT_END + 0x16, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_DISPLAY_POWER                                 = OBJECT_END + 0x17, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_OVERRIDE_DISPLAY_POWER                        = OBJECT_END + 0x18, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_HEALTH                                        = OBJECT_END + 0x19, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_POWER1                                        = OBJECT_END + 0x1A, // Size: 5, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_MAXHEALTH                                     = OBJECT_END + 0x1F, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_MAXPOWER1                                     = OBJECT_END + 0x20, // Size: 5, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_POWER_REGEN_FLAT_MODIFIER                     = OBJECT_END + 0x25, // Size: 5, Flags: UF_FLAG_PRIVATE, UF_FLAG_OWNER, UF_FLAG_UNIT_ALL
    UNIT_FIELD_POWER_REGEN_INTERRUPTED_FLAT_MODIFIER         = OBJECT_END + 0x2A, // Size: 5, Flags: UF_FLAG_PRIVATE, UF_FLAG_OWNER, UF_FLAG_UNIT_ALL
    UNIT_FIELD_LEVEL                                         = OBJECT_END + 0x2F, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_EFFECTIVE_LEVEL                               = OBJECT_END + 0x30, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_FACTIONTEMPLATE                               = OBJECT_END + 0x31, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_VIRTUAL_ITEM_SLOT_ID                                = OBJECT_END + 0x32, // Size: 3, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_FLAGS                                         = OBJECT_END + 0x35, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_FLAGS_2                                       = OBJECT_END + 0x36, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_AURASTATE                                    = OBJECT_END + 0x37, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_BASEATTACKTIME                        = OBJECT_END + 0x38, // Size: 2, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_RANGEDATTACKTIME                 = OBJECT_END + 0x3A, // Size: 1, Flags: UF_FLAG_PRIVATE
    UNIT_FIELD_BOUNDINGRADIUS                                = OBJECT_END + 0x3B, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_COMBATREACH                                   = OBJECT_END + 0x3C, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_DISPLAYID                                     = OBJECT_END + 0x3D, // Size: 1, Flags: UF_FLAG_VIEWER_DEPENDENT, UF_FLAG_URGENT
    UNIT_FIELD_NATIVEDISPLAYID                               = OBJECT_END + 0x3E, // Size: 1, Flags: UF_FLAG_PUBLIC, UF_FLAG_URGENT
    UNIT_FIELD_MOUNTDISPLAYID                                = OBJECT_END + 0x3F, // Size: 1, Flags: UF_FLAG_PUBLIC, UF_FLAG_URGENT
    UNIT_FIELD_MINDAMAGE                                     = OBJECT_END + 0x40, // Size: 1, Flags: UF_FLAG_PRIVATE, UF_FLAG_OWNER, UF_FLAG_EMPATH
    UNIT_FIELD_MAXDAMAGE                                     = OBJECT_END + 0x41, // Size: 1, Flags: UF_FLAG_PRIVATE, UF_FLAG_OWNER, UF_FLAG_EMPATH
    UNIT_FIELD_MINOFFHANDDAMAGE                              = OBJECT_END + 0x42, // Size: 1, Flags: UF_FLAG_PRIVATE, UF_FLAG_OWNER, UF_FLAG_EMPATH
    UNIT_FIELD_MAXOFFHANDDAMAGE                              = OBJECT_END + 0x43, // Size: 1, Flags: UF_FLAG_PRIVATE, UF_FLAG_OWNER, UF_FLAG_EMPATH
    UNIT_FIELD_BYTES_1                                       = OBJECT_END + 0x44, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_PETNUMBER                                     = OBJECT_END + 0x45, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_PET_NAME_TIMESTAMP                            = OBJECT_END + 0x46, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_PETEXPERIENCE                                 = OBJECT_END + 0x47, // Size: 1, Flags: UF_FLAG_OWNER
    UNIT_FIELD_PETNEXTLEVELEXP                               = OBJECT_END + 0x48, // Size: 1, Flags: UF_FLAG_OWNER
    UNIT_MOD_CAST_SPEED                                      = OBJECT_END + 0x49, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_MOD_CAST_HASTE                                      = OBJECT_END + 0x4A, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_MOD_HASTE                                           = OBJECT_END + 0x4B, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_MOD_RANGED_HASTE                              = OBJECT_END + 0x4C, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_MOD_HASTE_REGEN                                     = OBJECT_END + 0x4D, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_CREATED_BY_SPELL                                    = OBJECT_END + 0x4E, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_NPC_FLAGS                                           = OBJECT_END + 0x4F, // Size: 2, Flags: UF_FLAG_PUBLIC, UF_FLAG_VIEWER_DEPENDENT
    UNIT_NPC_EMOTESTATE                                      = OBJECT_END + 0x51, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_STAT0                                         = OBJECT_END + 0x52, // Size: 5, Flags: UF_FLAG_PRIVATE, UF_FLAG_OWNER
    UNIT_FIELD_POSSTAT0                                      = OBJECT_END + 0x57, // Size: 5, Flags: UF_FLAG_PRIVATE, UF_FLAG_OWNER
    UNIT_FIELD_NEGSTAT0                                      = OBJECT_END + 0x5C, // Size: 5, Flags: UF_FLAG_PRIVATE, UF_FLAG_OWNER
    UNIT_FIELD_RESISTANCES                                   = OBJECT_END + 0x61, // Size: 7, Flags: UF_FLAG_PRIVATE, UF_FLAG_OWNER, UF_FLAG_EMPATH
    UNIT_FIELD_RESISTANCEBUFFMODSPOSITIVE                    = OBJECT_END + 0x68, // Size: 7, Flags: UF_FLAG_PRIVATE, UF_FLAG_OWNER
    UNIT_FIELD_RESISTANCEBUFFMODSNEGATIVE                    = OBJECT_END + 0x6F, // Size: 7, Flags: UF_FLAG_PRIVATE, UF_FLAG_OWNER
    UNIT_FIELD_BASE_MANA                                     = OBJECT_END + 0x76, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_BASE_HEALTH                                   = OBJECT_END + 0x77, // Size: 1, Flags: UF_FLAG_PRIVATE, UF_FLAG_OWNER
    UNIT_FIELD_BYTES_2                                       = OBJECT_END + 0x78, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_ATTACK_POWER                                  = OBJECT_END + 0x79, // Size: 1, Flags: UF_FLAG_PRIVATE, UF_FLAG_OWNER
    UNIT_FIELD_ATTACK_POWER_MOD_POS                          = OBJECT_END + 0x7A, // Size: 1, Flags: UF_FLAG_PRIVATE, UF_FLAG_OWNER
    UNIT_FIELD_ATTACK_POWER_MOD_NEG                          = OBJECT_END + 0x7B, // Size: 1, Flags: UF_FLAG_PRIVATE, UF_FLAG_OWNER
    UNIT_FIELD_ATTACK_POWER_MULTIPLIER                       = OBJECT_END + 0x7C, // Size: 1, Flags: UF_FLAG_PRIVATE, UF_FLAG_OWNER
    UNIT_FIELD_RANGED_ATTACK_POWER                           = OBJECT_END + 0x7D, // Size: 1, Flags: UF_FLAG_PRIVATE, UF_FLAG_OWNER
    UNIT_FIELD_RANGED_ATTACK_POWER_MOD_POS                   = OBJECT_END + 0x7E, // Size: 1, Flags: UF_FLAG_PRIVATE, UF_FLAG_OWNER
    UNIT_FIELD_RANGED_ATTACK_POWER_MOD_NEG                   = OBJECT_END + 0x7F, // Size: 1, Flags: UF_FLAG_PRIVATE, UF_FLAG_OWNER
    UNIT_FIELD_RANGED_ATTACK_POWER_MULTIPLIER                = OBJECT_END + 0x80, // Size: 1, Flags: UF_FLAG_PRIVATE, UF_FLAG_OWNER
    UNIT_FIELD_MINRANGEDDAMAGE                               = OBJECT_END + 0x81, // Size: 1, Flags: UF_FLAG_PRIVATE, UF_FLAG_OWNER
    UNIT_FIELD_MAXRANGEDDAMAGE                               = OBJECT_END + 0x82, // Size: 1, Flags: UF_FLAG_PRIVATE, UF_FLAG_OWNER
    UNIT_FIELD_POWER_COST_MODIFIER                           = OBJECT_END + 0x83, // Size: 7, Flags: UF_FLAG_PRIVATE, UF_FLAG_OWNER
    UNIT_FIELD_POWER_COST_MULTIPLIER                         = OBJECT_END + 0x8A, // Size: 7, Flags: UF_FLAG_PRIVATE, UF_FLAG_OWNER
    UNIT_FIELD_MAX_HEALTH_MODIFIER                           = OBJECT_END + 0x91, // Size: 1, Flags: UF_FLAG_PRIVATE, UF_FLAG_OWNER
    UNIT_FIELD_HOVERHEIGHT                                   = OBJECT_END + 0x92, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_MIN_ITEM_LEVEL                                = OBJECT_END + 0x93, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_MAXITEMLEVEL                                  = OBJECT_END + 0x94, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_WILD_BATTLE_PET_LEVEL                         = OBJECT_END + 0x95, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_BATTLE_PET_COMPANION_NAME_TIMESTAMP           = OBJECT_END + 0x96, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_FIELD_INTERACT_SPELL_ID                             = OBJECT_END + 0x97, // Size: 1, Flags: UF_FLAG_PUBLIC
    UNIT_END                                                 = OBJECT_END + 0x98
};

enum EPlayerFields
{
    PLAYER_DUEL_ARBITER                                      = UNIT_END + 0x000, // Size: 2, Flags: UF_FLAG_PUBLIC
    PLAYER_FLAGS                                             = UNIT_END + 0x002, // Size: 1, Flags: UF_FLAG_PUBLIC
    PLAYER_GUILDRANK                                         = UNIT_END + 0x003, // Size: 1, Flags: UF_FLAG_PUBLIC
    PLAYER_FIELD_GUILD_DELETE_DATE                           = UNIT_END + 0x004, // Size: 1, Flags: UF_FLAG_PUBLIC
    PLAYER_GUILDLEVEL                                        = UNIT_END + 0x005, // Size: 1, Flags: UF_FLAG_PUBLIC
    PLAYER_BYTES                                             = UNIT_END + 0x006, // Size: 1, Flags: UF_FLAG_PUBLIC
    PLAYER_BYTES_2                                           = UNIT_END + 0x007, // Size: 1, Flags: UF_FLAG_PUBLIC
    PLAYER_BYTES_3                                           = UNIT_END + 0x008, // Size: 1, Flags: UF_FLAG_PUBLIC
    PLAYER_DUEL_TEAM                                         = UNIT_END + 0x009, // Size: 1, Flags: UF_FLAG_PUBLIC
    PLAYER_GUILD_TIMESTAMP                                   = UNIT_END + 0x00A, // Size: 1, Flags: UF_FLAG_PUBLIC
    PLAYER_QUEST_LOG_1_1                                     = UNIT_END + 0x00B, // Size: 750, Flags: UF_FLAG_PARTY
    //PLAYER_VISIBLE_ITEMS UNIT_END + 0x2F9, // Size: 38, Flags: UF_FLAG_PUBLIC
    PLAYER_VISIBLE_ITEM_1_ENTRYID                            = UNIT_END + 0x2F9,
    PLAYER_VISIBLE_ITEM_1_ENCHANTMENT                        = UNIT_END + 0x2FA,
    PLAYER_VISIBLE_ITEM_2_ENTRYID                            = UNIT_END + 0x2FB,
    PLAYER_VISIBLE_ITEM_2_ENCHANTMENT                        = UNIT_END + 0x2FC,
    PLAYER_VISIBLE_ITEM_3_ENTRYID                            = UNIT_END + 0x2FD,
    PLAYER_VISIBLE_ITEM_3_ENCHANTMENT                        = UNIT_END + 0x2FE,
    PLAYER_VISIBLE_ITEM_4_ENTRYID                            = UNIT_END + 0x2FF,
    PLAYER_VISIBLE_ITEM_4_ENCHANTMENT                        = UNIT_END + 0x300,
    PLAYER_VISIBLE_ITEM_5_ENTRYID                            = UNIT_END + 0x301,
    PLAYER_VISIBLE_ITEM_5_ENCHANTMENT                        = UNIT_END + 0x302,
    PLAYER_VISIBLE_ITEM_6_ENTRYID                            = UNIT_END + 0x303,
    PLAYER_VISIBLE_ITEM_6_ENCHANTMENT                        = UNIT_END + 0x304,
    PLAYER_VISIBLE_ITEM_7_ENTRYID                            = UNIT_END + 0x305,
    PLAYER_VISIBLE_ITEM_7_ENCHANTMENT                        = UNIT_END + 0x306,
    PLAYER_VISIBLE_ITEM_8_ENTRYID                            = UNIT_END + 0x307,
    PLAYER_VISIBLE_ITEM_8_ENCHANTMENT                        = UNIT_END + 0x308,
    PLAYER_VISIBLE_ITEM_9_ENTRYID                            = UNIT_END + 0x309,
    PLAYER_VISIBLE_ITEM_9_ENCHANTMENT                        = UNIT_END + 0x30A,
    PLAYER_VISIBLE_ITEM_10_ENTRYID                           = UNIT_END + 0x30B,
    PLAYER_VISIBLE_ITEM_10_ENCHANTMENT                       = UNIT_END + 0x30C,
    PLAYER_VISIBLE_ITEM_11_ENTRYID                           = UNIT_END + 0x30D,
    PLAYER_VISIBLE_ITEM_11_ENCHANTMENT                       = UNIT_END + 0x30E,
    PLAYER_VISIBLE_ITEM_12_ENTRYID                           = UNIT_END + 0x30F,
    PLAYER_VISIBLE_ITEM_12_ENCHANTMENT                       = UNIT_END + 0x310,
    PLAYER_VISIBLE_ITEM_13_ENTRYID                           = UNIT_END + 0x311,
    PLAYER_VISIBLE_ITEM_13_ENCHANTMENT                       = UNIT_END + 0x312,
    PLAYER_VISIBLE_ITEM_14_ENTRYID                           = UNIT_END + 0x313,
    PLAYER_VISIBLE_ITEM_14_ENCHANTMENT                       = UNIT_END + 0x314,
    PLAYER_VISIBLE_ITEM_15_ENTRYID                           = UNIT_END + 0x315,
    PLAYER_VISIBLE_ITEM_15_ENCHANTMENT                       = UNIT_END + 0x316,
    PLAYER_VISIBLE_ITEM_16_ENTRYID                           = UNIT_END + 0x317,
    PLAYER_VISIBLE_ITEM_16_ENCHANTMENT                       = UNIT_END + 0x318,
    PLAYER_VISIBLE_ITEM_17_ENTRYID                           = UNIT_END + 0x319,
    PLAYER_VISIBLE_ITEM_17_ENCHANTMENT                       = UNIT_END + 0x31A,
    PLAYER_VISIBLE_ITEM_18_ENTRYID                           = UNIT_END + 0x31B,
    PLAYER_VISIBLE_ITEM_18_ENCHANTMENT                       = UNIT_END + 0x31C,
    PLAYER_VISIBLE_ITEM_19_ENTRYID                           = UNIT_END + 0x31D,
    PLAYER_VISIBLE_ITEM_19_ENCHANTMENT                       = UNIT_END + 0x31E,
    PLAYER_CHOSEN_TITLE                                      = UNIT_END + 0x31F, // Size: 1, Flags: UF_FLAG_PUBLIC
    PLAYER_FAKE_INEBRIATION                                  = UNIT_END + 0x320, // Size: 1, Flags: UF_FLAG_PUBLIC
    PLAYER_FIELD_VIRTUAL_PLAYER_REALM                        = UNIT_END + 0x321, // Size: 1, Flags: UF_FLAG_PUBLIC
    PLAYER_CURRENT_SPEC_ID                                   = UNIT_END + 0x322, // Size: 1, Flags: UF_FLAG_PUBLIC
    PLAYER_FIELD_TAXI_MOUNT_ANIM_KIT_ID                      = UNIT_END + 0x323, // Size: 1, Flags: UF_FLAG_PUBLIC
    PLAYER_FIELD_CURRENT_BATTLE_PET_BREED_QUALITY            = UNIT_END + 0x324, // Size: 1, Flags: UF_FLAG_PUBLIC
    PLAYER_FIELD_INV_SLOT_HEAD                               = UNIT_END + 0x325, // Size: 46, Flags: UF_FLAG_PRIVATE
    PLAYER_PACK_SLOTS                                        = UNIT_END + 0x353, // Size: 32, Flags: UF_FLAG_PRIVATE
    PLAYER_BANK_SLOTS                                        = UNIT_END + 0x373, // Size: 56, Flags: UF_FLAG_PRIVATE
    PLAYER_BANKBAG_SLOTS                                     = UNIT_END + 0x3AB, // Size: 14  Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_VENDORBUYBACK_SLOT_1                        = UNIT_END + 0x3B9, // Size: 24, Flags: UF_FLAG_PRIVATE
    PLAYER_FARSIGHT                                          = UNIT_END + 0x3D1, // Size: 2, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_KNOWN_TITLES                                = UNIT_END + 0x3D3, // Size: 10, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_COINAGE                                     = UNIT_END + 0x3DD, // Size: 2, Flags: UF_FLAG_PRIVATE
    PLAYER_XP                                                = UNIT_END + 0x3DF, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_NEXT_LEVEL_XP                                     = UNIT_END + 0x3E0, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_SKILL_LINEID_0                                    = UNIT_END + 0x03E1, // Size: 64, Flags: UF_FLAG_PRIVATE
    PLAYER_SKILL_STEP_0                                      = UNIT_END + 0x0421, // Size: 64, Flags: UF_FLAG_PRIVATE
    PLAYER_SKILL_RANK_0                                      = UNIT_END + 0x0461, // Size: 64, Flags: UF_FLAG_PRIVATE
    PLAYER_SKILL_MODIFIER_0                                  = UNIT_END + 0x04A1, // Size: 64, Flags: UF_FLAG_PRIVATE
    PLAYER_SKILL_MAX_RANK_0                                  = UNIT_END + 0x04E1, // Size: 64, Flags: UF_FLAG_PRIVATE
    PLAYER_SKILL_TALENT_0                                    = UNIT_END + 0x0521, // Size: 64, Flags: UF_FLAG_PRIVATE
    PLAYER_SKILL_UNKNOWN                                     = UNIT_END + 0x056F, // Size: 64, Flags: UF_FLAG_PRIVATE
    PLAYER_CHARACTER_POINTS                                  = UNIT_END + 0x5A1, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_MAX_TALENT_TIERS                                  = UNIT_END + 0x5A2, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_TRACK_CREATURES                                   = UNIT_END + 0x5A3, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_TRACK_RESOURCES                                   = UNIT_END + 0x5A4, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_EXPERTISE                                         = UNIT_END + 0x5A5, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_OFFHAND_EXPERTISE                                 = UNIT_END + 0x5A6, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_RANGED_EXPERTISE                                  = UNIT_END + 0x5A7, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_COMBAT_RATING_EXPERTISE                     = UNIT_END + 0x5A8, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_BLOCK_PERCENTAGE                                  = UNIT_END + 0x5A9, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_DODGE_PERCENTAGE                                  = UNIT_END + 0x5AA, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_PARRY_PERCENTAGE                                  = UNIT_END + 0x5AB, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_CRIT_PERCENTAGE                                   = UNIT_END + 0x5AC, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_RANGED_CRIT_PERCENTAGE                            = UNIT_END + 0x5AD, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_OFFHAND_CRIT_PERCENTAGE                           = UNIT_END + 0x5AE, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_SPELL_CRIT_PERCENTAGE1                            = UNIT_END + 0x5AF, // Size: 7, Flags: UF_FLAG_PRIVATE
    PLAYER_SHIELD_BLOCK                                      = UNIT_END + 0x5B6, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_SHIELD_BLOCK_CRIT_PERCENTAGE                = UNIT_END + 0x5B7, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_MASTERY                                           = UNIT_END + 0x5B8, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_PVP_POWER_DAMAGE                            = UNIT_END + 0x5B9, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_PVP_POWER_HEALING                           = UNIT_END + 0x5BA, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_EXPLORED_ZONES_1                                  = UNIT_END + 0x5BB, // Size: 200, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_REST_STATE_BONUS_POOL                       = UNIT_END + 0x683, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_MOD_DAMAGE_DONE_POS                         = UNIT_END + 0x684, // Size: 7, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_MOD_DAMAGE_DONE_NEG                         = UNIT_END + 0x68B, // Size: 7, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_MOD_DAMAGE_DONE_PCT                         = UNIT_END + 0x692, // Size: 7, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_MOD_HEALING_DONE_POS                        = UNIT_END + 0x699, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_MOD_HEALING_PCT                             = UNIT_END + 0x69A, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_MOD_HEALING_DONE_PCT                        = UNIT_END + 0x69B, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_MOD_PERIODIC_HEALING_DONE_PERCENT           = UNIT_END + 0x69C, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_WEAPON_DMG_MULTIPLIERS                      = UNIT_END + 0x69D, // Size: 3, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_MOD_SPELL_POWER_PCT                         = UNIT_END + 0x6A0, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_MOD_RESILIENCE_PCT                          = UNIT_END + 0x6A1, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_OVERRIDE_SPELL_POWER_BY_AP_PCT              = UNIT_END + 0x6A2, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_OVERRIDE_AP_BY_SPELL_POWER_PCT              = UNIT_END + 0x6A3, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_MOD_TARGET_RESISTANCE                       = UNIT_END + 0x6A4, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_MOD_TARGET_PHYSICAL_RESISTANCE              = UNIT_END + 0x6A5, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_BYTES                                       = UNIT_END + 0x6A6, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_SELF_RES_SPELL                                    = UNIT_END + 0x6A7, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_PVP_MEDALS                                  = UNIT_END + 0x6A8, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_BUYBACK_PRICE_1                             = UNIT_END + 0x6A9, // Size: 12, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_BUYBACK_TIMESTAMP_1                         = UNIT_END + 0x6B5, // Size: 12, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_KILLS                                       = UNIT_END + 0x6C1, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_LIFETIME_HONORABLE_KILLS                    = UNIT_END + 0x6C2, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_WATCHED_FACTION_INDEX                       = UNIT_END + 0x6C3, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_COMBAT_RATING_1                             = UNIT_END + 0x6C4, // Size: 27, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_PVP_INFO                                    = UNIT_END + 0x6DF, // Size: 24, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_MAX_LEVEL                                   = UNIT_END + 0x6F7, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_RUNE_REGEN_1                                      = UNIT_END + 0x6F8, // Size: 4, Flags: UF_FLAG_PRIVATE
    PLAYER_NO_REAGENT_COST_1                                 = UNIT_END + 0x6FC, // Size: 4, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_GLYPH_SLOTS_1                               = UNIT_END + 0x700, // Size: 6, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_GLYPHS_1                                    = UNIT_END + 0x706, // Size: 6, Flags: UF_FLAG_PRIVATE
    PLAYER_GLYPHS_ENABLED                                    = UNIT_END + 0x70C, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_PET_SPELL_POWER                                   = UNIT_END + 0x70D, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_RESEARCHING                                 = UNIT_END + 0x70E, // Size: 8, Flags: UF_FLAG_PRIVATE
    PLAYER_PROFESSION_SKILL_LINE_1                           = UNIT_END + 0x716, // Size: 2, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_UI_HIT_MODIFIER                             = UNIT_END + 0x718, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_UI_SPELL_HIT_MODIFIER                       = UNIT_END + 0x719, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_HOME_REALM_TIME_OFFSET                      = UNIT_END + 0x71A, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_MOD_PET_HASTE                               = UNIT_END + 0x71B, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_SUMMONED_BATTLE_PET_GUID                    = UNIT_END + 0x71C, // Size: 2, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_BYTES2                                      = UNIT_END + 0x71E, // Size: 1, Flags: UF_FLAG_PRIVATE, UF_FLAG_URGENT_SELF_ONLY
    PLAYER_FIELD_LFG_BONUS_FACTION_ID                        = UNIT_END + 0x71F, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_LOOT_SPEC_ID                                = UNIT_END + 0x720, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_FIELD_OVERRIDE_ZONE_PVP_TYPE                      = UNIT_END + 0x721, // Size: 1, Flags: UF_FLAG_PRIVATE, UF_FLAG_URGENT_SELF_ONLY
    PLAYER_FIELD_ITEM_LEVEL_DELTA                            = UNIT_END + 0x722, // Size: 1, Flags: UF_FLAG_PRIVATE
    PLAYER_END                                               = UNIT_END + 0x723
};

enum EGameObjectFields
{
    OBJECT_FIELD_CREATED_BY                            = OBJECT_END + 0x0, // Size: 2, Flags: UF_FLAG_PUBLIC
    GAMEOBJECT_DISPLAYID                               = OBJECT_END + 0x2, // Size: 1, Flags: UF_FLAG_PUBLIC
    GAMEOBJECT_FLAGS                                   = OBJECT_END + 0x3, // Size: 1, Flags: UF_FLAG_PUBLIC, UF_FLAG_URGENT
    GAMEOBJECT_PARENTROTATION                          = OBJECT_END + 0x4, // Size: 4, Flags: UF_FLAG_PUBLIC
    GAMEOBJECT_FACTION                                 = OBJECT_END + 0x8, // Size: 1, Flags: UF_FLAG_PUBLIC
    GAMEOBJECT_LEVEL                                   = OBJECT_END + 0x9, // Size: 1, Flags: UF_FLAG_PUBLIC
    GAMEOBJECT_BYTES_1                                 = OBJECT_END + 0xA, // Size: 1, Flags: UF_FLAG_PUBLIC, UF_FLAG_URGENT
    GAMEOBJECT_FIELD_ANIM_PROGRESS                     = OBJECT_END + 0xB, // Size: 1, Flags: UF_FLAG_PUBLIC, UF_FLAG_URGENT
    GAMEOBJECT_END                                     = OBJECT_END + 0xC
};

enum EDynamicObjectFields
{
    DYNAMICOBJECT_CASTER                               = OBJECT_END + 0x0, // Size: 2, Flags: UF_FLAG_PUBLIC
    DYNAMICOBJECT_BYTES                                = OBJECT_END + 0x2, // Size: 1, Flags: UF_FLAG_VIEWER_DEPENDENT
    DYNAMICOBJECT_SPELLID                              = OBJECT_END + 0x3, // Size: 1, Flags: UF_FLAG_PUBLIC
    DYNAMICOBJECT_RADIUS                               = OBJECT_END + 0x4, // Size: 1, Flags: UF_FLAG_PUBLIC
    DYNAMICOBJECT_CASTTIME                             = OBJECT_END + 0x5, // Size: 1, Flags: UF_FLAG_PUBLIC
    DYNAMICOBJECT_END                                  = OBJECT_END + 0x6
};

enum ECorpseFields
{
    CORPSE_FIELD_OWNER                                       = OBJECT_END + 0x00, // Size: 2, Flags: UF_FLAG_PUBLIC
    CORPSE_FIELD_PARTY                                       = OBJECT_END + 0x02, // Size: 2, Flags: UF_FLAG_PUBLIC
    CORPSE_FIELD_DISPLAY_ID                                  = OBJECT_END + 0x04, // Size: 1, Flags: UF_FLAG_PUBLIC
    CORPSE_FIELD_ITEM                                        = OBJECT_END + 0x05, // Size: 19, Flags: UF_FLAG_PUBLIC
    CORPSE_FIELD_BYTES_1                                     = OBJECT_END + 0x18, // Size: 1, Flags: UF_FLAG_PUBLIC
    CORPSE_FIELD_BYTES_2                                     = OBJECT_END + 0x19, // Size: 1, Flags: UF_FLAG_PUBLIC
    CORPSE_FIELD_FLAGS                                       = OBJECT_END + 0x1A, // Size: 1, Flags: UF_FLAG_PUBLIC
    CORPSE_FIELD_DYNAMIC_FLAGS                               = OBJECT_END + 0x1B, // Size: 1, Flags: UF_FLAG_VIEWER_DEPENDENT
    CORPSE_END                                               = OBJECT_END + 0x1C
};

enum EAreaTriggerFields
{
    AREATRIGGER_CASTER                                 = OBJECT_END + 0x0, // Size: 2, Flags: UF_FLAG_PUBLIC
    AREATRIGGER_DURATION                               = OBJECT_END + 0x2, // Size: 1, Flags: UF_FLAG_PUBLIC
    AREATRIGGER_SPELL_ID                               = OBJECT_END + 0x3, // Size: 1, Flags: UF_FLAG_PUBLIC
    AREATRIGGER_SPELL_VISUAL_ID                        = OBJECT_END + 0x4, // Size: 1, Flags: UF_FLAG_VIEWER_DEPENDENT
    AREATRIGGER_EXPLICIT_SCALE                         = OBJECT_END + 0x5, // Size: 1, Flags: UF_FLAG_PUBLIC, UF_FLAG_URGENT
    AREATRIGGER_END                                    = OBJECT_END + 0x6
};

enum ESceneObjectFields
{
    SCENEOBJECT_FIELD_SCRIPT_PACKAGE_ID                      = OBJECT_END + 0x0, // Size: 1, Flags: UF_FLAG_PUBLIC
    SCENEOBJECT_FIELD_RND_SEED_VAL                           = OBJECT_END + 0x1, // Size: 1, Flags: UF_FLAG_PUBLIC
    SCENEOBJECT_FIELD_CREATED_BY                             = OBJECT_END + 0x2, // Size: 2, Flags: UF_FLAG_PUBLIC
    SCENEOBJECT_FIELD_SCENE_TYPE                             = OBJECT_END + 0x4, // Size: 1, Flags: UF_FLAG_PUBLIC
    SCENEOBJECT_FIELD_END                                    = OBJECT_END + 0x5
};

enum EObjectDynamicFields
{
    OBJECT_DYNAMIC_END = 0x0,
};

enum EUnitDynamicFields
{
    UNIT_DYNAMIC_PASSIVE_SPELLS = OBJECT_DYNAMIC_END + 0x0, // Size: 0x1
    UNIT_DYNAMIC_WORLD_EFFECTS = OBJECT_DYNAMIC_END + 0x1, // Size: 0x1
    UNIT_DYNAMIC_END = OBJECT_DYNAMIC_END + 0x2,
};

enum EPlayerDynamicFields
{
    PLAYER_DYNAMIC_RESEARCH_SITE = UNIT_DYNAMIC_END + 0x0, // Size: 0x1
    PLAYER_DYNAMIC_RESEARCH_SITE_PROGRESS = UNIT_DYNAMIC_END + 0x1, // Size: 0x1
    PLAYER_DYNAMIC_DAILY_QUESTS = UNIT_DYNAMIC_END + 0x2, // Size: 0x1
    PLAYER_DYNAMIC_END = UNIT_DYNAMIC_END + 0x3
};

#endif // _UPDATEFIELDS_H
