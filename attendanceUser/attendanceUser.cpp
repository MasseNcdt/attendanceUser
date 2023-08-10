#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "checkLogin.h"
#include "init.h"
#include "searchCadet.h"
#include "attendance.h"

using namespace std;

vector<string> emailAddresses;
string email;
vector<string> passwords;
string password;
vector<string> persons;
string person;
vector<string> units;
string unit;

fstream menu;

int main() {

	//Initiate the program by filling email vector with saved data
	memoryInit();

	//Welcome the user
	cout << "Welcome to the attendance taking tool of the cadets program!";

	//Begin the login process

	login();

	system("cls");

	menu.open("title.txt", ios::in);
	string line;
	while (getline(menu, line)) {
		cout << line << endl;
	}
	menu.close();

	while (true) {

		cout << "\n\nWhat would you like to do?\n\nTake attendance - 1\nAdd new cadet - 2\nSee your info - 3\nQuit - 4\n\n[1/2/3/4]";
		int option;
		cin >> option;

		switch (option) {

		case 1:

			attendance();
			break;

		case 2:

			cout << "bruh";
			cadetsList(false);
			system("cls");
			break;

		case 3:

			cout << "\nYour email: " << email << "\nYour password: " << password << "\nYour unit: " << unit << "\n\nYour cadets:\n\n";
				for (int i = 0; i < persons.size(); i++) {
					cout << persons.at(i);
					cout << endl;
				}
				cout << "\n\n";
			break;

		case 4:
			return 0;
			break;

		}

	}

	return 0;

}