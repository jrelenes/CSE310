//#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
using namespace std;

#include <iostream> 
#include <time.h>
#include <string>		
#include <vector>
#define TABLE_SIZE 100
#define	STATE_LEN	15
#define	MONTH_LEN	10
#define	EVENT_LEN	26
#define	COUNTY_LEN	30
#define	TOR_LEN		4
#define DATE_LEN    20
#define FAC_LOC     25


struct storm_event {
	int event_id; // Event id
	char state[STATE_LEN]; // State name
	int year; // Four digit year of event
	char month_name[MONTH_LEN]; // Month of event
	char event_type[EVENT_LEN]; // Event type
	char cz_type; // Where event happened, C, Z, or M
	char cz_name[COUNTY_LEN]; // Name of county/zone
	int injuries_direct; // Number of direct injuries
	int injuries_indirect; // Number of indirect injuries
	int deaths_direct; // Number of direct deaths
	int deaths_indirect; // Number of indirect deaths
	int damage_property; // Amount of property damage; convert to integer
	int damage_crops; // Amount of crop damage; convert to integer
	char tor_f_scale[TOR_LEN]; // Strength of tornado on Fujita scale
	struct fatality_event* f; // Linked list of fatalities associated with this storm event
};


///////////BINARYSEARCH//////////////////////////////////////////////////////////////////////////@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// A iterative binary search function. It returns 
// location of x in given array arr[l..r] if present, 
// otherwise -1 
int binarySearch(int arr[], int l, int r, int x)
{
	while (l <= r) {
		int m = l + (r - l) / 2;

		// Check if x is present at mid 
		if (arr[m] == x)
			return m;

		// If x greater, ignore left half 
		if (arr[m] < x)
			l = m + 1;

		// If x is smaller, ignore right half 
		else
			r = m - 1;
	}

	// if we reach here, then element was 
	// not present 
	return -1;
}


//HEAPSORT//////////////////////////////////////////////////////////////////////////////

// C++ program for implementation of Heap Sort 
// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far 
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root 
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest);
	}
}

// main function to do heap sort 
void heapSort(int arr[], int n)
{
	// Build heap (rearrange array) 
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap 
	for (int i = n - 1; i >= 0; i--)
	{
		// Move current root to end 
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap 
		heapify(arr, i, 0);
	}
}

// A utility function to print array of size n */


void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@2

/////////////////////////2 base streuctures////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct entry_t {
	char* key;
	char* value;
	struct entry_t* next;
} entry_t;


typedef struct {
	entry_t** entries;
} ht_t;
///////////////////////////2 base structures////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////hash function
unsigned int hash1(const char* key) {
	unsigned long int value = 0;
	unsigned int i = 0;
	unsigned int key_len = strlen(key);

	// do several rounds of multiplication
	for (; i < key_len; ++i) {
		value = value * 37 + key[i];
	}

	// make sure value is 0 <= value < TABLE_SIZE
	value = value % TABLE_SIZE;

	return value;
}/////////////////////////////////////////////////////////hash function













////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//key=event_id


unsigned int storm_event(const int* event_id) 
{
	unsigned long int event_id=0, state = 0, year = 0, month_name = 0, event_type = 0, cz_type = 0, cz_name = 0, injuries_indirect = 0;
	unsigned long int injuries_direct = 0, deaths_direct = 0, deaths_indirect = 0, damage_property = 0, damage_crops = 0, tor_f_scale = 0;

	//modified struct 1
	unsigned int i = 0;
	unsigned int event_id_len = strlen(event_id);

	// do several rounds of multiplication
	for (; i < event_id_len; ++i) {
		event_id = event_id * 37 + event_id[i];
		state = state * 37 + event_id[i];
		year = year * 37 + event_id[i];
		month_name = month_name * 37 + event_id[i];
		event_type = event_type * 37 + event_id[i];
		cz_type = cz_type * 37 + event_id[i];
		cz_name = cz_name * 37 + event_id[i];
		injuries_indirect = injuries_indirect * 37 + event_id[i];
		injuries_direct = injuries_direct * 37 + event_id[i];
		deaths_direct = deaths_direct * 37 + event_id[i];
		deaths_indirect = deaths_indirect * 37 + event_id[i];
		damage_property = damage_property * 37 + event_id[i];
		damage_crops = damage_crops * 37 + event_id[i];
		tor_f_scale = tor_f_scale * 37 + event_id[i];
	}

	// make sure value is 0 <= value < TABLE_SIZE
	state = state % TABLE_SIZE;
	year = rear % TABLE_SIZE;
	month_name = month_name % TABLE_SIZE;
	event_type = event_type % TABLE_SIZE;
	cz_type = cz_type % TABLE_SIZE;
	cz_name = cz_name % TABLE_SIZE;

	injuries_indirect = injuries_indirect % TABLE_SIZE;
	injuries_direct = injuries_direct % TABLE_SIZE;
	deaths_direct = deaths_direct % TABLE_SIZE;
	deaths_indirect = deaths_indirect % TABLE_SIZE;
	damage_property = damage_property % TABLE_SIZE;
	damage_crops = damage_crops % TABLE_SIZE;
	tor_f_scale = tor_f_scale % TABLE_SIZE;



	return state, year, month_name, event_type, cz_type, cz_name, injuries_indirect, injuries_direct;
	return deaths_direct, deaths_indirect, damage_property, damage_crops, tor_f_scale;


}

