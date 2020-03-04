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

int main(void) {
	ifstream weatherin;
	ofstream weatherout;
	string s_tmax, s_tmin, s_prcp, dataline;
	int pos_tmax, pos_tmin, pos_prcp;
	float f_tmax, f_tmin, f_prcp;
	unsigned int i = 0, records = 0;

	cout << "Attempting to open AL_Weather_Station.txt..." << endl << endl;
	weatherin.open("C:/Temp/AL_Weather_Station.txt");

	if (!weatherin) {
		cout << "ERROR: AL_Weather_Station file not found." << endl << endl;
		system("pause");
		return 1;
	}
	else {
		cout << "AL_Weather_Station file opened." << endl << endl;
	}

	cout << "Creating new file: Filtered_AL_Weather_Station.txt..." << endl << endl;
	weatherout.open("C:/Temp/Filtered_AL_Weather_Station.txt");
	if (!weatherout) {
		cout << "ERROR: Filtered_AL_Weather_Station file not found." << endl << endl;
		system("pause");
		return 1;
	}
	else {
		cout << "Filtered_AL_Weather_Station file opened." << endl << endl;
	}

	cout << "Attempting to find position of TMAX, TMIN, and PRCP columns..." << endl << endl;
	getline(weatherin, dataline);
	weatherout << dataline << endl;

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
	
	pos_prcp = dataline.find("PRCP");
	if (pos_prcp != string::npos)
		cout << "The index of the PRCP column is " << pos_prcp << endl << endl;
	else
	{
		cout << "Unable to find PRCP" << endl << endl;
		system("pause");
		return 2;
	}

	// Skipping formatting line
	getline(weatherin, dataline);

	cout << "Parsing data..." << endl << endl;

	while (!weatherin.eof()) {
		// Continuously scroll through each line of data
		getline(weatherin, dataline);

		// Find the value for each header
		s_tmax = dataline.substr(pos_tmax, 5);
		s_tmin = dataline.substr(pos_tmin, 5);
		s_prcp = dataline.substr(pos_prcp, 5);

		// Converting string values to floats
		f_tmax = stof(s_tmax);
		f_tmin = stof(s_tmin);
		f_prcp = stof(s_prcp);

		if (f_tmax != -9999 && f_tmin != -9999 && f_prcp != -9999) {
			weatherout << dataline << endl;
			records++;
		}
	}

	cout << "Total number of valid weather data entries: " << records << endl << endl;
	cout << "Closing files..." << endl;
	weatherin.close();
	weatherout.close();

	system("pause");
	return 0;
}
