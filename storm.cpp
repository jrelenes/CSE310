#include <iostream> 
#include <string>		
#include <fstream>
#include "defn.h"
#include <math.h>
#include<stdio.h> 
#include<stdlib.h> 
using namespace std;
int BST_height(bst* node)
{
	if (node == NULL)
		return 0;
	else
	{
		int lroot = BST_height(node->left);
		int rroot = BST_height(node->right);
		if (lroot > rroot)
			return(lroot + 1);
		else return(rroot + 1);
	}
}
int BST_height_left(bst* node)
{
	if (node == NULL)
		return 0;
	else
	{
		int lroot = BST_height(node->left);
		return lroot;
	}
}
int BST_height_right(bst* node)
{
	if (node == NULL)
		return 0;
	else
	{
		int rroot = BST_height(node->right);		
		return rroot;
	}
}
struct bst* newNode(char *s,int item)
{
	struct bst* temp = (struct bst*)malloc(sizeof(struct bst));
	temp->s = s;
	temp->event_id = item;
	temp->left = temp->right = NULL;
	return temp;
}
struct bst* insert(struct bst* bst, char *s,int event_id)				
{
	if (bst == NULL) return newNode(s,event_id);
	string t = s;
	string g = bst->s;	
	if (t.compare(g) < 0)
	{
		bst->left = insert(bst->left, s, event_id);
	}
	else if (t.compare(g) > 0)
	{
		bst->right = insert(bst->right, s, event_id);
	}
	else
	{
		if (event_id < bst->event_id)
		{
			bst->left = insert(bst->left, s, event_id);
		}
		else
		{
			bst->right = insert(bst->right, s, event_id);
		}
	}
	return bst;
}
struct bst* insert_month(struct bst* bst, char* s, int event_id)
{
	if (bst == NULL) return newNode(s, event_id);
	pair<int, string> test[100];
	test[0] = make_pair(1, "January");
	test[1] = make_pair(2, "February");
	test[2] = make_pair(3, "March");
	test[3] = make_pair(4, "April");
	test[4] = make_pair(5, "May");
	test[5] = make_pair(6, "June");
	test[6] = make_pair(7, "July");
	test[7] = make_pair(8, "August");
	test[8] = make_pair(9, "September");
	test[9] = make_pair(10, "October");
	test[10] = make_pair(11, "November");
	test[11] = make_pair(12, "December");
	string t = s;
	string g = bst->s;
	int not_stored;
	int stored;
	for (int j = 0; j < 100; j++)
	{
		if (t.compare(test[j].second) == 0)
		{
			not_stored = test[j].first;
			break;
		}
	}
	for (int j = 0; j < 100; j++)
	{
		if (g.compare(test[j].second) == 0)
		{
			stored = test[j].first;
			break;

		}

	}
	if (not_stored < stored)
	{
		bst->left = insert_month(bst->left, s, event_id);
	}
	else if (not_stored > stored)
	{
		bst->right = insert_month(bst->right, s, event_id);
	}
	else
	{
		if (event_id < bst->event_id)
		{
			bst->left = insert_month(bst->left, s, event_id);
		}
		else
		{
			bst->right = insert_month(bst->right, s, event_id);
		}
	}
	return bst;
}
void heapify(pair<int,int> arr[], int n, int i)
{
	int largest = i; 
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 
	if (l < n && arr[l].first > arr[largest].first)
		largest = l;
	if (r < n && arr[r].first > arr[largest].first)
		largest = r;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}
