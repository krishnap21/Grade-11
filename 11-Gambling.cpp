// FerrisWheel - This program gives a random amount of money to the user and then asks the user is they want to play (S)ingle, (E)ven,
//               (O)dd, (D)ouble numbers or e(X)it. Depending on the users option, the program will then run accordingly, if Single was
//               the users choice then the program will ask the user to pick a number from 1-36, validating that the user enters a number 
//               between this value and then the program will ask the user to enter an amount of money they would like to bet on, once
//               again validating they bet an amount of money less than or equal to what they have. The program will print a random 
//               number between 1-36 and if the user is correct in their guess they gain the amount of money they betted on, if not then 
//               they lose the amount of money they betted on. If the user picks Odd then the program will again ask the user to bet on 
//               an amount of money and validate the amount that the user enters. A number is randomly generated and if this number is 
//               odd, the user wins the amount of money they bet on, if not then they lose the amount of money that they bet on. If the
//               user picks Double then the program asks the user to choose two numbers between 1-36 validating that they input a number
//               between this value and then asks them to once again bet an amount of money, validating this bet again and generates a 
//               random number between 1-36 and if the user guess the double number right then they win the amount of money they betted
//               on, if not they lose the amount of money that they betted on. If the user picks Even the program will again ask the
//               user to bet on an amount of money and validate the amount that the user enters. The program will randomly generate an 
//               even number and if the number is even, then the user will win the amount of money they bet on, if not then they lose 
//               the amount of money that they bet on. Finally if the user picks Exit the program will end. However, if at any point in 
//               the game, the user looses all of the money that they had then, then the program will end automatically
// Krishna Patel - Computer Science 30s
// Feb. 27 2022



// Prototypes
char menu();                        // Menu Function
void PlaySingle(int& money);        // Asks user single number from 1-36 and tells them if they guessed right
void PlayEven(int& money);          // Gets bet from GetBet function and tells user if the number is even or not/if 
// the user is correct
void PlayOdd(int& money);           // Gets bet from GetBet function and tells user if the number is odd or not/if
// the user is correct
void PlayDouble(int& money);        // Asks user for double numbers from 1-36 and tells them if they guessed right
void GetBet(int& bet, int& money);  // Asks user for how much they want to bet and validates if they entered an amount
// within the range of money that they have



#include <iostream>
#include <time.h>
using namespace std;

// Main Program
int main(void)
{
	int money;              // How much money the user has
	char choice;	        // The users choice on whether they want to play single, double, odd, even or exit
	int i;                  // Loop counter

	// Seed the random number generator  - Use the system time
	srand((unsigned)time(NULL));
	for (i = 0; i < rand(); i++)
		rand();


	// Randomly pick how much money the user gets
	money = rand() % 1000 + 1;
	cout << "WELCOME - you have $ " << money << " to start";
	// Loop until the user quits of runs out of money
	do
	{
		// Call function to get menu choice
		choice = menu();
		// based on choice, act accordingly
		switch (choice)
		{         // Money goes to PlaySingle function
		case 'S': PlaySingle(money);
			break;
			// Money goes to PlayEven function 
		case 'E': PlayEven(money);
			break;
			// Money goes to PlayOdd function
		case 'O': PlayOdd(money);
			break;
			// Money goes to PlayDouble function
		case 'D':PlayDouble(money);
			break;
		} // switch choice
		// Check if the user is broke
		if (money == 0)
		{
			choice = 'X';
		} // if
	} while (choice != 'X');
	if (money == 0)
	{
		cout << " You are BROKE - get out NOW!!" << endl;
	} // if
	else
	{
		cout << " You are leaving with $" << money << " - CONGRATS!" << endl;
	} // else

	return 0;
} // Main

// Menu - This function asks the user for what they want to play and validates that they answer Single, Even, Odd,
//        Double or Exit
char menu()
{
	char choice; // Users choice on what they want to play
	// Ask user
	cout << " Do you want to play (S)ingle, (E)ven, (O)dd or (D)ouble numbers or e(X)it? ";
	choice = toupper(_getwche());
	cout << endl;

	// Validate the users choice
	while (choice != 'S' && choice != 'E' && choice != 'O' && choice != 'D' && choice != 'X')
	{
		cout << "INVALID CHOICE - pick (S)ingle, (E)ven, (O)dd or (D)ouble numbers or e(X)it: ";
		choice = toupper(_getwche());
		cout << endl;
	}
	return choice;
} // menu


