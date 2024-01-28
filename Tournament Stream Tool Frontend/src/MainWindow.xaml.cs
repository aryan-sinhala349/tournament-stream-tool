using System;
using System.Text.RegularExpressions;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace TST
{
    public partial class MainWindow : Window
    {
        private static readonly Regex s_NumberRegex = new Regex("[^0-9]+");

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

            //General Set Information
            RoundNameTextBox.Text = ProgramState.GetRoundName();
            Team1ScoreTextBox.Text = ProgramState.GetTeamScore(0).ToString();
            Team2ScoreTextBox.Text = ProgramState.GetTeamScore(1).ToString();
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

        private void RoundNameTextBox_TextChanged(object sender, TextChangedEventArgs e)
        {
            ProgramState.SetRoundName(RoundNameTextBox.Text);
        }

        private void Score_PreviewTextInput(object sender, TextCompositionEventArgs e)
        {
            try
            {
                int.Parse(e.Text);
            }
            catch (FormatException)
            {
                e.Handled = true;
                return;
            }

            TextBox textBox = (TextBox)sender;
            int score = int.Parse(textBox.Text + e.Text);

            if (score < 0 || score > 99)
                e.Handled = true;
        }

        private void Score_Pasting(object sender, DataObjectPastingEventArgs e)
        {
            if (!e.DataObject.GetDataPresent(typeof(string)))
            {
                e.CancelCommand();
                return;
            }

            string text = (string)e.DataObject.GetData(typeof(string));

            try
            {
                int.Parse(text);
            }
            catch (FormatException)
            {
                e.CancelCommand();
                return;
            }

            TextBox textBox = (TextBox)sender;
            int score = int.Parse(textBox.Text + text);

            if (score < 0)
            {
                e.CancelCommand();
                return;
            }

            if (score > 99)
            {
                string convertedScore = textBox.Text + text;
                string clampedScore = convertedScore.Substring(0, 2);
                textBox.Text = clampedScore;
                e.CancelCommand();
            }
        }

        private void Team1ScoreTextBox_TextChanged(object sender, TextChangedEventArgs e)
        {
            string text = Team1ScoreTextBox.Text;

            try
            {
                int.Parse(text);
            }
            catch (FormatException)
            {
                e.Handled = true;
                return;
            }

            int score = int.Parse(text);

            if (score < 0 || score > 99)
                return;

            ProgramState.SetTeamScore(0, score);
        }

        private void Team2ScoreTextBox_TextChanged(object sender, TextChangedEventArgs e)
        {
            string text = Team2ScoreTextBox.Text;

            try
            {
                int.Parse(text);
            }
            catch (FormatException)
            {
                e.Handled = true;
                return;
            }

            int score = int.Parse(text);

            if (score < 0 || score > 99)
                return;

            ProgramState.SetTeamScore(1, score);
        }
    }
}
