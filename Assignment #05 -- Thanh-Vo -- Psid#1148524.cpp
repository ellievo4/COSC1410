/*
Course:		COSC - 1410
Assignment: #05
Date Due :  3 - 11 - 2015
Student :   Thanh Vo
Peoplesoft: 1148524
TA :        David Fullerton

Purpose:    The purpose of this lab is to help me have a better understanding of functions with call-by-value
			and call-by-reference parameters. I also use several library functions from <cmath> and <cstdlib> 
			library. I am going to do some interesting calculations with limited syntax that I have
			learned so far.
*/

	#include <iostream>      // provides:  cout, cin
	#include <cstdlib>       // provides: system, srand, rand()
	#include <ctime>         // provides: time(0)
	#include <cmath>         // provides: sqrt
	#include <iomanip>       // provides: setw()

// set user environment
	using namespace std;
	 
// global constants & variables
	const int NUMSCORE = 100;			 // number of input score is 100

	const double MAXSCORE = 100.00;      // maximum score is 100.00
	const double MINSCORE = 0.00;		 // minimum score is 0.00

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

// This is the function declarations
	int GetScore1();										 // get a random score from 0 to 40
	int GetScore2(); 										 // get a random score from 40 to 70
	int GetScore3(); 										 // get a random score from 70 to 100
	void GetStat (double& Mean, double& StanDev); 			 // calculate mean and standard deviation
	void PrintGradeRange (double Mean, double StanDev);      // print N, mean, standard deviation and a table of grade ranges

//
// This is the main code for the program that is called from the operating system.
//
int main()
{
    // one-time setup of the program 
        Program_Setup();
	
	// list of local variables:
		double Avg, SD;      //keep track with values of mean and standard deviation
	
	// avoid the repetition of random scores over times of execution  
		srand(time(0));      
	
	// call function GetStat that calculates mean and standard deviation
		GetStat(Avg, SD);
	
	// call function that prints N, mean, standard deviation and a table of letter grades and ranges
		PrintGradeRange(Avg, SD);
	
	// program ends
        Program_Ending();
        
}

//
// get any number from 0 to 40 and return that number 
//
int GetScore1() 
{
	int num1;
	
	num1= rand()%41;
	
	return num1;	
}
	
//
// get any number from 40 to 70 and return that number 
//
int GetScore2() 
{
	int num2;
	
	num2= rand()%31+40;
	
	return num2;
}

//
// get any number from 70 to 100 and return that number 
//
int GetScore3() 
{
	int num3;
	 
	num3= rand()%31+70;
	
	return num3;
}

//
// do all the input scores in three desired ranges while computing mean and std. Return mean and std. 
//
void GetStat (double& Mean, double& StanDev) 
{
	// List of local variables
		int i; 											// used in for loop, i will run from 1 to 100
	
		int score1, score2, score3;        				// for random scores in three desired ranges
		
		double sum1 = 0, sum2 = 0, sum3 = 0; 			// all sums of scores are initialed with 0
		double sumsq1 = 0, sumsq2 = 0, sumsq3 = 0;      // all sums of square scores are also initialed with 0 
	
		double sum, sumsq; 								// for calculting sum of all 100 scores and sum of 100 square scores 
	
	// for getting 10% scores from 0 to 40
		for (i=1; i<=10; i++) {  
		
			score1 = GetScore1();
			cout << i << " " << score1 << endl;
			sum1+= score1;
			sumsq1+=score1*score1;
		}

	// for getting 80% scores from 40 to 70
		for (i=11; i<=90; i++) { 
		
			score2 = GetScore2();
			cout << i << " " << score2 << endl;
			sum2+=score2;
			sumsq2+=score2*score2; 
		}
	
	// for getting 10% scores from 70 to 100
		for (i=91; i<=100; i++) { 
			score3 = GetScore3();
			cout << i << " " << score3 << endl;
			sum3+=score3;
			sumsq3+=score3*score3; 
		}
	
	// get sum of scores and sum of square scores	
		sum = sum1 + sum2 + sum3;  
		sumsq = sumsq1 + sumsq2 + sumsq3;
	
	/* cout << sum1 << " " << sumsq1 << " " << sum2 << " " << sumsq2 << " " << sum3 << " " << sumsq3 << " " << sum << " " << sumsq << endl; */
	//for checking if the calculations are right
	
	// calculate mean and standard deviation in double type
		Mean = static_cast<double>(sum) / 100;
		StanDev = sqrt (sumsq/100 - Mean*Mean);
		
}

//
// print, N, mean, std, and the range of each grade 
//
void PrintGradeRange (double Mean, double StanDev)
{
	// List of local variables:
		double MinScore1, MinScore2, MinScore3, MinScore4;      // 4 minimum scores
	
	// print N
		cout << "Number of Scores: " << NUMSCORE << endl; 
	
	// print mean and print standard deviation
		cout << "Mean Score:       " << setw(5) << Mean << endl; 
		cout << "Std deviation:    " << setw(5) << StanDev << endl;
	
	// output introduction of ranges
		cout << "\nRanges of Letter Grade:\n" << endl;
	
	// set up the formulas to calculate each min score
		MinScore1 = Mean + StanDev * 1.5; 
		MinScore2 = Mean + StanDev * 0.5;
		MinScore3 = Mean - StanDev * 0.5;
		MinScore4 = Mean - StanDev * 1.5;
	
	// print table
		cout << "A:  " << setw(6) << MinScore1 << " to " << setw(6) << MAXSCORE << endl;
		cout << "B:  " << setw(6) << MinScore2 << " to " << setw(6) << MinScore1 << endl;
		cout << "C:  " << setw(6) << MinScore3 << " to " << setw(6) << MinScore2 << endl;
		cout << "D:  " << setw(6) << MinScore4 << " to " << setw(6) << MinScore3 << endl;
		cout << "F:  " << setw(6) << MINSCORE << " to  " << setw(5) << MinScore4 << endl;
	
}
	
