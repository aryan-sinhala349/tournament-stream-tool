#pragma once

#include <string>
#include <vector>

struct ProgramState
{
	struct
	{
		std::string TournamentName = "";
		std::string EventName = "";
	} TournamentInfo;

	struct
	{
		std::string RoundName = "";

		struct PlayerInfo
		{
			std::string Sponsor = "";
			std::string Tag = "";
		};

		struct TeamInfo
		{
			std::string TeamName = "";
			int Score = 0;
			bool Losers = false;
			std::vector<PlayerInfo> Players;
		};

		TeamInfo Teams[2];

	} SetInfo;
};

extern ProgramState State;
void LoadProgramState();
void SaveProgramState();