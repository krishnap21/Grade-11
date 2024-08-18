// Musical Chairs - This program starts off by welcoming the user and then asking how many players are playing, making sure to validate that the user enters a number
//                  that is greater than 1 but less than or eual to 10. The program then randomly assigns money (from $1-$1000) to the user and asks how
//                  much the user wants to bet, validating that the user enters a bet between 1 to the amount of money that they have, the user is then 
//                  asked to guess which player they thnk would win and the program validates that the user enters a guess from 1 to however many players
//                  the user said would play previously. The program then runs, randomly seating the players and eliminating one player each round, if the
//                  user was wrong in their guess, the program plays out showing the user who the winner was and then the user looses their bet. If the
//                  user was right in their guess, the user wins (their bet * (how many players the user entered - 1)). Then finally, the program asks 
//                  the user if they want to play again, validating that the user actually has money to play again, (if the user doesn't have any money
//                  left the program kicks the user out of the game) if the user says no, the program prints out a final message for the user telling them
//                  if they won money or lost money since they began the game, if the user says yes, the program runs again but this time, with the amount
//                  of money the user has from the previous round and the program also doesn't re-ask the user to enter an amount of players if the user
//                  decides to play again (the program goes straight to asking the user for a bet and a guess of which player the user thinks will win).
// Krishna Patel - Computer Science 30s
// March. 31 2022



// Prototypes
void Play_Round(int num_players, int& money);           // Plays 1 game of musical chairs
void seed_random();                                     // Seeds the random number generator



#include <iostream>
#include <time.h>
using namespace std;

// Main Program
int main(void)
{
	int money;               // How much money the user has
	char choice;             // Used to ask the user if they want to play the game again or not
	int num_players;         // Used to ask the user how many players will be playing
	int MT;					 // Money Tracker - used to track how much money the user won, lost or broke even compared to the start of the
	// game - used to print the the final message

// Seed the random numbers
	seed_random();

	// Randomly pick how much money the user gets
	money = rand() % 1000 + 1;
	// Set Money Tracker to money so I know the original amount of money that the user started with 
	MT = money;

	// Welcome the user
	cout << "WELCOME to the OG Survivor Game : MUSICAL CHAIRS!!!" << endl;
	// Ask for the number of players
	cout << "How many players are playing (from 2 -10)? ";
	cin >> num_players;
	// Validate how many players the user entered
	while (num_players <= 1 || num_players > 10)
	{
		cout << "INVALID CHOICE! - How many players are playing (from 2 - 10)? ";
		cin >> num_players;
	} // while

	do
	{
		// Call the Play_Round function to play 1 game 
		Play_Round(num_players, money);

		// Play again - only ask if they still have money
		if (money == 0)
		{
			choice = 'N';
		}  // they have no money, so they can't play again
		else
		{ // Ask if they want to play again, since they still have money
			cout << endl;
			cout << "Do you want to play again? (Y/N) ";
			choice = toupper(_getwche());
			cout << endl;
			// Validate answer
			while (choice != 'Y' && choice != 'N')
			{
				cout << "INVALID ANSWER - you must enter Y or N.";
				cout << " Do you want to play again? (Y/N) ";
				choice = toupper(_getwche());
				cout << endl;
			} // while
		} // else
	} // do
	while (choice == 'Y');

	// Print final message
	if (money == 0)
	{ // The user is broke
		cout << endl;
		cout << "You are broke - get out of here NOW!!!" << endl;
	} // if
	else
	{   // The user is leaving with more money than what they started the game with
		if (money > MT)
		{
			MT = money - MT;
			cout << endl;
			cout << "You are leaving with $" << money << ", which means you won $" << MT << " since you started - CONGRATULATIONS!!"
				<< endl;
		} // if - money won
		else
		{   // The user is leaving with les money than what they started the game with
			if (money < MT)
			{
				MT = MT - money;
				cout << endl;
				cout << "You are leaving with $" << money << ", which means you lost $" << MT << " since you started. "
					<< endl;
			} // if - money lost
			else
			{ // The user didn't gain or lose any money
				cout << "You are leaving with $" << money << ", which means you didn't lose or gain any money since you" <<
					" started" << endl;
			} // else 
		} // else
	} // else 

	return 0;
} // Main Program 

