#pragma once

#include "resident.h"
#include <list>
#include <map>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

class ResidentGroup {
private:
	map<string, list<Resident>> residents; // list of residents and mapped with city name

public:
	// Read residents from the file
	void read_residents_file(const string& file) {
		ifstream fin(file);

		if (fin.fail()) {
			cout << "Unable to read file " << file << endl;
			return;
		}
		while (!fin.fail()) {
			string city;
			string fname;
			string lname;
			string string_age;
			string gender;
			getline(fin, city, ',');
			getline(fin, fname, ',');
			getline(fin, lname, ',');
			getline(fin, string_age, ',');
			getline(fin, gender, '\n');
			int age;
			stringstream ssInt(string_age);    // change the string type age to int type
			ssInt >> age;
			
			if (!fin.fail()) {
				Resident resident(city, fname, lname, age, gender);
				residents[city].push_back(resident);    // Store the resident to the resident group
			}
		}
		fin.close();
	}

	// display all residents
	void display_all_residents() const {
		auto iter = residents.begin(); // Check if there are residents in the city

		while (iter != residents.end()) {
			for (auto& resident : (iter->second)) {
				resident.display_resident();
			}
			iter++;
		}
	}

	//display all residents in the city
	void display_residents(const string& city) const {
		auto iter = residents.find(city); // Check if there are residents in the city

		if (iter == residents.end()) {   
			cout << "There are no residents in the " << city << endl;
			return;
		}
		
		auto& list = iter->second;

		for (auto& resident : list) {
			resident.display_resident();
		}
	}

	// display residents of given gender in the city
	void display_residents_by_gender(const string& city, const string& gender) const {
		auto iter = residents.find(city); // Check if there are residents in the city

		if (iter == residents.end()) {
			cout << "There are no residents in the " << city << endl;
			return;
		}
		auto& list = (*iter).second;
		for (auto& resident : list) {
			if (resident.get_gender() == gender) {
				resident.display_resident();
			}
		}
	}

	//display residents between the ages in the city
	void display_residents_by_age(const string& city, int& min_age, int& max_age) const {
		auto iter = residents.find(city);
		if (iter == residents.end()) {
			cout << "There are no residents in the " << city << endl;
			return;
		}
		auto& list = (*iter).second;
		for (auto& resident : list) {
			if ((resident.get_age() >= min_age) and (resident.get_age() <= max_age)) {
				resident.display_resident();
			}
		}
	}

	// Save resident in the residents group
	void save_resident(const string& city, const string& fname, const string& lname, const int& age, const string& gender) {
		Resident resident(city, fname, lname, age, gender);

		residents[city].push_back(resident);
	}

	// write the residents group into the file
	void write_residents(const string& file) {
		ofstream fout(file);

		for (auto& item : residents) {
			for (auto& resident : item.second) {
				fout << resident.get_city() << "," << resident.get_fname() << "," << resident.get_lname() << ","
					<< resident.get_age() << "," << resident.get_gender() << endl;
			}
		}
		fout.close();
	}
};