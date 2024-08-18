// MasterMind - The game starts off by telling the user the possible colors that may be included in the randomly generated word and then each round, the player guess
//              the 4 positions. The user has 10 chances to guess the correct combination of letters, if they do so within 10 chances or less, the are told that they 
//              guessed correctly, if they don't, then they are told that they didn't guess correctly and the correct combination of letters is printed out so the
//              user can compare between the answer they got and the correct answer. The user then is asked if they want to play the game again, if they say yes
//              this process occur again but with a different randomly generated letter combination, if they say then the program prints out how many rounds the user
//              played, how many rounds they won and lost, the user's winning percentage and there best guess score (the lowest number of guesses they got the correct
//              combination of letters while playing), if the user never won any rounds and decides to not play anymore, the program still prints out how many rounds 
//              the user played, how many rounds they won and lost, but the winning percentage is 0% and a message saying they have no best guess score will be printed
//              out since they don't have a best score since the user never won. 
// Krishna Patel - Computer Science 30s
// May. 27 2022


// Constants
const int CODESIZE = 4;    // 4 letter codes

// Prototype
bool master_mind(int& topscore);             // Plays a round of the game - where user has to try and guess the correct combination of letters
void seed_random();                          // Seeds the random number generator

#include <iostream>
#include "MACcolors.h"
using namespace std;
int main(void)
{
	int topscore;          // The least amount of guesses it took the user to guess the correct combination of letters
	char choice;           // The users choice on whether they want to play the mastermind game again or not
	float gamenum;         // The number of times the user played the game
	float percentage;      // The users winning percentage
	int numw;              // The number of wins the user had throughout all the games the user played
	int numl;              // The number of losses the user had throughout all the games the user played

	
	// Initialize values 
	topscore = 100;
	gamenum = 1.0;
	numw = 0;
	numl = 0;
	
	do 
	{   // Call mastermind function to play one round of game
		if (master_mind(topscore) == true)
		{   // If true increase the number of wins the user has
			numw++;
			cout << endl;
			// Ask if the user wants to play again
			cout << "Do you want to play again (Y/N)? ";
			choice = toupper(_getwche());
			cout << endl;
			// Validate the users choice on whether they want to play again or not
			while (choice != 'Y' && choice != 'N')
			{
				cout << "INVALID INPUT - You must enter Y or N: ";
				choice = toupper(_getwche());
				cout << endl;
			} // while`
			if (choice == 'Y')
			{   // Increase the number game rounds the user has played if they say yes to playing again
				gamenum++;
			} // if
		} // if
		else
		{   // It's false so increase the number of losses the user has
			numl++;
			cout << endl;
			// Ask if the user wants to play again
			cout << "Do you want to play again (Y/N)? ";
			choice = toupper(_getwche());
			cout << endl;
			// Validate the users choice on whether they want to play again or not
			while (choice != 'Y' && choice != 'N')
			{
				cout << "INVALID INPUT - You must enter Y or N: ";
				choice = toupper(_getwche());
				cout << endl;
			} // while`
			if (choice == 'Y')
			{   // Increase the number game rounds the user has played if they say yes to playing again
				gamenum++;
			} // if
		} // else
	} // do
	while (choice == 'Y');
	// Calculate the user's winning percentgae
	percentage = (numw / gamenum) * 100;

	// Print out final message
	if (percentage == 0)
	{   // The user doesn't have a best score of guesses because they lost all the games they played
		cout << "You played " << gamenum << " game(s) - " << numw << " Win and " << numl << " Loss for a winning percentage of " << percentage <<
			"% and you don't have a best score since you never won ";
	} // if
	else
	{   // The user has won at least 1 game so they have a winning percentage
		cout << "You played " << gamenum << " game(s) - " << numw << " Win(s) and " << numl << " Loss(es) for a winning percentage of " << percentage <<
			"% and your best score was getting it in " << topscore << " guesses!";
	} // else


	return 0;
} // Main Program