/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//MODIFIED STRUCT 2
unsigned int fatality_event(const char* fatality_id)
{
	unsigned long int event_id = 0, fatality_type=0, fatality_date=0, fatality_age=0, fatality_sex=0, fatality_location=0;

	unsigned int i = 0;
	unsigned int fatality_id_len = strlen(fatality_id);

	// do several rounds of multiplication
	for (; i < fatality_id_len; ++i) {
		event_id = event_id * 37 + fatality_id[i];
		fatality_type = fatality_type * 37 + fatality_id[i];
		fatality_date = fatality_date * 37 + fatality_id[i];
		fatality_age = fatality_age * 37 + fatality_id[i];
		fatality_sex = fatality_sex * 37 + fatality_id[i];
		fatality_location = fatality_location * 37 + fatality_id[i];
	}

	// make sure value is 0 <= value < TABLE_SIZE
	fatality_date = fatality_date % DATE_LEN;
	fatality_location = fatality_location % FAC_LOC;

	return event_id, fatality_type, fatality_date, fatality_age, fatality_sex, fatality_location;


}

///////////////////////////////////////////////////////////////////////////////////////////////////////////


//struct 3 modified
unsigned int hash_table_entry(const char* event_id)
{
	unsigned long int year = 0, event_index=0;


	unsigned int i = 0;
	unsigned int event_id_len = strlen(event_id);

	// do several rounds of multiplication
	for (; i < event_id_len; ++i) {
		year = year * 37 + event_id[i];
		event_index = event_index * 37 + event_id[i];
	}

	// make sure value is 0 <= value < TABLE_SIZE
	

	return year, event_index;



}

//////////////////////////////////////////////////////////////////////////////////////////////////////////



unsigned int bst(const char* s)

{
	unsigned long int event_id = 0;
	//////////////////verify
	struct bst* left;
	struct bst* right;

	unsigned int i = 0;
	unsigned int s_len = strlen(s);

	// do several rounds of multiplication
	for (; i < s_len; ++i) {
		event_id = event_id * 37 + s[i];

	}

	// make sure value is 0 <= value < TABLE_SIZE
	

	return event_id;


}

