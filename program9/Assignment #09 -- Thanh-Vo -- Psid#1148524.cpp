/*
	Course:		COSC - 1410
	Assignment: #09
	Date Due :  4 - 17 - 2015
	Student :   Thanh Vo
	Peoplesoft: 1148524
	TA :        David Fullerton

	Purpose:    The purpose of this lab is to make sure I am familiar with C-string,
				String class, and classes in general. The old C-strings are being 
				used a lot in the existing applications, so it is important to know 
				how it works. In addition, it is important that I know how to use 
				functions to structure my program. 
*/

// libraries to add that are required for this program with 
// identification of what library gives what objects
	#include <cstdio>		// provides: streams
	#include <iostream>		// provides: cout, cin
	#include <string>		// provides: string
	#include <cctype>		// provides: islower() and toupper()
	#include <cstdlib>		// provides: system
	#include <iomanip>		// provides: setw()
	#include <fstream>		// provides: ifstream

// set user environment
	using namespace std;

// global constants & variables
	const int MAKESIZE = 20;		// maximum number of characters in make
	const int CARSIZE = 100;		// maximum number of cars 
	ifstream inStream;				// use to stream in information from a text file

//
// class that stores information of a car and functions to process a car
//
class Auto {
	public:
		void setAll(char make[], string model, string color , int year, double price);		// set all information about a car
		void display();																		// display all information of a car
		double getPrice();																	// get price of the car
		string getMake();																	// get make of the car
		
	private:
		char Make[MAKESIZE];		// track the brand of the car
		string Model;				// track the model of the car
		int Year;					// track the year which the car is produced
		string Color;				// track the color of the car
		double Price;				// track the price of the car
};

//
// class that stores information of added cars and functions that process added cars
// 
class Dealer 
{
	public:
		void addCar();										// to insert a new car to the array
		void displayAll();									// print table of all the cars
		int getNoOfCars();									// return the number of cars stored in the array
		void displayBetween(double min, double max);		// display all the cars with prices between min and max
		void displayByMake(char mk[]);						// display all the cars that has the same make input
	
	private:
		Auto cars[CARSIZE];		// store information of all the cars
		Auto cars1[CARSIZE];	// store information of cars that have price between two input ranges
		Auto cars2[CARSIZE];	// store information of cars that have make matched with input make
		int noOfCars;			// track number of cars added
};

// function prototypes are below
	bool getRecord(int& recNum, char make[], string& model, string& color , int& year, double& price);

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
	// local variable list
		Dealer info;			// keep track with access to class Dealer's functions
		bool done = false;		// keep track with the while loop that asks user to input option until exit
		int num;				// keep track with number of car added
		int option;				// keep track with user's option
		double min;				// keep track with user's minimum price input
		double max;				// keep track with user's maximum price input
		char mk[MAKESIZE];		// keep track with user's make input
        
    // add new car to array cars[] in class Dealer and display a table of all the cars
		info.addCar();
		info.displayAll();  
       
	// display options and number of cars, ask user to enter an option and operate each option 
		while (!done)
		{
			num = info.getNoOfCars();
			cout << "********** Class Dealer ******* Total cars = " << num << endl;
			cout << "1. Display all cars" << endl;
			cout << "2. Display all cars within price range" << endl;
			cout << "3. Display all cars with specific make" << endl;
			cout << "4. Exit" << endl;
			cout << ">>";
			cin >> option;
			
			switch(option)
			{
				// display all cars
					case 1: info.displayAll(); break;											
					
				// display cars in range of prices
					case 2: cout << "Enter the minimum amount you want to spend: ";
							cin >> min;
							cout << "Enter the maximum amount you can pay: ";
							cin >> max; 
							info.displayBetween(min,max);
							break;
				
				// display cars following desired make	
					case 3: cout << "Enter the make you are looking for : ";	
							cin.ignore(100,'\n');
							cin.getline(mk,MAKESIZE);
							info.displayByMake(mk);
							break;
        
        		// exit program													
					case 4: cout << "Exit!" << endl; 
							done = true;
					 		break;
				
				// invalid entry												
					default: cout << "Invalid! Please enter 1 to 4" << endl; 
					continue;			
			}
			cout << endl; 
		}
       
   	// program ends
        Program_Ending();	  
}
	
//
// set all information about the car: make, size, model, color, year and price
//
void Auto::setAll(char make[], string model, string color, int year, double price)
{
	// set make of a car
		for (int i =0; make[i]!='\0'; i++) 
			Make[i]=make[i];
		
	// set model, color and year of a car
		Model = model;
		Color = color;
		Year = year;
		
	// set price of a car and make sure the price is valid
		Price = price;
		while (Price < 0)
		{
			cout << "The Price is Invalid. Price is Now Change to 0!";
			Price = 0;
		}
}	
	
