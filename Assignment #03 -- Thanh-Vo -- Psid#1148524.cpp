/*
Course:		COSC - 1410
Assignment: #03
Date Due :  02 - 23 - 2015
Student :   Thanh Vo
Peoplesoft: 1148524
TA :        David Fullerton

Purpose:    The purpose of this lab is to show my understanding of the syntax in Chapter 2
			including while-, do-while-, and for-loops, if-else, and nested loops, etc. 
*/

#include <iostream>  // provides:  cout, cin
#include <iomanip>   // provides:  setw

using namespace std; // setting up my environment


const double Item1 = 2.00,    // price of item 1
			 Item2 = 2.50,    // price of item 2
			 Item3 = 1.50,    // price of item 3
			 Item4 = 3.00;    // price of item 4


int main() 
{

	double bal, any; //bal for tracking the debit card balance, any for tracking the end balance

	int num, quantity; // quantity for tracking quantity of a selected item, num for number of the selected item

	char YN; // YN for yes or no if being ask if buying more item

	// set variables for all numbers of selected items, num1 for item 1, num2 for item 2, num3 for item 3, num4 for item 4
	int num1 = 1, num2 = 2, num3 = 3, num4 = 4;

	// set variables to keep track of the quantity added. These quantities start with zero and will be added up if the customer 
	// would like to choose more
	int quant1 = 0, quant2 = 0, quant3 = 0, quant4 = 0;

	// set variables to keep track of prices for item 1, 2, 3 and 4. Similarly, all prices start with 0.00 and will be added up 
	// when any amount of item is enterred
	double price1 = 0.00, price2 = 0.00, price3 = 0.00, price4 = 0.00;


	cout << "Please enter your debit card balance: "; 
	cin >> bal; // enter debit card balance
	any = 0 + bal; //use this to separate end balance and debit card balance


	while ((YN = 'Y') || (YN = 'y') && (any >= 0)) //open a loop with default 'Y' and 'y'
	{

		cout << "Your current balance is: " << setprecision(2) << fixed << any << endl;
		//output current balance with exactly 2 decimal places

		// enter a list of item 1, 2, 3, and 4
		cout << "Item 1: $" << Item1 << "\nItem 2: $" << Item2 << "\nItem 3: $" << Item3 << "\nItem 4: $" << Item4 << endl;


		// enter the number of a selected item, a while loop is perform to keep customer entering num from 1 to 4 
		cout << "Please choose the item number from the menu above: ";
		cin >> num;
		while ((num < 1) || (num > 4)) {
			cout << "ERROR! Please enter the number from 1 to 4!" << endl;
			cout << "Please choose the item number from the menu above: ";
			cin >> num;
		}


		// A switch operation in order to give the number of item shown in receipt. Since item number will not be added up,
		// I choose to add each of num1, num2, num3 and num4 with zero 
		switch (num){
		case 1: num1 = num1 + 0; break;
		case 2: num2 = num2 + 0; break;
		case 3: num3 = num3 + 0; break;
		default: num4 = num4 + 0;
		}


		//enter quantity of the selected item, again, a while loop to keep customer entering a positive quantity of the selected item
		cout << "Please enter the quantity: ";
		cin >> quantity;
		while (quantity < 0) {
			cout << "ERROR! Please enter a number larger than 0 or equal to 0!" << endl;
			cout << "Please enter the quantity: ";
			cin >> quantity;
		}


		// A switch operation in order to give the quantity of selected item shown in receipt. Whenever the customer adds more 
		// item 1 or 2 or 3 or 4, the quant1, quant2, quant3 or quant4 will be added up with quantity
		switch (num){
		case 1: quant1 = quant1 + quantity; break;
		case 2: quant2 = quant2 + quantity; break;
		case 3: quant3 = quant3 + quantity; break;
		default: quant4 = quant4 + quantity;
		}


		// A switch operation in order to find the end balance after buying any quantity of item 1 or 2 or 3 or 4
		switch (num){
		case 1: price1 = (quant1 * Item1), any = any - (quantity * Item1); break;
		case 2: price2 = (quant2 * Item2), any = any - (quantity * Item2); break;
		case 3: price3 = (quant3 * Item3), any = any - (quantity * Item3); break;
		default: price4 = (quant4 * Item4), any = any - (quantity * Item4);
		}


		cout << "Your new balance is: $" << any << endl; //output the end balance after buying a selected item


		// I use this to stop he program when the customer does not have enough money in his or her debit card
		if (any < 0) {
			cout << "Sorry you do not have enough money to make this purchase.Your order has been cancelled." << endl;
			break; // end the loop immediately  
		}


		// Ask if the customer wants to buy another item
		cout << endl;
		cout << "Would you like to buy more items? if yes enter [y] otherwise enter [n]: ";
		cin >> YN;


		// if the customer enters 'N' or 'n' for "no" answer. The receipt will be printed out.
		if ((YN == 'N') || (YN == 'n')) {
			cout << "You made the following purchase." << endl;
			cout << "Item " << "Quantity    " << "Price" << endl;
			cout << "----------------------" << endl;


			//This is for a list (table) of selected items with their quantities and prices
			//First of all, a while loop filters out item no.1 when its quantity is 0
			while (quant1 != 0) {
				cout << "  " << setw(1) << num1 << "     " << setw(1) << quant1 << "      " << setw(7) << price1 << endl; break;
				if (quant1 == 0) break;
			}

			//Second of all, a while loop filters out item no.2 when its quantity is 0
			while (quant2 != 0) {
				cout << "  " << setw(1) << num2 << "     " << setw(1) << quant2 << "      " << setw(7) << price2 << endl; break;
				if (quant2 == 0) break;
			}

			//Third of all, a while loop filters out item no.3 when its quantity is 0
			while (quant3 != 0) {
				cout << "  " << setw(1) << num3 << "     " << setw(1) << quant3 << "      " << setw(7) << price3 << endl; break;
				if (quant3 == 0) break;
			}

			//Fourth of all, a while loop filters out item no.4 when its quantity is 0
			while (quant4 != 0) {
				cout << "  " << setw(1) << num4 << "     " << setw(1) << quant4 << "      " << setw(7) << price4 << endl; break;
				if (quant4 == 0) break;
			}


			// output the begining balance bal and ending balance any
			cout << endl;
			cout << "Beginning Balance: " << setw(6) << bal << endl;
			cout << "Ending Balance:    " << setw(6) << any << endl;

			// output the ending part of a receipt which is a friendly greeting 
			cout << endl;
			cout << "Thank you for shopping. Please come again." << endl;
			break; // end the loop immediately  
		}

	}

	// tell the customer to hit any key and wait to return back to operating system
	system("Pause"); 
	return 0;

}

//End the program!!!