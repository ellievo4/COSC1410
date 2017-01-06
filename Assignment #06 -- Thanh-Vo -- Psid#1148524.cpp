/*
Course:		COSC - 1410
Assignment: #06
Date Due :  3 - 23 - 2015
Student :   Thanh Vo
Peoplesoft: 1148524
TA :        David Fullerton

Purpose:    The purpose of this lab is to help me have a better understanding of functions and arrays. More
			specifically I am looking for: function definitions and prototypes, call-by-value and call-by-
			reference parameters, and also array definition and usage. 
*/

// libraries to add that are required for this program with 
// identification of what library gives what objects
	#include <iostream>      // provides:  cout, cin
	#include <cstdlib>       // provides:  system, srand, rand()
	#include <ctime>         // provides:  time(0)
	#include <cmath>         // provides:  sqrt
	#include <iomanip>       // provides:  setw()

// set user environment
	using namespace std;
	 
// global constants & variables
	const int NUMSCORE = 100;			 // number of input score is 100

	const double MAXSCORE = 100.00;      // maximum score is 100.00
	const double MINSCORE = 0.00;		 // minimum score is 0.00

// This is the function declarations
	int getScore1();										 								// get a random score from 0 to 40
	int getScore2(); 										 								// get a random score from 40 to 70
	int getScore3(); 										 								// get a random score from 70 to 100
	void getScores (int score[], int scoreSize); 											// get 100 scores
	double getMean(const int score[], int scoreSize);										// getting mean
	double getStd (const int score[], int scoreSize, double Mean);							// getting standard deviation
	void computeGrade (char grade[], int gradeSize, double range[], const int score[]);		// compute letter grades
	void computeRange(double range[], int rangeSize, double Mean, double StanDev);			// compute ranges for letter grades
	// print out scores and table of ranges
		void printStat(const int score[], int scoreSize, int counter[], char grade[], int gradeSize, double range[], int rangeSize);

//
// Setup of the program -- called once
//
void Program_Setup()
{   
    // one-time setup of output object (COUT) for pretty printing of decimal places
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);          
}

//
// Ending of the program -- called once
//
void Program_Ending()
{   
    // tell user to hit key and wait to return back to operating system
        cout << endl;
        system("pause");
        exit(0);        
}
	
//
// This is the main code for the program that is called from the operating system.
//
int main()
{
    // one-time setup of the program 
        Program_Setup();
	
	// list of local variables:
		double Avg;      // keep track with values of mean 
		double SD;		 // keep track with values of standard deviation
		
	// list of arrays:
		int score[NUMSCORE];			// keep track with a list of 100 scores
		int counter[NUMSCORE]; 			// keep track of count of  each letter score
		char grade[NUMSCORE];			// keep track of letter grades
		double range[4];				// keep track of ranges of score
		
	// avoid the repetition of random scores over times of execution  
		srand(time(0));  
		
	// do input scores
		getScores(score,NUMSCORE);
	
	// getting mean
		Avg = getMean(score,NUMSCORE); 
		
	// getting standard deviation
		SD = getStd(score,NUMSCORE,Avg); 
		
	// output number of scores, mean and standard deviation	
		cout << "Number of Scores: " << NUMSCORE << endl;
		cout << "Mean Score: 	  " << setw(5) << Avg << endl;
		cout << "Std deviation:    " << setw(5) << SD << endl;
		cout << endl;
		
	// compute range of 5 letter grades
		computeRange (range,4,Avg,SD);
		
	// compute letter grades
		computeGrade(grade,NUMSCORE,range,score);
		
	// print scores with responsive letter grades and a table of ranges of letter grades
		printStat (score,NUMSCORE,counter,grade,NUMSCORE,range,4);
		
	// program ends
        Program_Ending();	
}
		
//
// get any number from 0 to 40 and return that number 
//
int getScore1() 
{
	int num1;
	num1= rand()%41;
	return num1;	
}
	
//
// get any number from 40 to 70 and return that number 
//
int getScore2() 
{
	int num2;
	num2= rand()%31+40;
	return num2;
}

//
// get any number from 70 to 100 and return that number 
//
int getScore3() 
{
	int num3;
	num3= rand()%31+70;
	return num3;
}

