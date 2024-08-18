// Higher/Lower/The Same - this game randomly prints out a card for the user and asks if the user thinks that the next card will be 
//                         higher, lower or the same. If the user guesses correctly they get to continue playing but, if they answer
//                         incorrectly then the game will end and print out the users results of how many answers they got correct
//                         and what their high score is and finally the game will ask the user if they wish to play again, if the user
//                         says yes then there will be a 2nd round of the game if the user says no then the program will print out
//                         how many rounds the user played, the users average of correct answers per each round and the users highest
//                         correct answer streak
// Krishna Patel - Computer Science 30s
// Feb. 25 2022


// Prototypes
int get_card();                           // function that returns a card from 1-13
int get_suit();                           // function that returns suit # (3 = H, 4 = D, 5 =C, 6 = S)
void print_card(int card, int suit);      // prints the card suit and number
int card_value(int card);                 // function that returns value based on card

#include <iostream>
#include <time.h>
#include "MACcolors.h"
using namespace std;
// get_card - this function returns a random card from 1-13 (1 = Ace, 13 = King)
// card - the card that gets printed out later
int get_card()
{
	return rand() % 13 + 1;  // returns card 
} // get_card

// get_suit - this fuction returns a random suit # (3 = H, 4 = D, 5 = C, 6 = S)
// suit - the suit that will be later printed out
int get_suit()
{
	return rand() % 4 + 3;        // gets a random number
}// get_suit

// card_value - this function returns a value based on the card - they are in order, excpet for Ace
// card - this will return a value for the card that gets printed
int card_value(int card)
{
	if (card == 1)
	{
		return 14;
	} // if
	else
	{
		switch (card)
		{
		case 2: return 2;
			break;
		case 3: return 3;
			break;
		case 4: return 4;
			break;
		case 5: return 5;
			break;
		case 6: return 6;
			break;
		case 7: return 7;
			break;
		case 8: return 8;
			break;
		case 9: return 9;
			break;
		case 10: return 10;
			break;
		case 11: return 11;
			break;
		case 12: return 12;
			break;
		case 13: return 13;
			break;
		} // switch
	} // else
} // card_value 


// print_card - This function prints a single card
// card, suit - the random value that was previously picked comes here and is assigned a cardpic and suitpic
void print_card(int card, int suit)
{
	char suit_pic, card_pic;                   // Character values of card/suit

	// Define suit / card values 
	suit_pic = suit;
	// used to assign a card value to the random number that was picked in the get_card fucntion
	switch (card)
	{
	case 1: card_pic = 'A'; break;        case 2: card_pic = '2'; break;         case 3: card_pic = '3'; break;
	case 4: card_pic = '4'; break;        case 5: card_pic = '5'; break;         case 6: card_pic = '6'; break;
	case 7: card_pic = '7'; break;        case 8: card_pic = '8'; break;         case 9: card_pic = '9'; break;
	case 10: card_pic = 'T'; break;        case 11: card_pic = 'J'; break;         case 12: card_pic = 'Q'; break;
	case 13: card_pic = 'K'; break;
	} // switch

	// used to assign a color to the random number that was picked in the get_suit function
	// Set the colour
	if (suit == 3 || suit == 4)
	{
		cout << RED << B_WHITE;
	}
	else
	{
		cout << BLACK << B_WHITE;
	}

	// Print the card
	cout << card_pic << suit_pic << endl;

} // print_card


// Main Program 
int main(void)
{
	int high;                   //the highest streak the user had of correct answers
	int total_correct;          // the total number of correct answers that the user got out of all the rounds the user played
	int total;                  // the total number of correct answers the user got in a round
	int round;                  // the round number
	int correct;                // used to tell the user how many correct answers they had while the user is playing
	int topcard;                // used to print the 1st card
	int topsuit;                // used to print the 1st suit
	char guess;                 // the guess that the user inputs ((H)igher, (L)ower, (S)ame)
	int nextcard;               // used to print the next card if the user guesses correctly for the previous card
	int nextsuit;               // used to print the next suit if the user guesses correctly for the previous card
	int topvalue;               // used to check what the current card is and used to detrmine if the user is correct in their guess or not
	int nextvalue;              // used to check what the next card is and determine if the user is correct in their guess or not
	char playagain;             // used to ask the user if they want to play again
	int average;                // used to determine the average number of correct answers the user got per round
	int i;                      // Loop counter

	// Seed the random number generator  - Use the system time
	srand((unsigned)time(NULL));
	for (i = 0; i < rand(); i++)
		rand();
	// prints out in a nice format
	cout << BLACK << B_WHITE;
	// set totals to 0 for high and average
	high = 0;
	total_correct = 0;
	total = 0;
	// Initialize round
	round = 0;
	// loop until the user quits
	do
	{
		// play next round
		round++;
		cout << LIGREEN << B_WHITE;
		cout << "ROUND # " << round << ":" << endl;
		correct = 0;
		cout << RESET;
		// get top card
		topcard = get_card();
		topsuit = get_suit();
		cout << LIGREEN << B_WHITE;
		cout << "The card is ";
		print_card(topcard, topsuit);
		// Loop until the user is wrong
		do
		{
			// Ask for the users choice
			cout << LIGREEN << B_WHITE;
			cout << " Will the next card be (H)igher, (L)ower, or the (S)ame? ";
			guess = toupper(_getwche());
			cout << endl;
			// Validate the users input for the guess
			while (guess != 'H' && guess != 'L' && guess != 'S')
			{
				cout << "INVALID GUESS - re-enter H,L or S only!";
				guess = toupper(_getwche());
				cout << endl;
			} // while
			// pick the next card
			nextcard = get_card();
			nextsuit = get_suit();
			cout << "The next card was ";
			print_card(nextcard, nextsuit);
			// Check if they were correct
			topvalue = card_value(topcard);
			nextvalue = card_value(nextcard);
			cout << LIGREEN << B_WHITE;
			if ((nextvalue > topvalue && guess == 'H') || (nextvalue < topvalue && guess == 'L') ||
				(nextvalue == topvalue && guess == 'S'))
			{ // The users guess was correct - print the message and update the top card
				correct++;
				cout << "You are Correct! You have " << correct << " in a row!";
				topcard = nextcard;
				topsuit = nextsuit;
				total++;
			} // if
			else
			{ // The users guess was incorrect - print message and update totals
				cout << " You are Wrong! You got " << correct << " correct in a row this round." << endl;
				// Check if they got a new high score
				if (correct > high)
				{
					cout << " - a new high!";
					high = correct;
				} // if new high score
				// Add correct to toal 
				total_correct += total;
				// reset correct to 0
				correct = 0;
			} // else
		} // do - keep going if the user is correct
		while (correct != 0);
		{
			// check to see if the user wants to keep playing
			cout << " Do you want to play another round (Y/N): ";
			playagain = toupper(_getwche());
			cout << endl;
			// Validate playagain
			while (playagain != 'Y' && playagain != 'N')
			{
				cout << "INVALID ANSWER - you must enter Y or N: ";
				playagain = toupper(_getwche());
				cout << endl;
			} // while
		} // while
	} // do
	// keep playing if the user wants
	while (playagain == 'Y');

	// Calculate and print out final message - high score and average
	average = total_correct / round;
	cout << "You played " << round << " round(s), with an average of " << average << " correct per round, and your highest score"
		" was " << high << " in a row!" << endl;

	return 0;
} // main




