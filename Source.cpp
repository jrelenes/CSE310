#include <iostream> 
#include <string>		
#include <vector>
#include <fstream>
#include "defn.h"
using namespace std;
unsigned int hash1(int event_id) {
	unsigned long int value = event_id;
	value = value % TABLE_SIZE;
	return value;
}
vector<struct storm_event> input_details(int n, vector<string>year_array)
{
	vector<struct storm_event> events1;
	int z = 0;
	int m = 0;
	while (m < n)
	{
		//cout << year_array[z] << endl;
		string details0 = "details-" + year_array[z] + ".csv";
		ifstream infile;
		int control;
		control = 13;
		infile.open(details0);
		string STRING;
		vector <string> STRING11;
		int t = 0;
		string* tempstring = new string[100 * 10 ^ 10];
		infile >> STRING;
		int i = 0;
		string temp;
		int counter = 0;
		while (infile >> STRING && t < 1)
		{
			tempstring[t] = STRING;
			if (t >= 0)
			{
				while (i < tempstring[0].length())
				{
					if (tempstring[0].substr(i, 1) == ",")
					{
						counter++;
					}
					i++;
				}
				//13 or 6
				if (counter != control)
				{
					temp = temp + tempstring[0] + " ";
					i = 0;
					counter = 0;
					while (i < temp.length())
					{
						if (temp.substr(i, 1) == ",")
						{
							counter++;
						}
						i++;
					}
					//13 or 6
					if (counter == control)
					{
						STRING11.push_back(temp);
						temp.clear();
					}
					i = 0;
					counter = 0;
				}
				else
				{
					STRING11.push_back(tempstring[0]);
				}
				t = -1;
				i = 0;
				counter = 0;
			}
			t++;
		}
		vector<string>STRING1;
		for (int i = 0; i < STRING11.size(); i++)
		{
			STRING11[i].append(",");
			int j = 0;
			while (j < STRING11[i].length())
			{
				if (STRING11[i].substr(j, 1) == ",")
				{
					STRING1.push_back(temp);
					temp.clear();
					j++;
				}
				else
				{
					temp = temp + STRING11[i].substr(j, 1);
					j++;
				}
			}
			j = 0;
		}
		delete[] tempstring;
		STRING.clear();
		infile.close();
		vector<string>words1;
		words1 = STRING1;
		vector<int> newEvent1;
		int a = 0;
		for (int i = 0; i < words1.size(); i += 14)
		{
			struct storm_event newEvent1[19000];
			newEvent1[a].event_id = stoi(words1[i]);
			for (int j = 0; j < words1[i + 1].length(); ++j) {
				newEvent1[a].state[j] = words1[i + 1][j];
			}
			newEvent1[a].year = stoi(words1[i + 2]);
			for (int j = 0; j < words1[i + 3].length(); ++j) {
				newEvent1[a].month_name[j] = words1[i + 3][j];
			}
			for (int j = 0; j < words1[i + 4].length(); ++j) {
				newEvent1[a].event_type[j] = words1[i + 4][j];
			}
			newEvent1[a].cz_type = words1[i + 5][0];
			for (int j = 0; j < words1[i + 6].length(); ++j) {
				newEvent1[a].cz_name[j] = words1[i + 6][j];
			}
			newEvent1[a].injuries_direct = stoi(words1[i + 7]);
			newEvent1[a].injuries_indirect = stoi(words1[i + 8]);
			newEvent1[a].deaths_direct = stoi(words1[i + 9]);
			newEvent1[a].deaths_indirect = stoi(words1[i + 10]);
			string temp;
			int temp1;
			int temp2;
			if (words1[i + 11].substr(0, 1) == ".")
			{
				temp = "0" + words1[i + 11];
				if (words1[i + 11].substr(words1[i + 11].length() - 1, words1[i + 11].length() - 1) == "K")
				{
					temp1 = stod(temp.substr(0, temp.length() - 1));
					temp2 = temp1 * 10 ^ 3;
					newEvent1[a].damage_property = temp2;
				}
				else if (words1[i + 11].substr(words1[i + 11].length() - 1, words1[i + 11].length() - 1) == "M")
				{
					temp1 = stod(temp.substr(0, temp.length() - 1));
					temp2 = temp1 * 10 ^ 6;
					newEvent1[a].damage_property = temp2;
				}
			}
			else
			{
				if (words1[i + 11].substr(words1[i + 11].length() - 1, words1[i + 11].length() - 1) == "K")
				{
					temp1 = stoi(words1[i + 11].substr(0, words1[i + 11].length() - 1));
					temp2 = temp1 * 10 ^ 3;
					newEvent1[a].damage_property = temp2;
				}
				else if (words1[i + 11].substr(words1[i + 11].length() - 1, words1[i + 11].length() - 1) == "M")
				{
					temp1 = stoi(words1[i + 11].substr(0, words1[i + 11].length() - 1));
					temp2 = temp1 * 10 ^ 6;
					newEvent1[a].damage_property = stoi(words1[i + 11].substr(0, words1[i + 11].length() - 1));
				}
			}
			temp.clear();
			newEvent1[a].damage_crops = stoi(words1[i + 12]);
			for (int j = 0; j < words1[i + 13].length(); ++j) {
				newEvent1[a].tor_f_scale[j] = words1[i + 13][j];
			}
			events1.push_back(newEvent1[a]);
///////////////////////////////////////////////////////////////////////////////////////////////////////////
			for (int j = 0; j < words1[i + 1].length(); ++j) {
				newEvent1[a].state[j]='\0';
			}
			for (int j = 0; j < words1[i + 3].length(); ++j) 
			{
				newEvent1[a].month_name[j] = '\0';
			}
			for (int j = 0; j < words1[i + 4].length(); ++j) {
				newEvent1[a].event_type[j] = '\0';
			}
			for (int j = 0; j < words1[i + 6].length(); ++j) {
				newEvent1[a].cz_name[j] = '\0';
			}
			for (int j = 0; j < words1[i + 13].length(); ++j) {
				newEvent1[a].tor_f_scale[j] = '\0';
			}
			a++;
		}
		m++;
		z++;
	}
	return events1;
}
vector<struct fatality_event> input_fatality(int n, vector<string>year_array)
{
	vector<struct fatality_event> event0;// (TABLE_SIZE);
	int z = 0;
	int m = 0;
	while (m < n)
	{
		//cout << year_array[z] << endl;
		string fatalities0 = "fatalities-" + year_array[z] + ".csv";
		ifstream infile;
		int control;
		control = 6;
		infile.open(fatalities0);
		string STRING;
		vector <string> STRING11;
		int t = 0;
		string* tempstring = new string[100 * 10 ^ 10];
		infile >> STRING;
		int i = 0;
		string temp;
		int counter = 0;
		while (infile >> STRING && t < 1)
		{
			tempstring[t] = STRING;
			if (t >= 0)
			{
				while (i < tempstring[0].length())
				{
					if (tempstring[0].substr(i, 1) == ",")
					{
						counter++;
					}
					i++;
				}
				//13 or 6
				if (counter != control)
				{
					temp = temp + tempstring[0] + " ";
					i = 0;
					counter = 0;
					while (i < temp.length())
					{
						if (temp.substr(i, 1) == ",")
						{
							counter++;
						}
						i++;
					}
					//13 or 6
					if (counter == control)
					{
						STRING11.push_back(temp);
						temp.clear();
					}
					i = 0;
					counter = 0;
				}
				else
				{
					STRING11.push_back(tempstring[0]);
				}
				t = -1;
				i = 0;
				counter = 0;
			}
			t++;
		}
		vector<string>STRING1;
		for (int i = 0; i < STRING11.size(); i++)
		{
			STRING11[i].append(",");
			int j = 0;
			while (j < STRING11[i].length())
			{
				if (STRING11[i].substr(j, 1) == ",")
				{
					STRING1.push_back(temp);
					temp.clear();
					j++;
				}
				else
				{
					temp = temp + STRING11[i].substr(j, 1);
					j++;
				}
			}
			j = 0;
		}
		delete[] tempstring;
		STRING.clear();
		infile.close();
		vector<string>words;
		words = STRING1;
		vector<int> newEvent0;
		int b = 0;
		for (int i = 0; i < words.size(); i += 7)
		{
			struct fatality_event newEvent0[110000];
			newEvent0[b].fatality_id = stoi(words[i]);
			newEvent0[b].event_id = stoi(words[i + 1]);
			newEvent0[b].fatality_type = words[i + 2][0];
			for (int j = 0; j < words[i + 3].length(); ++j)
			{
				newEvent0[b].fatality_date[j] = words[i + 3][j];
			}
			if (words[i + 4] != "")
			{
				newEvent0[b].fatality_age = stoi(words[i + 4]);
			}
			else
			{
				newEvent0[b].fatality_age = 0;
			}
			newEvent0[b].fatality_sex = words[i + 5][0];
			for (int j = 0; j < words[i + 6].length(); ++j) {

				newEvent0[b].fatality_location[j] = words[i + 6][j];
			}
			event0.push_back(newEvent0[b]);
///////////////////////////////////////////////////////////////////////////////////////////////////
			for (int j = 0; j < words[i + 3].length(); ++j)
			{
				newEvent0[b].fatality_date[j] = '\0';
			}

			for (int j = 0; j < words[i + 6].length(); ++j) {

				newEvent0[b].fatality_location[j] = '\0';
			}
			b++;
		}
		m++;
		z++;
	}
	return event0;
}
int main(int argc, char* argv[])
{
	vector<string>year_array;
	vector<struct storm_event>total_details;
	vector<struct fatality_event>total_fatalities;
	for (int i = 2; i <= stoi(argv[1]) + 1; i++)
	{
		string year = argv[i];
		year_array.push_back(year);
	}
	total_details = input_details(stoi(argv[1]), year_array);
	total_fatalities = input_fatality(stoi(argv[1]), year_array);
	for (int i = 0; i < total_details.size(); i++)
	{
		cout << total_details[i].event_id << endl;
		cout << total_details[i].state << endl;
		cout << total_details[i].year << endl;
		cout << total_details[i].month_name << endl;
		cout << total_details[i].event_type << endl;
		cout << total_details[i].cz_type << endl;
		cout << total_details[i].cz_name << endl;
		cout << total_details[i].injuries_direct << endl;
		cout << total_details[i].injuries_indirect << endl;
		cout << total_details[i].deaths_direct << endl;
		cout << total_details[i].deaths_indirect << endl;
		cout << total_details[i].damage_property << endl;
		cout << total_details[i].damage_crops << endl;
		cout << total_details[i].tor_f_scale << endl;
	}
	for (int i = 0; i < total_fatalities.size(); i++)
	{
		cout << total_fatalities[i].fatality_id << endl;
		cout << total_fatalities[i].event_id << endl;
		cout << total_fatalities[i].fatality_type << endl;
		cout << total_fatalities[i].fatality_date << endl;
		cout << total_fatalities[i].fatality_age << endl;
		cout << total_fatalities[i]. fatality_sex<< endl;
		cout << total_fatalities[i].fatality_location << endl;
	}
}