//
// input 20% scores from 0 to 100 and 80% scores from 40 to 70 in array score[], input 0 to 100 for array counter[], and return sum and sumsq
// 
void getScores (int score[], int scoreSize) 
	{
	int i;
	
	// get 10 scores from 0 to 40 
		for (i = 0; i < (scoreSize - 90); i++) 
		{ 
			score[i]= getScore1();
		}
	
	// get 80 scores from 40 to 70
		for (i = 10; i < (scoreSize-10); i++)
		{ 
			score[i] = getScore2();
		}
	
	// get 10 scores from 70 to 100
		for (i=90; i < (scoreSize); i++)
		{
			score[i] = getScore3();
		}
	}
	
//
// use array score[] to calculate sum then divide by NUMSCORE to get mean, return Mean
//
double getMean(const int score[], int scoreSize)
{
	int sum = 0;
	double Mean;
	
	for (int i = 0; i<scoreSize; i++)
	{
		sum = sum + score[i];	
	}
	Mean = static_cast<double>(sum)/NUMSCORE;
	return Mean;
}

//
// use array score[] to calculate sumsq then divide by NUMSCORE to get standard deviation, return StanDev
//
double getStd (const int score[], int scoreSize, double Mean)
{
	double StanDev;
	double sumsq = 0;
	
	for (int i = 0; i<scoreSize; i++)
	{
		sumsq = sumsq + pow(score[i]-Mean,2);
	}
	StanDev = sqrt(sumsq/NUMSCORE); 
	return StanDev;
}	

//
// fill array grade[] with letter grades A,B,C,D,F
//
void computeGrade (char grade[], int gradeSize, double range[], const int score[])
{
	for (int i = 0; i<gradeSize; i++)
		{
			if ((range[0] <= score[i]) && (score[i]<= MAXSCORE))
			{
				grade[i] = 'A';
			}
			
			else if ((range[1] <= score[i]) && (score[i] <= range[0]))
			{
				grade [i] = 'B';
			}
			
			else if ((range[2] <= score[i]) && (score[i] <= range[1]))
			{
				grade [i] = 'C';
			}
			
			else if ((range[3] <= score[i]) && (score [i] <= range[2]))
			{
				grade [i] = 'D';
			}
			
			else
			{
				grade [i] = 'F';
			}
	}
}

//
// use mean and standard deviation to compute range and store range in array range[]
// 
void computeRange(double range[], int rangeSize, double Mean, double StanDev)
{
	for (int i = 0; i < rangeSize; i++) 
		{
		range[i] = (Mean + StanDev*1.5) - i*StanDev; 
		}
}

//
// print out scores and determine the letter grades, print out table of ranges of scores for responsive letter grades
//
void printStat(const int score[], int scoreSize, int counter[], char grade[], int gradeSize, double range[], int rangeSize)
{
	// initialize all counter with zero so it can be add up later
		counter[0]= 0; 
		counter[1]=0; 
		counter[2]=0; 
		counter[3]=0; 
		counter[4]=0;
	
 	// output scores and responsive letter grades
        for (int i = 0; i<scoreSize; i++)
		{               
        	cout << "Score[" << setw(2) << i <<"] = "<< setw(3) << score[i] << "  " << grade[i] << endl;
                                                
												if (grade[i] == 'A')
                                                    	counter[0]++;
                                                else if (grade[i] == 'B')
                                                        counter[1]++;
                                                else if (grade[i] == 'C')
                                                        counter[2]++;
                                                else if (grade[i] == 'D')
                                                        counter[3]++;
                                                else
                                                        counter[4]++; 
   		}
		
	// output introdution
		cout << "\nRanges of Letter Grades:\n" << endl;
	
	// output table
		cout << "A:  " << setw(6) << range[0] << " to " << setw(6) << MAXSCORE << "  " << setw(2) << counter[0] << endl;
		cout << "B:  " << setw(6) << range[1] << " to " << setw(6) << range[0] << "  " << setw(2) << counter[1] << endl;
		cout << "C:  " << setw(6) << range[2] << " to " << setw(6) << range[1] << "  " << setw(2) << counter[2] << endl;
		cout << "D:  " << setw(6) << range[3] << " to " << setw(6) << range[2] << "  " << setw(2) << counter[3] << endl;
		cout << "F:  " << setw(6) << MINSCORE << " to  " << setw(5) << range[3] << "  " << setw(2) << counter[4] << endl;
}
