/*
	Course:		COSC - 1410
	Assignment: #10
	Date Due :  04 - 24 - 2015
	Student :   Thanh Vo
	Peoplesoft: 1148524
	TA :        David Fullerton

	Purpose:    The purpose of this lab is to provide practice on the following concepts: 
				Sequential ASCII file (no random access file in this assignment), 
				File Processing (input and output), 
				C++ Classes (not really new).
*/

// libraries to add that are required for this program with 
// identification of what library gives what objects
	#include <cstdio>		// provides: streams#include <fstream>
	#include <iostream>		// provides: cout, cin
	#include <string>		// provides: string
	#include <cstdlib>		// provides: system
	#include <iomanip>		// provides: setw()
	#include <fstream>		// provides: ifstream, ofstream

// set user environment
	using namespace std;
	
// global constants & variables
	const int SIZE = 100;

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
// structure that stores information of each student including ID, last name, first name, and bank account balance 
//
struct account 
{
	int Id;				// track ID of student
	string Last;		// track last name of student
	string First;		// track first name of student
	double Balance;		// track bank account balance of student
};

//
// class that stores functions to operate list of students' information, arrays of students and numbers of students 
//
class accountList
{
	public:
		void getRecord (int ID, string last, string first, double balance);							// set ID, first name, last name and balance to an element of array student
		void setNum();																				// initialize both num and numOutput with 0
		void showList();																			// show a list of students' information got from text file
		void sort();																				// sort sets of student's information following increasing ID
		void showAfterSort();																		// show the list of of students' information after sorting 
		int returnNum();																			// return number of students added
		void output(string& finalFirst, string& finalLast, int& finalID, double& finalBalance);		// prepare sets of student's information to write on another text file
		
	private:
		account student[SIZE];		   	  // store information of students
		account studentSorted[SIZE];	  // store information of students after sorting by ID
		int num;						  // track number of students added
		int numOutput;					  // track number of sets of student's information that will be written to a new text file
};

//
// This is the main code for the program that is called from the operating system. The  command-line argument is applied to pass 2 filenames
//
int main(int argc, char* argv[])
{ 
	// one-time setup of the program 
        Program_Setup();

	// lists of local variables
		accountList info;			  // get access from class accountList
		int n;						  // track the number of students returned from class accountList
		
		ifstream infile(argv[1]);	  // track the input stream of argument 1 which is the text file prog10in.txt
		string first;				  // track the first name get from file
		string last; 				  // track the last name get from file
		int ID; 					  // track the ID get from file
		double balance;				  // track the balance get from file
		
		ofstream outfile(argv[2]);		// track the output stream of argument 2 which is the text file prog10out.txt
		string finalFirst; 				// track the first name write to file
		string finalLast; 				// track the last name write to file
		int finalID; 					// track the ID write to file
		double finalBalance;			// track the balance write to file
	
	// check if there is more than 1 argument
		if (argc > 1)
		{
			cout << "argv[1] = " << argv[1] << endl; 
		}
		else
		{
			cout << "No file name entered. Exiting...";
			return -1;
		}
    
    // open the file and check if file is valid. if valid, stream input from file. notify a warning when file is invalid
    	if (!infile.fail()) 
		{
        	cout << "File is now open!\nContains:\n";
        
        	// initialize the number of students added
				info.setNum();
        
        	// get information from text file until end of file and store information of students into an array 
        		while(!infile.eof())
        		{
        			infile >> ID >> last >> first >> balance;
        			info.getRecord(ID,last,first,balance);
    			}
    	
    		// show the list of students with their information
    			cout << endl;
    			info.showList();
    	} 
		else 
		{
        	cout << "Failed to open file..";
    	}
	
	// sort, and show the list after sort
		cout << endl;
		info.sort();
		info.showAfterSort();
    
    // open a new text file, check validity: if valid, stream output to text file, notify a warning when file is invalid
    	if (!outfile.fail()) 
		{
    		cout << "File is now open!\n";
    		
    		// get number of students n, write n sets of student's information to a new text file
	    		n = info.returnNum();
    			for (int i=0; i<n; i++)
    			{
    				info.output(finalFirst, finalLast, finalID, finalBalance); 
					outfile << setw(5) << finalID << "  " << setw(7) << finalLast << "   " 
			 				<< setw(7) << finalFirst << "      " << setw(8) << setprecision(2) << fixed << finalBalance << endl;
				}
		}
    	else
    	{
    		cout << "Failed to open file..";
		}
		
	// close both files prog10in.txt and prog10out.txt
		infile.close();
		outfile.close();
	
    // program ends
        Program_Ending();
}

//
// storing information of a student into each element of array student, also the number of students added increases by 1  
//
void accountList::getRecord (int ID, string last, string first, double balance)
{
	student[num].Id = ID;
	student[num].Last = last;
	student[num].First = first;
	student[num].Balance = balance;
	num++;		
}

//
// initialize number of students num and number of student information sets numOutput with zero
//
void accountList::setNum()
{
	num=0;
	numOutput=0;
}

//
// show a list of students with their information
//
void accountList::showList()
{
	for (int i = 0; i<num; i++)
	{
		cout << setw(5) << student[i].Id << "  " << setw(7) << student[i].Last << "   " 
			 << setw(7) << student[i].First << "      " << setw(8) << student[i].Balance << endl;
	}
}

//
// sorting students by ID from low to high and store information into another array
//
void accountList::sort()
{
	// local variable
		account tmp;
	
	// sorting ID in increasing order	
		for (int i=0; i<num-1; i++)
		{
			for (int k=i+1; k<num; k++)
			{
				if (student[i].Id > student[k].Id)
				{
					tmp = student[i];
					student[i] = student[k];
					student[k] = tmp;	
				}
			}
		}
		
	// store the sorted information into another array
		for (int i=0; i<num; i++)
		{
			studentSorted[i] = student[i];
		}
}

//
// show list of students after sorting
//
void accountList::showAfterSort()
{
	for (int i=0; i<num; i++)
	{
		cout << setw(5) << studentSorted[i].Id << "  " << setw(7) << studentSorted[i].Last << "   " 
			 << setw(7) << studentSorted[i].First << "      " << setw(8) << studentSorted[i].Balance << endl;
	}
}

//
// return number of student
//
int accountList::returnNum()
{
	return num;
}

//
// prepare sets of student's information to write on another text file
//
void accountList::output(string& finalFirst, string& finalLast, int& finalID, double& finalBalance)
{
	finalID = studentSorted[numOutput].Id; 
	finalLast = studentSorted[numOutput].Last;
	finalFirst = studentSorted[numOutput].First;
	finalBalance = studentSorted[numOutput].Balance;
	numOutput++;
}
