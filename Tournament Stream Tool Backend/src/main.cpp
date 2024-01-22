#include "ProgramState.h"

#include <iostream>

int main(int argc, char** argv)
{
    std::cout << std::boolalpha;

    LoadProgramState();

    std::cout << "Tournament Info:\n";
    std::cout << "\tTournament Name: " << State.TournamentInfo.TournamentName << "\n";
    std::cout << "\tEvent Name: " << State.TournamentInfo.EventName << "\n";
    
    std::cout << "Set Info:\n";
    std::cout << "\tRound Name: " << State.SetInfo.RoundName << "\n";
    std::cout << "\tTeams:\n";
    
    for (uint8_t i = 0; i < 2; i++)
    {
        std::cout << "\t\tTeam " << i + 1 << ":\n";
        std::cout << "\t\t\tTeam Name: " << State.SetInfo.Teams[i].TeamName << "\n";
        std::cout << "\t\t\tScore: " << State.SetInfo.Teams[i].Score << "\n";
        std::cout << "\t\t\tLosers: " << State.SetInfo.Teams[i].Losers << "\n";
        std::cout << "\t\t\tPlayers:\n";

        for (uint32_t j = 0; j < State.SetInfo.Teams[i].Players.size(); j++)
        {
            std::cout << "\t\t\t\tPlayer " << j + 1 << ":\n";
            std::cout << "\t\t\t\t\tSponsor: " << State.SetInfo.Teams[i].Players[j].Sponsor << "\n";
            std::cout << "\t\t\t\t\tTag: " << State.SetInfo.Teams[i].Players[j].Tag << "\n";
        }
    }

    return 0;
}