void heapSort(pair<int,int> arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}
pair<int,int> height(int N)
{
	int tree_height = ceil(log2(N + 1)) - 1;
	int left_tree = tree_height - 1;
	return make_pair(tree_height, left_tree);
}
int height_right(int N)
{
	int tree_height = ceil(log2(N + 1)) - 1;
	int left_tree = tree_height - 1;
	int right_tree;

	if (N < 2 ^ (tree_height + 1) - 1 - (2 ^ tree_height) / 2)
	{
		right_tree = left_tree - 1;
	}
	else
	{
		right_tree = left_tree;
	}
		return right_tree;
}

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
	size = size * 2 +1;
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
		for (int i = 0; i < array_counter; i++)
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
		for (int i = 0; i < array_counter_2; i += 14)
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
	int allEvents = 0;
	for (int i = 0; i < hash_table_size; i++)
	{
		curPtr = hashtable[i];
		int temp = 0;
		while (curPtr != NULL)
		{
			temp++;
			allEvents++;
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
		numLists = 0;
		for (int j = 0; j < hash_table_size; j++)
		{
			curPtr = hashtable[j];
			int temp = 0;
			while (curPtr != NULL)
			{
				temp++;
				curPtr = curPtr->next;
			}
			if (i == temp)
			{
				numLists++;
			}
		}
		total += numLists;
		cout << i << ": " << numLists << endl;
	}
	double load_factor = (double)allEvents / hash_table_size;
	cout << "\n" << "Load factor: " << load_factor << endl << endl;
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
					cout << "event id: "<<(total_details.first[i]->events)[next->event_index]->event_id << endl;
					cout << "state: "<<(total_details.first[i]->events)[next->event_index]->state << endl;
					cout << "year: "<<(total_details.first[i]->events)[next->event_index]->year << endl;
					cout << "month name: "<<(total_details.first[i]->events)[next->event_index]->month_name << endl;
					cout << "event type: "<<(total_details.first[i]->events)[next->event_index]->event_type << endl;
					cout << "cz type: "<<(total_details.first[i]->events)[next->event_index]->cz_type << endl;
					cout << "cz name: "<<(total_details.first[i]->events)[next->event_index]->cz_name << endl;
					cout << "injuries direct: "<<(total_details.first[i]->events)[next->event_index]->injuries_direct << endl;
					cout << "injuries indirect: "<<(total_details.first[i]->events)[next->event_index]->injuries_indirect << endl;
					cout << "deaths direct: "<<(total_details.first[i]->events)[next->event_index]->deaths_direct << endl;
					cout << "deaths indirect: "<<(total_details.first[i]->events)[next->event_index]->deaths_indirect << endl;
					cout << "damage property: "<<(total_details.first[i]->events)[next->event_index]->damage_property << endl;
					cout << "damage crops: "<<(total_details.first[i]->events)[next->event_index]->damage_crops << endl;
					cout << "tor f scale: "<<(total_details.first[i]->events)[next->event_index]->tor_f_scale << endl << endl;
					pair<struct fatality_event**, int> year;
					year = fatality_population(to_string((total_details.first[i]->events)[next->event_index]->year));
					int test = 0;
					while (((total_details.first[i]->events)[next->event_index]->f)[test] != NULL && test < year.second)
					{
						if ((total_details.first[i]->events)[next->event_index]->event_id == ((total_details.first[i]->events)[next->event_index]->f)[test]->event_id)
						{
							cout << "fatality id: "<<((total_details.first[i]->events)[next->event_index]->f)[test]->fatality_id << endl;
							cout << "event id: "<<((total_details.first[i]->events)[next->event_index]->f)[test]->event_id << endl;
							cout << "fatality type: "<<((total_details.first[i]->events)[next->event_index]->f)[test]->fatality_type << endl;
							cout << "fatality date: "<<((total_details.first[i]->events)[next->event_index]->f)[test]->fatality_date << endl;
							cout << "fatality age: "<<((total_details.first[i]->events)[next->event_index]->f)[test]->fatality_age << endl;
							cout << "fatality sex: "<<((total_details.first[i]->events)[next->event_index]->f)[test]->fatality_sex << endl;
							cout << "fatality location: " << ((total_details.first[i]->events)[next->event_index]->f)[test]->fatality_location << endl << endl;
						}
						test++;
					}
					if (test == 0)
					{
						cout << "no fatalities" << endl<<endl;
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
void search_heap(struct hash_table_entry** T, int key, int n, string storm_array[], int storm_lines, struct hash_table_entry** hash1, bool type)
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
					cout << (total_details.first[i]->events)[next->event_index]->event_id << endl;
					cout << (total_details.first[i]->events)[next->event_index]->event_type << endl;

					if (type == false)
					{
						cout << (total_details.first[i]->events)[next->event_index]->damage_property << endl<<endl;
					}
					else
					{
						cout << (total_details.first[i]->events)[next->event_index]->damage_crops << endl<<endl;
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
	}
}
void search_range(struct hash_table_entry** T, int key, int n, string storm_array[], int storm_lines, struct hash_table_entry** hash1, bool state)
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

					if (state == false)
					{

						cout << "state: " << (total_details.first[i]->events)[next->event_index]->state << endl;
						cout << "event id: " << (total_details.first[i]->events)[next->event_index]->event_id << endl;
						cout << "year: " << (total_details.first[i]->events)[next->event_index]->year << endl;
						cout << "event type: " << (total_details.first[i]->events)[next->event_index]->event_type << endl;
						cout << "cz type: " << (total_details.first[i]->events)[next->event_index]->cz_type << endl;
						cout << "cz name: " << (total_details.first[i]->events)[next->event_index]->cz_name << endl << endl;
					}
					else
					{
						cout << (total_details.first[i]->events)[next->event_index]->month_name << endl;
						cout << "event id: " << (total_details.first[i]->events)[next->event_index]->event_id << endl;
						cout << "year: " << (total_details.first[i]->events)[next->event_index]->year << endl;
						cout << "event type: " << (total_details.first[i]->events)[next->event_index]->event_type << endl;
						cout << "cz type: " << (total_details.first[i]->events)[next->event_index]->cz_type << endl;
						cout << "cz name: " << (total_details.first[i]->events)[next->event_index]->cz_name << endl << endl;
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
	}
}
void find_max(string damage_type,int max_times,string year, int n,string storm_array[], int storm_lines, struct hash_table_entry** hash1, bool all)
{
	pair<struct annual_storms**, int> total_details;
	string arr0[1] = { year };
	int year_size = storm_lines_size_counter(1,arr0);
	total_details = annual_storm_population(n, storm_array, storm_lines, hash1);
	int temp = 0;
	int j = 0;
	int arr_number[10000];
	int arr_ID[10000];
	pair<int,int>arr_total[10000];
	int counter = 0;

	if (all == false)
	{
		if (damage_type == "damage_property")
		{
			int temp = 0;
			for (int i = 0; i < n; i++)
			{
				if (total_details.first[i]->year == stol(year))
				{
					int h = 0;
					while (h < year_size)
					{
						arr_number[j] = (total_details.first[i]->events)[j]->damage_property;
						arr_ID[j] = (total_details.first[i]->events)[j]->event_id;
						arr_total[j] = make_pair(arr_number[j], arr_ID[j]);
						j++;
						h++;
					}
					heapSort(arr_total, j);
					for (int s = 0; s < max_times; s++)
					{
						search_heap(hash1, arr_total[j - 1 - s].second, n, storm_array, storm_lines, hash1,false);
					}



					cout << "Nodes: " << j << endl;
					cout << "Height: " << height(j).first << endl;
					cout << "Height Left Tree: " << height(j).second << endl;
					cout << "Height Right Tree: " << height_right(j) << endl<<endl;


				}


			}
		}
		else if (damage_type == "damage_crops")
		{

			int temp = 0;
			for (int i = 0; i < n; i++)
			{

				if (total_details.first[i]->year == stol(year))
				{
					int h = 0;
					while (h < year_size)
					{
						arr_number[j] = (total_details.first[i]->events)[j]->damage_crops;
						arr_ID[j] = (total_details.first[i]->events)[j]->event_id;
						arr_total[j] = make_pair(arr_number[j], arr_ID[j]);
						j++;
						h++;
					}
					heapSort(arr_total, j);
					for (int s = 0; s < max_times; s++)
					{
						
						search_heap(hash1, arr_total[j - 1 - s].second, n, storm_array, storm_lines, hash1, true);

					}
					cout << "Nodes: " << j << endl;
					cout << "Height: " << height(j).first << endl;
					cout << "Height Left Tree: " << height(j).second << endl;
					cout << "Height Right Tree: " << height_right(j) << endl<<endl;


				}
			}
		}
	}
	else
	{

		int total = 0;

		if (damage_type == "damage_property")
		{
			int temp = 0;
			for (int i = 0; i < n; i++)
			{
				string arr0[1] = { to_string(total_details.first[i]->year) };
				int year_size = storm_lines_size_counter(1, arr0);
				
					int h = 0;
					j = 0;
					while (h < year_size)
					{
						arr_number[total] = (total_details.first[i]->events)[j]->damage_property;
						arr_ID[total] = (total_details.first[i]->events)[j]->event_id;
						arr_total[total] = make_pair(arr_number[total], arr_ID[total]);
						j++;
						h++;
						total++;
					}
			}


			heapSort(arr_total, total);
			for (int s = 0; s < max_times; s++)
			{
				search_heap(hash1, arr_total[total - 1 - s].second, n, storm_array, storm_lines, hash1,false);
			}



			cout << "Nodes: " << total << endl;
			cout << "Height: " << height(total).first << endl;
			cout << "Height Left Tree: " << height(total).second << endl;
			cout << "Height Right Tree: " << height_right(total) << endl<<endl;


			

		}
		else if (damage_type == "damage_crops")
		{

			int temp = 0;
			for (int i = 0; i < n; i++)
			{

				string arr0[1] = { to_string(total_details.first[i]->year) };
				int year_size = storm_lines_size_counter(1, arr0);

				
					int h = 0;
					j = 0;
					while (h < year_size)
					{
						
						arr_number[total] = (total_details.first[i]->events)[j]->damage_crops;
						arr_ID[total] = (total_details.first[i]->events)[j]->event_id;
						arr_total[total] = make_pair(arr_number[total], arr_ID[total]);
						

						j++;
						h++;
						total++;
					}
					
				
			}
			
			heapSort(arr_total, total);
			for (int s = 0; s < max_times; s++)
			{
				
				search_heap(hash1, arr_total[total - 1 - s].second, n, storm_array, storm_lines, hash1,true);

			}

			cout << "Nodes: " << total << endl;
			cout << "Height: " << height(total).first << endl;
			cout << "Height Left Tree: " << height(total).second << endl;
			cout << "Height Right Tree: " << height_right(total) << endl<<endl;

			
		}


	}


	

}
void find_max_fatality(int year, int max_times, int n, string storm_array[], int storm_lines, struct hash_table_entry** hash1, bool all)
{
	pair<struct annual_storms**, int> total_details;
	total_details = annual_storm_population(n, storm_array, storm_lines, hash1);
	string year1 = to_string(year);
	string arr0[1] = { year1 };
	int year_size = storm_lines_size_counter(1, arr0);
	pair<struct fatality_event**, int> year_fatalities;
	int annual_year_size = sizeof(total_details.first) / sizeof(total_details.first[0]);
	
	int fatality_number[10000];
	int arr_ID[10000];
	int temp = 0;
	pair<int, int> arr[10000];
	pair<int, int>arr_final[10000];

	if (all == true)
	{
		int j = 0;
		for (int i = 0; i < n; i++)
		{
			
			int fatality_counter = 0;
			int max_fatality = 0;
			int deep_counter = 0;
				int h = 0;
				string arr1[1] = { storm_array[i] };
				while (h < storm_lines_size_counter(1, arr1))
				{
					year_fatalities = fatality_population(to_string((total_details.first[i]->events)[h]->year));
					int test = 0;
					while (((total_details.first[i]->events)[h]->f)[test] != NULL && test < year_fatalities.second)
					{
						if ((total_details.first[i]->events)[h]->event_id == ((total_details.first[i]->events)[h]->f)[test]->event_id)
						{
							fatality_counter++;
						}
						test++;
					}
					fatality_number[h] = fatality_counter;
					arr_ID[h] = (total_details.first[i]->events)[h]->event_id;
					arr[h] = make_pair(fatality_number[h], arr_ID[h]);
					fatality_counter = 0;
					
					arr_final[j] = arr[h];
					j++;
					h++;
				}				
		}

		

		int d = j;

		while (max_times > 0)
		{
			search(hash1, arr_final[d - 1].second, n, storm_array, storm_lines, hash1);
			max_times--;
			d--;
		}


		cout << "Nodes: " << j << endl;
		cout << "Height: " << height(j).first << endl;
		cout << "Height Left Tree: " << height(j).second << endl;
		cout << "Height Right Tree: " << height_right(j) << endl<<endl;

	}
	else
	{

		for (int i = 0; i < n; i++)
		{
			int j = 0;
			int fatality_counter = 0;
			int max_fatality = 0;
			int deep_counter = 0;
			if (total_details.first[i]->year == year)
			{
				int h = 0;
				while (h < year_size)
				{
					year_fatalities = fatality_population(to_string((total_details.first[i]->events)[h]->year));
					int test = 0;
					while (((total_details.first[i]->events)[h]->f)[test] != NULL && test < year_fatalities.second)
					{
						if ((total_details.first[i]->events)[h]->event_id == ((total_details.first[i]->events)[h]->f)[test]->event_id)
						{
							fatality_counter++;
						}
						test++;
					}
					fatality_number[h] = fatality_counter;
					arr_ID[h] = (total_details.first[i]->events)[h]->event_id;
					arr[h] = make_pair(fatality_number[h], arr_ID[h]);
					fatality_counter = 0;
					
					h++;
				}
				

				int d = year_size;
				while (max_times > 0)
				{
					search(hash1, arr[d - 1].second, n, storm_array, storm_lines, hash1);
					max_times--;
					d--;
				}

				cout << "Nodes: " << year_size << endl;
				cout << "Height: " << height(year_size).first << endl;
				cout << "Height Left Tree: " << height(year_size).second << endl;
				cout << "Height Right Tree: " << height_right(year_size) << endl<<endl;

			}
		}
	}


}

