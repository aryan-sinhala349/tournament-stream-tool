#pragma once

#include <cstdint>
#include <vector>

struct ProgramState
{
	struct
	{
		const char* TournamentName = "";
		const char* EventName = "";
	} TournamentInfo;

	struct
	{
		const char* RoundName = "";

		struct PlayerInfo
		{
			const char* Sponsor = "";
			const char* Tag = "";
		};

		struct TeamInfo
		{
			const char* TeamName = "";
			uint8_t Score = 0;
			bool Losers = false;
			std::vector<PlayerInfo> Players;
		};

		TeamInfo Teams[2];

	} SetInfo;
};

extern ProgramState State;
void SaveProgramState();