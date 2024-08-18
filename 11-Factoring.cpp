// Factor Game - This program is a 2 player game, it asks the users for a maximum value that is greater than 1 but less than 100 and then based on the maximum number 
//               that the users chose, the program prints out a board from 1 to the maximum number in green. Then each team chooses a number and they get however many 
//               points as the number that they picked but, the other team gets points for every number left on the board that's a factor of the number picked. Once
//               certain numbers have been picked and the factors of that number have been used up, those numbers turn into red indicating that they are no longer 
//               available to be used and the program validates that the user doesn't pick a number that is red. After a number is picked by a team, the program 
//               prints out a message which tells the team whose turn it is what number they picked and as a result how many points the other team gets. As well, 
//               the program prints out the current points for both teams. Once all of the numbers on the board have beem used up/turned red, the program prints 
//               out a final message stating how many points both teams have and the winner of the game. 
// Krishna Patel - Computer Science 30s
// March, 29 2022


// Prototypes
void initialize(int& p1_score, int& p2_score, bool taken[101], int& max_num); // This function asks the users what the maximum value will be, sets all numbers to not
// taken and sets scores for each team to 0
bool more_numbers(bool taken[101], int max_num);                              // This function returns true if there are any numbers left on the board and false if not
void Print_Board(bool taken[101], int max_num);                               // Based on the users maximum value, this function prints out numbers from 1 to the max 
// value and makes sure to print the numbers available in green while the numbers that are 
// not available in red
int pick_num(int turn, int& pick_team, int& other_team, bool taken[101], int max_num); // This function asks the user to pick a number on the board and prints out
// messages informing the users how many points each team has

#include <iostream>
#include "MACcolors.h"
using namespace std;
int main(void)
// Main Program
{
	int p1_score;       // The first team's/player's score
	int p2_score;       // The second team's/player's score
	bool taken[101];    // Tells if a number is taken or not
	int max_num;        // The maximum value that the user wants to go up to (greater than 1 but less than 100)

	// Call initialize function to ask the user for the max value
	initialize(p1_score, p2_score, taken, max_num);
	// Check if there are numbers left on the board with the more_numbers function
	while (more_numbers(taken, max_num))
	{   // Team/Player 1 picks what number that they want
		pick_num(1, p1_score, p2_score, taken, max_num);
		// If there are still more numbers on the board
		if (more_numbers(taken, max_num))
		{   // Team/Player 2 picks what number that they want
			pick_num(2, p2_score, p1_score, taken, max_num);
		} // if
	} // while


	// Give final results 
	if (p1_score > p2_score)
	{
		cout << endl;
		cout << "Team #1 ended with " << p1_score << " points while Team #2 ended with " << p2_score << ", making Team #1 the winner of this game!!!";
		cout << endl;
	} // if
	else
	{
		cout << endl;
		cout << "Team #2 ended with " << p2_score << " points while Team #1 ended with " << p1_score << ", making Team #2 the winner of this game!!!";
		cout << endl;
	} // else

	return 0;
} // Main Program

// more_numbers - This function returns true if there are any numbers left on the board and false if not
// taken - tells if a number is taken or not
// max_num - the maximum number that the users wanted to go up to
bool more_numbers(bool taken[101], int max_num)
{
	int i; // Loop counter 

	// Check if any numbers left
	for (i = 1; i <= max_num; i++)
	{
		if (!taken[i])
		{
			return true;
		} // if
	} // for 

	// loop is over, so all are taken
	return false;
} // more_numbers

