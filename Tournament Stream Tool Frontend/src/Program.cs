using System;
using System.Windows;

using TST;

public static class Program
{
    [STAThread]
    private static void Main(string[] args)
    {
        //Create the app
        Application app = new Application();

        //Create Window
        Window window = new MainWindow();

        //Launch app
        app.Run(window);
    }
}