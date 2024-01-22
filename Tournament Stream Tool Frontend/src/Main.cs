using System;

public static class Program
{
    public static void Main(string[] args)
    {
        ProgramState.LoadProgramState();
        Console.WriteLine("Team Name: " + ProgramState.SetInfo.Teams[0].TeamName);
        ProgramState.SetInfo.Teams[0].TeamName = "Updated Team Name";
        ProgramState.SaveProgramState();
    }
}