// pick_num - This function asks the user to pick a number on the board and prints out messages informing the users how many points each team has
// turn - This indicates which team/players turn it is
// pick_team - The score for the team/player whose turn it is
// other_team - The score for the team/player whose turn it isn't
// taken - tells if a number is taken or not
// max_num - the maximum number that the users wanted to go up to
int pick_num(int turn, int& pick_team, int& other_team, bool taken[101], int max_num)
{
	int choice;   // The users choice on which number they want to pick (must be less than the max number)
	int pts;      // The points for the team whose turn it isn't (the points they got from the factors of the number the team whose turn it is picked)
	int i;        // Loop counter

	// To make the output look nice
	cout << endl;
	// Print Board to show what's left
	Print_Board(taken, max_num);

	cout << endl;
	// Get the users pick
	cout << WHITE << "Team #" << turn << " what number do you want to pick? ";
	cin >> choice;

	// Validate the users choice 
	while (choice < 1 || choice > max_num || taken[choice])
	{ // The users choice is invalid and they must pick again
		cout << " INVALID - please pick another number: ";
		cin >> choice;
	} // while

	// Set choice to taken
	taken[choice] = true;

	// User has chosen their chioce - initialize the points and see what points the other team gets
	pts = 0;

	cout << "You picked " << choice << " so, ";
	if (turn == 1)
	{
		cout << "Team #2 gets ";
	}
	else
	{
		cout << "Team #1 gets ";
	}
	// Loop through looking for factors
	for (i = 1; i <= choice / 2; i++)
	{
		// is it a factor and not taken
		if (choice % i == 0 && !taken[i])
		{ // points for the other team
			cout << i << ", ";
			pts += i;          // add new points to previous points
			taken[i] = true;   // set the factor to taken
		} // if
	} // for

	// Check if the other team gets points or not
	if (pts == 0)
	{
		cout << "0 points" << endl;
	} // if
	else
	{
		cout << "for a total of " << pts << " points" << endl;
	} // else

	// Update scores
	pick_team += choice;
	other_team += pts;

	// Print current score
	cout << "Current points: TEAM #" << turn << " - " << pick_team << " points ";
	if (turn == 1)
	{
		cout << "|| TEAM #2 - " << other_team << " points" << endl;
	} // if
	else
	{
		cout << " || TEAM #1 - " << other_team << " points" << endl;
	} // else

	// Return each teams/players points
	return pick_team, other_team;

} // pick_num

// initialize - This function asks the users what the maximum value will be, sets all numbers to not taken and sets scores for each team to 0 // initializes the board
// p1_score - The first team's/player's initial score
// p2_score - The second team's/player's inital score
// taken - tells if a number is taken or not
// max_num - the maximum number that the users wanted to go up to
void initialize(int& p1_score, int& p2_score, bool taken[101], int& max_num)
{
	int i; // Loop counter


	// Ask for the max value
	cout << WHITE << " What is the maximum number you want to go up to between 1-100: ";
	cin >> max_num;

	// Validate that the maximum value that the user entered is less than 100 but greater than 1
	while (max_num <= 1 || max_num > 100)
	{
		cout << "INVALID - please pick the maximum number you want to go up to between 1-100: ";
		cin >> max_num;
	} // while

	// Set all values up to the maximum number to not taken
	for (i = 1; i <= max_num; i++)
	{
		taken[i] = false;
	} // for

	cout << " NOTE: " << GREEN << "GREEN " << WHITE << "means the numbers are available to be picked while " << RED << "RED " << WHITE <<
		"means the numbers have already been picked" << endl;

	// Initialize the scores for each team/player
	p1_score = 0;
	p2_score = 0;

} // initialize

// Print_Board - This function prints out a board of numbers from 1 to the maximum number (which the user previously entered) and makes sure makes sure to print 
//               the numbers available in green while the numbers that are not available in red
// taken - tells if a number is taken or not
// max_num - the maximum number that the users wanted to go up to
void Print_Board(bool taken[101], int max_num)
{
	int i; // Loop counter

	// Loop through all the numbers needed to be printed on the board
	for (i = 1; i <= max_num; i++)
	{   // If the number is not taken/still available print the number out in green
		if (!taken[i])
		{
			cout << GREEN << i << "   ";
		} // if
		else
		{   // The number has been taken already/is not available so print the number out in red
			cout << RED << i << "   ";
		} // else
	} // for
	// Used to make the output look nice
	cout << endl;
} // Print_Board
