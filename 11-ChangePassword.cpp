// Password - This program starts off by asking the user what length of password they want generated, validating that they enter a length that is 
//            below 24. The program then randomly generates a password for the user and then asked the user to type the password that was randomly
//            generated two times (the program makes sure that when the user enters this password, they can't see what they are inputting), if
//            both the passwords match then the password is reset but if the 2 passwords that the user inputted doesn't match to the randomly
//            generated password then the user is asked to re-enter the password twice until both passwords match the randomly generated password. 
// Krishna Patel - Computer Science 30s
// May. 10 2022

// Constant for program
const int MAXSIZE = 24;                // Password can be up to 24 lengths

// Prototype
void seed_random();                   // seeds the random number generator

#include <iostream>
#include "MACcolors.h"
using namespace std;
int main(void)
{ // Main Program
	char p_c[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789" };  // All possible password characters
	int l_pass;                                                                         // The length of password the user wants
	char password[MAXSIZE + 1];                                                         // The randomly generated password (made space for eos 
	// character)
	char p2[MAXSIZE + 1];                                                               // The first time the user is asked to input the randomly 
	// generated password (made space for eos character)
	char p3[MAXSIZE + 1];                                                               // The second time the user is asked to input the randomly 
	// generated password (made space for eos character)
	int pos;                                                                            // Loop counter


	// Call the funtion to seed the random number generator
	seed_random();

	// Ask the user what length they want the password to be
	cout << "What length of password do you want (max = 24)? ";
	cin >> l_pass;

	// Validate that the length the user inputted is greater than 1 and less than 24
	while (l_pass < 1 || l_pass > 24)
	{
		cout << "INVALID - what length of password do you want? ";
		cin >> l_pass;
	} // while

	// Clear the buffer
	cin.ignore();

	// Randomly generate a password that is as many length as the user previously said they wanted 
	for (pos = 0; pos < l_pass; pos++)
	{
		password[pos] = p_c[rand() % strlen(p_c)];

	} // for
	// Add eos character
	password[pos] = '\0';


	// Tell the user their new password
	cout << "Your new password is " << password << endl;

	do
	{  // Ask user to type in password for 1st time
		cout << "Type your new password: ";
		cout << CYAN << B_CYAN;     // change color of text and background to same so the user can't see what password they inputted
		cin.getline(p2, MAXSIZE + 1, '\n');
		// Ask user to type in password for 2nd time
		cout << RESET << "Confirm your new password by re-typing it: ";
		cout << CYAN << B_CYAN;    // change color of text and background to same so the user can't see what password they inputted
		cin.getline(p3, MAXSIZE + 1, '\n');
		// Check if the passwords the user entered match the randomly generated one
		if (strcmp(password, p2) != 0 || strcmp(password, p3) != 0)
		{ // Passwords don't match (must re-enter twice again)
			cout << RESET << "PASSWORDS DON'T MATCH!!" << endl;
		} // if
		else
		{ // Passwordsdo match - the password is reset
			cout << RESET << "Password reset!!!";
		} // else
	} // do
	while (strcmp(password, p2) != 0 || strcmp(password, p3) != 0);

	return 0;
} // Main Program

// seed_random - This function seeds the random number generator
void seed_random()
{
	int i;                  // Loop counter

	// Seed the random number generator  - Use the system time
	srand((unsigned)time(NULL));
	for (i = 0; i < rand(); i++)
		rand();
} // seed_random