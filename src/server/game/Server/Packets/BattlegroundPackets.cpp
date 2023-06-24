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

#include "BattlegroundPackets.h"

WorldPacket const* WorldPackets::Battleground::SeasonInfo::Write()
{
    _worldPacket << uint32(CurrentSeason);
    _worldPacket << uint32(PreviousSeason);

    return &_worldPacket;
}

void WorldPackets::Battleground::AreaSpiritHealerQuery::Read()
{
    _worldPacket >> HealerGuid;
}

void WorldPackets::Battleground::AreaSpiritHealerQueue::Read()
{
    _worldPacket >> HealerGuid;
}

WorldPacket const* WorldPackets::Battleground::AreaSpiritHealerTime::Write()
{
    _worldPacket << HealerGuid;
    _worldPacket << int32(TimeLeft);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Battleground::PVPMatchStatistics::RatingData const& ratingData)
{
    data.append(ratingData.Prematch, 2);
    data.append(ratingData.Postmatch, 2);
    data.append(ratingData.PrematchMMR, 2);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Battleground::PVPMatchStatistics::HonorData const& honorData)
{
    data << uint32(honorData.HonorKills);
    data << uint32(honorData.Deaths);
    data << uint32(honorData.ContributionPoints);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Battleground::PVPMatchStatistics::PVPMatchPlayerPVPStat const& pvpStat)
{
    data << int32(pvpStat.PvpStatID);
    data << int32(pvpStat.PvpStatValue);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Battleground::PVPMatchStatistics::PVPMatchPlayerStatistics const& playerData)
{
    data << playerData.PlayerGUID;
    data << uint32(playerData.Kills);
    data << uint32(playerData.DamageDone);
    data << uint32(playerData.HealingDone);
    data << uint32(playerData.Stats.size());
    data << int32(playerData.PrimaryTalentTree);
    data << int32(playerData.PrimaryTalentTreeNameIndex);
    data << int32(playerData.Race);
    data << uint32(playerData.Prestige);
    if (!playerData.Stats.empty())
        data.append(playerData.Stats.data(), playerData.Stats.size());

    data.WriteBit(playerData.Faction != 0);
    data.WriteBit(playerData.IsInWorld);
    data.WriteBit(playerData.Honor.has_value());
    data.WriteBit(playerData.PreMatchRating.has_value());
    data.WriteBit(playerData.RatingChange.has_value());
    data.WriteBit(playerData.PreMatchMMR.has_value());
    data.WriteBit(playerData.MmrChange.has_value());
    data.FlushBits();

    if (playerData.Honor)
        data << *playerData.Honor;

    if (playerData.PreMatchRating)
        data << uint32(*playerData.PreMatchRating);

    if (playerData.RatingChange)
        data << int32(*playerData.RatingChange);

    if (playerData.PreMatchMMR)
        data << uint32(*playerData.PreMatchMMR);

    if (playerData.MmrChange)
        data << int32(*playerData.MmrChange);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Battleground::PVPMatchStatistics const& pvpLogData)
{
    data.WriteBit(pvpLogData.Ratings.has_value());
    data << uint32(pvpLogData.Statistics.size());
    data.append(pvpLogData.PlayerCount.data(), pvpLogData.PlayerCount.size());

    if (pvpLogData.Ratings.has_value())
        data << *pvpLogData.Ratings;

    for (WorldPackets::Battleground::PVPMatchStatistics::PVPMatchPlayerStatistics const& player : pvpLogData.Statistics)
        data << player;

    return data;
}

WorldPacket const* WorldPackets::Battleground::PVPMatchStatisticsMessage::Write()
{
    _worldPacket.reserve(Data.Statistics.size() * sizeof(PVPMatchStatistics::PVPMatchPlayerStatistics) + sizeof(PVPMatchStatistics));

    _worldPacket << Data;

    return &_worldPacket;
}

void WorldPackets::Battleground::BattlemasterJoin::Read()
{
    _worldPacket >> QueueID;
    _worldPacket >> Roles;
    _worldPacket >> BlacklistMap[0] >> BlacklistMap[1];
    JoinAsGroup = _worldPacket.ReadBit();
}

