#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Resident {
private:
	string city;
	string fname;
	string lname;
	int age;
	string gender;

public:
	// Constructor for a resident
	Resident(const string& city, const string& fname, const string& lname, const int& age, const string& gender):
		city{ city }, fname{ fname }, lname{ lname }, age{ age }, gender{ gender } {}

	// Display the resident information
	void display_resident() const {
		cout << "[ " << city << " ]" << fname << " " << lname << " - " << gender << " - " << age << endl;
	}

	// Getter
	string get_city() const { return city; }
	string get_fname() const { return fname; }
	string get_lname() const { return lname; }
	int get_age() const { return age; }
	string get_gender() const { return gender; }
};