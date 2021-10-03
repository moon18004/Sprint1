#include <iostream>
#include <string>
#include "resident_group.h"
using namespace std;


// menu options
void display_menu1() {
	cout << "Choose an option " << endl;
	cout << "      1. Display all residents in all cities" << endl;
	cout << "      2. Select a city" << endl;
	cout << "      3. Add a resident" << endl;
	cout << "      4. Exit" << endl;
}
void display_menu2()
{
	cout << "Choose an option " << endl;
	cout << "      1. Display all residents in the city" << endl;
	cout << "      2. Display residents by gender" << endl;
	cout << "      3. Display residents by age" << endl;
	cout << "      4. Exit" << endl;
}

// Add a new resisdent
void add_resident(ResidentGroup &rs) {
	string city;       // resident city
	string fname;      // resident's first name
	string lname;      // resident's last name
	int age;           // resident's age
	string gender;     // resident's gender

	cout << "City: ";
	getline(cin, city);
	cout << "First name: ";
	cin >> fname;
	cout << "Last name: ";
	cin >> lname;
	cout << "Gender: ";
	cin >> gender;
	cout << "Age: ";
	cin >> age;
	rs.save_resident(city, fname, lname, age, gender);  // add the resident into the residents group
}

// for user's response
void select_menu(ResidentGroup& rs) {
	int input;   //user's input for menu options
	while (true) {
		display_menu1();
		cout << ">> ";
		cin >> input;
		cin.ignore();
		cout << endl;

		if (input == 1) {                    // display all resisdents 
			rs.display_all_residents();
		}
		else if (input == 2) {               //display resisdents in a city
			cout << "City: ";
			string city;
			getline(cin, city);
			display_menu2();
			cout << ">> ";
			cin >> input;
			cin.ignore();
			if (input == 1) {
				rs.display_residents(city);  // display all residents in the city
			}
			else if (input == 2) {           // display residents of given gender in the city
				string gender;
				cout << "Gender: ";
				cin >> gender;
				rs.display_residents_by_gender(city, gender);
			}
			else if (input == 3) {           // display residents betweend the ages in the city
				int min_age;
				int max_age;
				cout << "Min age: ";
				cin >> min_age;
				cout << "Max age: ";
				cin >> max_age;
				rs.display_residents_by_age(city, min_age, max_age);
			}
			else if (input == 4) {
				return;
			}
		}
		else if (input == 3) {
			add_resident(rs);
		}
		else {
			return;
		}
	} 
}

int main()
{
	// Create a resisdents group
	ResidentGroup rs;
	
	// Read residents' information from the file
	rs.read_residents_file("residents.txt");

	// Select menu
	select_menu(rs);

	// Save the residents into the file
	rs.write_residents("residents.txt");
}
