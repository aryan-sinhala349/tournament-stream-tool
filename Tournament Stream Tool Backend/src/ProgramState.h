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

		struct TeamInfo
		{
			struct PlayerInfo
			{
				std::string Sponsor = "";
				std::string Tag = "";
			};

			std::string TeamName = "";
			int Score = 0;
			bool Losers = false;
			std::vector<PlayerInfo> Players;
		};

		TeamInfo Teams[2];

	} SetInfo;
};

#ifdef __cplusplus
extern "C"
{
#endif

	extern __declspec(dllexport) ProgramState State;
	void __declspec(dllexport) LoadProgramState();
	void __declspec(dllexport) SaveProgramState();

	__declspec(dllexport) const char* ProgramState_GetTournamentName();
	void __declspec(dllexport) ProgramState_SetTournamentName(const char* tournamentName);

	__declspec(dllexport) const char* ProgramState_GetEventName();
	void __declspec(dllexport) ProgramState_SetEventName(const char* eventName);

	__declspec(dllexport) const char* ProgramState_GetRoundName();
	void __declspec(dllexport) ProgramState_SetRoundName(const char* roundName);

	__declspec(dllexport) const char* ProgramState_GetTeamName(int teamID);
	void __declspec(dllexport) ProgramState_SetTeamName(int teamID, const char* teamName);

	__declspec(dllexport) int ProgramState_GetTeamScore(int teamID);
	void __declspec(dllexport) ProgramState_SetTeamScore(int teamID, int score);

	__declspec(dllexport) bool ProgramState_IsTeamLosers(int teamID);
	void __declspec(dllexport) ProgramState_SetTeamLosers(int teamID, bool losers);

#ifdef __cplusplus
}
#endif