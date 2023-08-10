#pragma once

#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<string> present;
vector<string> absent;
vector<string> excused;
vector<string> na;
extern vector<string> persons;
bool firstname = true;

string condition;
string date;
char confirmation;

void attendance();
void assign(string name, string condition);
void writeCSV(vector<string> namesPresent, vector<string> namesAbsent, vector<string> namesNA, vector<string> namesExcused, string currentDate);

void attendance() {

	cout << "You will have to assign all of your cadets into 4 categories:\n\nPresent;\nAbsent;\nExcused and\nNon-Applicable\n\n";
	
	for (int i = 0; i < persons.size(); i++) {

		cout << persons.at(i) << ": [p/a/n/e]";
		getline(cin, condition);
		assign(persons.at(i), condition);
	
	}

	system("cls");
	cout << "Is this correct?\n\n";

	cout << "Present:\n\n";
	for (int i = 0; i < present.size(); i++) { cout << present.at(i) << endl; }
	cout << "\n\n";

	cout << "Absent:\n\n";
	for (int i = 0; i < absent.size(); i++) { cout << absent.at(i) << endl; }
	cout << "\n\n";

	cout << "Non-Applicable:\n\n";
	for (int i = 0; i < na.size(); i++) { cout << na.at(i) << endl; }
	cout << "\n\n";

	cout << "Excused:\n\n";
	for (int i = 0; i < excused.size(); i++) { cout << excused.at(i) << endl; }
	cout << "\n\n";

	cout << "[y/n]";
	cin >> confirmation;
	
	if (confirmation == 'y') {
		cout << "What day is it? [DD-MM-YYYY]\n\n";
		cin.ignore();
		getline(cin, date);
		writeCSV(present, absent, na, excused, date);
	}

}

void assign(string name, string condition) {

	if (condition == "p") {present.push_back(name); firstname = false;}
	else if (condition == "a") { absent.push_back(name); firstname = false;}
	else if (condition == "n") { na.push_back(name); firstname = false;}
	else if (condition == "e") { excused.push_back(name); firstname = false;}
	else {
		if (firstname != true) { cout << "\nThis input is invalid, please try again.\n\n" << name << ": [p/a/n/e]"; }
			firstname = false;
			getline(cin, condition);
			assign(name, condition);
		
	}
}

void writeCSV(vector<string> namesPresent, vector<string> namesAbsent, vector<string> namesNA, vector<string> namesExcused, string currentDate) {

	ofstream outputFile("truedata.txt", ios::app); // Open the file in append mode

	if (outputFile.is_open()) {
		// Loop through each vector and write data for each status
		for (string name : namesPresent) {
			outputFile << name << "," << "Present" << "," << currentDate << "\n";
		}
		for (string name : namesAbsent) {
			outputFile << name << "," << "Absent" << "," << currentDate << "\n";
		}
		for (string name : namesNA) {
			outputFile << name << "," << "NA" << "," << currentDate << "\n";
		}
		for (string name : namesExcused) {
			outputFile << name << "," << "Excused" << "," << currentDate << "\n";
		}
		outputFile.close();
		cout << "Attendance taken, thank you." << endl;
	}
	else {
		cout << "Error: Unable to open file for writing." << endl;
	}
}
