// Too High or Too Low - This program  generates a random 3 letter uppercase word and then the program asks the user to enter a 3 letter word,
//                       converting any letters the user inputs into uppercase letters if the word is too high, the program will say so and if 
//                       it's too low, the program will say also, the program will continue saying "too low" or "too high" until the user guesses
//                       the word correctly, when the user does so, the program tells the use the amount of tries it took them to guess the right 
//                       answer and gives them a rating. After this, the program asks the user if they want to play again, if the user says yes, 
//                       the program picks another random 3 letter uppercase word and the user must find the correct word again. If the user says
//                       no, the program prints out how many rounds the user played and then tells the user the average amount of tries it took 
//                       the user to get the right answer and then the program tells the user the lowest number of tries it took the user to guess
//                       the correct word.
// Krishna Patel - Computer Science 30s
// May. 19 2022

// Constant for program
const int CODESIZE = 3;                // Word can be up to 3 lengths

// Prototypes
void seed_random();                   // seeds the random number generator
void open_locker(float &howmany, int&best);     // Function that generates a random alphabetic code and then plays the Too High / Too Low game
                                                // until the user guesses the combination

#include <iostream>
using namespace std;
int main(void)
{ // Main Program 
	char choice;           // User choice of whether they want to play the game again
	float times;           // The number of rounds the user played
	float howmany;         // The number of tries it took the user to guess the correct answer (for all rounds played)
	float average;         // The average amount of tries it took the user to guess the correct combination
	int best;              // Determines the lowest amount of tries it took the user to get the correct combination (between all rounds played)

	// Initialize the rounds, tries and best
	times = 1;
	howmany = 0;
	best = 1000000; 

	do
	{
		// Call the function to play the game
		open_locker(howmany,best);

		// Ask the user if they want to play again
		cout << endl;
		cout << "Do you want to play again? (Y/N) ";
		// Convert the users input into uppercase
		choice = toupper(_getwche());
		cout << endl;
		// Validate the users choice
		while (choice != 'Y' && choice != 'N')
		{
			cout << "INVALID ANSWER - you must enter Y or N.";
			cout << " Do you want to play again? (Y/N) ";
			// Convert the users input int uppercase
			choice = toupper(_getwche());
			cout << endl;
		} // while
		// If the user chooses to play again add 1 to the number of rounds the user played
		if (choice == 'Y')
		{
			times++;
		} // if
		cout << endl;
	} // do
	while (choice == 'Y');
	
	// Calculate the average amount of tries it took the user to guess the correct combination
	average = howmany / times;
	// Print out final comment
	cout << "You played " << times << " time(s) and it took you an average of " << average << " tires to solve each one! Your best score was " <<
		     best << " tries!!" << endl;

	
	return 0;
} // Main

// open_locker - Function that generates a random alphabetic code and then plays the Too High / Too Low game until the user guesses the 
//               combination
// howmany - the number of tries it took the user to guess the right combinaton (continues adding up tries for all rounds)
// best - the lowest number of tries it took the user to guess the right combination (between all rounds played)
void open_locker(float &howmany, int& best)
{
	char letters[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };  // All possible password characters
	int pos;                                            // Loop counter
	float attempt;                                      // The number of tries it took the user to win during the round that is being played
	int x;                                              // Loop counter
	char correct[CODESIZE + 1];                         // The randomly generated combination
	char guess[CODESIZE + 1];                           // The users guess of the combination that was randomly generated
	

	// Call the funtion to seed the random number generator
	seed_random();

	// Loop thorugh generating the random 3 letter word combination
	for (pos = 0; pos < CODESIZE; pos++)
	{
		correct[pos] = letters[rand() % strlen(letters)];
	} // for
	// Add eos character
	correct[pos] = '\0';

	// Initialize attempt
	attempt = 0;
	// Loop until the user gets the code
	do
	{
		// Get the users guess
		cout << "TRY #" << attempt + 1 << " Guess the 3 letter combo: ";
		cin >> guess;

		// Loop through the users guess converting the letters they inputted into uppercase letters
		for (x = 0; x < strlen(guess); x++)
		{
			guess[x] = toupper(guess[x]);
		} // for

		// Check if guess is too high
		if (strncmp(guess, correct, CODESIZE) > 0)
		{
			cout << guess << " is TOO HIGH!!" << endl;
		} // if
		else
		{ // The guess is too low
			if (strncmp(guess, correct, CODESIZE) < 0)
			{
				cout << guess << " is TOO LOW!!" << endl;
			} // if
		} // else
		// Update attempt 
		attempt++;
	} // do
	while (strncmp(guess, correct, CODESIZE) != 0);
	// Update howmany - adds up the number of tries it took the user to guess the correct combination in all the rounds
	howmany += attempt;
	// Calculate the lowest amount of tries it took the user to get the answer
	if (attempt < best)
	{
		best = attempt;
	} // if

	// Give the user their rating
	cout << "YOU GOT IT IN " << attempt << " TRIES - YOUR RATING IS ";
	if (attempt <= 3)
	{
		cout << "MASTER" << endl;
	} // if
	else
	{
		if (attempt > 3 && attempt <= 6)
		{
			cout << "SUPERSTAR" << endl;
		} // if
		else
		{
			if (attempt > 6 && attempt <= 9)
			{
				cout << "AMAZING" << endl;
			} // if
			else
			{
				if (attempt > 9 && attempt <= 12)
				{
					cout << "GOOD" << endl;
				} // if
				else
				{
					if (attempt > 12 && attempt <= 15)
					{
						cout << "NOT BAD" << endl;
					} // if
					else
					{
						cout << "POSSIBLE BURGLAR" << endl;
					} // else
				} // else
			} // else
		} // else
	} // else
} // open_lockaer

// seed_random - This function seeds the random number generator
void seed_random()
{
	int i;                  // Loop counter

// Seed the random number generator  - Use the system time
	srand((unsigned)time(NULL));
	for (i = 0; i < rand(); i++)
		rand();
} // seed_random