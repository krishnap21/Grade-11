// Manager - This program provides the user with sevral options which are  Enter Data, Highest, Lowest, Range, Positive, Negative, Average, Variance or Quit and based
//           on which option the user picks the program acts accordingly. The program makes sure that before calculating the Highest, Lowest, Range, Positive, Negative,
//           Average or Variance values, it validates that the user enters values in the Enter_Data function. In this function the user is aksed how many values they
//           want to enter and then asked to enter that many values. In the highest function the program finds the highest number in the data, while in the Lowsr function
//           the prgram does the opposite and finds the lowest number in the data. In the Range function, the range of the data is calculated by calling the Highest and
//           Lowest function and then subtracting the Lowest funtion form the Highest unction. The Positive function finds the number of positive values in the data, while
//           the Negative function does the opposite and finds the number of negative values in the data. The average function finds the average value in the data which
//           is calculated by adding up all the numbers in the data and dividing by how many numbers there were in total and the Variance function calculates the variance
//           in the data which is founds by calculating the sum of (each Data value - Average)^2 and then dividing the sum by the (number of values - 1). Finally the user
//           has the option to Quit the program which just ends the program
// Krishna Patel - Computer Science 30s
// March. 27 2022

// Prototypes
void Enter_Data(int data[15], int& howmany); // asks how many values will be entered and then asks user to enter that many values
char Menu(void);                             // provides the user with options from which they can choose what they want to do
int Highest(int data[15], int howmany);      // finds the highest value in the data
int Lowest(int data[15], int howmany);       // finds the lowest value in the data
int Range(int data[15], int howmany);        // finds the range value in the data, which is the higest value minus the lowest value
int Positive(int data[15], int howmany);     // tells how many numbers in the data set are positive
int Negative(int data[15], int howmany);     // tells how many numbers in the data set are negative
int Average(int data[15], int howmany);      // calculates the average of all the data (which is calculated by adding up all the numbers in the data and dividing
// by how many numbers there were in total )
int Variance(int data[15], int howmany);     // calulates the sum of (each Data value - Average)^2 and then divides the sum by the (number of values - 1)


#include <iostream>
using namespace std;
int main(void)
// Main Program
{
	int howmany;       // the number of values the user decided to enter (less than 15)
	char choice;       // the users choice on what they want to calulate
	int data[15];      // the array of number of data values entered by the user (the maximum data values that the user can enter is 15)
	int high;          // the highest value in the data
	int low;           // the lowest value in the data
	int range;         // the range value in the data
	int average;       // the average value
	int positive;      // the number of positive values
	int negative;      // the number of negative values
	int variance;      // the variance value
	// Set howmany to a dummy value
	howmany = -1;
	// Loop until the user quits
	do
	{
		// Call function the get the menu choice
		choice = Menu();
		// Perform actions based on choice
		switch (choice)
		{   // the user is asked how many values they want to enter and then enter that many values
		case 'E':Enter_Data(data, howmany); break;
			// data and how many values from Enter_Data function is sent to the Highest function
		case 'H': high = Highest(data, howmany);
			// check for no data
			if (high == INT_MAX)
			{
				cout << "INVALID - you need to enter data first!" << endl;
			} // if
			else
			{   // Print the highest value
				cout << "The highest value is " << high << endl;
			} // else
			break;
			// data and how many values from Enter_Data function is sent to the Lowest function
		case 'L': low = Lowest(data, howmany);
			// check for no data
			if (low == INT_MAX)
			{
				cout << "INVALID - you need to enter data first!" << endl;
			} // if
			else
			{   // Print the lowest value
				cout << "The lowest value is " << low << endl;
			} // else
			break;
			// data and how many values from Enter_Data function is sent to the Range function
		case 'R': range = Range(data, howmany);
			// check for no data
			if (range == INT_MAX)
			{
				cout << "INVALID - you need to enter data first!" << endl;
			} // if
			else
			{   // Print the range value
				cout << "The range value is " << range << endl;
			} // else
			break;
			// data and how many values from Enter_Data function is sent to the Average function
		case 'A': average = Average(data, howmany);
			// check for no data
			if (average == INT_MAX)
			{
				cout << "INVALID - you need to enter data first!" << endl;
			} // if
			else
			{   // Print the average value
				cout << "The average value is " << average << endl;
			} // else
			break;
			// data and how many values from Enter_Data function is sent to the Positive function
		case 'P': positive = Positive(data, howmany);
			// check for no data
			if (positive == INT_MAX)
			{
				cout << "INVALID - you need to enter data first!" << endl;
			} // if
			else
			{   // Print the amount of positive values
				cout << "There are " << positive << " positive values " << endl;
			} // else
			break;
			// data and how many values from Enter_Data function is sent to the Negative function
		case 'N':  negative = Negative(data, howmany);
			// check for no data
			if (negative == INT_MAX)
			{
				cout << "INVALID - you need to enter data first!" << endl;
			} // if
			else
			{   // Print the amount of negative values
				cout << "There are " << negative << " negative values " << endl;
			} // else
			break;
			// data and how many values from Enter_Data function is sent to the Variance function
		case 'V': variance = Variance(data, howmany);
			// check for no data
			if (variance == INT_MAX)
			{
				cout << "INVALID - you need to enter data first!" << endl;
			} // if
			else
			{   // Print the variance value
				cout << "The variance value is " << variance << endl;
			} // else
			break;
		} // Switch choice
	} while (choice != 'Q');
	return 0;
} // Main Program

