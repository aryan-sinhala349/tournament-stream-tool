#include "ProgramState.h"

#include "rapidjson/document.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/prettywriter.h"

#include <iostream>

ProgramState State;

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
			rapidjson::Value tournamentName(State.TournamentInfo.TournamentName, document.GetAllocator());

			tournamentInfo.AddMember(tournamentNameKey, tournamentName, document.GetAllocator());
		}

		//Set the event name
		{
			rapidjson::Value eventNameKey("event_name", document.GetAllocator());
			rapidjson::Value eventName(State.TournamentInfo.EventName, document.GetAllocator());

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
			rapidjson::Value roundName(State.SetInfo.RoundName, document.GetAllocator());

			setInfo.AddMember(roundNameKey, roundName, document.GetAllocator());
		}

		//Set the teams info
		{
			rapidjson::Value teamsKey("teams", document.GetAllocator());
			rapidjson::Value teams;
			teams.SetArray();

			for (uint8_t i = 0; i < 2; i++)
			{
				rapidjson::Value team;
				team.SetObject();

				rapidjson::Value teamNameKey("team_name", document.GetAllocator());
				rapidjson::Value teamName(State.SetInfo.Teams[i].TeamName, document.GetAllocator());

				rapidjson::Value scoreKey("score", document.GetAllocator());
				rapidjson::Value score(State.SetInfo.Teams[i].Score);

				rapidjson::Value losersKey("losers", document.GetAllocator());
				rapidjson::Value losers(State.SetInfo.Teams[i].Losers);
				
				rapidjson::Value playersKey("players", document.GetAllocator());
				rapidjson::Value players;
				players.SetArray();

				for (uint32_t j = 0; j < State.SetInfo.Teams[i].Players.size(); j++)
				{
					rapidjson::Value player;
					player.SetObject();

					rapidjson::Value sponsorKey("sponsor", document.GetAllocator());
					rapidjson::Value sponsor(State.SetInfo.Teams[i].Players[j].Sponsor, document.GetAllocator());
		
					rapidjson::Value tagKey("tag", document.GetAllocator());	
					rapidjson::Value tag(State.SetInfo.Teams[i].Players[j].Tag, document.GetAllocator());

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