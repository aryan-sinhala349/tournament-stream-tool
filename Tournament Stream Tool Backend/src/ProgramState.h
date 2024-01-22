#pragma once

#include <cstdint>
#include <list>

struct ProgramState
{
	struct
	{
		const char* TournamentName;
		const char* EventName;
	} TournamentInfo;

	struct
	{
		const char* RoundName;

		struct PlayerInfo
		{
			const char* Sponsor;
			const char* Tag;
		};

		struct TeamInfo
		{
			const char* TeamName;
			uint8_t Score;
			std::list<PlayerInfo> Players;
		};

		TeamInfo Team1;
		TeamInfo Team2;

	} SetInfo;
};