// Menu - This function asks the user for what they want to play and validates that they answer Enter Data, Highest, Lowest, Range, Positive,
//        Negative, Average, Variance or Quit
char Menu(void)
{
	char choice; // Users choice on what they want to play

	// Ask user
	cout << " Do you want to (E)nter Data or calculate (H)ighest, (L)owest, (R)ange, (P)ositive, " << endl;
	cout << "                (N)egative, (A)verage, (V)ariance or (Q)uit? ";
	choice = toupper(_getwche());
	cout << endl;

	// Validate the users choice
	while (choice != 'E' && choice != 'H' && choice != 'L' && choice != 'R' && choice != 'P' && choice != 'N'
		&& choice != 'A' && choice != 'V' && choice != 'Q')
	{
		cout << "INVALID CHOICE - pick (E)nter Data, (H)ighest, (L)owest, (R)ange, (P)ositive, (N)egative," << endl;
		cout << "                (A)verage, (V)ariance or (Q)uit:";
		choice = toupper(_getwche());
		cout << endl;
	} // while 
	// Return the choice 
	return choice;
} // Menu

// Enter_Data - this function asks the user how many values will be entered (validating that it is 15 or less and then asks user to enter that many values
// data - the different numbers that the user entered (EX: 3,4,5)
// howmany - the number of values the user entered all together (for the example above howmany would be 3 because the user entered 3 numbers)
void Enter_Data(int data[15], int& howmany)
{
	int i; // Loop counter

	// Ask the user how many values they want to enter
	cout << "How many values do you want to enter?";
	cin >> howmany;

	// Validate that the user enters 15 or less values
	while (howmany > 15)
	{
		cout << "INVALID: you can only enter 15 or less values - how many values do you want to enter?";
		cin >> howmany;
	} // while

	// The user is asked to enter as many values as they previously wanted to enter
	// Loop for how many values the user wanted to enter
	for (i = 0; i < howmany; i++)
	{
		cout << "Enter value #" << i + 1 << " please:";
		cin >> data[i];
	} // for
} // Enter_Data



// Highest - this function finds the highest number in the data
// data - the different numbers that the user entered (EX: 3,4,5)
// howmany - the number of values the user entered all together (for the example above howmany would be 3 because the user entered 3 numbers)
int Highest(int data[15], int howmany)
{
	int high;   // The highest value in the data
	int i;      // Loop counter

	// Check to see if any there are any values entered
	if (howmany == -1)
	{   // Return a dummy value
		return INT_MAX;
	} // if
	else
	{
		// Assume 1st value is the highest value
		high = data[0];
		// Loop through, looking for higher values
		for (i = 1; i < howmany; i++)
		{
			if (data[i] > high)
			{
				high = data[i];
			} // if
		} // for
	} // else

	// Return the highest value
	return high;
} // Highest

// Lowest - this function find the lowest number in the data
// data - the different numbers that the user entered (EX: 3,4,5)
// howmany - the number of values the user entered all together (for the example above howmany would be 3 because the user entered 3 numbers)
int Lowest(int data[15], int howmany)
{
	int low;  // The lowest value in the data
	int i;    // Loop counter

	// Check to see if any there are any values entered
	if (howmany == -1)
	{   // Return a dummy value
		return INT_MAX;
	} // if
	else
	{
		// Assume 1st value is the lowest value
		low = data[0];
		// Loop through, looking for lower values
		for (i = 1; i < howmany; i++)
		{
			if (data[i] < low)
			{
				low = data[i];
			} // if
		} // for
	} // else

	// Return the lowest value
	return low;
} // Lowest

