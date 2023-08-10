#pragma once


using namespace std;

fstream checkLogin;
string newEmail;
string newPassword;
string confirmPassword;
string loginPassword;

extern vector<string> emailAddresses;
extern string email;
extern vector<string> passwords;
extern string password;
extern vector <string> persons;

void newUser(string email, string password);
bool login();
bool match(string mail, string pass1, string pass2);
void confirm(string mail, string password);
void unitAssign();
int cadetsList(bool signin);

bool login() {

	//Check if user is new and take their info if they are
	if (emailAddresses.at(0) == "new") {

		//Ask for the user's email
		cout << "\n\nIt seems you are new to this program, please enter your email address and its password to continue.\n\nIT IS IMPORTANT TO CAREFULLY READ INSTRUCTIONS\n\n";
		cout << "Email: ";
		getline(cin, newEmail);

		//Ask for the email's password
		cout << "\nPassword: ";
		getline(cin, newPassword);

		//Check if input is empty
		while (newPassword.empty()) {

			cout << "You can't just enter nothing and expect me not to notice it, enter your actual password now.\n\nPassword: ";
			getline(cin, newPassword);

		}

		//Ask password again
		cout << "\nEnter password again: ";
		getline(cin, confirmPassword);

		//See if the passwords entered match
		match(newEmail, newPassword, confirmPassword);

		//If passwords do not match, ask what the password was again
		while (match(newEmail, newPassword, confirmPassword) == false) {

			cout << "The two passwords do not match, please enter them again.\n\nEnter password again: ";
			getline(cin, confirmPassword);
			match(newEmail, newPassword, confirmPassword);

		}


	}

	else
		cout << "\n\nWelcome back. Please enter the password for the email " << emailAddresses.at(0) << ": ";

	bool logpswd = false;
	while (logpswd == false) {

		getline(cin, loginPassword);

		//Check if password matches account's password
		if (loginPassword == passwords.at(0)) {
			logpswd = true;
			return true;
		}
		else
			cout << "This is not the right password, try again.\n\nPassword: ";

	}

}

//Checks if two strings match
bool match(string mail, string pass1, string pass2) {

	if (pass1 == pass2) {
		confirm(mail, pass1);
		return true;
	}
	else
		return false;

}

//Confirms the entered credentials are the ones desired and registers them if they are
void confirm(string mail, string password) {

	char answer;

	cout << "Are these informations correct?\n\nEmail: " << mail << "\nPassword: " << password << "\n\n[y/n]";
	cin >> answer;

	if (answer == 'y') {

		newUser(mail, password);

	}
	else if (answer == 'n') {

		cout << "\n\nPlease answer the questions again.\n\n";
		cin.ignore();
		login();

	}
	else
		cout << "This is not a valid answer, please try again.\n\n";
	confirm(mail, password);
}

fstream newAccount;

void newUser(string email, string password) {

	newAccount.open("login.txt", ios::out | ios::trunc);
	newAccount << email;
	newAccount.close();

	newAccount.open("password.txt", ios::out | ios::trunc);
	newAccount << password;
	newAccount.close();

	unitAssign();

}

void unitAssign() {

	int choice;
	string element;
	int unit;
	char confirm = NULL;

	cout << "\n\nPlease identify what is your home unit's element.\n\nIf you are an air cadet (RCACS), enter 1.\nIf you are a sea cadet (RCSCC), enter 2.\nIf you are an army cadet (RCACC), enter 3.\n[1/2/3]";
	cin >> choice;

	while (choice < 1 or choice > 3) {

		switch (choice) {

		case 1:
			element = "RCACS";
			break;
		case 2:
			element = "RCSCC";
			break;
		case 3:
			element = "RCACC";
			break;
		defaullt:
			cout << "This is not an option, try again.";
			continue;

		}
	}

	cout << "\nWhat about your home unit's number?\nEnter here: ";
	cin >> unit;

	while (cin.fail()) {

		cout << "\n\nInvalid input, please enter only numbers\n\nEnter here: ";
		cin >> unit;

	}

	//This question will keep repeating until the user's input is valid
	while (confirm != 'y' and confirm != 'n') {

		cout << "\n\nIs this your unit?\n" << element << " " << unit << "\n\n[y/n]";
		cin >> confirm;

		if (confirm == 'y') {

			newAccount.open("unit.txt", ios::out | ios::trunc);
			newAccount << element << " " << unit;
			newAccount.close();

			cout << "Unit registered.\n\n";

		}

		else if (confirm == 'n') {

			cout << "Please answer the questions again, then.\n\n";
			unitAssign();

		}

		else
			cout << "Invalid input, try again.\n\n";

	}

	cout << "Lastly, please enter the names of the cadets you are in charge of.";
	cadetsList(true);

}

int cadetsList(bool signin) {

	string name;
	cout << "\nStart with the last name of the cadet (starting with a capital, e.g Doe) followed by the first name of your cadet(starting with a capital, e.g John).\nNothing should separate the two from each other(e.g DoeJohn).\nIf you are done, type in 'DONE'.\n\n";
	cin.ignore();

	while (name != "DONE") {

		cout << "Name: ";

		getline(cin, name);
		
		if (name == "DONE") {
			break;
		}

		persons.push_back(name);

	}

	newAccount.open("persons.txt", ios::out | ios::trunc);

	for (int i = 0; i < persons.size(); i++) {
		newAccount << persons.at(i) << endl;
	}

	newAccount.close();

	if (signin == true) {

		cout << "Great, you are all setup. Restart the program to start taking attendance!\n\n";
		exit(0);

	}
}