// GetBet - This function asks the user for the amount of money that they want to bet and verifies that the amount
//          that the user enters in within the amount of money that they have
// money - The amount of money tht the user has
// bet - The amount of money that the user wants to bet
void GetBet(int& bet, int& money)
{
	cout << "How much money do you want to bet? ";
	cin >> bet;
	// Validate users bet
	while (bet == 0 || bet > money)
	{
		cout << "INVALID AMOUNT - please re-enter a bet from $1 - $" << money << endl;
		cin >> bet;
	} // while
} // GetBet

// PlaySingle - This function asks the user for a single number from 1-36 and tells them if they guessed right and updates
//              the amount of money they have
// money - The amount of money the user has
void PlaySingle(int& money)
{
	int guess;    // The users guess on a number between 1-36
	int bet;      // The amount of money the user wants to bet, used to update money
	int correct;  // The correct number which is randomly picked

	cout << "What number do you think it will be (1-36)?";
	cin >> guess;
	// Validate
	while (guess < 1 || guess > 36)
	{
		cout << "INVALID guess - re enter a number from 1-36 ";
		cin >> guess;
	} // while
	// Get their bet
	GetBet(bet, money);
	// Find the answer
	correct = rand() % 36 + 1;
	cout << " The number is..... " << correct << "!" << endl;
	// Are they correct?
	if (guess == correct)
	{ // correct - print message and update money
		money += 35 * bet;
		cout << "You are correct!! You now have $" << money << endl;
	} // if correct
	else
	{ // Wrong - print message and update money
		money -= bet;
		cout << "You are wrong since you bet on " << guess << " you lose $" << bet << " and now you have $" << money << "!";
	} // else wrong
} // PlaySingle

// PlayOdd - This function gets the users bet from GetBet function and tells user if the number is odd or not/if they
//            are correct
// money - The amount of money the user has
void PlayOdd(int& money)
{
	int correct; // The correct odd number that is randomly picked
	int bet;     // The amount of money the user wants to bet, used to update money
	// Get the users bet
	GetBet(bet, money);
	// Find the answer
	correct = rand() % 36 + 1;
	// Are they correct?
	if (correct % 2 != 0)
	{   // correct - print message and update money
		cout << " The number is..... " << correct << "!" << endl;
		money += bet;
		cout << "You are correct!! You now have $" << money << endl;
	} // if correct
	else
	{   // Wrong - print message and update money
		cout << " The number is..... " << correct << "!" << endl;
		money -= bet;
		cout << "You are wrong, you lose $" << bet << " and now you have $" << money << "!";
	} // else wrong
} // PlayOdd

// PlayEven - This function gets the users bet from GetBet function and tells user if the number is even or not/if they 
//            are correct
// money - The amount of money the user has
void PlayEven(int& money)
{
	int correct;  // The correct odd number that is randomly picked
	int bet;      // The amount of money the user wants to bet, used to update money
	// Get the users bet
	GetBet(bet, money);
	// Find the answer
	correct = rand() % 36 + 1;
	// Are they correct?
	if (correct % 2 == 0)
	{   // correct - print message and update money
		cout << " The number is..... " << correct << "!" << endl;
		money += bet;
		cout << "You are correct!! You now have $" << money << endl;
	} // if correct
	else
	{   // Wrong - print message and update money
		cout << " The number is..... " << correct << "!" << endl;
		money -= bet;
		cout << "You are wrong, you lose $" << bet << " and now you have $" << money << "!";
	} // else wrong
} // PlayEven

// PlayDouble - this function asks the user for two numbers from 1-36 and tells them if they guessed right and updates
//              the amount of money they have
// money - The amount of money the user has
void PlayDouble(int& money)
{
	int guess;   // The first number the user guesses from 1-36
	int guess2;  // The second number the user guesses from 1-36
	int bet;     // The amount of money the user wants to bet, used to update money
	int correct; // The correct number which is randomly picked

	cout << "What two numbers do you think it will be (1-36)?";
	cin >> guess >> guess2;
	// Validate
	while (guess < 1 || guess > 36 || guess2 < 1 || guess2 > 36)
	{
		cout << "INVALID guess - re enter two numbers from 1-36 ";
		cin >> guess >> guess2;
	} // while
	// Get the users bet
	GetBet(bet, money);
	// Find the answer
	correct = rand() % 36 + 1;
	cout << " The number is..... " << correct << "!" << endl;
	// Are they correct?
	if (guess == correct || guess2 == correct)
	{ // correct - print message and update money
		money += 17 * bet;
		cout << "You are correct!! You now have $" << money << endl;
	} // if correct
	else
	{ // Wrong - print message and update money
		money -= bet;
		cout << "You are wrong since you bet on " << guess << " and " << guess2 << " you lose $" << bet <<
			" and now you have $" << money << "!";
	} // else wrong
} // PlayDouble

