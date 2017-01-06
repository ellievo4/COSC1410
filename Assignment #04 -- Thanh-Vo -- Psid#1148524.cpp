/*
Course:		COSC - 1410
Assignment: #04
Date Due :  3 - 2 - 2015
Student :   Thanh Vo
Peoplesoft: 1148524
TA :        David Fullerton

Purpose:    The purpose of this lab is to show my understanding of the syntax in Chapter 2 including loops and
			switch statements, enumeration type and functions (Chapter 3). You will write some simple functions 
			using value parameters (only). This assignment also demonstrates the design pattern of menu-driven 
			programming. 
*/

// libraries to add that are required for this program with 
// identification of what library gives what objects
	#include <iostream>		// provides: cin, cout
	#include <iomanip>		// provides:  setw

// setting up my environment
	using namespace std; 

// global constants & variables
	const double SALETAX = 0.0825;		// the sale tax is 8.25% of the price
	// set 4 transaction types: either purchase a new item or discount rate or print receipt or exit
		enum TRANSTYPE { PURCHASE = 1, DISCOUNT = 2, PRINT = 3, EXIT = 4 }; 

// This is the function declarations
	int showMenu();												// show a menu of types of transaction
	double getPrice();  										// enter price
	double getDiscountRate(); 									// enter the discount rate
	void printReceipt(double TOTAL, double discount);			// print out receipt

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
		int num;		// num for number
		int n;			// n for doing the showMenu function
	
	
		double TOTAL;			// TOTAL for total price after purchasing
		double discount;		// discount for discount rate
	
		bool done = false;		// boolean "done" that would be used for a while loop
	
	// while loop with default not done
		while (!done)  
		{
			// this is for the menu of transaction types and choose any of these
				num = showMenu();

			// matching the input with the right transaction
				switch (num) 
				{
				// num=1, get total price after enterring prices	
					case PURCHASE: TOTAL = getPrice(); break;  
				// num=2, input discount rate
					case DISCOUNT: discount = getDiscountRate(); break; 
				// num=3, print receipt of total price, discount, tax and the final price
					case PRINT: printReceipt(TOTAL, discount); break; 
				// num=4, print receipt then exit the program immediately
					case EXIT: printReceipt(TOTAL, discount); cout << "System Exit." << endl; cout << endl; done = true; break;  
				// num != 1, 2, 3, 4
					default: cout << "Invalid number! Please enter 1 to 4!!!" << endl; continue; // any number other than 1 to 4, output the statement and skip to asking "num" 
				}
		}
	
	// program ends
        Program_Ending();	
}

//
// Precondition: int n
// Postcondition: show menu of transaction options and return n as number of option
//
int showMenu() 
{
	int n;
	cout << "CougarCS Supermarket POS System" << endl;
	cout << "------------------------------------" << endl;
	cout << "Select an option" << endl;
	cout << "  " << "1. Scan an item" << endl;
	cout << "  " << "2. Set Discount Rate" << endl;
	cout << "  " << "3. Print Receipt" << endl;
	cout << "  " << "4. Exit" << endl;
	cout << endl;
	cout << ">> ";
	cin >> n; 
	return n;
}

//
// Precondition: double price, TOTAL
// Postcondition: enter price that is larger than zero, add price to the TOTAL, return the TOTAL
// 
double getPrice()
{
	// list of local variables 
		double price;		// keep track of price input
		double TOTAL;		// keep track of total of price
	
	// input price and make sure the price is larger than zero
		do{   
			cout << "Enter the price of the item (positive number only): ";
			cin >> price;
			if (price <= 0) 
			{ 
				cout << "The price is INVALID. Please enter a positive price!" << endl;
				cout << "Enter the price of the item (positive number only): ";
				cin >> price;
			}
		}
		 while (price <= 0);

	// calculating total
		cout << "*** " << setprecision(2) << fixed << price << endl;
		cout << endl;
		TOTAL = TOTAL + price;
		cout << "Running Total: " << TOTAL << endl;
		cout << endl;
		
	// return the total price to the main function
		return TOTAL; 
}

//
// Precondition: double percent, discount
// Postcondition: enter discount that is from 0.0 to 1.0, convert discount into percent, return the discount
//
double getDiscountRate()
{
	// list of local variables
		double percent;			// for discount percent
		double discount;		// for discount rate

	// input discount rate and make sure discount is a positive number
		cout << "Enter the Discount Rate (0.0-1.0): ";
		cin >> discount;
		while ((discount <= 0) || (discount > 1)) {
			cout << "The discount is INVALID. Please enter a discount from 0 to 1!" << endl;
			cout << "Enter the Discount Rate (0.0-1.0): ";
			cin >> discount;
		}
	
	// output discount percent
		percent = discount * 100;
		cout << "Customer Discount is " << setprecision(0) << fixed << percent << "% off." << endl;
		cout << endl;
		
	// return discount rate to the main function
		return discount; 
}

//
// Precondition: double TOTAL, discount
// Postcondition: using TOTAL and discount from 2 functions above to calculate tax and totalCharge, return totalCharge
//
void printReceipt(double TOTAL, double discount)
{
	// list of local variables
		double discountprice;		// keep track of discount amount that can be subtracted from TOTAL
		double tax;					// keep track of amount of tax added to TOTAL
		double totalCharge;			// keep track of the final price

	// output total price
		cout << "Total Purchase:" << "   " << setw(6) << setprecision(2) << fixed << TOTAL << endl; 

	// discount
		discountprice = discount * TOTAL;
		cout << "Discount:      " << " - " << setw(6) << setprecision(2) << fixed << discountprice << endl;

	// tax
		tax = (TOTAL - discountprice)*SALETAX;
		cout << "Tax:           " << " + " << setw(6) << setprecision(2) << fixed << tax << endl;

	// total charge
		totalCharge = TOTAL - discountprice + tax;
		cout << "Total Charge:  " << " = " << setw(6) << totalCharge << endl;
		cout << endl;	
}
