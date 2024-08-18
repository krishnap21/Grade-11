// Word Analyzer - This program asks the user how many words they want to analyze and then runs asking the user to enter a word the amount of times
//                  the user said they wanted to analyze a word. After the user inputs each word, the program prints out the value of that word, 
//                  the program does this by looking at each individual letter in the word, the letter already has a value thanks to the ASCII 
//                  code so the program simply adds the value of each individual letter therefore providing the value of the word. If the user 
//                  determines a word with a value of 100, the program prints a message telling that they have discovered a word with a value of 
//                  100, if the user has not discovered a word with the value of 100, the program keeps asking the user for a word depending on 
//                  how many words the user said they wanted to analyze.
// Krishna Patel - Computer Science 30s
// May. 15 2022

// Words with a value of 100% that I found - Grumpy, Embodiment, Honeycomb, Magnetize

// Constant for the program
const int MAXSIZE = 26;

#include <iostream>
using namespace std;
int main()
{
	char alphabet[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };         // All possible characters for the words that the user enters
	char word[MAXSIZE];                                         // The word that the user enters
	int numword;                                                // The amount of words the user wants to analyze
	int word_value;                                             // The value of the word the user entered
	int pos;                                                    // Loop counter 1
	int pos2;                                                   // Loop counter 2
	int x;                                                      // Loop counter 3
	int add;                                                    // The value of each individual letter in the word the user entered

	// Welcome the user
	cout << "Welcome to the Word Alphabetic Knowledge And Numeric Data Analyzer (WAKANDA)" << endl;

	// Ask the user for how many words they want to analyze
	cout << "How many words do you want to analyze? ";
	cin >> numword;

	// Clear the buffer
	cin.ignore();

	// Loop asking the user for each word
	for (x = 0; x < numword; x++)
	{   // Ask user to enter word
		cout << endl;
		cout << "Enter word #" << x + 1 << ": ";
		cin.getline(word, MAXSIZE, '\n');

		// Loop through making the word the user enetered into all uppercase letters
		for (pos = 0; pos < strlen(word); pos++)
		{
			word[pos] = toupper(word[pos]);
		} // for
		
		cout << word << " has a WAKANDA value of ";

		// Initialize the word and add values
		word_value = 0;
		add = 0;
		// Loop through each letter in the word, finding its value
		for (pos = 0; pos < strlen(word); pos++)
		{   // Initialize pos2 value
			pos2 = 0;
			while (alphabet[pos2] != word[pos])
			{
				pos2++;
			} // while
			// Perform calculations
			word_value += (pos2 + 1);
			add = pos2 + 1;
			// Print out to make output look nice
			cout << add;
			// To make the ouput look nice
			if (pos + 1 == strlen(word))
			{
				cout << " = ";
			} // if
			else
			{
				cout << " + ";
			} // else
		} // for
		// Final comment which tells the user what value their word had
		cout << word_value << "%";
		// If the user found a word with a value of 100% congratulate them for doing so
		if (word_value == 100)
		{ 
			cout << endl;
			cout << "CONGRATULATIONS - you have discovered a 100% word - " << word << "!!!!" << endl;
		} // if
	} // for

	return 0;
} // Main Program