// Range - his function finds the range value in the data (which is the highest value minus the lowest value)
// data - the different numbers that the user entered (EX: 3,4,5)
// howmany - the number of values the user entered all together (for the example above howmany would be 3 because the user entered 3 numbers)
int Range(int data[15], int howmany)
{
	int range;   // the range value in the data

	// Check to see if any there are any values entered
	if (howmany == -1)
	{   // Return a dummy value
		return INT_MAX;
	} // if
	else
	{ // Calculate the range by calling the highest and lowest function
		range = (Highest(data, howmany)) - (Lowest(data, howmany));
	} // else

	// Return the range value
	return range;
} // Range

// Average - this function calculates the average value in the data (which is adding up all the numbers and dividing by how many numbers there were)
// data - the different numbers that the user entered (EX: 3,4,5)
// howmany - the number of values the user entered all together (for the example above howmany would be 3 because the user entered 3 numbers)
int Average(int data[15], int howmany)
{
	int average;    // the average value in the data
	int sum;        // all the numbers in the data added up 
	int i;          // Loop counter

	// Check to see if any there are any values entered
	if (howmany == -1)
	{   // Return a dummy value
		return INT_MAX;
	} // if
	else
	{
		// Initialize the sum value
		sum = 0;

		// Loop through to find the average
		for (i = 0; i < howmany; i++)
		{
			sum += data[i];
		} // for

		// Calculate the average
		average = sum / howmany;
	} // else

	// Return average value
	return average;
} // Average

// Positive - this function finds how many positive values there are in the data
// data - the different numbers that the user entered (EX: 3,4,5)
// howmany - the number of values the user entered all together (for the example above howmany would be 3 because the user entered 3 numbers)
int Positive(int data[15], int howmany)
{
	int positive;  // the number of positive values
	int i;         // Loop counter

	// Check to see if any there are any values entered
	if (howmany == -1)
	{   // Return a dummy value
		return INT_MAX;
	} // if
	else
	{
		// Initialize positive value
		positive = 0;

		// Loop through looking for all the positive values
		for (i = 0; i < howmany; i++)
		{
			if (data[i] > 0)
			{
				positive++;
			} // else
		} // for
	} // else

	// Return positive value
	return positive;
} // Positive

// Negative - this function fidns how many negative values there are in the data
// data - the different numbers that the user entered (EX: 3,4,5)
// howmany - the number of values the user entered all together (for the example above howmany would be 3 because the user entered 3 numbers)
int Negative(int data[15], int howmany)
{
	int negative;  // the number of negative values
	int i;         // Loop counter

	// Check to see if any there are any values entered
	if (howmany == -1)
	{   // Return a dummy value
		return INT_MAX;
	} // if
	else
	{
		// Initialize neagtive value
		negative = 0;
		// Loop through looking for all the negative values
		for (i = 0; i < howmany; i++)
		{
			if (data[i] < 0)
			{
				negative++;
			} // else
		} // for
	} // else

	// Return negative value
	return negative;
} // Negative

// Variance - this function finds the varinace in the data (which is calulated by the sum of (each Data value - Average)^2 and then divides the sum by the 
//            (number of values - 1))
// data - the different numbers that the user entered (EX: 3,4,5)
// howmany - the number of values the user entered all together (for the example above howmany would be 3 because the user entered 3 numbers)
int Variance(int data[15], int howmany)
{
	int sum;       // all the numbers in the data added up 
	int average;   // the average value in the data
	int variance;  // the variance value in the data
	int i;         // Loop counter

	// Check to see if any there are any values entered
	if (howmany == -1)
	{   // Return a dummy value
		return INT_MAX;
	} // if
	else
	{
		// Call the average function and store that value into an identifier
		average = Average(data, howmany);

		// Initialize the sum value
		sum = 0;
		// Loop through all the numbers in the data 
		for (i = 0; i < howmany; i++)
		{
			// Perform the calculations
			sum += ((data[i] - average) * (data[i] - average));
		} // for

		// find the variance
		variance = sum / (howmany - 1);
	} // else

	// Return the variance value
	return variance;
} // Variance