//////////////////////////////////////////////end of modify struct///////////////////////////////////////////////////////////////////////
*/


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
entry_t* ht_pair(const char* key, const char* value) {
	// allocate the entry
	entry_t* entry = (entry_t*)malloc(sizeof(entry_t) * 1);
	entry->key = (char*)malloc(strlen(key) + 1);
	entry->value = (char*)malloc(strlen(value) + 1);

	// copy the key and value in place
	strcpy(entry->key, key);
	strcpy(entry->value, value);

	// next starts out null but may be set later on
	entry->next = NULL;

	return entry;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
entry_t* ht_pair_event(const int* event_id, const char* state, const int* year, const char* month_name, const char* event_type, const char* cz_type, const char* cz_name,const int* injuries_direct, const int* injuries_indirect, const int* deaths_direct, const int* deaths_indirect, const int* damage_property, const int* damage_crops, const char* tor_f_scale ) {
	// allocate the entry
	entry_t* entry = (entry_t*)malloc(sizeof(entry_t) * 1);
	entry->event_id = (char*)malloc(strlen(event_id) + 1);


	entry->event_id = (int*)malloc(strlen(event_id) + 1);
	entry->state = (char*)malloc(strlen(state) + 1);
	entry->year = (int*)malloc(strlen(year) + 1);
	entry->month_name = (char*)malloc(strlen(month_name) + 1);
	entry->event_type = (char*)malloc(strlen(event_type) + 1);
	entry->cz_type = (char*)malloc(strlen(cz_type) + 1);
	entry->cz_name = (char*)malloc(strlen(cz_name) + 1);
	entry->injuries_direct = (int*)malloc(strlen(injuries_direct) + 1);
	entry->injuries_indirect = (int*)malloc(strlen(injuries_indirect) + 1);
	entry->deaths_direct = (int*)malloc(strlen(deaths_direct) + 1);
	entry->deaths_indirect = (int*)malloc(strlen(deaths_indirect) + 1);
	entry->damage_property = (int*)malloc(strlen(damage_property) + 1);
	entry->damage_crops = (int*)malloc(strlen(damage_crops) + 1);
	entry->tor_f_scale = (char*)malloc(strlen(tor_f_scale) + 1);


	// copy the key and value in place
	strcpy(entry->event_id, event_id);
	strcpy(entry->event_id, event_id);
	strcpy(entry->state, state);
	strcpy(entry->year, year);
	strcpy(entry->month_name, month_name);
	strcpy(entry->event_type, event_type);
	strcpy(entry->cz_type, cz_type);
	strcpy(entry->cz_name, cz_name);
	strcpy(entry->injuries_direct, injuries_direct);
	strcpy(entry->injuries_indirect, injuries_indirect);
	strcpy(entry->deaths_direct, deaths_direct);
	strcpy(entry->deaths_indirect, deaths_indirect);
	strcpy(entry->damage_property, damage_property);
	strcpy(entry->damage_crops, damage_crops);
	strcpy(entry->tor_f_scale, tor_f_scale);


	// next starts out null but may be set later on
	entry->next = NULL;

	return entry;
}




////////////////////////////////////////////looks up value by key and retrieves value//////////////////////////////////////////////
char* ht_get(ht_t* hashtable, const char* key) {
	unsigned int slot = hash1(key);

	// try to find a valid slot
	entry_t* entry = hashtable->entries[slot];

	// no slot means no entry
	if (entry == NULL) {
		return NULL;
	}

	// walk through each entry in the slot, which could just be a single thing
	while (entry != NULL) {
		// return value if found
		if (strcmp(entry->key, key) == 0) {
			return entry->value;
		}

		// proceed to next key if available
		entry = entry->next;
	}

	// reaching here means there were >= 1 entries but no key match
	return NULL;
}////////////////////////////////////////////looks up value by key and retrieves value//////////////////////////////////////////////

//*********************************************************************************************************************************

char* ht_get_event(ht_t* hashtable, const int* event_id) {
	unsigned int slot = storm_event(event_id);

	// try to find a valid slot
	entry_t* entry = hashtable->entries[slot];

	// no slot means no entry
	if (entry == NULL) {
		return NULL;
	}

	// walk through each entry in the slot, which could just be a single thing
	while (entry != NULL) {
		// return value if found
		if (strcmp(entry->event_id, event_id) == 0) {
			return entry->event_id;
			return entry->state;
			return entry->year;
			return entry->month_name;
			return entry->event_type;
			return entry->cz_type;
			return entry->cz_name;
			return entry->injuries_direct;
			return entry->injuries_indirect;
			return entry->deaths_direct;
			return entry->deaths_indirect;
			return entry->damage_property;
			return entry->damage_crops;
			return entry->tor_f_scale;

		}

		// proceed to next key if available
		entry = entry->next;
	}

	// reaching here means there were >= 1 entries but no key match
	return NULL;



///////*************************************************************************************************************


	
/////////////////allocates space for new data entry and enters new entries/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ht_set(ht_t* hashtable, const char* key, const char* value) {
	unsigned int slot = hash1(key);

	// try to look up an entry set
	entry_t* entry = hashtable->entries[slot];

	// no entry means slot empty, insert immediately
	if (entry == NULL) {
		hashtable->entries[slot] = ht_pair(key, value);
		return;
	}

	entry_t* prev;

	// walk through each entry until either the end is
	// reached or a matching key is found
	while (entry != NULL) {
		// check key
		if (strcmp(entry->key, key) == 0) {
			// match found, replace value
			free(entry->value);
			entry->value = (char*)malloc(strlen(value) + 1);
			strcpy(entry->value, value);
			return;
		}

		// walk to next
		prev = entry;
		entry = prev->next;
	}

	// end of chain reached without a match, add new
	prev->next = ht_pair(key, value);
}/////////////////allocates space for new data entry and enters new entries/////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////allocates space for new data entry and enters new entries/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ht_set_event(ht_t* hashtable, const int* event_id, const char* state, const int* year, const char* month_name, const char* event_type, const char* cz_type, const char* cz_name, const int* injuries_direct, const int* injuries_indirect, const int* deaths_direct, const int* deaths_indirect, const int* damage_property, const int* damage_crops, const char* tor_f_scale) {
	unsigned int slot = storm_event(event_id);

	// try to look up an entry set
	entry_t* entry = hashtable->entries[slot];

	// no entry means slot empty, insert immediately
	if (entry == NULL) {
		hashtable->entries[slot] = ht_pair(event_id, state);
		hashtable->entries[slot] = ht_pair(event_id, year);
		hashtable->entries[slot] = ht_pair(event_id, month_name);
		hashtable->entries[slot] = ht_pair(event_id, event_type);
		hashtable->entries[slot] = ht_pair(event_id, cz_type);
		hashtable->entries[slot] = ht_pair(event_id, cz_name);
		hashtable->entries[slot] = ht_pair(event_id, injuries_direct);
		hashtable->entries[slot] = ht_pair(event_id, injuries_indirect);
		hashtable->entries[slot] = ht_pair(event_id, deaths_direct);
		hashtable->entries[slot] = ht_pair(event_id, deaths_indirect);
		hashtable->entries[slot] = ht_pair(event_id, damage_property);
		hashtable->entries[slot] = ht_pair(event_id, damage_crops);
		hashtable->entries[slot] = ht_pair(event_id, tor_f_scale);


		////pending




		return;
	}

	entry_t* prev;

	// walk through each entry until either the end is
	// reached or a matching key is found
	while (entry != NULL) {
		// check key
		if (strcmp(entry->event_id, event_id) == 0) {
			// match found, replace value
			free(entry->state);
			free(entry->year);
			free(entry->month_name);
			free(entry->event_type);
			free(entry->cz_type);
			free(entry->cz_name);
			free(entry->injuries_direct);
			free(entry->injuries_indirect);
			free(entry->deaths_direct);
			free(entry->deaths_indirect);
			free(entry->damage_property);
			free(entry->damage_crops);
			free(entry->tor_f_scale);



			entry->state = (char*)malloc(strlen(state) + 1);
			entry->year = (char*)malloc(strlen(year) + 1);
			entry->month_name = (char*)malloc(strlen(month_name) + 1);
			entry->event_type = (char*)malloc(strlen(event_type) + 1);
			entry->cz_type = (char*)malloc(strlen(cz_type) + 1);
			entry->cz_name = (char*)malloc(strlen(cz_name) + 1);
			entry->injuries_direct = (char*)malloc(strlen(injuries_direct) + 1);
			entry->injuries_indirect = (char*)malloc(strlen(injuries_indirect) + 1);
			entry->deaths_direct = (char*)malloc(strlen(deaths_direct) + 1);
			entry->deaths_indirect = (char*)malloc(strlen(deaths_indirect) + 1);
			entry->damage_property = (char*)malloc(strlen(damage_propety) + 1);
			entry->damage_crops = (char*)malloc(strlen(damage_crops) + 1);
			entry->tor_f_scale = (char*)malloc(strlen(tor_f_scale) + 1);






			strcpy(entry->state, state);
			strcpy(entry->year, year);
			strcpy(entry->month_name, month_name);
			strcpy(entry->event_type, event_type);
			strcpy(entry->cz_type, cz_type);
			strcpy(entry->cz_name, cz_name);
			strcpy(entry->injuries_direct, injuries_direct);
			strcpy(entry->injuries_indirect, injuries_indirect);
			strcpy(entry->deaths_indirect, deaths_indirect);
			strcpy(entry->deaths_indirect, deaths_indirect);
			strcpy(entry->damage_property, damage_property);
			strcpy(entry->damage_crops, damage_crops);
			strcpy(entry->tor_f_scale, tor_f_scale);


			return;
		}

		// walk to next
		prev = entry;
		entry = prev->next;
	}

	// end of chain reached without a match, add new
	prev->next = ht_pair_event(event_id, state);
	prev->next = ht_pair_event(event_id, year);
	prev->next = ht_pair_event(event_id, month_name);
	prev->next = ht_pair_event(event_id, event_type);
	prev->next = ht_pair_event(event_id, cz_type);
	prev->next = ht_pair_event(event_id, cz_name);
	prev->next = ht_pair_event(event_id, injuries_direct);
	prev->next = ht_pair_event(event_id, injuries_indirect);
	prev->next = ht_pair_event(event_id, deaths_indirect);
	prev->next = ht_pair_event(event_id, deaths_indirect);
	prev->next = ht_pair_event(event_id, damage_property);
	prev->next = ht_pair_event(event_id, damage_crops);
	prev->next = ht_pair_event(event_id, tor_f_scale);


}/////////////////allocates space for new data entry and enters new entries/////////////////////////////////////////////////////////////////////////////////////////////////////////////