//
// display all information of a car
//
void Auto::display() 
{
		cout<< setw(8) << Make << "  " << setw(7) << Model << "   " << setw(5) << Color << "   " 
			<< setw(4) << Year << "    " << setw(5) << Price << endl;
}


//
// return the price of a car
//
double Auto::getPrice()
{
	return Price;
}

//
// convert Make from C string to C++ string and return it
//
string Auto::getMake()
{
	string m;
	m = Make;
	return m;
}

//
// add a new car to the array cars[CARSIZE], increase noOfCars by 1 whenever a car is added
//
void Dealer::addCar()
{
	// local variables
    	int recNum=0;				// track record number is initialized wih zero
    	char make[MAKESIZE];		// track array of make of a car
    	string model;				// track model of a car
    	string color;				// track color of a car
    	int year;					// track year of a car
    	double price;				// track price of a car
    	bool done;					// track the return of getRecord() function
    	
	// initial number of cars with zero
		noOfCars=0;					
    	
    // transfer information of cars from the text file to elements in array cars  	
    	do
    	{
    		done = getRecord(recNum, make, model, color , year, price);
			cars[noOfCars].setAll(make, model, color, year, price);
    		noOfCars++;
		}	
		while (done==true);
}	
	
//
// return number of cars
//
int Dealer::getNoOfCars()
{
	return noOfCars;
}

//
// display a table of sets of all cars
//
void Dealer::displayAll()
{
	// print header of table
		cout << "   Make     Model   Color   Year    Price" << endl;
		cout << "---------------------------------------------" << endl;
		
	// print table of cars' information
		for (int i=0; i<noOfCars; i++)
		{
			cars[i].display();
		}
}

//
// display a table after getting cars that have price between min and max
//
void Dealer::displayBetween(double min, double max)
{
	// local variables
		double p;			// keep track with price of a car
		int n = 0;			// keep track with number of cars added to array cars1 and index of array cars1 
		int numUsed;		// keep track with final number of cars added to array cars1
			
	// get price and determine if it is in the range then put those in range in a separate array 
		for (int i = 0; i < noOfCars; i++)
			{
				p = cars[i].getPrice();	
				while ((p>=min) && (p<=max)) 
				{
					cars1[n] = cars[i];
					n++;
					break;			
				}
			}
	
	// print out the desired array, give a notification if there is no car matched	
		numUsed = n;
		if (numUsed == 0) cout << "No Car Found!" << endl;
		else 
		{
			cout << "   Make     Model   Color   Year    Price" << endl;
			cout << "---------------------------------------------" << endl;
			for (n=0; n<numUsed; n++)
			{
					cars1[n].display();
			}
		}
}

//
// display a table after getting cars that have the desired input make
//
void Dealer::displayByMake(char mk[])
{
	// local variables
		string s1;			// keep track with make of a car
		string s2;			// keep track with make that user enters
		int n = 0;			// keep track with number of cars added to array cars2 and index of array cars2
		int numUsed;		// keep track with final number of cars added to array cars2
		
	// convert first character of input make from lower to upper 
		if(islower(mk[0])) mk[0] = toupper(mk[0]);	
		
	// convert from second to last character of input make from upper to lower
		for (int i=1; mk[i]!='\0'; i++)
		{
			if(isupper(mk[i])) mk[i] = tolower(mk[i]);
		}	
		
	// get make of a car, convert user's make input from C string to C++ string and put makes matched the input into another array
		for (int i = 0; i < noOfCars; i++)
			{
					s1 = cars[i].getMake();	
					s2 = mk;
					while (s1==s2) 
						{
						cars2[n] = cars[i];
						n++;
						break;
						}
			}
			
	// print out the desired array, give a notification if there is no car matched	
		numUsed = n;
		if (numUsed == 0) cout << "No Car Found!" << endl;
		else 
		{
			cout << "   Make     Model   Color   Year    Price" << endl;
			cout << "---------------------------------------------" << endl;
			for (n=0; n<numUsed; n++)
			{
					cars2[n].display();
			}
		}
			
}

//
// stream in information of a car from text file named prog9in.txt
//
bool getRecord(int& recNum, char make[], string& model, string& color , int& year, double& price)
{
   if (recNum==0) {
      inStream.open("prog9in.txt");
      if (inStream.fail()){
         cout<<"File \"prog9in.txt\" cannot be opened."<<endl;
         system("pause"); 
         exit(1);
      } else cout<<"File \"prog9in.txt\" opened."<<endl;
   }         
   inStream >>make >>model >> color >>year >>price;
   if (inStream.eof()) return false;
   else {
       recNum++;
       return true;
   }      
}	