void WorldPackets::Battleground::BattlemasterJoinArena::Read()
{
    _worldPacket >> TeamSizeIndex;
    _worldPacket >> Roles;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Battleground::BattlefieldStatusHeader const& header)
{
    data << header.Ticket;
    data << uint64(header.QueueID);
    data << uint8(header.RangeMin);
    data << uint8(header.RangeMax);
    data << uint8(header.TeamSize);
    data << uint32(header.InstanceID);
    data.WriteBit(header.RegisteredMatch);
    data.WriteBit(header.TournamentRules);
    data.FlushBits();
    return data;
}

WorldPacket const* WorldPackets::Battleground::BattlefieldStatusNone::Write()
{
    _worldPacket << Ticket;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Battleground::BattlefieldStatusNeedConfirmation::Write()
{
    _worldPacket << Hdr;
    _worldPacket << uint32(Mapid);
    _worldPacket << uint32(Timeout);
    _worldPacket << uint8(Role);
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Battleground::BattlefieldStatusActive::Write()
{
    _worldPacket << Hdr;
    _worldPacket << uint32(Mapid);
    _worldPacket << uint32(ShutdownTimer);
    _worldPacket << uint32(StartTimer);
    _worldPacket.WriteBit(ArenaFaction != 0);
    _worldPacket.WriteBit(LeftEarly);
    _worldPacket.FlushBits();
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Battleground::BattlefieldStatusQueued::Write()
{
    _worldPacket << Hdr;
    _worldPacket << uint32(AverageWaitTime);
    _worldPacket << uint32(WaitTime);
    _worldPacket.WriteBit(AsGroup);
    _worldPacket.WriteBit(EligibleForMatchmaking);
    _worldPacket.WriteBit(SuspendedQueue);
    _worldPacket.FlushBits();
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Battleground::BattlefieldStatusFailed::Write()
{
    _worldPacket << Ticket;
    _worldPacket << uint64(QueueID);
    _worldPacket << uint32(Reason);
    _worldPacket << ClientID;
    return &_worldPacket;
}

void WorldPackets::Battleground::BattlefieldPort::Read()
{
    _worldPacket >> Ticket;
    AcceptedInvite = _worldPacket.ReadBit();
}

void WorldPackets::Battleground::BattlefieldListRequest::Read()
{
    _worldPacket >> ListID;
}

WorldPacket const* WorldPackets::Battleground::BattlefieldList::Write()
{
    _worldPacket << BattlemasterGuid;
    _worldPacket << int32(BattlemasterListID);
    _worldPacket << uint8(MinLevel);
    _worldPacket << uint8(MaxLevel);
    _worldPacket << uint32(Battlefields.size());
    if (!Battlefields.empty())
        _worldPacket.append(Battlefields.data(), Battlefields.size());

    _worldPacket.WriteBit(PvpAnywhere);
    _worldPacket.WriteBit(HasRandomWinToday);
    _worldPacket.FlushBits();
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Battleground::PVPOptionsEnabled::Write()
{
    _worldPacket.WriteBit(RatedBattlegrounds);
    _worldPacket.WriteBit(PugBattlegrounds);
    _worldPacket.WriteBit(WargameBattlegrounds);
    _worldPacket.WriteBit(WargameArenas);
    _worldPacket.WriteBit(RatedArenas);
    _worldPacket.WriteBit(ArenaSkirmish);
    _worldPacket.FlushBits();
    return &_worldPacket;
}

void WorldPackets::Battleground::ReportPvPPlayerAFK::Read()
{
    _worldPacket >> Offender;
}

WorldPacket const* WorldPackets::Battleground::ReportPvPPlayerAFKResult::Write()
{
    _worldPacket << Offender;
    _worldPacket << uint8(Result);
    _worldPacket << uint8(NumBlackMarksOnOffender);
    _worldPacket << uint8(NumPlayersIHaveReported);
    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Battleground::BattlegroundPlayerPosition const& playerPosition)
{
    data << playerPosition.Guid;
    data << playerPosition.Pos;
    data << int8(playerPosition.IconID);
    data << int8(playerPosition.ArenaSlot);
    return data;
}

WorldPacket const* WorldPackets::Battleground::BattlegroundPlayerPositions::Write()
{
    _worldPacket << uint32(FlagCarriers.size());
    for (BattlegroundPlayerPosition const& pos : FlagCarriers)
        _worldPacket << pos;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Battleground::BattlegroundPlayerJoined::Write()
{
    _worldPacket << Guid;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Battleground::BattlegroundPlayerLeft::Write()
{
    _worldPacket << Guid;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Battleground::DestroyArenaUnit::Write()
{
    _worldPacket << Guid;
    return &_worldPacket;
}
