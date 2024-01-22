using System;
using System.Runtime.InteropServices;

public static class ProgramState
{
    public static string GetTournamentName()
    {
        return Marshal.PtrToStringAnsi(ProgramState_GetTournamentName());
    }

    public static void SetTournamentName(string name)
    {
        ProgramState_SetTournamentName(name);
    }

    public static string GetEventName()
    {
        return Marshal.PtrToStringAnsi(ProgramState_GetEventName());
    }

    public static void SetEventName(string name)
    {
        ProgramState_SetEventName(name);
    }

    public static string GetRoundName()
    {
        return Marshal.PtrToStringAnsi(ProgramState_GetRoundName());
    }

    public static void SetRoundName(string roundName)
    {
        ProgramState_SetRoundName(roundName);
    }

    public static string GetTeamName(int teamID)
    {
        return Marshal.PtrToStringAnsi(ProgramState_GetTeamName(teamID));
    }

    public static void SetTeamName(int teamID, string teamName)
    {
        ProgramState_SetTeamName(teamID, teamName);
    }

    public static int GetTeamScore(int teamID)
    {
        return ProgramState_GetTeamScore(teamID);
    }

    public static void SetTeamScore(int teamID, int score)
    {
        ProgramState_SetTeamScore(teamID, score);
    }

    public static bool IsTeamLosers(int teamID)
    {
        return ProgramState_IsTeamLosers(teamID);
    }

    public static void SetTeamLosers(int teamID, bool losers)
    {
        ProgramState_SetTeamLosers(teamID, losers);
    }

    [DllImport("Tournament Stream Tool Backend.dll")]
    public static extern void LoadProgramState();
    [DllImport("Tournament Stream Tool Backend.dll")]
    public static extern void SaveProgramState();

    [DllImport("Tournament Stream Tool Backend.dll")]
    private static extern IntPtr ProgramState_GetTournamentName();
    [DllImport("Tournament Stream Tool Backend.dll", CharSet = CharSet.Ansi)]
    private static extern void ProgramState_SetTournamentName(string tournamentName);

    [DllImport("Tournament Stream Tool Backend.dll")]
    private static extern IntPtr ProgramState_GetEventName();
    [DllImport("Tournament Stream Tool Backend.dll", CharSet = CharSet.Ansi)]
    private static extern void ProgramState_SetEventName(string eventName);

    [DllImport("Tournament Stream Tool Backend.dll")]
    private static extern IntPtr ProgramState_GetRoundName();
    [DllImport("Tournament Stream Tool Backend.dll", CharSet = CharSet.Ansi)]
    private static extern void ProgramState_SetRoundName(string roundName);

    [DllImport("Tournament Stream Tool Backend.dll")]
    private static extern IntPtr ProgramState_GetTeamName(int teamID);
    [DllImport("Tournament Stream Tool Backend.dll", CharSet = CharSet.Ansi)]
    private static extern void ProgramState_SetTeamName(int teamID, string teamName);

    [DllImport("Tournament Stream Tool Backend.dll")]
    private static extern int ProgramState_GetTeamScore(int teamID);
    [DllImport("Tournament Stream Tool Backend.dll")]
    private static extern void ProgramState_SetTeamScore(int teamID, int score);

    [DllImport("Tournament Stream Tool Backend.dll")]
    private static extern bool ProgramState_IsTeamLosers(int teamID);
    [DllImport("Tournament Stream Tool Backend.dll")]
    private static extern void ProgramState_SetTeamLosers(int teamID, bool losers);
}