int main(int argc, char** argv) {

	//////READ_FILE_INPUT//////////////////////////////////////////
	vector<string> words;

	string STRING;
	ifstream infile;
	infile.open("C:\\Users\\Not-yours\\source\\repos\\ConsoleApplication16\\fatalities-1952.csv");
	
	while (getline(infile, STRING)) {
		STRING += ",";
		stringstream ss(STRING);
		string word;
		while (getline(ss, word, ','))
			words.push_back(word);
		
		
		
	}
	
	vector<string>fatality_id(words.size());

	
	
	for (int i = 8; i < words.size(); i+=8)
	{
		fatality_id[i] = words[i];
		fatality_id[i+1] = words[i+1];
		fatality_id[i+2] = words[i+2];
		fatality_id[i+3] = words[i+3];
		fatality_id[i+4] = words[i+4];
		fatality_id[i+5] = words[i+5];
		fatality_id[i+6] = words[i+6];
		fatality_id[i + 7] = words[i + 7];


	}
	/*
	for (int i=0;i<fatality_id.size();i++)
	{
		//cout << fatality_id[i] << endl;///processed clean vector data
		int arr[];
		arr[i]= { fatality_id[i] };

	}

	int j = 0;
	for (int i = 0; i < fatality_id.size(); i++)
	{
		//cout << fatality_id[i] << endl;///processed clean vector data
		int arr[];
		arr[i] = { fatality_id[i] };

	}



	

	///////////////////////////////////////////////////////
	///////////////////////BINARY TREE MAIN COMMANDS MUST BE MODIFIED

	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	int result = binarySearch(arr, 0, n - 1, x);
	(result == -1) ? cout << "Element is not present in array"
		: cout << "Element is present at index " << result;
	return 0;
	/////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	
	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, n);

	cout << "Sorted array is \n";
	printArray(arr, n);
	/*/////////////////////////////////////////////////////////////////////////////////////////

	

	//while (true)
	//{
	//	ht_set(ht, "event id", "em");
	//}

	ht_t* ht = ht_create();

	ht_set(ht, "state", "russian");
	ht_set(ht, "month", "pizza");
	ht_set(ht, "nam", "doge");
	ht_set(ht, "name5", "pyro");
	ht_set(ht, "name6", "joost");
	ht_set(ht, "name7", "kalix");
	ht_set(ht, "name7", "kalix");

	//ht_dump(ht);
	//ht_del(); delete values from table ///there are no deletions
	//ht_set(); set new values to table ///no need to set

	//ht_get(); retrieve values //definitely need
	//ht_pair(); link data might need 

	//ht_dump helper function displays all the values stored in hash table
	//ht_create; //creates new tables


	string A = ht_get(ht, "state");

	cout << A<<endl;

	return 0;
	
}