// master_mind -  plays a round of the game - where user has to try and guess the correct combination of letters
// topscore -  the least amount of guesses it took the user to guess the correct combination of letters
bool master_mind(int& topscore)
{
	char letters[] = { "RGBYCM" };   // All the possible letters that may be in the 4 letter combination
	char guess[CODESIZE + 1];        // The users guess of the 4 letter combination
	char answer[CODESIZE + 1];       // The randomly generated 4 letter combination (the answer that the user is trying to guess)
	char copy[CODESIZE + 1];         // A copy of the randomly generated 4 letter combination (the copy of the answer)
	int i;                           // Loop counter
	int round;                       // The amount of rounds it takes the user to guess the right combination (less than or equal to 10)
	int num_correct;                 // The number of letters that the user has in the right position in their guess
	int num_wrongplace;              // The number of letters that the user has in the wrong position in their guess
	int j;                           // Loop counter

	// Seed the random number generator
	seed_random();

	// Generate answer
	for (i = 0; i < CODESIZE; i++)
	{
		answer[i] = letters[rand() % strlen(letters)];
	} // for
	// Add end of string character
	answer[i] = '\0';
	
	// Initialize round
	round = 1;
	// Loop until the user wins or is out of rounds
	cout << "Possible Code Colors: " << RED << "(R)ed, " << GREEN << "(G)reen, " << BLUE << "(B)lue, " << YELLOW << "(Y)ellow, " << CYAN << 
		"(C)yan, " << MAGENTA << "(M)agenta" << endl;
	cout << RESET;
	do 
	{   // Coded like this to make the output look nicer
		if (round >= 1 && round <= 9)
		{
			cout << "ROUND #" << round << "  - Enter your guess: ";
		} // if
		else
		{
			cout << "ROUND #" << round << " - Enter your guess: ";
		} // else
		
		// Get the users guess 
		for (i = 0; i < CODESIZE; i++)
		{
			guess[i] = toupper(_getwch());

			// Validate the users guess
			while (guess[i] != 'R' && guess[i] != 'G' && guess[i] != 'B' && guess[i] != 'Y' && guess[i] != 'C' && guess[i] != 'M')
			{   // change in color to make any wrong letters the use inputs visible
				cout << BLACK << B_WHITE << guess[i];
				cout << endl;
				cout << RESET << "INVALID INPUT - please guess again ";
				guess[i] = toupper(_getwch());
			} // while
			// Print letter in correct color
			switch (guess[i])
			{
				case 'R': cout << RED << B_BLACK; break;
				case 'G': cout << GREEN << B_BLACK; break;
				case 'B': cout << BLUE << B_BLACK; break;
				case 'Y': cout << YELLOW << B_BLACK; break;
				case 'C': cout << CYAN << B_BLACK; break;
				case 'M': cout << MAGENTA << B_BLACK; break;
			} // switch
			cout << guess[i];
		} // for get user's guess loop
		// Add end of string character
		guess[i] = '\0';

		// Calculate the right/wrong position of letters
		// Make a copy of the answer
		for (i = 0; i < CODESIZE; i++)
		{
			copy[i] = answer[i];
		} // for
		// Add eos character
		copy[i] = '\0';
		// Find number of characters in exact position
		// Initialize value
		num_correct = 0;
		//Loop through all the spots
		for (i = 0; i < CODESIZE; i++)
		{
			if (guess[i] == copy[i])
			{
				num_correct++;
				copy[i] = '*';       // Blank out that spot in cop
				guess[i] = '#';      // Blank out differently in guess to prevent double counting later
			} // if
		} // for
		// Find number of letters in the wrong spot
		// Initialize value
		num_wrongplace = 0;
		// Loop through all spots
		for (i = 0; i < CODESIZE; i++)
		{
			//Check to see if not already found
			if (guess[i] != '#')
			{
				// Loop through copy, looking for this letter
				for (j = 0; j < CODESIZE; j++)
				{
					if (guess[i] == copy[j])
					{
						num_wrongplace++;
						copy[j] = '*';
						guess[i] = '#';
						j = CODESIZE;   // reset loop so another isn't found
					} // if
				} // for j
			} // if
		} // for
		// Print number of letters in correct and wrong spot 
		cout << RESET << " =====> " << num_correct << " Exact, " << num_wrongplace << " Wrong Place" << endl;
		// add another round 
		round++;
	} while (round <= 10 && num_correct != CODESIZE);
	// Print and return results
	if (num_correct == CODESIZE)
	{
		// correct - tell the user
		cout << "YOUR CORRECT!! The answer is ";
		for (i = 0; i < CODESIZE; i++)
		{   // To print letters in correct color
			switch (answer[i])
			{
			case 'R': cout << RED << B_BLACK; break;
			case 'G': cout << GREEN << B_BLACK; break;
			case 'B': cout << BLUE << B_BLACK; break;
			case 'Y': cout << YELLOW << B_BLACK; break;
			case 'C': cout << CYAN << B_BLACK; break;
			case 'M': cout << MAGENTA << B_BLACK; break;
			} // switch
			cout << answer[i];
		} // for
		cout << RESET << endl;
		// check if new top score
		if (round < topscore)
		{
			topscore = round - 1;   // this value will be sent back to the main program to be printed out as apart of the final comment
		} // if 
		// return true because the user guessed correctly
		return true;
	} // if
	else
	{
		// Wrong - tell the user the correct answer and return false
		cout << "TIMES UP // YOU LOST - The correct answer was ";
		for (i = 0; i < CODESIZE; i++)
		{   // To print letters in correct color
			switch (answer[i])
			{
			case 'R': cout << RED << B_BLACK; break;
			case 'G': cout << GREEN << B_BLACK; break;
			case 'B': cout << BLUE << B_BLACK; break;
			case 'Y': cout << YELLOW << B_BLACK; break;
			case 'C': cout << CYAN << B_BLACK; break;
			case 'M': cout << MAGENTA << B_BLACK; break;
			} // switch
			cout << answer[i];
		} // for
		cout << RESET << endl;
		// return false because the user guessed incorrectly
		return false;
	} // else
} // master_mind




// seed_random - This function seeds the random number generator
void seed_random()
{
	int i;                  // Loop counter

// Seed the random number generator  - Use the system time
	srand((unsigned)time(NULL));
	for (i = 0; i < rand(); i++)
		rand();
} // seed_random