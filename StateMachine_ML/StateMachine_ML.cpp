// StateMachine_ML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	//int inventory = 4;
	int coke = 3;
	int pepsi = 3;
	int inventory = coke + pepsi;
	int SodaCost = 75;
	int stage = 1;
	int sum = 0;
	int Change = 0;
	int total = 0;
	while (true) {
		enum myStages { Enter$ = 1, Selection = 2, InventoryCheck = 3, ReturnT = 4 };
		switch (stage) {
		case Enter$: //Enter$
			cout << "Enter Soda Cost or (0) to refund: ";
			cin >> total;
			if (total == 0) {
				stage = ReturnT;
				break;
			}
			sum += total;
			if (sum < SodaCost) {
				cout << "Please enter full amount remaining amount...75cents for a Soda" <<
					endl;
				stage = Enter$;
				break;
			}
			if (sum >= SodaCost) {
				Change = abs(sum) - SodaCost;
				sum = 0;
				cout << "Refunded amount: " << Change << endl;
				stage = Selection;
			}
		case Selection:  //selection 
			cout << "Waiting for Selection..." << endl;
			cout << "Select (1) for Pepsi and (2) for Cola, or (0) to Refund: ";
			int choices;
			cin >> choices;
			if (choices == 1) {
				stage = InventoryCheck;
				pepsi--;
			}
			if (choices == 2) {
				stage = InventoryCheck;
				coke--;
			}
			if (choices == 0) {
				sum = SodaCost;
				stage = ReturnT;
			}
			break;
		case InventoryCheck: //Inventory
			if (pepsi == 0) {
				cout << "Sorry Pepsi, sold out" << endl;
				pepsi = -1;
				stage = Selection;
			}
			else if (coke == 0) {
				coke = -1;
				if (pepsi < 0 && coke < 0) {
					cout << "Sorry all sold out, sorry...";
					sum = total;
					stage = ReturnT;
				}
				if (coke >= 0) {
					cout << "Sorry Coke, sold out" << endl;
					stage = Selection;
				}
			}
			else {
				if (choices == 1 && pepsi > 0) { //dispense pepsi
					cout << "Pepsi dispensing..." << endl;
					cout << "Refunded amount: " << Change << endl;
					stage = Enter$;
				}
				else if (choices == 2 && coke > 0) { //dispense cola
					cout << "Cola dispensing..." << endl;
					cout << "Refunded amount: " << Change << endl;
					stage = Enter$;
				}
				else {
					cout << "Returning to start:" << endl;
					stage = Selection;
				}
			}
			break;
		case ReturnT: //Return$ stage
			cout << "Refunded amount: " << sum << endl;
			sum = 0;
			stage = Enter$;
			break;
		}
	}
	return 0;
}