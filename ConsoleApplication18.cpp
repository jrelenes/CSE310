#include <iostream> 
#include <string>		
#include <vector>
#include <fstream>
#include <sstream>
#define	STATE_LEN	15
#define	MONTH_LEN	10
#define	EVENT_LEN	26
#define	COUNTY_LEN	30
#define	TOR_LEN		4
#define DATE_LEN    20
#define FAC_LOC     25
using namespace std;


struct annual_storms {
	int year; // Year of storm events
	struct storm_event* events;  // Pointer to array of storm events for the given year
};

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

struct fatality_event {
	int fatality_id; // Identifier of the fatality
	int event_id; // Identifier of the storm event
	char fatality_type; // D or I
	char fatality_date[DATE_LEN]; // Date and time of fatality
	int fatality_age; // Age of fatality
	char fatality_sex; // Gender of fatality
	char fatality_location[FAC_LOC]; // Location of fatality
};

struct hash_table_entry {
	char event_id; // Event id -- key used to hash on
	int year; // Year of storm event
	int event_index; // For the given year, the index into array of storm events
};

struct bst { // A binary search tree
	char* s; // String corresponding to either a state or a month_name
	int event_id; // Identifier of storm event
	struct bst* left;  // Pointer to the left subtree
	struct bst* right;  // Pointer to the right subtree
};





	int main(int argc, char** argv)
	{
		vector<string> words;
		string STRING;
		string STRING1;
		ifstream infile;
		ifstream infile1;
		infile.open("Cfatalities-1952.csv");
		infile1.open("details-1952.csv");
		
		while (getline(infile, STRING)) {
			STRING += ",";
			//cout << STRING << endl;
			stringstream ss(STRING);
			string word;
			while (getline(ss, word, ','))
				words.push_back(word);
		}
		vector<struct fatality_event> event0;
		for (int i = 7; i < words.size(); i += 7)
		{
			struct fatality_event newEvent0;
			newEvent0.fatality_id = stoi(words[i]);
			newEvent0.event_id = stoi(words[i + 1]);
			newEvent0.fatality_type = words[i + 2][0];
			//newEvent0.fatality_date = words[i + 3];
			for (int j = 0; j < words[i + 3].length(); ++j) {
				newEvent0.fatality_date[j] = words[i + 3][j];
			}
			if (words[i + 4] != "")
			{
				newEvent0.fatality_age = stoi(words[i + 4]);
			}
			else
			{
				newEvent0.fatality_age = 0;
			}
			
			newEvent0.fatality_sex = words[i + 5][0];
			//newEvent0.fatality_location = words[i + 6];
			for (int j = 0; j < words[i + 6].length(); ++j) {

				newEvent0.fatality_location[j] = words[i + 6][j];
			}

			event0.push_back(newEvent0);
			
		}
		
		//cout << event0[0].fatality_age << endl;
		
		vector<string> words1;

/*
		while (getline(infile1,STRING1)); 
		{

			STRING1 += ",";
			cout << STRING1 << endl;

			stringstream ss(STRING1);
			string word1;
			while (getline(ss, word1, ','))
				words1.push_back(word1);

			for (int i=14; i < words1.size()-14; i+=14)
			{
				//cout << words1[i] << endl;
			}
				
		}
		*/
	//////////////////////////////////////////////////////////////////////////////////////////////

		while (!infile1.eof()) // To get you all the lines.
		{
			infile1>> STRING1; // Saves the line in STRING.
						//cout << STRING1 << endl;

			int k = 0;
			string word = "";
			for (auto x : STRING1)
			{
				if (x == ',')
				{

					words1.push_back(word);
					cout << word<<endl;
					k++;
					word = "";
					
				}
				else
				{
					word = word + x;
				}

			}


			for (int i = 14; i < words1.size() - 14; i += 14)
			{
				cout << words1[i] << endl;
			}
			
			
		}
		infile.close();



	//////////////////////////////////////////////////////////////////////////////////////////////	
		vector<struct storm_event> events1;
		for (int i = 14; i < words1.size()-14; i += 14)
		{
			struct storm_event newEvent1;

			//cout << words1[i] << endl;
			/*
			newEvent1.event_id = stoi(words1[i]);			
			//newEvent1.state = words[i + 1];
			for (int j = 0; j < words1[i + 1].length(); ++j) {
				newEvent1.state[j] = words1[i + 1][j];
			}
			newEvent1.year = stoi(words1[i + 2]);
			//newEvent1.month_name = words[i + 3];
			for (int j = 0; j < words1[i + 3].length(); ++j) {
				newEvent1.month_name[j] = words1[i + 3][j];
			}
			//newEvent1.event_type = words[i + 4];
			for (int j = 0; j < words1[i + 4].length(); ++j) {
				newEvent1.event_type[j] = words1[i + 4][j];
			}
			newEvent1.cz_type = words1[i + 5][0];
			
			//newEvent1.cz_name = words[i + 6];
			for (int j = 0; j < words1[i + 6].length(); ++j) {
				newEvent1.cz_name[j] = words1[i + 6][j];
			}
			newEvent1.injuries_direct = stoi(words1[i + 7]);
			newEvent1.injuries_indirect = stoi(words1[i + 8]);
			newEvent1.deaths_direct = stoi(words1[i + 9]);
			newEvent1.deaths_indirect = stoi(words1[i + 10]);
			

			newEvent1.damage_property = stoi(words1[i + 11]);//must keep K add variable


			newEvent1.damage_crops = stoi(words1[i + 12]);
			//newEvent1.tor_f_scale = words[i + 13];
			for (int j = 0; j < words1[i + 13].length(); ++j) {
				newEvent1.tor_f_scale[j] = words1[i + 13][j];
			}
			events1.push_back(newEvent1);
			*/
			
		}
		
		


	}





	
