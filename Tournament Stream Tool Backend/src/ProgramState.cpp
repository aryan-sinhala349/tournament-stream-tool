#include "ProgramState.h"

#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/prettywriter.h"

#include <iostream>

ProgramState State;

void LoadProgramState()
{
	//Load the JSON object from disk
	FILE* fp = fopen("program_state.json", "rb");

	char readBuffer[0xFFFF + 1];
	rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));

	rapidjson::Document document;
	document.ParseStream(is);

	fclose(fp);

	//Parse the tournament info object
	{
		rapidjson::GenericObject tournamentInfo = document["tournament_info"].GetObject();

		//Get the tournament name and event name
		State.TournamentInfo.TournamentName = std::string(tournamentInfo["tournament_name"].GetString(), tournamentInfo["tournament_name"].GetStringLength());
		State.TournamentInfo.EventName = std::string(tournamentInfo["event_name"].GetString(), tournamentInfo["event_name"].GetStringLength());
	}

	//Parse the set info object
	{
		rapidjson::GenericObject setInfo = document["set_info"].GetObject();

		//Get the round name
		State.SetInfo.RoundName = std::string(setInfo["round_name"].GetString(), setInfo["round_name"].GetStringLength());

		//Get the teams array
		rapidjson::GenericArray teams = setInfo["teams"].GetArray();
		
		//Iterate through the teams
		for (uint8_t i = 0; i < 2; i++)
		{
			rapidjson::GenericObject team = teams[i].GetObject();

			//Get the team name
			State.SetInfo.Teams[i].TeamName = std::string(team["team_name"].GetString(), team["team_name"].GetStringLength());

			//Get the team score
			State.SetInfo.Teams[i].Score = team["score"].GetInt();

			//Get the team losers state
			State.SetInfo.Teams[i].Losers = team["losers"].GetBool();

			//Get the players array
			rapidjson::GenericArray players = team["players"].GetArray();
			State.SetInfo.Teams[i].Players.resize(players.Size());

			//Iterate through the players
			for (uint32_t j = 0; j < players.Size(); j++)
			{
				rapidjson::GenericObject player = players[j].GetObject();

				//Get the player sponsor
				State.SetInfo.Teams[i].Players[j].Sponsor = std::string(player["sponsor"].GetString(), player["sponsor"].GetStringLength());

				//Get the player tag
				State.SetInfo.Teams[i].Players[j].Tag = std::string(player["tag"].GetString(), player["tag"].GetStringLength());
			}
		}
	}
}

void SaveProgramState()
{
	//Create the JSON object
	rapidjson::Document document;
	document.SetObject();

	//Create the tournament info object
	{
		rapidjson::Value tournamentInfoKey("tournament_info", document.GetAllocator());
		rapidjson::Value tournamentInfo;
		tournamentInfo.SetObject();

		//Set the tournament name
		{
			rapidjson::Value tournamentNameKey("tournament_name", document.GetAllocator());
			rapidjson::Value tournamentName(State.TournamentInfo.TournamentName.c_str(), document.GetAllocator());

			tournamentInfo.AddMember(tournamentNameKey, tournamentName, document.GetAllocator());
		}

		//Set the event name
		{
			rapidjson::Value eventNameKey("event_name", document.GetAllocator());
			rapidjson::Value eventName(State.TournamentInfo.EventName.c_str(), document.GetAllocator());

			tournamentInfo.AddMember(eventNameKey, eventName, document.GetAllocator());
		}

		document.AddMember(tournamentInfoKey, tournamentInfo, document.GetAllocator());
	}

	//Create the set info object
	{
		rapidjson::Value setInfoKey("set_info", document.GetAllocator());
		rapidjson::Value setInfo;
		setInfo.SetObject();

		//Set the round name
		{
			rapidjson::Value roundNameKey("round_name", document.GetAllocator());
			rapidjson::Value roundName(State.SetInfo.RoundName.c_str(), document.GetAllocator());

			setInfo.AddMember(roundNameKey, roundName, document.GetAllocator());
		}

		//Set the teams info
		{
			rapidjson::Value teamsKey("teams", document.GetAllocator());
			rapidjson::Value teams;
			teams.SetArray();

			//Iterate through each team
			for (uint8_t i = 0; i < 2; i++)
			{
				rapidjson::Value team;
				team.SetObject();

				//Save the team's name, score, and losers state
				rapidjson::Value teamNameKey("team_name", document.GetAllocator());
				rapidjson::Value teamName(State.SetInfo.Teams[i].TeamName.c_str(), document.GetAllocator());

				rapidjson::Value scoreKey("score", document.GetAllocator());
				rapidjson::Value score(State.SetInfo.Teams[i].Score);

				rapidjson::Value losersKey("losers", document.GetAllocator());
				rapidjson::Value losers(State.SetInfo.Teams[i].Losers);
				
				rapidjson::Value playersKey("players", document.GetAllocator());
				rapidjson::Value players;
				players.SetArray();

				//Iterate through the team's players
				for (uint32_t j = 0; j < State.SetInfo.Teams[i].Players.size(); j++)
				{
					rapidjson::Value player;
					player.SetObject();

					//Save the player's sponsor and tag
					rapidjson::Value sponsorKey("sponsor", document.GetAllocator());
					rapidjson::Value sponsor(State.SetInfo.Teams[i].Players[j].Sponsor.c_str(), document.GetAllocator());
		
					rapidjson::Value tagKey("tag", document.GetAllocator());	
					rapidjson::Value tag(State.SetInfo.Teams[i].Players[j].Tag.c_str(), document.GetAllocator());

					player.AddMember(sponsorKey, sponsor, document.GetAllocator());
					player.AddMember(tagKey, tag, document.GetAllocator());

					players.PushBack(player, document.GetAllocator());
				}

				team.AddMember(teamNameKey, teamName, document.GetAllocator());
				team.AddMember(scoreKey, score, document.GetAllocator());
				team.AddMember(losersKey, losers, document.GetAllocator());
				team.AddMember(playersKey, players, document.GetAllocator());

				teams.PushBack(team, document.GetAllocator());
			}

			setInfo.AddMember(teamsKey, teams, document.GetAllocator());
		}

		document.AddMember(setInfoKey, setInfo, document.GetAllocator());
	}

	//Output the JSON object to a file
	FILE* fp = fopen("program_state.json", "wb");

	char writeBuffer[0xFFFF + 1];
	rapidjson::FileWriteStream os(fp, writeBuffer, sizeof(writeBuffer));

	rapidjson::PrettyWriter<rapidjson::FileWriteStream> writer(os);
	document.Accept(writer);

	fclose(fp);
}