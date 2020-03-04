//
// Program developed by Jeremiah Brewer & Gabriel Mendez-Frances
//
// This program finds the maximum and minimum temperatures from
// the Alabama weather stations in March 2018
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(void) {
	fstream five_column_in;
	string s_name, s_tmax, s_tmin, s_trutmax, s_trutmin, dataline;
	int pos_name, pos_tmax, pos_tmin;
	float f_tmax, f_tmin, trutmax = 0, trutmin = 0;

	cout << "PROBLEM 3" << endl << endl;

	cout << "Attempting to open Weather_Station_Five_Column.txt..." << endl << endl;
	five_column_in.open("C:/Temp/Weather_Station_Five_Column.txt", ios::in);

	if (!five_column_in) {
		cout << "ERROR: Weather_Station_Five_Column file not found." << endl << endl;
		system("pause");
		return 1;
	}
	else {
		cout << "Weather_Station_Five_Column file opened." << endl << endl;
	}

	cout << "Attempting to find position of STATION_NAME, TMAX, TMIN columns..." << endl << endl;
	getline(five_column_in, dataline);

	pos_name = dataline.find("STATION_NAME");
	if (pos_name != string::npos) {
		cout << "The index of the STATION_NAME column is " << pos_name << endl;
	}
	else
	{
		cout << "Unable to find STATION_NAME" << endl << endl;
		system("pause");
		return 2;
	}

	pos_tmax = dataline.find("TMAX");
	if (pos_tmax != string::npos) {
		cout << "The index of the TMAX column is " << pos_tmax << endl;
	}
	else
	{
		cout << "Unable to find TMAX" << endl << endl;
		system("pause");
		return 2;
	}

	pos_tmin = dataline.find("TMIN");
	if (pos_tmin != string::npos) {
		cout << "The index of the TMIN column is " << pos_tmin << endl;
	}
	else
	{
		cout << "Unable to find TMIN" << endl << endl;
		system("pause");
		return 2;
	}

	cout << "Parsing data..." << endl << endl;
	getline(five_column_in, dataline);

	// Find the station name
	s_name = dataline.substr(pos_name, 50);

	// Find the value for each header
	s_tmax = dataline.substr(pos_tmax, 5);
	s_tmin = dataline.substr(pos_tmin, 5);

	// Converting string values to floats
	f_tmax = stof(s_tmax);
	f_tmin = stof(s_tmin);

	//Setting maxes and mins
	trutmax = f_tmax; s_trutmax = s_name;
	trutmin = f_tmin; s_trutmin = s_name;
	while (!five_column_in.eof()) {
		// Find the value for each header
		s_tmax = dataline.substr(pos_tmax, 5);
		s_tmin = dataline.substr(pos_tmin, 5);

		// Converting string values to floats
		f_tmax = stof(s_tmax);
		f_tmin = stof(s_tmin);

		//Checking maxes and mins
		if (trutmax < f_tmax) {
			trutmax = f_tmax;
			s_trutmax = s_name;
		}
		if (trutmax = f_tmax) {
			if (!(s_trutmax == s_name)) {
				s_trutmax += " and ";
				s_trutmax += s_name;
			}
		}
		if (trutmin > f_tmin) {
			trutmin = f_tmin;
			s_trutmin = s_name;
		}
		if (trutmin = f_tmin) {
			if (!(s_trutmin == s_name)) {
				s_trutmin += " and ";
				s_trutmin += s_name;
			}
		}

		// Continuously scroll through each line of data
		getline(five_column_in, dataline);
	}
	cout << "Max temp value was " << trutmax << " from " << s_trutmax << endl;
	cout << "Min temp value was " << trutmin << " from " << s_trutmin << endl;

	cout << "Closing files..." << endl << endl;
	five_column_in.close();

	system("pause");
	return 0;
}