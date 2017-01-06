/*
	Course:		COSC - 1410
	Assignment: #08
	Date Due :  4 - 8 - 2015
	Student :   Thanh Vo
	Peoplesoft: 1148524
	TA :        David Fullerton

	Purpose:    The purpose of this lab is to  provide practice on the following concepts: Classes, Array of structures, Sorting.
*/

// libraries to add that are required for this program with 
// identification of what library gives what objects
	#include <iostream>      // provides:  cout, cin
	#include <cstdlib>       // provides: system, srand, rand()
	#include <ctime>         // provides: time(0)
	#include <iomanip>       // provides: setw()

// set user environment
	using namespace std;
	
// global constants & variables
	const int MAXSTU = 200;		// number of all students

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
// structure that stores ID and score
//
struct student 
{
	// variable list
		int ID;			// keep track of ID of each student
		int score;		// keep track score for each student
};

//
// class that stores functions and arrays original, operated, after-sort-ID and after-sort-score ID and score 
//
class Course
{
	// interface where functions are declared or function prototypes are listed
		public:
			void point();			// set initials for all values in array personal[MAXSTU] to be zero 
			void setOriginal();		// make a copy of all IDs and scores right after generating random IDs and scores
			void getScores();		// get 200 random scores
			void getIDs();			// get 200 unique random IDs
			void print();			// print 3 tables of scores and IDs: before sort, after sort IDs and after sort scores
			void sortID();			// sorting ID from small to large
			void sortScore();		// sorting score from large to small
			
	// implementation where variables are listed
		private:
			student personalOriginal[MAXSTU];		// keep track of IDS and scores before sort. this is for printing out table
			student personal[MAXSTU];				// keep track of IDs and scores before sort. this is used to operate (Ex. sort IDs and scores) 
			student personalID[MAXSTU];				// keep track of IDs and scores after sort IDs
			student personalScore[MAXSTU];			// keep track of IDs and scores after sort scores
};

//
// This is the main code for the program that is called from the operating system.
//
int main()
{
    // set to get different sets of random numbers for each operation
		srand(time(0)); 
	
	// list of local variables:
		Course info;		// keep track of all information in class Course that is passed to this function 
		
	// initialize the values in array personal[MAXSTU]
		info.point(); 	
		
	// fill array of ID with random unique numbers and array of score with random numbers 	
		info.getScores();
		info.getIDs();
		
	// keep the original array so that it can be printed out after sorting
		info.setOriginal();
	
	// sorting IDs from small to large and scores from large to small
		info.sortID();
		info.sortScore();
		
	// output 3 tables of score and ID: before sort, after sort ID, after sort Score	
		info.print();
		
	// program ends
        Program_Ending();
}

//
// set initialization for all values of array personal[MAXSTU] to be zero
//
void Course::point()
{
	for (int i = 0; i<MAXSTU; i++)
	{
		personal[i].ID=0;
		personal[i].score=0;
	}
}

//
// make a copy of array personal[MAXSTU] so that I can print out the table of before-sort scores and IDs 
//
void Course::setOriginal()
{
	for (int i = 0; i<MAXSTU; i++)
	{
		personalOriginal[i] = personal[i];
	}
}

//
// get 200 scores and store into array personal[MAXSTU]
//
void Course::getScores()
{
	for (int i = 1; i<MAXSTU; i++)
	{
		personal[i].score = rand()%100 + 1;
	}
}

//
// get 200 unique ID numbers and store into array personal[MAXSTU] 
//
void Course::getIDs()
{
		for (int i = 0; i<MAXSTU; i++) 
		{
			// local variable
				bool same;		// keep track of the do-while loop
			
			// generate unique random number
				do
				{
					same = false;
					personal[i].ID = rand()%200+1;
				
					// Check if the newly generated number is a duplicate:
						for (int check = 0; check < i; check++)
            			{
                			if (personal[i].ID == personal[check].ID)
                			{
                    			same = true;
                    			break;
                			}
            			}
        		} 
				while (same);
    	}
}
				
//
// sort IDs from smallest to largest 
//
void Course::sortID()
{
	// local variables
		int i, k;		// keep track of the two for-loops
		student tmp;	// keep track of the swapping between 2 values of array personal[MAXSTU]
	
	// sort IDs from small to large
		for (i = 0; i < MAXSTU-1; i++)
		{
			for (k = i+1; k < MAXSTU; k++)
			{
				if (personal[k].ID < personal[i].ID)
				{
					tmp=personal[i]; 
					personal[i]=personal[k]; 
					personal[k]=tmp;
				}
			}	
		}
		
	// assign a new array to store IDs and scores after sorting ID
		for (i=0; i<MAXSTU; i++)
		{ 
			personalID[i] = personal[i];
		}
}

//
// sort scores from largest to smallest 
//		
void Course::sortScore()
{
	// local variables
		int i, k;		// keep track of the two for-loops 
		student tmp;	// keep track of the swapping between 2 values of array personal[MAXSTU]
	
	// sort from large to small score
		for (i = 0; i < MAXSTU-1; i++)
		{
			for (k = i+1; k < MAXSTU; k++)
			{
				if (personal[k].score > personal[i].score)
				{
					tmp=personal[i]; 
					personal[i]=personal[k]; 
					personal[k]=tmp;
				}
			}	
		}
		
	// assign a new array to store IDs and scores after sorting score
		for (i=0; i<MAXSTU; i++) 
			{
				personalScore[i] = personal[i];	
			}
}
	
//
// print three tables of IDs and scores before sorting, after sorting IDs, and after sorting scores
//
void Course::print()
{
	// print header of the table of ID and Score
		cout << "Before Sort :\t\tAfter Sort by ID :\tAfter Sort by SCORE :" << endl;
		cout << "Student ID   Score      Student ID    Score     Student ID    Score" << endl;
	
	// print tables of ID and score before sorting, after sorting ID and after sorting score	
		for (int i = 0; i<MAXSTU; i++)
		{	
				cout << "       " << setw(3) << personalOriginal[i].ID << "     " << setw(3) << personalOriginal[i].score;
				cout << "\t       " << setw(3) << personalID[i].ID << "      " << setw(3) << personalID[i].score;
				cout << "\t       " << setw(3) << personalScore[i].ID << "      " << setw(3) << personalScore[i].score << endl;
		}
}