void inorder(struct bst* root, char low, char high, struct hash_table_entry** hash1, string storm_array[], int storm_lines, int n, bool state)
{



	if (root != NULL)
	{
		inorder(root->left, low, high,hash1, storm_array, storm_lines, n, state);

		if (root->s[0] >= low && root->s[0] <= high)
		{
			

			search_range(hash1, root->event_id, n, storm_array, storm_lines, hash1, state);


		}

		inorder(root->right, low, high, hash1, storm_array, storm_lines, n, state);
	}
}



void inorder_month(struct bst* root, string low, string high, struct hash_table_entry** hash1, string storm_array[], int storm_lines, int n, bool state)
{
	if (root != NULL)
	{
		pair<int, string> test[100];
		test[0] = make_pair(1, "January");
		test[1] = make_pair(2, "February");
		test[2] = make_pair(3, "March");
		test[3] = make_pair(4, "April");
		test[4] = make_pair(5, "May");
		test[5] = make_pair(6, "June");
		test[6] = make_pair(7, "July");
		test[7] = make_pair(8, "August");
		test[8] = make_pair(9, "September");
		test[9] = make_pair(10, "October");
		test[10] = make_pair(11, "November");
		test[11] = make_pair(12, "December");
		inorder_month(root->left, low, high, hash1, storm_array, storm_lines, n, state);
		string g = root->s;
		int not_stored_low;
		int not_stored_high;

		int stored;
		for (int j = 0; j < 100; j++)
		{
			if (low.compare(test[j].second) == 0)
			{
				not_stored_low = test[j].first;
			}

			if (high.compare(test[j].second) == 0)
			{
				not_stored_high = test[j].first;
			}


		}
		for (int j = 0; j < 100; j++)
		{
			if (g.compare(test[j].second) == 0)
			{
				stored = test[j].first;
				break;
			}
		}

		if (stored >= not_stored_low && stored <= not_stored_high)
		{
			
			search_range(hash1, root->event_id, n, storm_array, storm_lines, hash1, state);


		}

		inorder_month(root->right, low, high, hash1, storm_array, storm_lines, n, state);
	}
}
void range(int year, int n, string storm_array[], int storm_lines, struct hash_table_entry** hash1, string low, string high, bool all,bool month)
{
	pair<struct annual_storms**, int> total_details;
	total_details = annual_storm_population(n, storm_array, storm_lines, hash1);
	
	int annual_year_size = sizeof(total_details.first) / sizeof(total_details.first[0]);
	int arr[10000];
	bst* root = NULL;
	bst* root2 = NULL;
	root = insert(root, (total_details.first[0]->events)[0]->state, (total_details.first[0]->events)[0]->event_id);
	if (month == false)
	{
		if (all == false)
		{
			string year1 = to_string(year);
			string arr0[1] = { year1 };
			int year_size = storm_lines_size_counter(1, arr0);

			

			for (int i = 0; i < n; i++)
			{

				int j = 0;
				pair<int, int> arr[10000];
				if (total_details.first[i]->year == year)
				{

					int h = 0;
					while (h < year_size)
					{
						insert(root, (total_details.first[i]->events)[h]->state, (total_details.first[i]->events)[h]->event_id);



						h++;
					}

				}
			}
			inorder(root, low[0], high[0], hash1, storm_array, storm_lines, n, false);


			double Nnodes = pow(2, BST_height(root) + 1) -1;

			cout << "Nodes: " << Nnodes << endl;
			cout << "Binary Tree Height: " << BST_height(root) << endl;
			cout << "Binary Tree Height Left: " << BST_height_left(root) << endl;
			cout << "Binary Tree Height Right: " << BST_height_right(root) << endl<<endl;
		}
		else
		{
			for (int i = 0; i < n; i++)
			{

				int j = 0;
				pair<int, int> arr[10000];

				string arr0[1] = { to_string(total_details.first[i]->year) };
				int year_size = storm_lines_size_counter(1, arr0);

				int h = 0;
				while (h < year_size)
				{
					insert(root, (total_details.first[i]->events)[h]->state, (total_details.first[i]->events)[h]->event_id);
					h++;
				}
			}

			inorder(root, low[0], high[0], hash1, storm_array, storm_lines, n, false);
			double Nnodes = pow(2, BST_height(root) + 1) - 1;
			cout << "Nodes: " << Nnodes << endl;
			cout << "Binary Tree Height: " << BST_height(root) << endl;
			cout << "Binary Tree Height Left: " << BST_height_left(root) << endl;
			cout << "Binary Tree Height Right: " << BST_height_right(root) << endl<<endl;
		}
	}
	else
	{

		string year1 = to_string(year);
		string arr0[1] = { year1 };
		int year_size = storm_lines_size_counter(1, arr0);
		root2 = insert_month(root2, (total_details.first[0]->events)[0]->month_name, (total_details.first[0]->events)[0]->event_id);
		if (all == false)
		{

			for (int i = 0; i < n; i++)
			{

				int j = 0;
				char arr[10000];
				if (total_details.first[i]->year == year)
				{

					int h = 0;
					while (h < year_size)
					{
						insert_month(root2, (total_details.first[i]->events)[h]->month_name, (total_details.first[i]->events)[h]->event_id);
						h++;
					}
				}
			}
			inorder_month(root2, low, high, hash1, storm_array, storm_lines, n, true);
			double Nnodes = pow(2, BST_height(root2) + 1) - 1;
			cout << "Nodes: " << Nnodes << endl;
			cout << "Binary Tree Height: " << BST_height(root2) << endl;
			cout << "Binary Tree Height Left: " << BST_height_left(root2) << endl;
			cout << "Binary Tree Height Right: " << BST_height_right(root2) << endl<<endl;
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				string arr0[1] = { to_string(total_details.first[i]->year) };
				int year_size = storm_lines_size_counter(1, arr0);

				int j = 0;
				char arr[10000];
				

					int h = 0;
					while (h < year_size)
					{
						insert_month(root2, (total_details.first[i]->events)[h]->month_name, (total_details.first[i]->events)[h]->event_id);
						h++;
					}
			}
			inorder_month(root2, low, high, hash1, storm_array, storm_lines, n, true);
			double Nnodes = pow(2, BST_height(root2) + 1) - 1;
			cout << "Nodes: " << Nnodes << endl;
			cout << "Binary Tree Height: " << BST_height(root2) << endl;
			cout << "Binary Tree Height Left: " << BST_height_left(root2) << endl;
			cout << "Binary Tree Height Right: " << BST_height_right(root2) << endl<<endl;
		}
	}
}
int main(int argc, char* argv[])
{
	string* year_array = new string[100];
	pair<struct annual_storms**, int> total_details;
	int rev= stoi(argv[1]);
	int k = 0;
	
	for (int i = 2; i <= stoi(argv[1]) +1; i++)
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
	string repeat;
	getline(cin,repeat);
	int repeat_number = stol(repeat);
	while (repeat_number > 0)
	{
		repeat_number--;
		string query_type;
		getline(cin, query_type);
		int i = 11;
		int count[3];
		int y0 = 0;
		int control = query_type.length() - 11;
		while (control > 0)
		{
			if (query_type.substr(i, 1) == " ")
			{
				count[y0] = i;
				y0++;
			}

			i++;
			control--;
		}
		if (query_type.substr(0, 10) == "find event" && query_type.substr(0, 19) != "find event fatality")
		{
			string number = query_type.substr(11, count[0] - 11);
			search(hash1, stol(number), stoi(argv[1]), year_array, storm_lines, hash1);
		}
		else if (query_type.substr(0, 8) == "find max" && query_type.substr(0, 17) != "find max fatality")
		{
			int i = 9;
			int count[3];
			int y0 = 0;
			int control = query_type.length() - 9;
			while (control > 0)
			{
				if (query_type.substr(i, 1) == " ")
				{
					count[y0] = i;
					y0++;
				}
				i++;
				control--;
			}
			string number = query_type.substr(9, count[0] - 9);
			string years = query_type.substr(count[0] + 1, count[1] - count[0] - 1);
			string query = query_type.substr(count[1] + 1, count[2] - count[1] - 1);
			int max_times = stol(number);
			string year = years;
			string damage_type = query;
			if (years != "all")
			{
				find_max(damage_type, max_times, year, stoi(argv[1]), year_array, storm_lines, hash1, false);
			}
			else
			{
				find_max(damage_type, max_times, year, stoi(argv[1]), year_array, storm_lines, hash1, true);
			}
		}
		else if (query_type.substr(0, 17) == "find max fatality")
		{

			int i = 18;
			int count[3];
			int y0 = 0;
			int control = query_type.length() - 18;
			
			while (control > 0)
			{
				if (query_type.substr(i, 1) == " ")
				{
					count[y0] = i;
					y0++;
				}

				i++;
				control--;
			}
			string number = query_type.substr(18, count[0] - 18);
			string years = query_type.substr(count[0] + 1, count[1] - count[0] - 1);
			int max_times = stol(number);
			if (years != "all")
			{
				int year = stol(years);
				find_max_fatality(year, max_times, stoi(argv[1]), year_array, storm_lines, hash1, false);
			}
			else
			{
				find_max_fatality(stol(year_array[0]), max_times, stoi(argv[1]), year_array, storm_lines, hash1, true);
			}
		}
		else if (query_type.substr(0, 5) == "range")
		{
			int number = stoi(argv[1]);
			struct bst* root = NULL;
			int i = 6;
			int count[3];
			int y0 = 0;
			int control = query_type.length() - 6;
			while (control > 0)
			{
				if (query_type.substr(i, 1) == " ")
				{
					count[y0] = i;
					y0++;
				}
				i++;
				control--;
			}
			string year_type_range = query_type.substr(6, count[0] - 6);
			string month_low = query_type.substr(count[1] + 1, count[2] - count[1] - 1);
			string month_high = query_type.substr(count[2] + 1, control - count[2]);
			string state_name = query_type.substr(count[0] + 1, count[1] - count[0] - 1);
			string low = month_low;
			string high = month_high;
			if (state_name != "month_name")
			{
				if (year_type_range != "all")
				{
					int year = stol(year_type_range);
					range(year, number, year_array, storm_lines, hash1, low, high, false, false);
				}
				else
				{
					range(0000, number, year_array, storm_lines, hash1, low, high, true, false);
				}
			}
			else
			{
				if (year_type_range != "all")
				{
					int year = stol(year_type_range);
					range(year, number, year_array, storm_lines, hash1, low, high, false, true);
				}
				else
				{
					range(0000, number, year_array, storm_lines, hash1, low, high, true, true);
				}
			}
		}
		else
		{
			return 0;
		}
	}
				Characteristics(hash1, TABLE_SIZE);
}