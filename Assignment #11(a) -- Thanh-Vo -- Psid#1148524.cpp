/*
	Course:		COSC - 1410
	Assignment: #11
	Date Due :  05 - 4 - 2015
	Student :   Thanh Vo
	Peoplesoft: 1148524
	TA :        David Fullerton

	Purpose:    This assignment will serve as an exercise for using pointers and dynamic storage. I will
				be using the new operator to create storage space (without a static variable name) to 
				store data. I will also be using pointers to access data stored in the dynamic storage.
*/

// Here is part a of program 11

// libraries to add that are required for this program with 
// identification of what library gives what objects
	#include <iostream>		// provides: cout, cin

// set user environment
	using namespace std;

// global constants & variables
	const int INIT_SIZE = 4;		// track initial physical size of dynamic array 

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
// a class storing functions that operate dynamic array list and variables that track the size of array list
//
class dynArray
{
	public:
		void initialize ();			// initialize pointer to dynamic array and two sizes
		void showArray();			// display the array and the two sizes
		void addElem(int num);		// add an integer at the end of the list
		
	private:
		int* list;				// track pointer to dynamic array of numbers
		int pSize;				// physical size of array 
		int aSize;				// actual size of array
		int* temp;				// temporary pointer to dynamic array used for doubling size of array 
		void doubleSize();		// private function to double the physical size of the array
};

//
// This is the main code for the program that is called from the operating system.
//
int main()
{
	// local variable
		dynArray a; // get access to class dynArray
	
	// initial the array and two sizes
		a.initialize();
		
	// show the initial two sizes
		a.showArray();
		
	// add element to array, double physical size of array and show both physical size and actual size, and show current elements in array	
		for (int i=0; i<20; i++)
		{
			a.addElem(100+i);
			a.showArray();
		}	
	
	// program ends
        Program_Ending();
}

//
// initial the pointer to array, physical size and actual size
//
void dynArray::initialize()
{
	pSize = INIT_SIZE;
	aSize = 0;
	list = new int[INIT_SIZE];
}

//
// show physical size, actual size, and elements in array (if actual size different to zero)
//
void dynArray::showArray()
{
	// display both sizes at the begining
		if (aSize==0)
		{
			cout << "Physical Size: " << pSize << '\n';
			cout << "Number of Elements: " << aSize << '\n';
			cout << endl;
		}
	
	// display size after adding one number
		else 
		{
			for (int i=0; i < aSize; i++)
			{
				cout << "Array[" << i << "]: " << list[i] << endl;
			}
			cout << "Physical Size: " << pSize << endl;
			cout << "Number of Elements: " << aSize << endl;
			cout << endl;
		}
}

//
// add new integer to array and double the physical size if actual size is larger than it
//
void dynArray::addElem(int num)
{
	// add new integer to array so that actual size increases by 1
		list[aSize] = num;
		aSize++;
	
	// double size if actual size is larger than physical size
		doubleSize();
}

//
// double the physical size when actual size is larger than it
//
void dynArray::doubleSize()
{
	if (aSize>pSize)
	{
		// double pSize and give a notification about the double
			pSize = pSize * 2;
			cout << "Number of Physical Size Increases to " << pSize << endl;
			
		// initial pointer temp to an array and set this array to have dimension of new pSize	
			temp = new int[pSize];
			
		// copy elements in list into temp
			for (int i = 0; i< aSize; i++)
				temp[i] = list[i];
		
		// delete list (array's elements and dimension)
			delete [] list;
			list = NULL;
		
		// set pointer list to array that has new pSize and copy all elements in temp into list
			list = new int[pSize];
			for (int i = 0; i< aSize; i++)
				list[i] = temp[i];
				
		// delete temp (array's elements and dimension)
			delete [] temp;
			temp = NULL;
	}
}
