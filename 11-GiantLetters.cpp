// GIANTS - This program asks the user to enter 5 letters and validates that the user actually enters a number
//          and then prints out these 5 letters in giant letters vertically down the page.
// Krishna Patel - Computer Science 30s
// Feburary. 17 2022


#include <iostream>
using namespace std;


// PROTOTYPES
void get_letter(void);   // asks user for a single letter (5 times) and validates it
void P_L(char);          // prints the letter that the user inputs as a giant letter    

// Main
int main(void)
{
	get_letter();
}

// Validate that the user inputs a letter only
bool VAL(char val_letter)
{
	if (val_letter != 'A' && val_letter != 'B' && val_letter != 'C' && val_letter != 'D' && val_letter != 'E' &&
		val_letter != 'F' && val_letter != 'G' && val_letter != 'H' && val_letter != 'I' && val_letter != 'J' &&
		val_letter != 'K' && val_letter != 'L' && val_letter != 'M' && val_letter != 'N' && val_letter != 'O' &&
		val_letter != 'P' && val_letter != 'Q' && val_letter != 'R' && val_letter != 'S' && val_letter != 'T' &&
		val_letter != 'U' && val_letter != 'V' && val_letter != 'W' && val_letter != 'X' && val_letter != 'Y' &&
		val_letter != 'Z')
	{
		return false;
	} // if
	else // if user inputted  letter in uppercase or lowercase
	{
		return true;
	} // else
} // bool

// get_letter - this function gets and validates a letter
void get_letter()
{

	char L1;             // The 1st letter that the user inputs
	char L2;             // The 2nd letter that the user inputs
	char L3;             // The 3rd letter that the user inputs
	char L4;             // The 4th letter that the user inputs
	char L5;             // The 5th letter that the user inputs


	// Asks user to enter letter #1
	cout << " Enter letter #1: ";
	L1 = toupper(_getwche());
	cout << endl;
	// Validates the letter that the user inputs
	while (!VAL(L1))
	{
		cout << " INVALID - re-enter letter: ";
		L1 = toupper(_getwche());
		VAL(L1);
		cout << endl;
	} // while

	// Asks user to enter letter #2
	cout << " Enter letter #2: ";
	L2 = toupper(_getwche());
	cout << endl;
	// Validates the letter that the user inputs
	while (!VAL(L2))
	{
		cout << " INVALID - re-enter letter: ";
		L2 = toupper(_getwche());
		VAL(L2);
		cout << endl;
	}// while

	// Asks user to enter letter #3
	cout << " Enter letter #3: ";
	L3 = toupper(_getwche());
	cout << endl;
	// Validates the letter that the user inputs
	while (!VAL(L3))
	{
		cout << " INVALID - re-enter letter:  ";
		L3 = toupper(_getwche());
		VAL(L3);
		cout << endl;
	} // while

	// Asks user to enter letter #4
	cout << " Enter letter #4: ";
	L4 = toupper(_getwche());
	cout << endl;
	// Validates the letter that the user inputs
	while (!VAL(L4))
	{
		cout << " INVALID - re-enter letter:  ";
		L4 = toupper(_getwche());
		VAL(L4);
		cout << endl;
	} // while

	// Asks user to enter #5
	cout << " Enter letter #5: ";
	L5 = toupper(_getwche());
	cout << endl;
	// Validates the letter that the user inputs
	while (!VAL(L5))
	{
		cout << " INVALID - re-enter letter:  ";
		L5 = toupper(_getwche());
		VAL(L5);
		cout << endl;
	} // while

	// Take whatever letters the user inputted and send it to print letter
	for (int x = 1; x <= 5; x++)
	{
		switch (x)
		{
		case 1: P_L(L1); break;
		case 2: P_L(L2); break;
		case 3: P_L(L3); break;
		case 4: P_L(L4); break;
		case 5: P_L(L5); break;
		} // switch

	} // for loop
} // get_letter function

