#include "ProgramState.h"

int main(int argc, char** argv)
{
    State.TournamentInfo.TournamentName = "Tournament Name";
    State.TournamentInfo.EventName = "Event Name";

    State.SetInfo.RoundName = "Grands";

    State.SetInfo.Teams[0].TeamName = "Team 1";
    State.SetInfo.Teams[0].Score = 0;
    State.SetInfo.Teams[0].Losers = false;
    State.SetInfo.Teams[0].Players.resize(2);
    State.SetInfo.Teams[0].Players[0].Sponsor = "Team 1";
    State.SetInfo.Teams[0].Players[0].Tag = "Player 1";
    State.SetInfo.Teams[0].Players[1].Sponsor = "Team 1";
    State.SetInfo.Teams[0].Players[1].Tag = "Player 2";

    State.SetInfo.Teams[1].TeamName = "Team 2";
    State.SetInfo.Teams[1].Score = 0;
    State.SetInfo.Teams[1].Losers = false;
    State.SetInfo.Teams[1].Players.resize(2);
    State.SetInfo.Teams[1].Players[0].Sponsor = "Team 2";
    State.SetInfo.Teams[1].Players[0].Tag = "Player 3";
    State.SetInfo.Teams[1].Players[1].Sponsor = "Team 2";
    State.SetInfo.Teams[1].Players[1].Tag = "Player 4";

    SaveProgramState();

    return 0;
}