// seed_random - This function seeds the random number code
void seed_random()
{
	int i;

	// Seed the random number generator  - Use the system time
	srand((unsigned)time(NULL));
	for (i = 0; i < rand(); i++)
		rand();
} // seed_random

// Play_Round - This function plays one game of musical chairs and updates the amount of money that the user has at the end of the game depending on 
//              whether the user guessed correctly or not when trying to guess which player they think will win
// num_players - The number of players the user previously said would be playing
// money - The amount of money that the user has
void Play_Round(int num_players, int& money)
{
	int pos;          // Position on the board ***
	bool alive[10];   // Tells if a player is still alive/in the game or not *** (bool or int)
	int bet;          // The amount of money the user wants to bet
	int guess;        // The users guess on which player they think will win the game
	int round;        // The round number
	int spot;         // A spot for each player  ***
	int include[10];  // Includes all players who are alive in the game *** (bool or int)
	int seated;       // Seats the players (except for 1 since 1 player is eliminated each round)
	int winner;       // Prints out the players seated each round 
	int delay;        // Adds an dramatic delay to create suspension between each player seated
	int win;          // Used to calculate how much money the user won since they correctly guessed which player would win

	// Set all players to alive
	for (pos = 0; pos < num_players; pos++)
	{
		alive[pos] = true;
	} // for

	// Get and validate the users bet and ask who they think will win the game
	// Tell the user how much money they have and ask how much money they want to bet
	cout << "You have $" << money << " - how much money do you want to bet (from $1 - $" << money << ")?";
	cin >> bet;
	// Validate the users bet
	while (bet < 1 || bet > money)
	{

		cout << "INVALID BET - bet from $1 to $" << money << " only!";
		cout << " How much do you want to bet? ";
		cin >> bet;
	} // while
	// Ask the user which player they think would win
	cout << "Which player do you think will win (1 - " << num_players << ")? ";
	cin >> guess;
	// Validate the users guess
	while (guess < 1 || guess > num_players)
	{
		cout << " INVALID PLAYER - who do you think will win (1 - " << num_players << ")? ";
		cin >> guess;
	} // while

	// Play num_players-1 rounds (until a winner)
	for (round = 1; round < num_players; round++)
	{
		cout << endl;
		cout << "ROUND " << round << ": " << endl;
		cout << "PLAYERS SEATED: ";

		// Include all players still alive
		for (spot = 0; spot < num_players; spot++)
		{
			include[spot] = alive[spot];
		} // for

		// Seat x-1 players (where x is number of players left)
		for (seated = 1; seated <= num_players - round; seated++)
		{
			// Pick a random number
			winner = rand() % num_players;

			// Validate if that player is still in the game
			while (!include[winner])
			{
				winner = rand() % num_players;
			} // while

			// Players are seated - add delay for dramatic effect
			for (delay = 1; delay <= 1500000000; delay++);
			cout << "   ";
			cout << winner + 1;

			// Update that spot
			include[winner] = false;

		} // for seated

		// Tell who was eliminated
		spot = 0;
		while (!include[spot])
		{
			spot++;
		}
		cout << "   ||   so player " << spot + 1 << " was eliminated!" << endl;
		cout << "Press any key to continue...";
		_getwche();
		cout << endl;

		// Update eliminated player's status
		alive[spot] = false;

	} // for round

	// Tell who won
	spot = 0;
	while (!alive[spot])
	{
		spot++;
	}
	cout << endl;
	cout << "PLAYER " << spot + 1 << " WAS THE WINNER, so ";

	// Figure out if the user won their bet and update money
	if (spot + 1 == guess)
	{
		win = bet * (num_players - 1);
		money += win;
		cout << "you win $" << win << " ($" << bet << "*(" << num_players << "-1)) and now you have $" << money << " - CONGRATS!!!" << endl;
	} // if - user guessed the right player and wins money
	else
	{
		money -= bet;
		cout << "you lose $" << bet << " and now you have $" << money << endl;
	} // else - user guessed the wrong player and losses the money they bet

}  // Play_Round
