// Curling - This program starts by randomly giving the hammer to one team and then plays 10 rounds which are based on invented percentages
//           where the chance of both teams scoring 0 is 15%, the chance of the hammer team scoring 1 is 20%, scoring 2 is 15%, scoring 3
//           is 10% and scoring 4 is 5%. And the chance of the team without the hammer stealing and scoring 1 is 19%, stealing and scoring
//           2 is 10%, stealing and scoring 3 is 5% and stealing and scoring 4 is 1%. At the end of printing out the 10 rounds, if both
//           teams are tied, the program automatically plays extra ends until there is a winner. Once there is a winner, the program prints
//           which team won (30s or 40s) and gives the score of both teams added up. 
// Krishna Patel - Computer Science 30s
// Feb. 28 2022

// Prototypes
bool coin_toss(void);                                          // This function is used to determine which team gets the hammer first by 
// doing a coin flip
void seed_R(void);                                             // This function is to seed the random number generator
void play_end(bool& first_team, int& t1score, int& t2score);   // This function plays an end, and determines based on the percentages what
// happened and which team scored for that round.


#include <iostream>
using namespace std;
int main(void)
// Main Program
{
	bool first_team; // Tells if the first team has the hammer
	int score1;      // Used to show team 30s' score
	int score2;      // Used to show team 40s' score
	int end_num;     // Used to print out the round number

	// Seed the random number
	seed_R();

	// Do coin toss and print the results
	first_team = coin_toss();
	if (first_team)
	{
		cout << "Team 30s starts with the hammer" << endl;
	} // if
	else
	{
		cout << "Team 40s starts with the hammer" << endl;
	} // else

	// Initialize scores
	score1 = 0;
	score2 = 0;

	cout << "END               TEAM 30               TEAM 40S" << endl;
	// Loop for 10 ends
	for (end_num = 1; end_num <= 10; end_num++)
	{
		// Print end number
		cout << end_num;

		// Space added to make the output line up neatly
		if (end_num < 10)
		{
			cout << " ";
		} // if

		// Call function for each end
		play_end(first_team, score1, score2);
	} // for

	// If score is still tied, play extra end(s)
	while (score1 == score2)
	{
		cout << "extra end:" << endl;
		cout << "EN";
		// Call function for the extra end
		play_end(first_team, score1, score2);
		end_num++;
	} // for 

	// Print winner and final score 
	cout << endl;
	cout << "FINAL SCORE : " << endl;
	if (score1 > score2)
	{
		cout << "TEAM 30S WINS " << score1 << "-" << score2 << "!!!!" << endl;
	} // if
	else
	{
		cout << "TEAM 40S WINS " << score2 << "-" << score1 << "!!!!" << endl;
	} // else

	return 0;
} // main

// coin_toss - This function returns true if the first tem has the hammer or false if not - it basically flips a coin to see which team
//             gets the hammer
bool coin_toss(void)
{
	int value; // identifier that is given the random value of 1 or 2

	value = rand() % 2 + 1;

	if (value == 1)
	{
		return false;
	} // if
	else
	{
		return true;
	} // else
} // bool

// play-end - This function determines decides what score each team gets depending on percentages and it adjust the teams scores and 
//            adjusts the reference first_team parameter to show which team scored
// first_team - Used to show which team scored and update the hammer
// team1, team2 - Used to update team 30s and team 40s' scores
void play_end(bool& first_team, int& team1, int& team2)
{
	int result; // This identifier is assigned a random number from 1-100 and used to check to see hat happened/which team scored 
	// based on the percentages

// Get random result value
	result = rand() % 100 + 1;

	// Check to see what happened
	if (result <= 15)
	{
		// Blank end
		cout << "                   0		            0" << endl;
	} // if <= 15
	else
	{
		if (result <= 35)
		{ // Hammer team scores 1
			if (first_team) // The first team had the hammer
			{
				cout << "                   1			    0" << endl;
				team1 += 1;
			} // if
			else // The second team had the hammer
			{
				cout << "                   0		            1" << endl;
				team2 += 1;
			} // else
			// Update hammer
			first_team = !first_team;
		} // if <= 35
		else
		{
			if (result <= 50)
			{ // Hammer team scores 2 
				if (first_team) // The first team had the hammer
				{
					cout << "                   2			    0" << endl;
					team1 += 2;
				} // if
				else
				{
					cout << "                   0		            2" << endl;
					team2 += 2;
				} // else
				// Update hammer
				first_team = !first_team;
			} // if <= 50
			else
			{
				if (result <= 60)
				{ // Hammer team scores 3 
					if (first_team) // The first team had the hammer
					{
						cout << "                   3			    0" << endl;
						team1 += 3;
					} // if
					else
					{
						cout << "                   0			    3" << endl;
						team2 += 3;
					} // else
					// Update hammer
					first_team = !first_team;
				} // if <= 60
				else
				{
					if (result <= 65)
					{ // Hammer team scores 4 
						if (first_team) // The first team had the hammer
						{
							cout << "                   4			    0" << endl;
							team1 += 4;
						} // if
						else
						{
							cout << "                   0			    4" << endl;
							team2 += 4;
						} // else
						// Update hammer
						first_team = !first_team;
					} // if <= 65
					else
					{
						if (result <= 84)
						{ // Non Hammer team scores 2 
							if (first_team) // The first team didn't have the hammer
							{
								cout << "                   0                      1" << endl;
								team2 += 1;
							} // if
							else
							{
								cout << "                   1			    0" << endl;
								team1 += 1;
							} // else
						} // if <= 84
						else
						{
							if (result <= 94)
							{ // Non Hammer team scores 2 
								if (first_team) // The first team didn't have the hammer
								{
									cout << "                   0			    2" << endl;
									team2 += 2;
								} // if
								else
								{
									cout << "                   2			    0" << endl;
									team1 += 2;
								} // else
							} // if <= 94
							else
							{
								if (result <= 99)
								{ // Non Hammer team scores 2 
									if (first_team) // The first team didn't have the hammer
									{
										cout << "                   0			    3" << endl;
										team2 += 3;
									} // if
									else
									{
										cout << "                   3		            0" << endl;
										team1 += 3;
									} // else
								} // if <= 99 
								else
								{
									if (result <= 100)
									{ // Non Hammer team scores 2 
										if (first_team) // The first team didn't have the hammer
										{
											cout << "                   0                      4" << endl;
											team2 += 4;
										} // if
										else
										{
											cout << "                   4			    0" << endl;
											team1 += 4;
										} // else
									} // if <= 100
								} // else
							} // else
						} // else
					} // else
				} // else

			} // else
		} //else
	} // else
} // play_end


// seed_R - This function is used to seed the random number generator
void seed_R(void)
{
	int i;                  // Loop counter

	// Seed the random number generator  - Use the system time
	srand((unsigned)time(NULL));
	for (i = 0; i < rand(); i++)
		rand();
} // seed_R