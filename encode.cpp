#include <iostream>		// library
#include <string>		// string library
using namespace std;		// allows to type cout instead of std::cout<<
void Merger(string arr[], int lo, int  mi, int hi) {
	string* temp = new string[hi - lo + 1];//temporary merger array
	int i = lo, j = mi + 1;//i is for left-hand,j is for right-hand
	int k = 0;//k is for the temporary array
	while (i <= mi && j <= hi) {
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	//rest elements of left-half
	while (i <= mi)
		temp[k++] = arr[i++];
	//rest elements of right-half
	while (j <= hi)
		temp[k++] = arr[j++];
	//copy the mergered temporary array to the original array
	for (k = 0, i = lo; i <= hi; ++i, ++k)
		arr[i] = temp[k];

	delete[]temp;
}
void MergeSortHelper(string arr[], int lo, int hi) {
	int mid;
	if (lo < hi) {
		mid = (lo + hi) >> 1;
		MergeSortHelper(arr, lo, mid);
		MergeSortHelper(arr, mid + 1, hi);
		Merger(arr, lo, mid, hi);
	}
}
void MergeSort(string arr[], int arr_size) {
	MergeSortHelper(arr, 0, arr_size - 1);
}
int main(int argc, char* argv[])		// main program command line arguments 
{
	

	string type = argv[1];			// program cin option type
	if (type == "insertion") {		//  ./encode insertion <text.txt
		string STRING;				// string variable input from file
		string A;
		string last;			// variable for last letters of string after being sorted
		string final;			// final output after encoding
		int len;
		bool isChanged = false;
		while (getline(cin, STRING))			//gets string data from file using data name STRING to extract
		{
			cin.clear();
			//cout << (int)(STRING.at(len - 1)) << endl;
			if (STRING.length() == 0 || (STRING.length() == 1 && (int)(STRING.at(STRING.length() - 1)) == 13)) 
			{			// if empty space output a 0 value
				cout << "0" << endl << endl;		// empty line has 0
			}
			else {				// evaluates that if there are strings in a line enter the else condition
				int x = (int)(STRING.at(STRING.length() - 1));
				if (x == 13) {

					isChanged = true;
				}
				if (isChanged) {
					//cout << "hey " << STRING << endl;
					len = STRING.length() - 1;
				}
				else {
					//cout <<"hello : " << STRING << endl;
					len = STRING.length();
				}
				//isChanged = false;
				//len = STRING.length();
				//cout << "hello" << endl;
				string* V = new string[len];		// creates a new pointer array of size A.length()
				string C;		// is used to store values sifting
				string D;		// is used to store values (C & D combined iteration is array V[i])
				for (int i = 0; i < len; i++)		// loop starts at i=0 and increase by 1 to the end of line
				{
					// shifts starting at position i to the end of line per shift
					for (int j = len - 1; j >= 0; j--)				// starts loop starting from j=0 and increases by 1 to the end of line per shift
					{
						D = STRING.substr(0, i);		// assigns string values from the beggining position 0 to an arbitrary length i
					}
					C = STRING.substr(i, len - i);
					V[i] = C + D;				// combines string length from i to end and position 0 to arbitraru shift N
					//cout << D << end;
					//cout << V[i] << endl;
				}
				for (size_t j = 0; j < len - 1; j++)		// this loops softs the arrys of unsorted shifts lexicographically
				{
					if (V[j] == V[j + 1])			// if position A is equal to position B ignore and continue to next positon
					{
						continue;
					}
					else if (V[j] < V[j + 1])		// if position A is less than position B in string ignore and  
					{
						continue;					// continue to next position because it is already sorted
					}
					else if (V[j] > V[j + 1])		// however if position A is greater than position B the string is unsorted and must enter condition
					{
						while (V[j] > V[j + 1])		// so as long position A is greater swap the values from high to low (low to high)
						{
							swap(V[j], V[j + 1]);		// swaps position to correct order swaps A for B and vise versa
							j = 0;						// initiated the outside loop condition i to 0 as to re-evaluate string starting from 
						}								// zero until the condition is false and the string is sorted
					}
				}
				for (int i = 0; i < len; i++)
				{
					//cout << V[i] << endl;
				}
				for (int k = 0; k < len + 1; k++)		// this condition outputs the positon of the original string in the sorted array in lexicographic order
				{
					// evaluated the array from positon 0 to the end looking for a match to the original string name
					string G;
					if (isChanged) {
						G = STRING.substr(0, STRING.length() - 1);
					}
					else {
						G = STRING;
					}
					if (G == V[k]) {
						cout << k << endl;					// outputs position of original string
						break;								// the for look exits once the position is found
					}
				}
				for (int j = 0; j < len; j++)			// this loops concatenates the last string characters and creates one string
				{
					last = last + V[j].substr(len - 1, 1);			// the string starts is empty then adds the first last character of array[i] to and continues to add
				}																// last character as i increases from 0 to the end of total STRING shifts
				//cout << last << endl;
				for (size_t i = 0; i < len; i += 1)			// this inserts a number for repetive characters and simbols
				{
					int count = 1;						// initiates that characters repeat only once
					if (last[i] == last[i + 1])			// if the charcters repeat it counts how many times the characters repeat
					{
						while (last[i] == last[i + 1])		// if the character position A is the same as position B the while loops 
						{									// with continue to count how many times this occurs
							count++;		// characater counter
							i++;			// skips i because position A and and already evaluated before and after therefore it skips to two values ahead
						}
						final = final + to_string(count) + " " + last.substr(i, 1) + " ";	// adds fornmer positon of last character and count of the next 
					}																		// with a spcacer and the character evaluated
					else if (last[i] != last[i + 1])		// if they do not repeat and there are unique characters insert 1
					{
						final = final + to_string(count) + " " + last.substr(i, 1) + " ";	// inserts the count value outside the while loop and if conditions
					}
				}
				cout << final << endl; // outputs the encoded line
				final.clear();		// clears values for the next iteration
				last.clear();		// clears values for the next computations
				delete[] V;			// deletes the memory for array V[]
				D.clear();
				C.clear();
				isChanged = false;
			}
		}
		STRING.clear();
	}
	else if (type == "merge") {		//  ./encode insertion <text.txt
		string STRING;				// string variable input from file
		string A;
		string last;			// variable for last letters of string after being sorted
		string final;			// final output after encoding
		int len;
		bool isChanged = false;
		while (getline(cin, STRING))			//gets string data from file using data name STRING to extract
		{
			cin.clear();
			//cout << (int)(STRING.at(len - 1)) << endl;
			if (STRING.length() == 0 || (STRING.length() == 1 && (int)(STRING.at(STRING.length() - 1)) == 13)) {			// if empty space output a 0 value
				cout << "0" << endl << endl;		// empty line has 0
			}
			else {				// evaluates that if there are strings in a line enter the else condition
				int x = (int)(STRING.at(STRING.length() - 1));
				if (x == 13) {

					isChanged = true;
				}
				if (isChanged) {
					//cout << "hey " << STRING << endl;
					len = STRING.length() - 1;
				}
				else {
					//cout <<"hello : " << STRING << endl;
					len = STRING.length();
				}
				//isChanged = false;
				//len = STRING.length();
				//cout << "hello" << endl;
				string* V = new string[len];		// creates a new pointer array of size A.length()
				string C;		// is used to store values sifting
				string D;		// is used to store values (C & D combined iteration is array V[i])
				for (int i = 0; i < len; i++)		// loop starts at i=0 and increase by 1 to the end of line
				{
					// shifts starting at position i to the end of line per shift
					for (int j = len - 1; j >= 0; j--)				// starts loop starting from j=0 and increases by 1 to the end of line per shift
					{
						D = STRING.substr(0, i);		// assigns string values from the beggining position 0 to an arbitrary length i
					}
					C = STRING.substr(i, len - i);
					V[i] = C + D;				// combines string length from i to end and position 0 to arbitraru shift N
					//cout << D << end;
					//cout << V[i] << endl;
				}
				int n = sizeof(V) / sizeof(V[0]);
				MergeSort(V, n);
				for (int i = 0; i < len; i++)
				{
					//cout << V[i] << endl;
				}
				for (int k = 0; k < len + 1; k++)		// this condition outputs the positon of the original string in the sorted array in lexicographic order
				{
					// evaluated the array from positon 0 to the end looking for a match to the original string name
					string G;
					if (isChanged) {
						G = STRING.substr(0, STRING.length() - 1);
					}
					else {
						G = STRING;
					}
					if (G == V[k]) {
						cout << k << endl;					// outputs position of original string
						break;								// the for look exits once the position is found
					}
				}
				for (int j = 0; j < len; j++)			// this loops concatenates the last string characters and creates one string
				{
					last = last + V[j].substr(len - 1, 1);			// the string starts is empty then adds the first last character of array[i] to and continues to add
				}																// last character as i increases from 0 to the end of total STRING shifts
				//cout << last << endl;
				for (size_t i = 0; i < len; i += 1)			// this inserts a number for repetive characters and simbols
				{
					int count = 1;						// initiates that characters repeat only once
					if (last[i] == last[i + 1])			// if the charcters repeat it counts how many times the characters repeat
					{
						while (last[i] == last[i + 1])		// if the character position A is the same as position B the while loops 
						{									// with continue to count how many times this occurs
							count++;		// characater counter
							i++;			// skips i because position A and and already evaluated before and after therefore it skips to two values ahead
						}
						final = final + to_string(count) + " " + last.substr(i, 1) + " ";	// adds fornmer positon of last character and count of the next 
					}																		// with a spcacer and the character evaluated
					else if (last[i] != last[i + 1])		// if they do not repeat and there are unique characters insert 1
					{
						final = final + to_string(count) + " " + last.substr(i, 1) + " ";	// inserts the count value outside the while loop and if conditions
					}
				}
				cout << final << endl; // outputs the encoded line
				final.clear();		// clears values for the next iteration
				last.clear();		// clears values for the next computations
				delete[] V;			// deletes the memory for array V[]
				D.clear();
				C.clear();
				isChanged = false;
			}
		}
		STRING.clear();
	}
	
}