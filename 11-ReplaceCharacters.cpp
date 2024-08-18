// Replace - This function starts off by asking the user how many sentences they want to enter. Once the user has entered the amount, the program asks the 
//          user to enter the first sentence, once the user has entered the phrase, the program asks what character the user wants to replace and then
//          what that character should be replaced with, the program keeps asking the user what character they want to replace and with what until the 
//          user decides they no longer want to replace any characters and then the program makes the replacements and prints out the total replacements
//          that were made in that sentence and what that sentence now looks like with the new characters. The program repeats this process of asking for
//          a sentence, asking for what character the user wants to replace and asking what to replace that character depending on the number of sentences
//          the user said they wanted to enter at the beginning of the game. 
// May. 8 2022
// Krishna Patel - Computer Science 30s

// Constant for program
const int MAXSIZE = 80;                // Maximum size of a line

// Prototype
int replace(char string[], char badchar, char newchar);      // This function replaces the characters in the orginal sentence with the new characters 
// that the user wants

#include <iostream>
using namespace std;
int main(void)
{
	char string[MAXSIZE];        // The string that will be replaced with new characters
	char badchar;                // The character that the user wants to replace in the string
	char newchar;                // The new character that will be put in the place of the character that the user wants to replace (badchar)
	int num_s;                   // The number of strings the user wants to enter
	int howmany;                 // Keeps track of how many replacements were made
	int count;                   // Loop counter
	char more;                    // Used to ask the user if they want to replace more characters

	// Initialize howmany to keep track of total replacement
	howmany = 0;
	// Ask the user how many strings they want to enter
	cout << "How many strings are there?";
	cin >> num_s;

	// Clear the buffer
	cin.ignore();

	// Loop through each phrase
	for (count = 1; count <= num_s; count++)
	{
		cout << endl;
		// Ask for phrase
		cout << "Enter string #" << count << ":";
		cin.getline(string, MAXSIZE, '\n');
		do
		{
			// Get the character that the user wants to replace
			cout << "Enter character to replace: ";
			badchar = _getwche();
			cout << endl;
			// Replace that character
			cout << "What should " << badchar << " be replaced with? ";
			newchar = _getwche();
			cout << endl;
			// Call function and keep track of how many replacements were made
			howmany += replace(string, badchar, newchar);
			// Want to replace more character?
			cout << "Do you want another replacement? (Y/N) ";
			more = toupper(_getwche());
			cout << endl;
		}  // do
		while (more == 'Y');

		// FINAL COMMENT
		cout << "After a total of " << howmany << " replacements, the final string is: " << string << endl;
		// Re-initialize howmany for the next string
		howmany = 0;
	} // for

	return 0;
} // main

// replace - replaces the characters in the original string with the new characters that the user wants
// string - the orginal phrase
// badchar - the character the user wants to replace
// newchar - the charcater that will replace badchar
int replace(char string[], char badchar, char newchar)
{
	int pos;      // Loop counter
	int howmany;  // Keeps track of how many replacements were made

	// Initialize howmany
	howmany = 0;

	// Loop through to replace characters
	for (pos = 0; pos < strlen(string); pos++)
	{
		// If that letter is the character that the user wants to replace then...
		if (string[pos] == badchar)
		{   // change the bad char to new char
			string[pos] = newchar;
			// update howmany
			howmany++;
		} // if
	} // for

	// return the number of replacements
	return howmany;
} // replace