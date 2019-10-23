#include <iostream> 
#include <string>		
#include <fstream>
#include "defn.h"
#include <math.h>
using namespace std;
int storm_lines_size_counter(int n, string year_array[])
{
	int storm_lines_size = 0;
	int z = 0;
	int m = 0;
	while (m < n)
	{
		string details0 = "details-" + year_array[z] + ".csv";
		ifstream infile;
		int control;
		control = 13;
		infile.open(details0);
		string STRING;
		string* STRING11 = new string[10000];
		int array_counter = 0;
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
					if (counter == control)
					{
						STRING11[array_counter] = temp;
						array_counter++;
						temp.clear();
					}
					i = 0;
					counter = 0;
				}
				else
				{
					STRING11[array_counter] = tempstring[0];
					array_counter++;
				}
				t = -1;
				i = 0;
				counter = 0;
			}
			t++;
		}
		string* STRING1 = new string[(array_counter) * 14];
		int array_counter_2 = 0;
		for (int i = 0; i < array_counter - 1; i++)
		{
			STRING11[i].append(",");
			int j = 0;
			while (j < STRING11[i].length())
			{
				if (STRING11[i].substr(j, 1) == ",")
				{
					STRING1[array_counter_2] = temp;
					array_counter_2++;
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
		int a = 0;
		for (int i = 0; i < array_counter_2 - 1; i += 14)
		{
			a++;
		}
		m++;
		z++;
		storm_lines_size = storm_lines_size + a;

		a = 0;
	}
	return storm_lines_size;
}
int hashFunction(int event_id, int size)
{

	int index = event_id % size;
	return index;
}
bool TestForPrime(int sizei)
{
	int limit, factor = 2;
	limit = (long)(sqrtf((float)sizei) + 0.5f);
	while ((factor <= limit) && (sizei % factor))
		factor++;
	return(factor > limit);
}									
int hash0(int size)
{
	size = size * 2;
	int temp = size;
	while (!TestForPrime(temp))
	{

		temp++;
	}
	return temp;
}
void insertKey(struct hash_table_entry** hashtable, int event_id, int year, int event_index, int storm_lines)
{
	struct hash_table_entry* newNode = new struct hash_table_entry;
	newNode->event_id = event_id;
	newNode->year = year;
	newNode->event_index = event_index;
	int hashIndex = hashFunction(event_id, storm_lines);
	struct hash_table_entry* head = hashtable[hashIndex];
	if (head == NULL)
	{
		newNode->next = NULL;
	}			
	else
	{
		newNode->next = head;
	}			
	hashtable[hashIndex] = newNode;
}
pair<struct fatality_event**, int> fatality_population(string year_array)
{
	int b = 0;
	fatality_event** newEvent0 = new struct fatality_event* [1000];
	int z = 0;
	int m = 0;
	while (m < 1)
	{
		string fatalities0 = "fatalities-" + year_array + ".csv";
		ifstream infile;
		int control;
		control = 6;
		infile.open(fatalities0);
		string STRING;
		string* STRING11 = new string[10000];
		int t = 0;
		string* tempstring = new string[100 * 10 ^ 10];
		infile >> STRING;
		int i = 0;
		string temp;
		int counter = 0;
		int array_count = 0;
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
					if (counter == control)
					{
						STRING11[array_count] = temp;
						array_count++;
						temp.clear();
					}
					i = 0;
					counter = 0;
				}
				else
				{
					STRING11[array_count] = tempstring[0];
					array_count++;
				}
				t = -1;
				i = 0;
				counter = 0;
			}
			t++;
		}
		string* STRING1 = new string[(array_count) * 7];
		int array_counter_2 = 0;
		for (int i = 0; i < array_count; i++)
		{
			STRING11[i].append(",");
			int j = 0;
			while (j < STRING11[i].length())
			{
				if (STRING11[i].substr(j, 1) == ",")
				{
					STRING1[array_counter_2] = temp;
					array_counter_2++;
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
		delete[] STRING11;
		delete[] tempstring;
		STRING.clear();
		infile.close();
		string* words = new string[array_counter_2];
		words = STRING1;
		for (int i = 0; i < array_counter_2; i += 7)
		{
			fatality_event* tmp = new struct fatality_event();
			tmp->fatality_id = stoi(words[i]);
			tmp->event_id = stoi(words[i + 1]);
			tmp->fatality_type = words[i + 2][0];
			for (int j = 0; j < words[i + 3].length(); ++j)
			{
				tmp->fatality_date[j] = words[i + 3][j];
			}
			if (words[i + 4] != "")
			{
				tmp->fatality_age = stoi(words[i + 4]);
			}
			else
			{
				tmp->fatality_age = 0;
			}
			tmp->fatality_sex = words[i + 5][0];
			for (int j = 0; j < words[i + 6].length(); ++j) {

				tmp->fatality_location[j] = words[i + 6][j];
			}
			newEvent0[b] = tmp;
			b++;
		}
		m++;
		z++;
		delete[] STRING1;
	}
	return make_pair(newEvent0, b);
}
pair<struct annual_storms**, int> annual_storm_population(int n, string year_array[], int storm_lines, struct hash_table_entry** hash1)
{
	pair<struct fatality_event**, int> q;
	int TABLE_SIZE = 0;
	annual_storms** allArrays = new struct annual_storms* [n];
	int z = 0;
	int m = 0;
	while (m < n)
	{
		string details0 = "details-" + year_array[z] + ".csv";
		ifstream infile;
		int control;
		control = 13;
		infile.open(details0);
		string STRING;
		string* STRING11 = new string[10000];
		int array_counter = 0;
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
					if (counter == control)
					{
						STRING11[array_counter] = temp;
						array_counter++;
						temp.clear();
					}
					i = 0;
					counter = 0;
				}
				else
				{
					STRING11[array_counter] = tempstring[0];
					array_counter++;
				}
				t = -1;
				i = 0;
				counter = 0;
			}
			t++;
		}
		string* STRING1 = new string[(array_counter) * 14];
		int array_counter_2 = 0;
		for (int i = 0; i < array_counter - 1; i++)
		{
			STRING11[i].append(",");
			int j = 0;
			while (j < STRING11[i].length())
			{
				if (STRING11[i].substr(j, 1) == ",")
				{
					STRING1[array_counter_2] = temp;
					array_counter_2++;
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
		string* words1 = new string[array_counter_2];
		words1 = STRING1;
		int a = 0;
		storm_event** newEvent1 = new struct storm_event* [array_counter_2];
		for (int i = 0; i < array_counter_2 - 1; i += 14)
		{
			storm_event* tmp = new struct storm_event();
			tmp->event_id = stoi(words1[i]);
			for (int j = 0; j < words1[i + 1].length(); ++j) {
				tmp->state[j] = words1[i + 1][j];
			}
			tmp->year = stoi(words1[i + 2]);
			insertKey(hash1, tmp->event_id, tmp->year, a, storm_lines);
			for (int j = 0; j < words1[i + 3].length(); ++j) {
				tmp->month_name[j] = words1[i + 3][j];
			}
			for (int j = 0; j < words1[i + 4].length(); ++j) {
				tmp->event_type[j] = words1[i + 4][j];
			}
			tmp->cz_type = words1[i + 5][0];
			for (int j = 0; j < words1[i + 6].length(); ++j) {
				tmp->cz_name[j] = words1[i + 6][j];
			}
			tmp->injuries_direct = stoi(words1[i + 7]);
			tmp->injuries_indirect = stoi(words1[i + 8]);
			tmp->deaths_direct = stoi(words1[i + 9]);
			tmp->deaths_indirect = stoi(words1[i + 10]);
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
					tmp->damage_property = temp2;
				}
				else if (words1[i + 11].substr(words1[i + 11].length() - 1, words1[i + 11].length() - 1) == "M")
				{
					temp1 = stod(temp.substr(0, temp.length() - 1));
					temp2 = temp1 * 10 ^ 6;
					tmp->damage_property = temp2;
				}
			}
			else
			{
				if (words1[i + 11].substr(words1[i + 11].length() - 1, words1[i + 11].length() - 1) == "K")
				{
					temp1 = stoi(words1[i + 11].substr(0, words1[i + 11].length() - 1));
					temp2 = temp1 * 10 ^ 3;
					tmp->damage_property = temp2;
				}
				else if (words1[i + 11].substr(words1[i + 11].length() - 1, words1[i + 11].length() - 1) == "M")
				{
					temp1 = stoi(words1[i + 11].substr(0, words1[i + 11].length() - 1));
					temp2 = temp1 * 10 ^ 6;
					tmp->damage_property = stoi(words1[i + 11].substr(0, words1[i + 11].length() - 1));
				}
			}
			temp.clear();
			tmp->damage_crops = stoi(words1[i + 12]);
			for (int j = 0; j < words1[i + 13].length(); ++j) {
				tmp->tor_f_scale[j] = words1[i + 13][j];
			}
			struct fatality_event** newEvent0;
			pair<struct fatality_event**, int> p;
			p = fatality_population(year_array[z]);
			newEvent0 = p.first;
			int size = p.second;
			struct fatality_event** linked = new struct fatality_event* [size];
			int counter = 0;
			for (int h = 0; h < size; h++)
			{
				if (tmp->event_id == newEvent0[h]->event_id)
				{
					struct fatality_event miniarray;
					linked = newEvent0;
					counter++;

				}
			}
			if (counter == 0)
			{
				linked[0] = NULL;
			}
			tmp->f = linked;
			newEvent1[a] = tmp;
			a++;
		}
		struct annual_storms* storms = new struct annual_storms();
		storms->events = newEvent1;
		storms->year = stoi(year_array[z]);
		allArrays[z] = storms;
		m++;
		z++;
		TABLE_SIZE = TABLE_SIZE + a;
		a = 0;
	}
	return make_pair(allArrays, TABLE_SIZE);
}
void Characteristics(struct hash_table_entry** hashtable, int hash_table_size)
{
	struct hash_table_entry* curPtr;
	int characteristics = 0;
	for (int i = 0; i < hash_table_size; i++) 
	{
		curPtr = hashtable[i];
		int temp = 0;
		while (curPtr != NULL)
		{
			temp++;
			curPtr = curPtr->next;
		}
		if (characteristics < temp)
			characteristics = temp;
	}

	cout << "The maximum chain length() is: " << characteristics << endl;
	cout << "Number of chain lengths below " << endl << endl;
	int total = 0;
	int numLists = 0;
	for (int i = 0; i <= characteristics; i++)
	{
		for (int j = 0; j < hash_table_size; j++)
		{
			curPtr = hashtable[j];
			int temp = 0;
			while (curPtr != NULL)
			{
				temp++;
				curPtr = curPtr->next;
				//break;
			}
			if (i == temp)
			{
				numLists++;
			}
		}

		total += numLists;
		cout << i << ": " << numLists << endl;
	}
	int load_factor = numLists/hash_table_size;
	cout << "\n"<<"Load factor: " << load_factor << endl;

}
void search(struct hash_table_entry** T, int key,int n, string storm_array[], int storm_lines, struct hash_table_entry** hash1)
{
	pair<struct annual_storms**, int> total_details;
	total_details = annual_storm_population(n, storm_array, storm_lines, hash1);
	bool keyFound = false;
	int hashIndex = hashFunction(key, storm_lines);
	struct hash_table_entry* next;
	next = T[hashIndex];
	while (next != NULL && !keyFound) {
		int i = 0;
		if (next->event_id == key) {
			keyFound = true;
			int year = next->year;
			for (int i = 0; i < total_details.second; i++)
			{
				if (total_details.first[i]->year == year)
				{
					cout << "Events: " << endl << endl;;
					cout << (total_details.first[i]->events)[next->event_index]->event_id << endl;
					cout << (total_details.first[i]->events)[next->event_index]->state << endl;
					cout << (total_details.first[i]->events)[next->event_index]->year << endl;
					cout << (total_details.first[i]->events)[next->event_index]->month_name << endl;
					cout << (total_details.first[i]->events)[next->event_index]->event_type << endl;
					cout << (total_details.first[i]->events)[next->event_index]->cz_type << endl;
					cout << (total_details.first[i]->events)[next->event_index]->cz_name << endl;
					cout << (total_details.first[i]->events)[next->event_index]->injuries_direct << endl;
					cout << (total_details.first[i]->events)[next->event_index]->injuries_indirect << endl;
					cout << (total_details.first[i]->events)[next->event_index]->deaths_direct << endl;
					cout << (total_details.first[i]->events)[next->event_index]->deaths_indirect << endl;
					cout << (total_details.first[i]->events)[next->event_index]->damage_property << endl;
					cout << (total_details.first[i]->events)[next->event_index]->damage_crops << endl;
					cout << (total_details.first[i]->events)[next->event_index]->tor_f_scale << endl << endl;
					pair<struct fatality_event**, int> year;
					year = fatality_population(to_string((total_details.first[i]->events)[next->event_index]->year));
					int test = 0;
					while (((total_details.first[i]->events)[next->event_index]->f)[test] != NULL && test < year.second)
					{
						if ((total_details.first[i]->events)[next->event_index]->event_id == ((total_details.first[i]->events)[next->event_index]->f)[test]->event_id)
						{
							cout << "Fatalities: " << endl << endl;;
							cout << ((total_details.first[i]->events)[next->event_index]->f)[test]->fatality_id << endl;
							cout << ((total_details.first[i]->events)[next->event_index]->f)[test]->event_id << endl;
							cout << ((total_details.first[i]->events)[next->event_index]->f)[test]->fatality_type << endl;
							cout << ((total_details.first[i]->events)[next->event_index]->f)[test]->fatality_date << endl;
							cout << ((total_details.first[i]->events)[next->event_index]->f)[test]->fatality_age << endl;
							cout << ((total_details.first[i]->events)[next->event_index]->f)[test]->fatality_sex << endl;
							cout << ((total_details.first[i]->events)[next->event_index]->f)[test]->fatality_location << endl;
						}
						test++;
					}
					if (test == 0)
					{
						cout << "no fatalities" << endl;
					}
					break;
				}
			}
		}
		else
		{
			next = next->next;
		}
	}
	if (!keyFound) {
		cout << "Storm Event " << key << " not found." << endl;
	}
}
int main(int argc, char* argv[])
{
	string* year_array = new string[100];
	pair<struct annual_storms**, int> total_details;
	int rev= stoi(argv[1]);
	int k = 0;
	for (int i = 2; i <= stoi(argv[1]) + 1; i++)
	{
		string year = argv[i];
		year_array[k] = year;
		k++;
	}
	int storm_lines = storm_lines_size_counter(stoi(argv[1]), year_array);
	int TABLE_SIZE = hash0(storm_lines);
	struct hash_table_entry** hash1 = new struct hash_table_entry* [TABLE_SIZE];
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		hash1[i] = NULL;
	}
	string n_queries;
	getline(cin,n_queries);
	int temp = stoi(n_queries);
	while (temp > 0)
	{
		string query_event;
		getline(cin,query_event);
		string number;
		number = query_event.substr(11);
		search(hash1,stol(number) ,stoi(argv[1]), year_array, storm_lines, hash1);
		temp--;
	}
	Characteristics(hash1, TABLE_SIZE);
}






