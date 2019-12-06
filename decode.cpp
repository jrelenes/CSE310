#include <iostream>	
#include <string>		
#include <vector>
#include <stdio.h>
using namespace std;




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

	

	string complete;
	string STRING;
	vector<int> index0(10);
	vector<int> index1(10);
	string* part = new string[100 * 10 ^ 10];
	string* part1 = new string[100 * 10 ^ 10];
	int len;
	int i = 0;
	int t = 0;
	bool isChanged = false;
	string* tempstring = new string[100 * 10 ^ 10];
	int* temp = new int[100 * 10 ^ 10];
	int dd = 0;
	string char1;


	string type = argv[1];			// program cin option type
	if (type == "insertion") {		//  ./encode insertion <text.txt



		


		while (getline(cin, STRING) && t <= 1)
		{
			tempstring[t] = STRING;
			if (t >= 1)
			{
				if ((STRING.length() == 1 && (int)(STRING.at(STRING.length() - 1)) == 13))
				{
					cout << "\n" << endl;
				}
				else if (STRING.length() == 0)
				{
					cout << "" << endl;
				}
				else
				{
					string decoded;
					for (int d = 0; d <= t; d++)
					{
						char1 = tempstring[0];
						temp[0] = stoi(char1);
						string complete;
						string STRINGQ;
						STRINGQ = tempstring[1];
						//cout << STRINGQ << endl;
						int control = STRINGQ.length();
						int i = 0;
						string modified;
						int* size = new int[control];
						string A;
						string STRING_COMPUTATION = STRINGQ;
						string maybe;
						string other;
						cin.clear();
						string* otherarraycopy = new string[STRINGQ.length()];
						int s = 0;
						string str = STRING_COMPUTATION;

						//cout << "original: "<<STRING_COMPUTATION << endl;
						vector<string> discr(STRING_COMPUTATION.length() + 1);
						int k = 0;
						string word = "";
						for (auto x : str)
						{
							if (x == ' ')
							{
								discr[k] = word;
								//cout << discr[k]<<endl;
								k++;
								word = "";
							}
							else
							{
								word = word + x;
							}
						}
						discr[k] = STRING_COMPUTATION[str.length() - 1];
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

						///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
						vector<string>cleancopy(discr.size());
						int j = 0;
						for (int i = 0; i < discr.size(); i++)
						{
							if (discr[i] != "\0 ")
							{
								cleancopy[j] = discr[i];
								//cout << cleancopy[i]<<endl;
								j++;
							}
							else
							{
								if (i != discr.size() - 1)
								{

									///////////////////////////////////////////////////fix exeption
																	/*while (i <= discr.size() - 1 && discr[i + 1] == "\0 " ) {
																		i++;

																	}

																	i--;
																	cleancopy[j] = "\0"; j++;
																	*/

									if (discr[i + 1] == "\0 ")
									{
										i++;
										cleancopy[j] = "\0"; j++;
										//cout << cleancopy[j] << endl;
									}

									//*****************************************************************************************************************************////



																		/*
																		if (discr[i + 1] == "\0 " || discr[i + 1]=="\n" || discr[i + 1]==" " || discr[i + 1]=="")
																		{
																			cleancopy[j] = "\0"; j++; i++;

																			//cout << "test1" << endl;
																		}

																		*/


																		/////////////////////////////////////////////////////////////////////////////////////////////////

								}
							}
						}

						vector<string> clean(varsize - 1);
						for (int g = 0; g < varsize - 1; g++)
						{
							clean[g] = cleancopy[g];
							//cout << clean[g] << endl;
						}

						/////////////////////////////////////////////////////////////////////////////////////////////////
						while (i < clean.size())
						{
							int size;
							for (int k = 0; k < clean.size() && k < i + 1; k += 2)
							{
								size = stoi(clean[k]);
							}
							for (int k = 0; k < size; k++)
							{
								//cout << clean[i + 1] << endl;

								if (i < clean.size() && clean.size() != 1)
								{
									other = other + clean[i + 1];
									if (clean[i + 1] == "\0 ")
									{
										other = other + " ";
									}
								}
								else
								{
									other = other + " ";
								}
							}
							i += 2;
						}
						/////////////////////////////////////////////////////////////////////////////////////////////////////////////
						clean.clear();
						string othercopy = other;
						//cout << "other: "<<other << endl;
						for (size_t j = 0; j < other.length() - 1; j++)
						{
							if (other[j] == other[j + 1])
							{
								continue;
							}
							else if (other[j] < other[j + 1])
							{
								continue;
							}
							else if (other[j] > other[j + 1])
							{
								while (other[j] > other[j + 1])
								{
									swap(other[j], other[j + 1]);
									j = 0;
								}
							}
						}
						string sorted = other.substr(0, other.length());
						string next;
						int found;
						int pos = 0;
						vector<int>vectornext(sorted.length());
						for (int k = 0; k < othercopy.length(); k++)
						{
							pos = 0;
							while (true)
							{
								found = othercopy.find(sorted[k], pos);
								bool check = true;
								for (int h = 0; h < k; h++)
								{
									if (found == vectornext[h])
									{
										check = false;
										break;
									}
								}
								if (check == true) {
									vectornext[k] = found;
									break;
								}
								else {
									pos++;
								}
							}
						}


						int counter = 0;
						int index = temp[0];
						int termination = 0;
						decoded = sorted[index];
						while (termination < sorted.length() - 1)
						{
							//cout << "sorted index: "<<sorted[index]<<endl;
							//cout << "vectornext: " << vectornext[index] << endl;
							decoded = decoded + other[vectornext[index]];
							index = vectornext[index];
							termination++;
						}


					}
					cout << decoded << endl;
				}
				t = -1;
			}
			t++;
			dd++;
		}
		delete[] tempstring;
		STRING.clear();
		delete[] part;
		delete[] part1;












	}
	else if (type == "merge") {





	while (getline(cin, STRING) && t <= 1)
	{
		tempstring[t] = STRING;
		if (t >= 1)
		{
			if ((STRING.length() == 1 && (int)(STRING.at(STRING.length() - 1)) == 13))
			{
				cout << "\n" << endl;
			}
			else if (STRING.length() == 0)
			{
				cout << "" << endl;
			}
			else
			{
				string decoded;
				for (int d = 0; d <= t; d++)
				{
					char1 = tempstring[0];
					temp[0] = stoi(char1);
					string complete;
					string STRINGQ;
					STRINGQ = tempstring[1];
					//cout << STRINGQ << endl;
					int control = STRINGQ.length();
					int i = 0;
					string modified;
					int* size = new int[control];
					string A;
					string STRING_COMPUTATION = STRINGQ;
					string maybe;
					string other;
					cin.clear();
					string* otherarraycopy = new string[STRINGQ.length()];
					int s = 0;
					string str = STRING_COMPUTATION;

					//cout << "original: "<<STRING_COMPUTATION << endl;
					vector<string> discr(STRING_COMPUTATION.length() + 1);
					int k = 0;
					string word = "";
					for (auto x : str)
					{
						if (x == ' ')
						{
							discr[k] = word;
							//cout << discr[k]<<endl;
							k++;
							word = "";
						}
						else
						{
							word = word + x;
						}
					}
					discr[k] = STRING_COMPUTATION[str.length() - 1];
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

					///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					vector<string>cleancopy(discr.size());
					int j = 0;
					for (int i = 0; i < discr.size(); i++)
					{
						if (discr[i] != "\0 ")
						{
							cleancopy[j] = discr[i];
							//cout << cleancopy[i]<<endl;
							j++;
						}
						else
						{
							if (i != discr.size() - 1)
							{

								///////////////////////////////////////////////////fix exeption
																/*while (i <= discr.size() - 1 && discr[i + 1] == "\0 " ) {
																	i++;

																}

																i--;
																cleancopy[j] = "\0"; j++;
																*/

								if (discr[i + 1] == "\0 ")
								{
									i++;
									cleancopy[j] = "\0"; j++;
									//cout << cleancopy[j] << endl;
								}

								//*****************************************************************************************************************************////



																	/*
																	if (discr[i + 1] == "\0 " || discr[i + 1]=="\n" || discr[i + 1]==" " || discr[i + 1]=="")
																	{
																		cleancopy[j] = "\0"; j++; i++;

																		//cout << "test1" << endl;
																	}

																	*/


																	/////////////////////////////////////////////////////////////////////////////////////////////////

							}
						}
					}

					vector<string> clean(varsize - 1);
					for (int g = 0; g < varsize - 1; g++)
					{
						clean[g] = cleancopy[g];
						//cout << clean[g] << endl;
					}

					/////////////////////////////////////////////////////////////////////////////////////////////////
					while (i < clean.size())
					{
						int size;
						for (int k = 0; k < clean.size() && k < i + 1; k += 2)
						{
							size = stoi(clean[k]);
						}
						for (int k = 0; k < size; k++)
						{
							//cout << clean[i + 1] << endl;

							if (i < clean.size() && clean.size() != 1)
							{
								other = other + clean[i + 1];
								if (clean[i + 1] == "\0 ")
								{
									other = other + " ";
								}
							}
							else
							{
								other = other + " ";
							}
						}
						i += 2;
					}
					/////////////////////////////////////////////////////////////////////////////////////////////////////////////
					clean.clear();
					string othercopy = other;
					//cout << "other: "<<other << endl;


					string* tempo=new string[other.length()];
					for (int h = 0; h < other.length(); h++)
					{
						tempo[h] = other.substr(h, 1);
					}
					MergeSort(tempo, other.length());

					string convert;
					for (int h = 0; h < other.length(); h++)
					{
						convert = convert+ tempo[h];
					}
					other = convert;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

					for (size_t j = 0; j < other.length() - 1; j++)
					{
						if (other[j] == other[j + 1])
						{
							continue;
						}
						else if (other[j] < other[j + 1])
						{
							continue;
						}
						else if (other[j] > other[j + 1])
						{
							while (other[j] > other[j + 1])
							{
								swap(other[j], other[j + 1]);
								j = 0;
							}
						}
					}







					string sorted = other.substr(0, other.length());
					string next;
					int found;
					int pos = 0;
					vector<int>vectornext(sorted.length());
					for (int k = 0; k < othercopy.length(); k++)
					{
						pos = 0;
						while (true)
						{
							found = othercopy.find(sorted[k], pos);
							bool check = true;
							for (int h = 0; h < k; h++)
							{
								if (found == vectornext[h])
								{
									check = false;
									break;
								}
							}
							if (check == true) {
								vectornext[k] = found;
								break;
							}
							else {
								pos++;
							}
						}
					}


					int counter = 0;
					int index = temp[0];
					int termination = 0;
					decoded = sorted[index];
					while (termination < sorted.length() - 1)
					{
						//cout << "sorted index: "<<sorted[index]<<endl;
						//cout << "vectornext: " << vectornext[index] << endl;
						decoded = decoded + other[vectornext[index]];
						index = vectornext[index];
						termination++;
					}


				}
				cout << decoded << endl;
			}
			t = -1;
		}
		t++;
		dd++;
	}
	delete[] tempstring;
	STRING.clear();
	delete[] part;
	delete[] part1;










	}




	
	

	
}







