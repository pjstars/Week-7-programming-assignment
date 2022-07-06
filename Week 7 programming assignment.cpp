// Week 7 programming assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<iomanip>
#include<fstream>

//using namespace 
using namespace std;

//struct Bowler
struct Bowler
{
	string name;
	int scores[5]{};
	int averageScore{};
};

//declare the constants and functions 
//const int cols = 5, rows = 10;
bool GetBowlingData(const string& filename, Bowler bowlers[], int& count);
void GetAverageScore(Bowler bowlers[], int count);
void PrettyPrintResults(Bowler bowlers[], int count);

int main()
{
	//declare the variables 
	int count = 0;

	//filename, rows, and columns
	string filename = "BowlingScores.txt";
	Bowler bowlers[100];

	//the precision 
	cout << setprecision(2) << fixed << showpoint;

	//call the functions 
	if (GetBowlingData(filename, bowlers, count))
	{
		GetAverageScore(bowlers, count);
		PrettyPrintResults(bowlers, count);
	}
	//if file not opened 
	else
	{
		cout << "** File Not Found **" << endl;
	}
	return 0;
}
//getBowlingData to read the bowling scores txt file 
bool GetBowlingData(const string& filename, Bowler bowlers[], int&count)
{
	//input stream for the file 
	ifstream dataIn;
	//open the input file 
	dataIn.open(filename.c_str());
	//check the file name 
	if (dataIn.fail())
	{
		cout << "**File Not Found **";
		return false;

	}
	else
	{
		//count the records in file 
		while (dataIn >> bowlers[count].name)
		{
			for (int& score : bowlers[count].scores)
			{
				dataIn >> score;
			}
			count++;
		}
		//cose the file 
		dataIn.close();
	}
	return true;
}
//GetAverageScore to calculate the average 
void GetAverageScore(Bowler bowlers[], int count)
{
	double total;
	//for loop to read the scores of each bowler 
	for (int i = 0; i < count; i++)
	{
		total = 0;
		for (int score : bowlers[i].scores)
		{
			total += score;
		}

		//calculate average
		bowlers[i].averageScore = (int)(total / 5);
	}
}
//display the output
void PrettyPrintResults(Bowler bowlers[], int count)
{
	//header
	cout <<setw(14) << left << "Name" << setw(8) <<left << "Score1\tScore2\tScore3\tScore4\tScore5\tAverage" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << setw(14) << left << bowlers[i].name;
		for (int score : bowlers[i].scores) {
			cout << score<< "\t";
		}
		cout << setw(5) << bowlers[i].averageScore << endl;
	}
}


