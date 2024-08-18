// SlotMachine - This program assigns a random value to the user and then asks the user how much moneyt hey want to bet.
//               the program makes sure to validate that the amount of money that the user wants to best is within the
//               range of money that they have. The program randomly prints out slots, if none of the slots were the same
//               the user looses the amount of money they bet, if two of the slots were the same the user wins the amount
//               money they bet and if all 3 slots are the same the user wins 25 times their bet. The program makes sure to 
//               add a dramatic pause before printing each slot and updates the amount of money the user has once the all 
//               of the slots have been printed. The user is then asked if they want to continue playing, if the user says 
//               yes, the program runs once again but with the updated amount of money. But, if the user says no, or the
//               user runs out of moeny, the program tells the user the amount of money they won, losy or broke even
//               compared to the original amount of money that they started with
// Krishna Patel - Computer Science 30s
// Mar. 8 2022


// Prototypes
void RunMachine(int& slot1, int& slot2, int& slot3, int bet, int& money); // This funtion is used to assign a random value from 1-3 
// to each of the different slots that will later be printed
void ShowResults(int slot1, int slot2, int slot3, int bet, int& money);   // Based on the value assigned to the slot in the RunMachine,
// this function prints the different slots using a switch 
// statement
void Results(int slots1, int slots2, int slots3, int bet, int& money);    // This function is used to tell the user whether they win 
// the jackpot, keep their money or lose money based on whether
// the slots printed in the ShowResults function all matched, 2
// matched or none matched

#include <iostream>
#include <time.h>
#include "MACcolors.h"
using namespace std;

