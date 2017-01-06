/*
Course:		COSC - 1410
Assignment: #07
Date Due :  3 - 30 - 2015
Student :   Thanh Vo
Peoplesoft: 1148524
TA :        David Fullerton

Purpose:    The purpose of this lab is to make sure I am familiar with using arrays (in particular,
			two dimensional arrays). In addition, it is important that I know how to use functions 
			to structure my program.
*/

// libraries to add that are required for this program with 
// identification of what library gives what objects
	#include <iostream>      // provides:  cout, cin
	#include <cstdlib>       // provides:  system

// set user environment
	using namespace std;
	 
// global constants & variables
	const int NUMROWS = 6; 
	const int NUMCOLS = 4;
	
// This is the function declarations
	void Reset (int seat[][NUMCOLS], int rowSize);
	int getSeat (int& row, char& col);
	int Reserve (int seat[][NUMCOLS], int rowSize, int row, int col);
	void Print (int seat[][NUMCOLS], int rowSize);
	void isFull (int seat[][NUMCOLS], int rowSize, int& foundIndex1, int& foundIndex2);
	
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
        
    // list of local variables:
    int seat[NUMROWS][NUMCOLS];		// 2D array keeps track of seat
    
    int result;						// keep track of checking validity of the seat
    int taken;						// keep track of checking reseravtion of the seat	
    	
    int row;							// keep track of row
    char col;							// keep track of column
    
    bool done = false;				// keep control of the while loop
    
    int foundIndex1, foundIndex2;	// keep track of determining whether all are reserved
    
    // set up a table
		Reset (seat, NUMROWS);
	
	// operate a process of input and checking as well as print out
		while(!done)
		{
			// get seat
				result = getSeat(row,col);
			
			// process the result from getSeat
				if (result==1)
				{
					// determine reservation
						taken = Reserve(seat, NUMROWS,row,col);
						if (taken==0) 
							continue;
					
					// print out table after one successful reservation		
						Print (seat, NUMROWS);		
				} 
				
				if (result==0)
				{
					Print (seat, NUMROWS);
					cout << "*** You chose to exit! ***" << endl;
					done = true;
				}
			
				if (result==-1)
				{
					cout << "*** You had an invalid entry! Please enter again! ***" << endl;
					continue;
				}
				
			// notification when all are reserved
				isFull(seat, NUMROWS, foundIndex1, foundIndex2);
				if ((foundIndex1 == -1) && (foundIndex2 == -1)) {
					Print (seat, NUMROWS);
					cout << "*** NO MORE SEATS ARE AVAILABLE! ***" << endl;
					done = true;
				}
				else continue; 	
		}
		
	// program ends
        Program_Ending();
}

// 
// insert table with initialization '-' for all seats
//
void Reset (int seat[][NUMCOLS], int rowSize)
{
	int k, i;
	cout << "- = Available		R = Reserved" << endl;
	cout << "0  A  B  C  D  " << endl;
	for (k=0; k<NUMROWS; k++) {
		cout << k+1 << "  ";
		for (i=0; i<NUMCOLS; i++){
			seat[k][i] = 45;
			cout  << (char)seat[k][i] << "  ";
		}
		cout << endl;
	}
}

//
// enter a row and column of seat and check if seat is valid. Return 1 as valid entry, 0 as a special case for exit and -1 as invalid entry
//
int getSeat (int& row, char& col)
{
	// list of local variables
		int R;			// row input
		char C;			// column input
		int n;			// keep track of conversion character to number
		int result;		// keep track of the result return
		
	// input row and column
		cout << "Seat (Row, Column): ";
		cin >> R >> C;
	
	// conversions of column from char to int
		n= (int)C;
		if ((n>=97) && (n<=100)) 
		n = n - 32;
		
		col = n - 65;
	
	// determine validity
		if ((R>=1) && (R<=6) && (col>=0) && (col<=3))
		{
			row = R - 1;
			result = 1;
		}
		else if ((R==0) && ((col==16) || (col ==48)))
			result = 0;
		else
			result = -1;
		
	return result;
}

//
// using row and col to determine if seat is reserved. return 0 as already been reserved, 1 if successfully reserve
//
int Reserve (int seat[][NUMCOLS], int rowSize, int row, int col)
{
	// list of local variables
		int taken;		// keep track of reserve notification return
	
	if (seat[row][col]==82) 
	{
		cout << "*** Your chosen seat has already been reserved! Please enter again! ***" << endl;
		taken = 0;	
	}
	else
	{
		seat[row][col] = 82;
		taken = 1;
	}
	return taken;
}
	
//
// print table after reservation
//
void Print (int seat[][NUMCOLS], int rowSize)
{
	int k, i;
	cout << "- = Available		R = Reserved" << endl;
	cout << "0  A  B  C  D  " << endl;
	for (k=0; k<NUMROWS; k++) {
		cout << k+1 << "  ";
		for (i=0; i<NUMCOLS; i++){
			cout  << (char)seat[k][i] << "  ";
		}
		cout << endl;
	}
}
	
//
// determine if all are reserved
//
void isFull (int seat[][NUMCOLS], int rowSize, int& foundIndex1, int& foundIndex2)
{
	int k, i;
	foundIndex1=-1; foundIndex2=-1;
	for (k=0; k<NUMROWS; k++) {
		for (i=0; i<NUMCOLS; i++) {
			if (seat[k][i] == 45)  {
			foundIndex1 = i;
			foundIndex2 = k;	
			}	
		}
	}
}
	
	
	

  
    
