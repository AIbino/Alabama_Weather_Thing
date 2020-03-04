//
// Program developed by Jeremiah Brewer & Gabriel Mendez-Frances
//
// This program prepares the Alabama weather data file by 
// finding and removing bad data flags and filtering 
// the data into a new file.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;
string leftAlignStringSpace(string replaceThis);

int main(void) {
	ifstream weatherin;
	ofstream weatherout;
	string s_stname, s_date, s_prcp, s_tmax, s_tmin, dataline;
	int pos_stname, pos_date, pos_prcp, pos_tmax, pos_tmin;
	float f_date, f_prcp, f_tmax, f_tmin;
	unsigned int i = 0, records = 0;

	cout << "PROBLEM 2" << endl << endl;

	cout << "Attempting to open Filtered_AL_Weather_Station.txt..." << endl << endl;
	weatherin.open("C:/Temp/Filtered_AL_Weather_Station.txt");

	if (!weatherin) {
		cout << "ERROR: Filtered_AL_Weather_Station file not found." << endl << endl;
		system("pause");
		return 1;
	}
	else {
		cout << "Filtered_AL_Weather_Station file opened." << endl << endl;
	}

	cout << "Creating new file: Weather_Station_Five_Column.txt..." << endl << endl;
	weatherout.open("C:/Temp/Weather_Station_Five_Column.txt");
	if (!weatherout) {
		cout << "ERROR: Weather_Station_Five_Column file not found." << endl << endl;
		system("pause");
		return 1;
	}
	else {
		cout << "Weather_Station_Five_Column file opened." << endl << endl;
	}

	cout << "Attempting to find position of STATION_NAME, DATE, PRCP, TMAX, and TMIN columns..." << endl << endl;
	getline(weatherin, dataline);
	weatherout << left << setw(55) << "STATION_NAME" << setw(15) << "DATE" << setw(10) << "PRCP" << setw(10) << "TMAX" << setw(10) << "TMIN" << endl;

	pos_stname = dataline.find("STATION_NAME");
	if (pos_stname != string::npos) {
		cout << "The index of the STATION_NAME column is " << pos_stname << endl;
	}
	else 
	{
		cout << "Unable to find STATION_NAME" << endl << endl;
		system("pause");
		return 2;
	}

	pos_date = dataline.find("DATE");
	if (pos_date != string::npos) {
		cout << "The index of the DATE column is " << pos_date << endl;
	}
	else
	{
		cout << "Unable to find DATE" << endl << endl;
		system("pause");
		return 2;
	}
	
	pos_prcp = dataline.find("PRCP");
	if (pos_prcp != string::npos) {
		cout << "The index of the PRCP column is " << pos_prcp << endl;
	}
	else
	{
		cout << "Unable to find PRCP" << endl << endl;
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
		cout << "The index of the TMIN column is " << pos_tmin << endl << endl;
	}
	else
	{
		cout << "Unable to find TMIN" << endl << endl;
		system("pause");
		return 2;
	}

	cout << "Parsing data..." << endl << endl;
	getline(weatherin, dataline);
	while (!weatherin.eof()) {
		// Find the value for each header
		s_stname = dataline.substr(pos_stname, 50);
		s_date = dataline.substr(pos_date, 8);
		s_prcp = dataline.substr(pos_prcp, 4);
		s_tmax = dataline.substr(pos_tmax, 2);
		s_tmin = dataline.substr(pos_tmin, 2);

		s_stname = leftAlignStringSpace(s_stname);

		//Output each important value to the output file
		weatherout << left << setw(55) << s_stname 
			<< setw(15) << s_date 
			<< setw(10) << s_prcp 
			<< setw(10) << s_tmax 
			<< setw(10) << s_tmin << endl;

		// Continuously scroll through each line of data
		getline(weatherin, dataline);
		records++;
	}
	cout << "Total number of valid weather entries: " << records << endl << endl;
	cout << "Closing files..." << endl << endl;
	weatherin.close();
	weatherout.close();

	system("pause");
	return 0;
}

string leftAlignStringSpace(string replaceThis) {
	string replacedBy = "";
	int value = replaceThis.length();
	bool nospace = 1;
	for (int i = 0; i < value; i++) {
		if (!nospace) 
		{
			replacedBy += replaceThis.at(i);
		}
		if (!isspace(replaceThis.at(i)) && nospace)
		{
			replacedBy += replaceThis.at(i);
			nospace = 0;
		}
	}
	return replacedBy;
}