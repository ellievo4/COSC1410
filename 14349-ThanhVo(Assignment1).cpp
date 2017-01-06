//1410
//Program 1
//Student: Thanh Vo
//TA: David Fullerton
//Date: 2/2/2015

#include<iostream>
#include <cstdlib>
#include<iomanip>
using namespace std;
const double Rent = 1200.00; const double Internet = 50.00;
int main(){
	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(2);
	double Electricity; double Gas;
	cout << "Electricity bill is ?  $"; cin >> Electricity;
	cout << "Gas bill is ?  $"; cin >> Gas;
	cout << " Bill Name:    " << "Amount:    " << "Who Pays:\n"
		<< "--------------------------------------" << endl;
	cout << " Rent         $ " <<setw(7)<< Rent << "     Moe" << endl;
	cout << " Internet     $ " << setw(7)<< Internet << "     Curly" << endl;
	cout << " Electricity  $ " <<setw(7)<< Electricity << "     Larry" << endl;
	cout << " Gas          $ " <<setw(7)<< Gas << "     Larry\n" <<
	endl;
	cout << " Total Bills  $" << setw(7) << Rent + Internet + Electricity + Gas << endl;
	cout << " Each Share   $" << setw(7) << (Rent + Internet + Electricity + Gas) / 3 << endl;
	cout << "\n Who       " << "Pays to Moe\n"
		 << "--------------------------------------\n";
	double Larry = (Rent + Internet + Electricity + Gas) / 3 - Electricity - Gas; 
	double Curly = (Rent + Internet + Electricity + Gas) / 3 - Internet;
	cout << " Larry     $  " << setw(6) << Larry << endl;
	cout << " Curly     $  " << setw(6) << Curly << endl;
	system("Pause");
	return 0;
}