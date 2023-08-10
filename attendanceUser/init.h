#pragma once

fstream init;

int memoryInit();

extern vector<string> emailAddresses;
extern vector<string> passwords;
extern vector<string> persons;
extern vector<string> units;
extern string unit;
extern string person;

using namespace std;

int memoryInit() {

	init.open("login.txt", ios::in);

	//Read previously recorded email adress
	while (getline(init, email)) {

		emailAddresses.push_back(email);

	}

	init.close();
	init.open("password.txt", ios::in);

	//Read previously recorded password
	while (getline(init, password)) {

		passwords.push_back(password);

	}

	init.close();
	init.open("persons.txt", ios::in);

	while (getline(init, person)) {

		persons.push_back(person);

	}

	init.close();
	init.open("unit.txt", ios::in);

	while (getline(init, unit)) {

		units.push_back(unit);

	}

	init.close();
	return 1;

}