// Main Program
int main(void)
{
	int money;               // How much money the user has
	int MT;					 // Money Tracker - used to track how much money the user won, lost or broke even compared to the start of the
	// game - used to print the the final message
	int bet;                 // The amount of money the user wants to bet
	char choice;             // Used to ask the user if they want to play the Slot Machine again or not
	int i;                   // Loop counter
	int slot1, slot2, slot3; // Used for the RunMachine function which determines randomly picks a number from 1-3 fro each of the slots

	// Seed the random number generator  - Use the system time
	srand((unsigned)time(NULL));
	for (i = 0; i < rand(); i++)
		rand();

	// Set color
	cout << BOLDMAGENTA;
	// Randomly pick how much money the user gets

	money = rand() % 1000 + 1;
	// Set Money Tracker to money so I know the original amount of money that the user started with 
	MT = money;
	// Welcome the user
	cout << "WELCOME to the Slot Machine - you have $" << money << "." << endl;
	do
	{
		// Tell the user how much money they have and ask how much money they want to bet
		cout << "How much do you want to bet? ($1 - $" << money << ") ";
		cin >> bet;

		// Validate the users bet
		while (bet < 1 || bet > money)
		{
			// change color
			cout << BOLDRED;
			cout << "INVALID BET - bet from $1 to $" << money << " only!";
			cout << " How much do you want to bet? ";
			cin >> bet;
		} // while

		// change color
		cout << BOLDMAGENTA;
		RESET;
		cout << " For your $" << money << " bet, the Slot Machine shows..." << endl;
		RunMachine(slot1, slot2, slot3, bet, money);

		// Play again - only ask if they still have money
		if (money == 0)
		{
			choice = 'N';
		}  // they have no money, so they can't play again
		else
		{ // Ask if they want to play again, since they still have moeny
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
		cout << "You are broke - get out of this casino NOW!!!" << endl;
	} // if
	else
	{ // The user is leaving with more money than what they started with
		if (money > MT)
		{
			MT = money - MT;
			cout << "You are leaving with $" << money << ", which means you won $" << MT << " since you started - CONGRATS!!"
				<< endl;
		} // if
		else
		{ // The user if leaving with less money than what they started with
			if (money < MT)
			{
				MT = MT - money;
				cout << "You are leaving with $" << money << ", which means you lost $" << MT << " since you started"
					<< endl;
			} // if
			else
			{ // The user didn't gain or lose any money
				cout << "You are leaving with $" << money << ", which means you didn't lose or gain any money since you" <<
					" started" << endl;
			} // else
		} // else
	} // else 

	return 0;
} // Main Program 

//  RunMachine - this function randomly assigns a number from 1-3 to each of the slots
//  slot1, slot2, slot3 - The slots that have a random number assigned to them between 1-3
//  bet, money - These values are sent over but not used in this function (it's sent over to be used in the Results function)
void RunMachine(int& slot1, int& slot2, int& slot3, int bet, int& money)
{ //
	slot1 = rand() % 3 + 1;
	slot2 = rand() % 3 + 1;
	slot3 = rand() % 3 + 1;
	ShowResults(slot1, slot2, slot3, bet, money);
} // RunMachine

// ShowResults - this function prints out the different slots
// slot1, slot2, slot3 - based on the random number assigned to each of the slots in the RunMachine function, the program prints either
//                       wheel, of or font
// bet, money - These values are sent over but not used in this function (it's sent over to be used in the Results function)
void ShowResults(int slot1, int slot2, int slot3, int bet, int& money)
{
	int delay; // used to make a dramatic pause between each of the slots being printed
	// Print results of slot 1
	switch (slot1)
	{ // change the color with the diferent cases
	case 1: cout << BOLDYELLOW << " WHEEL "; break;
	case 2: cout << BOLDBLUE << " OF "; break;
	case 3: cout << BOLDGREEN << " FONT "; break;
	} // switch - slot1

	// Delay loop
	for (delay = 1; delay <= 1500000000; delay++);

	// Print results of slot 2
	switch (slot2)
	{ // change the color with the diferent cases
	case 1: cout << BOLDYELLOW << " WHEEL "; break;
	case 2: cout << BOLDBLUE << " OF "; break;
	case 3: cout << BOLDGREEN << " FONT "; break;
	} // switch - slot2

	// Delay loop
	for (delay = 1; delay <= 1500000000; delay++);

	// Print results of slot 3
	switch (slot3)
	{ // change the color with the diferent cases
	case 1: cout << BOLDYELLOW << " WHEEL "; break;
	case 2: cout << BOLDBLUE << " OF "; break;
	case 3: cout << BOLDGREEN << " FONT "; break;
	} // switch - slot3
	Results(slot1, slot2, slot3, bet, money); // sends the slots that are printed to the Results function to see if the user won the 
	//  jackpot, kept their bet, or lost their bet
} // ShowResults

// Results - this function determines whether the user wins the jackpot, keeps their bet or loses their bet
// slots1, slots2, slots3 - based on what was printed in the ShowResults function, used to determine if none of the slots matched,
//                          2 of the slots matched or all 3 slots matched
// bet, money - depending on whether none of the slots matched, 2 slots matched or 3 slots matched, used to calculate whether the user
//              lost money, kept their money or won the jackpot
void Results(int slots1, int slots2, int slots3, int bet, int& money)
{

	int Win;    // used when all the slots are the same and the user wins the jackpot (it calculates the jackpot)

	// chnage color back to magenta
	cout << BOLDMAGENTA;

	// Check if none of the slots match
	if (slots1 != slots2 && slots2 != slots3 && slots1 != slots3)
	{ // Print that none of the slots matches and update money
		money -= bet;
		cout << endl;
		cout << "There are no matches, so you lost $" << bet << " and now you have $" << money << endl;
	} // if - none of the slots matched
	else
	{
		// Check if all 3 slots matched
		if (slots1 == slots2 && slots2 == slots3)
		{ // Print that all the slots match an update money
			Win = bet * 25;
			money += Win;
			cout << endl;
			cout << "All three slots match, you win the $" << Win << " (25 * $" << bet << ") jackpot and now you have $" <<
				money << "!!!!" << endl;
		} // if - all 3 slots matched
		else
		{ // Two slots matched - print and update money
			cout << endl;
			cout << " Two slots matched, so you keep your $" << bet << " and you still have $" << money << endl;
		} // else - 2 slots matched
	} // else
} // Results






