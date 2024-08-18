// POWERrangers - This program asks the user to input a base and a power 3 times and then returns the answer to the base raised
//                to the power of the exponent. The program makes sure to validate that the user doesn't enter a base and power
//                of 0. Finally the program asks the user to input 2 sets of base/exponents and then calculate those sets of 
//                bases/exponenets added together and then when they are a power of a power.
// Krishna Patel - Comp Sci 30s
// Feb. 20 2022

#include <iostream>
using namespace std;


// Prototypes
float power(int base, int exponent);// performs the calulations to return the answer for the users input 
bool VAL(int check_b, int check_e); // used to validate if the base and exponent that the user entered is 0

// Main
int main(void)
{
	int B;         // base user inputs 3 times
	int E;         // exponent user inputs 3 times
	int B_;        // the base of the 1st set from the 2 sets of bases/exponents that the user is asked for
	int E_;        // the exponent of the 1st set from the 2 sets of bases/exponents that the user is asked for
	int B_2;       // the base of the 2nd set from the 2 sets of bases/exponents that the user is asked for
	int E_2;       // the exponent of the 2nd set from the 2 sets of bases/exponents that the user is asked for
	int P1;        // used to help raise the first set of base / exponent to the second set of base / exponent
	int P2;        // used to help raise the first set of base / exponent to the second set of base / exponent


	// Loop through 3 times to ask the user to input a base and an exponent
	for (int x = 1; x <= 3; x++)
	{
		cout << endl;
		cout << "Enter a base: ";
		cin >> B;
		cout << "Enter an exponent: ";
		cin >> E;
		// Validate 
		while (!VAL(B, E))
		{
			cout << " Invaild - both the base and the exponent can't be 0! Please re-enter" << endl;
			cout << "Enter a base: ";
			cin >> B;
			cout << "Enter an exponent: ";
			cin >> E;
			VAL(B, E);
		} // while
		// call the function
		power(B, E);
		// print out results in a nice format
		cout << B << "^" << E << " = " << power(B, E);
		cout << endl;
	} // for loop | 1st part of program

	// 2nd part of the program: ask user for 2 sets of bases/exponents
	cout << endl;
	cout << "Enter a base: ";
	cin >> B_;
	cout << "Enter an exponent: ";
	cin >> E_;
	cout << endl;
	cout << "Enter a second base: ";
	cin >> B_2;
	cout << "Enter a second exponent: ";
	cin >> E_2;
	cout << endl;
	// Validate 
	while (!VAL(B_, E_) || !VAL(B_2, E_2))
	{
		cout << " Invaild - both the base and the exponent can't be 0! Please re-enter" << endl;
		cout << "Enter a base: ";
		cin >> B_;
		cout << "Enter an exponent: ";
		cin >> E_;
		cout << endl;
		cout << "Enter a second base: ";
		cin >> B_2;
		cout << "Enter a second exponent: ";
		cin >> E_2;
		cout << endl;
		VAL(B_, E_);
		VAL(B_2, E_2);
	} // while loop
// call the function
	power(B_, E_) && power(B_2, E_2);
	// print out results in a nice format
	cout << "(" << B_ << " to the power of " << E_ << " which equals " << power(B_, E_) << ") + (" << B_2 << " to the power of " << E_2 << " which equals " << power(B_2, E_2) << ") is: " << power(B_, E_) + power(B_2, E_2) << endl;
	P1 = power(B_, E_);
	P2 = power(B_2, E_2);
	cout << "(" << B_ << " to the power of " << E_ << " which equals " << power(B_, E_) << ") to the power of (" << B_2 << " to the power of " << E_2 << " which equals " << power(B_2, E_2) << ") is: " << power(P1, P2);

return 0;
} // main


// power - this function returns the base that the user inputted to the power of the exponent that the user inputted 
// base, exponent - the answer is to be calculated 
float power(int base, int exponent)
{
	float answer; // the answer that is returned when the base is raised to the exponent


	// check to see if exponent is 0 and returns 1
	if (exponent == 0)
	{
		return 1;
	} // if 
	else
	{   // check to see if exponent is positive
		if (exponent > 0)
		{
			answer = 1;
			// loop through each multiplication
			for (int counter = 1; counter <= exponent; counter++)
			{
				answer *= base;

			} // for loop
			// send back result
			return answer;
		} // if
		else
		{   // check to see if exponent is negative
			if (exponent < 0)
			{
				answer = 1;
				// loop through each multiplication
				for (int counter = 1; counter <= (exponent * -1); counter++)
				{
					answer *= 1.0 / base;
				} // for loop
				// send back result
				return answer;
			} // if loop

		} // else loop
	} // else loop

} // power

// val - this function returns true if the base and exponent that the user inputted is both 0
// check_b, check_e - check to see is base and exponent is 0
bool VAL(int check_b, int check_e)
{
	if (check_b == 0 && check_e == 0)
	{
		return false;
	}
	else
	{
		return true;
	} // else
} // bool