/*

string STRING;

int t = 0;
string type = argv[1];

if (type == "argument1") {		//  ./encode insertion <text.txt






	while (getline(cin, STRING) && t < 1)
	{

		if (t >= 1)
		{
			if ((STRING.length() == 1 && (int)(STRING.at(STRING.length() - 1)) == 13))
			{
				continue;
			}
			else if (STRING.length() == 0)
			{
				continue;
			}
			else
			{
				for (int d = 0; d <= t; d++)
				{
					cin.clear();

					string str = STRING;
					vector<string> discr(STRING.length() + 1);
					int k = 0;
					string word = "";
					for (auto x : str)
					{
						if (x == ' ')
						{
							discr[k] = word;
							k++;
							word = "";
						}
						else
						{
							word = word + x;
						}
					}
					discr[k] = STRING[str.length() - 1];
					int countr = 0;
					int varsize = 0;
					for (int i = 0; i < discr.size() - 2; i++)
					{
						if (discr[i] == "")
						{
							if (discr[i + 1] == "" && discr[i + 2] != "")
							{
								varsize += 1;
								i++;
							}
							else
							{
								i++;
							}
						}
						else
						{
							varsize += 1;
						}
					}
					vector<string>cleancopy(discr.size());
					int j = 0;
					for (int i = 0; i < discr.size(); i++)
					{
						if (discr[i] != "\0 ")
						{
							cleancopy[j] = discr[i];
							j++;
						}
						else
						{
							if (i != discr.size() - 1)
							{

								if (discr[i + 1] == "\0 ")
								{
									i++;
									cleancopy[j] = "\0"; j++;
								}

							}
						}
					}

					vector<string> clean(varsize - 1);
					for (int g = 0; g < varsize - 1; g++)
					{
						clean[g] = cleancopy[g];
					}









				}

			}
			t = -1;
		}
		t++;

	}
	STRING.clear();

}*/











