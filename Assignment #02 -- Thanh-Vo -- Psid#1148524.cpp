/*
Course:		COSC - 1410
Assignment: #02
Date Due :  2 - 16 - 2015
Student :   Thanh Vo
Peoplesoft: 1148524
TA :        David Fullerton

Purpose:    The purpose of this lab is to test my knowledge of if, if-else, while loop, and loop with sentinel.
*/

// libraries to add that are required for this program with 
// identification of what library gives what objects
	#include <iostream>      // provides:  cout, cin
	#include <cstdlib>       // provides: system

// set user environment
	using namespace std;

// global constants & variables
	// set constants for number grades corresponding to letter grade
	const double A = 4; 						const double B = 3; 
	const double C = 2; 						const double D = 1; 
	const double F = 0;			
	
	// set constants for ranges of letter grades  
	const double Max = 100.00; 					const double min1 = 0.00; 
	const double min2 = 60.00; 					const double min3 = 70.00;
	const double min4 = 80.00; 					const double min5 = 90.00;

//
// This is the main code for the program that is called from the operating system.
//
int main()
{
	// one-time setup of output object (COUT) for pretty printing of decimal places
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);   
        
	// list of local variables:
	char YN; 					// track the answer Yes or No (YN)	
	int CourseNumb = 0; 		// track the number of course
	double sum = 0; 			// track the sum of grades being responsible to each letter grade, sum starts with 0 and would be add up   
	double Grade; 				// track my grade received from each course
	double Avg; 				// track GPA
	

	// set default for this While Loop 'Y' and 'y'
		while ((YN = 'Y') && (YN = 'y')) 
		{    
			// enter the course number and my grade received from each course. 
			// since i set CousreNumb is 0, in this case i add 1 so that the ouput would be course number 1
				cout << "Enter Grade " << CourseNumb + 1 << " (From 0 to 100): "; 
				cin >> Grade;
		
			//whatever Grade enterred is in this range, the output would indicate A-grade.
			//sum immediately adds the grade being responsible for A
			//course number increases by 1
				if ((Grade >= min5) && (Grade <= Max)) 
				{
					cout << "Your Letter Grade is A\n";
					cout << endl;
					sum = sum + A;
					CourseNumb++;
				}
				
			//whatever Grade enterred is in this range, the output would indicate B-grade.
			//sum immediately adds the grade being responsible for B
			//course number increases by 1	
				else if ((Grade >= min4) && (Grade <= min5)) 
				{
					cout << "Your Letter Grade is B\n";
					cout << endl;
					sum = sum + B;
					CourseNumb++;
				}
				
			//whatever Grade enterred is in this range, the output would indicate C-grade.
			//sum immediately adds the grade being responsible for C
			//course number increases by 1
				else if ((Grade >= min3) && (Grade <= min4)) 
				{
					cout << "Your Letter Grade is C\n";
					cout << endl;
					sum = sum + C;
					CourseNumb++;
				}
				
			//whatever Grade enterred is in this range, the output would indicate D-grade.
			//sum immediately adds the grade being responsible for D
			//course number increases by 1	
				else if ((Grade >= min2) && (Grade <= min3)) 
				{
					cout << "Your Letter Grade is D\n";
					cout << endl;
					sum = sum + D;
					CourseNumb++;
				}
				
			//whatever Grade enterred is in this range, the output would indicate F-grade.
			//sum immediately adds the grade being responsible for F
			//course number increases by 1	
				else if ((Grade >= min1) && (Grade <= min2)) 
				{
					cout << "Your Letter Grade is F\n";
					cout << endl;
					sum = sum + F;
					CourseNumb++;
				}
				
			// whatever grade enterred is not in the five ranges above would be invalid	
				else 
				{
					cout << "*** ERROR: \"" << Grade << "\" is INVALID grade\n" << "      Grade must be from 0 to 100!" << endl;
					cout << endl;
				}
		
			//ask whether adding a new grade or not
			//if the answer is 'y' or 'Y', the process will start again: ask for a new grade and check the range it belongs to
				cout << "Do you wish to enter another grade? (Y/N): "; cin >> YN;
				cout << endl;
		
			//when my input for the question above is 'n' or 'N', the system will process the part below
				if ((YN == 'N') || (YN == 'n')) 
				{ 
					//set Avg equal this calculation
						Avg = sum / CourseNumb; 
					
					//output my GPA
						cout << "Your GPA is " << Avg << endl; 
						cout << endl;
					
					break; 
				}
		}

	// tell user to hit key and wait to return back to operating system
        cout << endl;
        system("pause");
        exit(0);    
}
