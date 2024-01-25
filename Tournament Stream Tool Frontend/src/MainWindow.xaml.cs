using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace TST
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            /* Load Tournament Information */
            TournamentNameTextBox.Text = ProgramState.GetTournamentName();
            EventNameTextBox.Text = ProgramState.GetEventName();

            /* Load Set Information*/
            //Team 1
            Team1CheckBox.IsChecked = ProgramState.IsTeamLosers(0);
            Team1NameTextBox.Text = ProgramState.GetTeamName(0);

            //Team 2
            Team2CheckBox.IsChecked = ProgramState.IsTeamLosers(1);
            Team2NameTextBox.Text = ProgramState.GetTeamName(1);
        }

        private void UpdateButton_Click(object sender, RoutedEventArgs e)
        {
            ProgramState.SaveProgramState();
        }

        private void MainGrid_MouseDown(object sender, MouseButtonEventArgs e)
        {
            MainGrid.Focus();
        }

        private void TournamentNameTextBox_TextChanged(object sender, TextChangedEventArgs e)
        {
            ProgramState.SetTournamentName(TournamentNameTextBox.Text);
        }

        private void EventNameTextBox_TextChanged(object sender, TextChangedEventArgs e)
        {
            ProgramState.SetEventName(EventNameTextBox.Text);
        }

        private void Team1CheckBox_Checked(object sender, RoutedEventArgs e)
        {
            ProgramState.SetTeamLosers(0, true);
        }

        private void Team1CheckBox_Unchecked(object sender, RoutedEventArgs e)
        {
            ProgramState.SetTeamLosers(0, false);
        }

        private void Team1NameTextBox_TextChanged(object sender, TextChangedEventArgs e)
        {
            ProgramState.SetTeamName(0, Team1NameTextBox.Text);
        }

        private void Team2CheckBox_Checked(object sender, RoutedEventArgs e)
        {
            ProgramState.SetTeamLosers(1, true);
        }

        private void Team2CheckBox_Unchecked(object sender, RoutedEventArgs e)
        {
            ProgramState.SetTeamLosers(1, false);
        }

        private void Team2NameTextBox_TextChanged(object sender, TextChangedEventArgs e)
        {
            ProgramState.SetTeamName(1, Team2NameTextBox.Text);
        }
    }
}