/*
////////////////////////////outputs all the data from hash table (helper method not part of hash table)////@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@2///////////////////////////////////////////////////////////////////////
void ht_dump(ht_t* hashtable) {
	for (int i = 0; i < TABLE_SIZE; ++i) {
		entry_t* entry = hashtable->entries[i];

		if (entry == NULL) {
			continue;
		}

		printf("slot[%4d]: ", i);

		for (;;) {
			printf("%s=%s ", entry->key, entry->value);

			if (entry->next == NULL) {
				break;
			}

			entry = entry->next;
		}

		printf("\n");
	}
}
////////////////////////////outputs all the data from hash table (helper method not part of hash table)/////@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//////////////////////////////////////////////////////////////////////


*/

/*
void ht_del(ht_t* hashtable, const char* key) {
	unsigned int bucket = hash1(key);

	// try to find a valid bucket
	entry_t* entry = hashtable->entries[bucket];

	// no bucket means no entry
	if (entry == NULL) {
		return;
	}

	entry_t* prev;
	int idx = 0;

	// walk through each entry until either the end is reached or a matching key is found
	while (entry != NULL) {
		// check key
		if (strcmp(entry->key, key) == 0) {
			// first item and no next entry
			if (entry->next == NULL && idx == 0) {
				hashtable->entries[bucket] = NULL;
			}

			// first item with a next entry
			if (entry->next != NULL && idx == 0) {
				hashtable->entries[bucket] = entry->next;
			}

			// last item
			if (entry->next == NULL && idx != 0) {
				prev->next = NULL;
			}

			// middle item
			if (entry->next != NULL && idx != 0) {
				prev->next = entry->next;
			}

			// free the deleted entry
			free(entry->key);
			free(entry->value);
			free(entry);

			return;
		}

		// walk to next
		prev = entry;
		entry = prev->next;

		++idx;
	}
}

*/

/*
///////////////////////////////base table/////////////////////////////////////////////////////////////////////////////////////////////
ht_t* ht_create(void) {
	// allocate table
	ht_t* hashtable = (ht_t*)malloc(sizeof(ht_t) * 1);

	// allocate table entries
	hashtable->entries = (entry_t * *)malloc(sizeof(entry_t*) * TABLE_SIZE);

	// set each to null (needed for proper operation)
	int i = 0;
	for (; i < TABLE_SIZE; ++i) {
		hashtable->entries[i] = NULL;
	}

	return hashtable;
}////////////////////////////////base table///////////////////////////////////////////////////////////////////////////////////////////
*/




