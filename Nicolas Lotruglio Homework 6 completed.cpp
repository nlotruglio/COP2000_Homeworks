// Nicolas Lotruglio	
// 12/05/17
// COP200
// Homework 6

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

void showAll(string theAccounts[5][7]);
void sortInput(string theAccounts[5][7]);
bool validateUser(string theAccounts[5][7], string username, string password, int &saveRow);
bool readFile(string theAccounts[5][7]);


bool readFile(string theAccounts[5][7])
{
	ifstream file ("AccountData.txt");
	if (!file.is_open()) {
		return false;
	} 
	else {
		cout << "File read successfully \n\n";
	}
	for (int i = 0; i != 5; ++i) {
		for (int j = 0; j != 7; ++j) {
			file >> theAccounts[i][j];
		}
	}
	file.close();
}

void showAll(string theAccounts[5][7])
{
	ofstream myfile("sortedBackup.txt");
	if (!myfile.is_open()) {
		cout << "Unable to backup data";
	}
	else {
		for (int i = 0; i != 5; ++i) {
			cout << "\n";
			for (int j = 0; j != 7; ++j) {
				cout << setw(18) << theAccounts[i][j] << "\t";
				myfile << setw(18) << theAccounts[i][j] << "\t";
			}
		}
		cout << "Backup file completed \n";
	}
}
	

void sortInput(string theAccounts[5][7])
{
	bool flag;
	do
	{
		flag = 0;
		for (int count = 0; count < 6; count++)
		{
			if (theAccounts[count][2] > theAccounts[count + 1][2])
			{
				theAccounts[count][2].swap(theAccounts[count + 1][2]);
				flag = 1;
			}
		}
	} while (flag == 1);
}

bool validateUser(string theAccounts[5][7], string username, string password, int &saveRow)
{
	for (int i = 0; i != 5; ++i) {
		if (username == theAccounts[i][0])
		{
			saveRow = i;
		}
	}
	if (password == theAccounts[saveRow][3])
	{
		return true;
	}
	else
		cout << "Username and Password do not match... Please try again...\n";
		return false;
}

int main()
{
	string theAccounts[5][7];
	string username = "";
	string password = "";
	string prev_username = "Previous_Username";
	string prev_password = "Previous_Password";
	int saveRow;

	if (readFile(theAccounts) == false)
	{
		cout << "The program will now exit due to an error reading the file.";
		return 0;
	}

	while (username != prev_username && password != prev_password) {
		do {
			cout << "Please enter the following information or 0 to Exit... \n";

			cout << "\n Enter username > \t";
			cin >> username;
			if (cin.fail() || username == "0" || username == prev_username) {
				return 0;
			}

			cout << "\n Enter password > \t";
			cin >> password;
			if (cin.fail() || password == "0" || password == prev_password) {
				return 0;
			}

			validateUser(theAccounts, username, password, saveRow);
		} while (validateUser(theAccounts, username, password, saveRow) == false);
		string user_access = "A";
		if (theAccounts[saveRow][5] == user_access) {
			showAll(theAccounts);
		}
		else {
			cout << "Welcome back " << theAccounts[saveRow][1] << "\n";
			for (int j = 0; j != 7; ++j) {
				cout << theAccounts[j][saveRow] << "\t";
			}
			prev_username = username;
			prev_password = password;
			username = "username";
			password = "password";
		}
	}
		return 0;
}