// P_L - This function prints the letter in a nice format
// letter (L1, L2, L3, L4, L5) - is what gets printed
void P_L(char letter)
{
	cout << endl << endl;
	switch (letter)
	{
	case 'A': cout << "          //$$" << endl;
		cout << "         //  $$" << endl;
		cout << "        //    $$" << endl;
		cout << "       //      $$" << endl;
		cout << "      //--------$$" << endl;
		cout << "     //          $$" << endl;
		cout << "    //            $$" << endl;
		cout << "   //              $$" << endl;
		cout << "  //                $$" << endl;
		break;
	case 'B': cout << " ||$$$$$$$$$$$$$$$$ " << endl;
		cout << " ||               $$" << endl;
		cout << " ||               //" << endl;
		cout << " ||              // " << endl;
		cout << " ||--------------$$ " << endl;
		cout << " ||               $$" << endl;
		cout << " ||               //" << endl;
		cout << " ||              // " << endl;
		cout << " ||_____________//  " << endl;
		break;
	case 'C': cout << " ||$$$$$$$$$$$$$$$$$$||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||                    " << endl;
		cout << " ||                    " << endl;
		cout << " ||                    " << endl;
		cout << " ||                  ||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||__________________||" << endl;
		break;
	case 'D': cout << " ||$$$$$$$$$$$$$$$$   " << endl;
		cout << " ||               $$  " << endl;
		cout << " ||                $$ " << endl;
		cout << " ||                || " << endl;
		cout << " ||                || " << endl;
		cout << " ||                || " << endl;
		cout << " ||                // " << endl;
		cout << " ||               //  " << endl;
		cout << " ||______________//   " << endl;
		break;
	case 'E': cout << " ||$$$$$$$$$$$$$$$$$$$$" << endl;
		cout << " ||                    " << endl;
		cout << " ||                    " << endl;
		cout << " ||                    " << endl;
		cout << " ||--------------------" << endl;
		cout << " ||                    " << endl;
		cout << " ||                    " << endl;
		cout << " ||                    " << endl;
		cout << " ||____________________" << endl;
		break;
	case 'F': cout << " ||$$$$$$$$$$$$$$$$$$$$" << endl;
		cout << " ||                    " << endl;
		cout << " ||                    " << endl;
		cout << " ||                    " << endl;
		cout << " ||--------------------" << endl;
		cout << " ||                    " << endl;
		cout << " ||                    " << endl;
		cout << " ||                    " << endl;
		cout << " ||                    " << endl;
		break;
	case 'G': cout << " ||$$$$$$$$$$$$$$$$$$||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||                    " << endl;
		cout << " ||                    " << endl;
		cout << " ||------------------||" << endl;
		cout << " ||------------------||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||__________________||" << endl;
		break;
	case 'H': cout << " ||                  ||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||------------------||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||                  ||" << endl;
		break;
	case 'I': cout << " ______________________" << endl;
		cout << "           ||          " << endl;
		cout << "           ||          " << endl;
		cout << "           ||          " << endl;
		cout << "           ||          " << endl;
		cout << "           ||          " << endl;
		cout << "           ||          " << endl;
		cout << "           ||          " << endl;
		cout << " $$$$$$$$$$$$$$$$$$$$$$" << endl;
		break;
	case 'J': cout << " ______________________" << endl;
		cout << "           ||          " << endl;
		cout << "           ||          " << endl;
		cout << "           ||          " << endl;
		cout << "           ||          " << endl;
		cout << " ||        ||          " << endl;
		cout << " ||        ||          " << endl;
		cout << " ||        ||          " << endl;
		cout << " ||________||          " << endl;
		break;
	case 'K': cout << " |||    / /            " << endl;
		cout << " |||   / /             " << endl;
		cout << " |||  / /              " << endl;
		cout << " ||| / /               " << endl;
		cout << " |||/ /                " << endl;
		cout << " |||$ $                " << endl;
		cout << " ||| $ $               " << endl;
		cout << " |||  $ $              " << endl;
		cout << " |||   $ $            " << endl;
		break;
	case 'L': cout << " ||                    " << endl;
		cout << " ||                    " << endl;
		cout << " ||                    " << endl;
		cout << " ||                    " << endl;
		cout << " ||                    " << endl;
		cout << " ||                    " << endl;
		cout << " ||                    " << endl;
		cout << " ||                    " << endl;
		cout << " ||____________________" << endl;
		break;
	case 'M': cout << " ||$ $         / /||   " << endl;
		cout << " || $ $       / / ||   " << endl;
		cout << " ||  $ $     / /  ||   " << endl;
		cout << " ||   $ $   / /   ||   " << endl;
		cout << " ||    $ $ / /    ||   " << endl;
		cout << " ||               ||   " << endl;
		cout << " ||               ||   " << endl;
		cout << " ||               ||   " << endl;
		cout << " ||               ||   " << endl;
		break;
	case 'N': cout << " ||$ $        ||       " << endl;
		cout << " || $ $       ||       " << endl;
		cout << " ||  $ $      ||       " << endl;
		cout << " ||   $ $     ||       " << endl;
		cout << " ||    $ $    ||       " << endl;
		cout << " ||     $ $   ||       " << endl;
		cout << " ||      $ $  ||       " << endl;
		cout << " ||       $ $ ||       " << endl;
		cout << " ||        $ $||       " << endl;
		break;
	case 'O': cout << " ||$$$$$$$$$$$$$$$$$$||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||__________________||" << endl;
		break;
	case 'P': cout << " ||$$$$$$$$$$$$$$$  " << endl;
		cout << " ||              $$ " << endl;
		cout << " ||               ||" << endl;
		cout << " ||               //" << endl;
		cout << " ||_____________//" << endl;
		cout << " ||                 " << endl;
		cout << " ||                 " << endl;
		cout << " ||                 " << endl;
		cout << " ||                 " << endl;
		break;
	case 'Q': cout << " ||$$$$$$$$$$$$$$$$$$||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||         $ $      ||" << endl;
		cout << " ||          $ $     ||" << endl;
		cout << " ||           $ $    ||" << endl;
		cout << " ||____________$ $___||" << endl;
		cout << "                $ $    " << endl;
		break;
	case 'R': cout << " ||$$$$$$$$$$$$$$$     " << endl;
		cout << " ||              $$    " << endl;
		cout << " ||               ||   " << endl;
		cout << " ||               //   " << endl;
		cout << " ||______________//    " << endl;
		cout << " ||       $ $          " << endl;
		cout << " ||        $ $         " << endl;
		cout << " ||         $ $        " << endl;
		cout << " ||          $ $       " << endl;
		break;
	case 'S': cout << " ||$$$$$$$$$$$$$$$$$$$$" << endl;
		cout << " ||                    " << endl;
		cout << " ||                    " << endl;
		cout << " ||                    " << endl;
		cout << " ||--------------------" << endl;
		cout << "                     ||" << endl;
		cout << "                     ||" << endl;
		cout << "                     ||" << endl;
		cout << " ____________________||" << endl;
		break;
	case 'T': cout << " $$$$$$$$$$$$$$$$$$$$$$" << endl;
		cout << "           ||          " << endl;
		cout << "           ||          " << endl;
		cout << "           ||          " << endl;
		cout << "           ||          " << endl;
		cout << "           ||          " << endl;
		cout << "           ||          " << endl;
		cout << "           ||          " << endl;
		cout << "           ||          " << endl;
		break;
	case 'U': cout << " ||                  ||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||                  ||" << endl;
		cout << " ||__________________||" << endl;
		break;
	case 'V': cout << "  $$                // " << endl;
		cout << "   $$              //  " << endl;
		cout << "    $$            //   " << endl;
		cout << "     $$          //    " << endl;
		cout << "      $$        //     " << endl;
		cout << "       $$      //      " << endl;
		cout << "        $$    //       " << endl;
		cout << "         $$  //        " << endl;
		cout << "          $$//         " << endl;
		break;
	case 'W': cout << "$$                         //" << endl;
		cout << " $$                       // " << endl;
		cout << "  $$                     //  " << endl;
		cout << "   $$                   //   " << endl;
		cout << "    $$      //$$       //    " << endl;
		cout << "     $$    //  $$     //     " << endl;
		cout << "      $$  //    $$   //      " << endl;
		cout << "       $$//      $$ //       " << endl;
		cout << "        $/         $/        " << endl;
		break;
	case 'X': cout << "  $$               //  " << endl;
		cout << "    $$           //    " << endl;
		cout << "      $$       //      " << endl;
		cout << "        $$   //        " << endl;
		cout << "           $/          " << endl;
		cout << "          // $$        " << endl;
		cout << "        //     $$      " << endl;
		cout << "      //         $$    " << endl;
		cout << "    //             $$  " << endl;
		break;
	case 'Y': cout << "  $$               //  " << endl;
		cout << "    $$           //    " << endl;
		cout << "      $$       //      " << endl;
		cout << "        $$   //        " << endl;
		cout << "           $/          " << endl;
		cout << "           ||          " << endl;
		cout << "           ||          " << endl;
		cout << "           ||          " << endl;
		cout << "           ||          " << endl;
		break;
	case 'Z': cout << " ____________________  " << endl;
		cout << "                   //  " << endl;
		cout << "                 //    " << endl;
		cout << "              //       " << endl;
		cout << "           //          " << endl;
		cout << "        //             " << endl;
		cout << "     //                " << endl;
		cout << "  //                   " << endl;
		cout << " $$$$$$$$$$$$$$$$$$$$$ " << endl;
		break;
	} // switch

} // P_L function
