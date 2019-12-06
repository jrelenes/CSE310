#include <iostream>
#include <fstream>
#include "seaice.h"
#include <string>
#include <cmath>
#include <stdio.h> 
#include <thread> 
using namespace std;

//sorts the array to output the histogram
#define V_SIZE 3969
#define INF 99999     

int matrix1[V_SIZE][V_SIZE];
int matrix2[V_SIZE][V_SIZE];
int matrix3[V_SIZE][V_SIZE];
double path_length[3];
double random_clustering_coefficient[3];
double PathLength[3];

void floydWarshall(int graph[][V_SIZE], int n)
{
	
	int i, j, k;


	for (k = 0; k < V_SIZE; k++)
	{
		for (i = 0; i < V_SIZE; i++)
		{
			
			for (j = i+1; j < V_SIZE; j++)
			{
				
				if (graph[i][k] + graph[k][j] < graph[i][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
					graph[j][i] = graph[i][j];
				}
			}
		}
	}

	double counter = 0;
	double number = 0;
	for (int i = 0; i < V_SIZE; i++)
	{
		for (int j = i + 1; j < V_SIZE; j++)
		{
			if (graph[i][j] != INF)
			{
				counter += graph[i][j];
				number += 1;
			}

		}
	}

	PathLength[n] = counter / number;

}




void heapify(int arr[], int n, int i)
{
	int largest = i;

	int l = 2 * i + 1;

	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
	{

		largest = l;

	}

	if (r < n && arr[r] > arr[largest])
	{

		largest = r;

	}

	if (largest != i)
	{

		swap(arr[i], arr[largest]);

		heapify(arr, n, largest);

	}

}

//is composed of two parts heapsort and heapify

void heapSort(int arr[], int n)
{

	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
}

//global variable for ladn values and array counter for histogram

int global = 0;

int land = 0;





//sums the values of each linked list in the array

pair<float, float> S(struct node  X[], int n)
{
	float sum_X = 0;

	for (int i = 0; i < n; i++)
	{

		sum_X = sum_X + X[i].data;

	}

	float x_mean = sum_X / n;

	float Sxx = 0;

	float Sxy = 0;

	for (int i = 0; i < n; i++)
	{

		Sxx = Sxx + pow(X[i].data - x_mean, 2);

	}

	return make_pair(Sxx, x_mean);

}

//calculates the correlation coefficent

float correlationCoefficient(struct node  X[], struct node  Y[], int n, float x_mean, float y_mean, float Sxx, float Syy)
{

	//float sum_X = 0, sum_Y = 0, sum_XY = 0;

	float Sxy = 0;

	for (int i = 0; i < n; i++)
	{

		Sxy = Sxy + (X[i].data - x_mean) * (Y[i].data - y_mean);

	}

	float corr = fabs(Sxy / sqrt(Sxx * Syy));

	return corr;

}

//this creases a node in the graph

struct Node* createNode(int v)
{

	//struct Node* newNode = new Node[sizeof(struct Node)];
	struct Node* newNode = new struct Node;

	newNode->vertex = v;

	newNode->next = NULL;

	return newNode;

}

//this the graph for the array that has values from thresholds

struct Graph* createGraph(int vertices)
{

	//struct Graph* graph = new Graph[sizeof(struct Graph)];
	struct Graph* graph = new struct Graph;

	graph->numVertices = vertices;

	// graph->adjLists = new Node * [vertices * sizeof(struct Node*)];
	graph->adjLists = new struct Node* [vertices];

	int i;

	for (i = 0; i < vertices; i++)
	{
		graph->adjLists[i] = NULL;
	}

	return graph;

}

//adds edges into the graph

void addEdge(struct Graph* graph, int src, int dest)
{

	struct Node* newNode = createNode(dest);

	newNode->next = graph->adjLists[src];

	graph->adjLists[src] = newNode;

	newNode = createNode(src);

	newNode->next = graph->adjLists[dest];

	graph->adjLists[dest] = newNode;

}

//this function is caled to calculate depth first search

void DFSUtil(int v, bool visited[], struct Graph* graph)
{

	visited[v] = true;

	global++;

	struct Node* temp = graph->adjLists[v];

	while (temp)
	{

		if (!visited[temp->vertex])
		{

			DFSUtil(temp->vertex, visited, graph);

		}

		temp = temp->next;

	}

}

//this function calculates the number of connected componets
//in the array based on thresholds

void connectedComponents(struct Graph* graph)
{
	

	int V = graph->numVertices;

	bool* visited = new bool[V];

	for (int v = 0; v < V; v++)
	{

		visited[v] = false;

	}

	int* arr = new int[V];

	int j1 = 0;

	for (int v = 0; v < V; v++)
	{

		if (visited[v] == false)
		{

			DFSUtil(v, visited, graph);

			arr[j1] = global;

			global = 0;

			j1++;

		}

	}

	//heapsort is called to arrange componets

	heapSort(arr, j1);

	int count = 1;

	int total = 0;
	for (int i = j1 - 1; i > -1; i--)
	{

		if (arr[i] == arr[i - 1])
		{

			count++;

		}

		if (arr[i] != arr[i - 1])
		{

			if (arr[i] != 1)
			{
				total = total + count;
				cout << "NUMBER OF CONNECTED COMPONENTS WITH SIZE " << arr[i] << ": " << count << endl;

			}
			else
			{
				total = total + count - land;
				cout << "NUMBER OF CONNECTED COMPONENTS WITH SIZE " << arr[i] << ": " << count - land << endl << endl;
				


			}

			count = 1;

		}

	}
	cout << "TOTAL: " << total << endl;
	
	


}

//the histogran is printed using this function

void printGraph(struct Graph* graph, int n)
{

	double k = 0;
	double k_actual = 0;
	

	int arr_total[3969];

	int v;

	for (v = 0; v < graph->numVertices; v++)
	{

		struct Node* temp = graph->adjLists[v];

		int temp1 = 0;

		//cout << v<< ": ";
		while (temp != NULL)
		{

			temp1++;
			//cout << temp->vertex << " ";
			switch (n)
			{
			case 0:			matrix1[v][temp->vertex] = 1;

				break;
			case 1:			matrix2[v][temp->vertex] = 1;

				break;
			case 2:			matrix3[v][temp->vertex] = 1;

				break;
			}



			temp = temp->next;

		}
		
		
		//	cout << endl;
		
		arr_total[v] = temp1;



		temp1 = 0;

	}

	//heapsort arranges the histogram

	heapSort(arr_total, graph->numVertices);



	int count2 = 1;

	for (int i = graph->numVertices - 1; i >= -1; i--)
	{

		if (arr_total[i] == arr_total[i - 1])
		{

			count2++;

		}

		if (arr_total[i] != arr_total[i - 1])
		{

			if (arr_total[i] != 0)
			{

				cout << "NUMBER OF VERTICES WITH DEGREE " << arr_total[i] << ": ";

				for (int h = 0; h < count2; h++)
				{

					cout << "*";

				}

				cout << " (" << count2 << ")" << " " << endl;
				k = k + arr_total[i] * count2;


			}
			else
			{
				cout << "NUMBER OF VERTICES WITH DEGREE " << arr_total[i] << ": ";

				for (int h = 0; h < count2 - land; h++)
				{

					cout << "*";

				}

				cout << " (" << count2 - land - 1 << ")" << " " << endl;
				k = k + arr_total[i] * (count2 - land - 1);

			}

			count2 = 1;

		}

	}

	double land_conversion = 3969 - land;
	k_actual = k / land_conversion;
	random_clustering_coefficient[n] = k_actual / land_conversion;
	path_length[n] = log(3186) / log(k_actual);

	

}


void clustering_coefficient(struct Graph* graph)
{
	float neightboor = 0;
	float number = 0;
	float coeff = 0;
	float all;
	for (int v = 0; v < graph->numVertices; v++)
	{
		//cout << v << ": ";
		struct Node* temp = graph->adjLists[v];
		while (temp != NULL)
		{
			//cout << temp->vertex << " ";
			number++;
			if (temp->next != NULL) {
				struct Node* curCompare = temp->next;
				while (curCompare != NULL)
				{
					struct Node* position = graph->adjLists[temp->vertex];

					while (position != NULL)
					{
						if (position->vertex == curCompare->vertex)
						{
							neightboor++;
						}
						position = position->next;

					}
					curCompare = curCompare->next;
				}
			}


			temp = temp->next;
		}
		//cout << endl;
		//cout << neightboor << endl;

		if (number > 1 && neightboor > 0)
		{
			coeff = coeff + (2 * neightboor) / (number * (number - 1));
		}


		neightboor = 0;
		number = 0;
	}
	float t = graph->numVertices - land;
	all = coeff / t;

	cout << all << endl;

}

//reads binary file and prints histogran and connected components

void read()
{
	//this is where the data from each node
	// is connected froming a 63 by 63 arrray

	struct node_data array[63][63];

	//temporary data entry from binary to decimal

	float dataIn = 0;

	//node height to store data points from
	//each node to build to calculate mean

	int one_node_index = 0;

	//the fro loops reads binary data and converts it to decimal

	for (int year = 1990; year < 2006; year++)
	{

		for (int week = 01; week < 53; week++)
		{

			//the integer values are converted to strings to use
			// when calling the data directory to open files

			string year_name = to_string(year);

			string week_name = to_string(week);

			//file directory are using with type string

			string data_input;

			//specified directory where the files are stored

			if (week < 10)
			{
				//the file has problems converting from integer to string when numbers start with zero 

				data_input = "CS310_project_subregion/" + year_name + "/Beaufort_Sea_diffw0" + week_name + "y" + year_name + "+landmask";
			}
			else
			{
				// does not need 0 but just w to call directory location

				data_input = "CS310_project_subregion/" + year_name + "/Beaufort_Sea_diffw" + week_name + "y" + year_name + "+landmask";
			}

			//opens a file of type binary to read the data from directory

			ifstream input(data_input, std::ios::in | std::ios::binary);

			//multiple files opened

			if (input.is_open())
			{
				//the decimal values are entered as a linked list into an array 63 by 63

				for (int x = 0; x < 63; x++)
				{

					for (int y = 0; y < 63; y++)
					{

						input.read((char*)&dataIn, 4);

						float control = dataIn;

						//hold 832 empty values from each array location
						//which composes of individual node with data inside

						array[x][y].one_node[one_node_index].data = dataIn;

					}

				}

				//everytime a file is opened it then is closed

				input.close();

				//node height in incremented everytime that
				//data is inputed from each file with values

				one_node_index++;

			}

		}

	}

	//this calls a function to build three graphs of size

	struct Graph* graph1 = createGraph(3969);

	struct Graph* graph2 = createGraph(3969);

	struct Graph* graph3 = createGraph(3969);




	//this array hold the mean values of the data before
	//calculating a correlation with the array nodes

	struct Sum array_sum[63][63];

	//the linked list sum of the node data is processed only if the 
	//the land and missig values are ommited

	for (int g = 0; g < V_SIZE; g++)
	{

		for (int h = 0; h < V_SIZE; h++)
		{

			matrix1[g][h] = INF;
			matrix2[g][h] = INF;
			matrix3[g][h] = INF;

			if (g == h)
			{

				matrix1[g][h] = 0;
				matrix2[g][h] = 0;
				matrix3[g][h] = 0;
			}

			

		}

	}



	for (int g = 0; g < 63; g++)
	{

		for (int h = 0; h < 63; h++)
		{

			

			if (array[g][h].one_node->data != 168 && array[g][h].one_node->data != 157)
			{

				array_sum[g][h].S = S(array[g][h].one_node, 832).first;

				array_sum[g][h].mean = S(array[g][h].one_node, 832).second;

			}

			if (array[g][h].one_node->data == 168 || array[g][h].one_node->data == 157)
			{

				//land values are incremented to keep a counter to
				//remove from histogram

				land++;
				

			}

		}

	}

	//the data is inputed into a linked list if it meets threshold parameters from data correlation

	for (int k = 0; k < 63; k++)
	{

		for (int l = 0; l < 63; l++)
		{

			//position of the outside for loop

			int y = l;

			int control = k * 63 + l;

			for (int i = k; i < 63; i++)
			{

				//data values are ommited if they are equal to missign data or land values
				//in the first array node position

				if (array[k][l].one_node->data != 168 && array[k][l].one_node->data != 157)
				{

					//the nodes are compared one in front of the other and
					//not from the begining everytime

					for (int j = y + 1; j < 63; j++)
					{

						//linked list insertion factor to prevent data overlap

						int location = i * 63 + j;

						//data values are ommited if they are equal to missign data or land values
						//in the second array node position

						if (array[i][j].one_node->data != 168 && array[i][j].one_node->data != 157)
						{

							//the correlation coefficient based on mean values are computed




							float coefficient = correlationCoefficient(array[k][l].one_node, array[i][j].one_node, 832, array_sum[k][l].mean, array_sum[i][j].mean, array_sum[k][l].S, array_sum[i][j].S);

							//threshold is greater than or equal to 95% add edge to graph


							if (coefficient >= 0.95)
							{

								addEdge(graph1, control, location);

							}

							//threshold is greater than or equal to 92.5% add edge to graph


							if (coefficient >= 0.925)
							{

								addEdge(graph2, control, location);

							}

							//threshold is greater than or equal to 90% add edge to graph

							if (coefficient >= 0.90)
							{

								addEdge(graph3, control, location);

							}

						}


						//the node comparison get reseted to start from beggining
						//of the array



					}
					y = -1;

				}


			}

		}

	}


	//prints the histogram degree distribution

	cout << "******************************************************************" << endl;

	cout << "DEGREE HISTOGRAM 0.95 THRESHOLD (DEG VS #) - VISUAL & QUANTITATIVE" << endl;

	cout << "******************************************************************" << endl;

	printGraph(graph1, 0);
	thread th1(floydWarshall, matrix1, 0);


	cout << endl;

	cout << "*******************************************************************" << endl;

	cout << "DEGREE HISTOGRAM 0.925 THRESHOLD (DEG VS #) - VISUAL & QUANTITATIVE" << endl;

	cout << "*******************************************************************" << endl;

	printGraph(graph2, 1);
	thread th2(floydWarshall, matrix2, 1);


	cout << endl;

	cout << "******************************************************************" << endl;

	cout << "DEGREE HISTOGRAM 0.90 THRESHOLD (DEG VS #) - VISUAL & QUANTITATIVE" << endl;

	cout << "******************************************************************" << endl;

	printGraph(graph3, 2);
	thread th3(floydWarshall, matrix3, 2);


	cout << endl;

	cout << "*************************************************" << endl;

	cout << "     CONNECTED COMPONENTS 0.95 THRESHOLD" << endl;

	cout << "*************************************************" << endl;

	//prints the connected componets in the graph

	connectedComponents(graph1);
	

	cout << endl;

	cout << "*************************************************" << endl;

	cout << "     CONNECTED COMPONENTS 0.925 THRESHOLD" << endl;

	cout << "*************************************************" << endl;

	connectedComponents(graph2);
	

	cout << endl;

	cout << "*************************************************" << endl;

	cout << "      CONNECTED COMPONENTS 0.90 THRESHOLD" << endl;

	cout << "*************************************************" << endl;

	connectedComponents(graph3);

	cout << endl;

	cout << "***********************************" << endl;

	cout << "CORRELATION CLUSTERING COEFFICIENTS" << endl;

	cout << "***********************************" << endl;

	cout << "THRESHOLD 0.95  : ";
	clustering_coefficient(graph1);
	cout << "THRESHOLD 0.925 : ";
	clustering_coefficient(graph2);
	cout << "THRESHOLD 0.90  : ";
	clustering_coefficient(graph3);

	cout << endl;

	

	cout << "**************************" << endl;

	cout << " CORRELATION PATH LENGTHS" << endl;

	cout << "**************************" << endl;


	th1.join();
	th2.join();
	th3.join();



	cout << "THRESHOLD 0.95  : ";
	cout << PathLength[0] << endl;
	cout << "THRESHOLD 0.925 : ";
	cout << PathLength[1] << endl;
	cout << "THRESHOLD 0.90  : ";
	cout << PathLength[2] << endl;



	


	cout << endl;
	cout << "************************************" << endl;

	cout << "RANDOM GRAPHS CLUSTERING COEFFICIENT" << endl;

	cout << "************************************" << endl;

	cout << "THRESHOLD 0.95  : "<< random_clustering_coefficient[0] <<endl;
	cout << "THRESHOLD 0.925 : " << random_clustering_coefficient[1] << endl;
	cout << "THRESHOLD 0.90  : " << random_clustering_coefficient[2] << endl;

	cout << endl;


	cout << "**************************" << endl;

	cout << "RANDOM GRAPHS PATH LENGTHS" << endl;

	cout << "**************************" << endl;

	cout << "THRESHOLD 0.95  : " << path_length[0] << endl;
	cout << "THRESHOLD 0.925 : " << path_length[1] << endl;
	cout << "THRESHOLD 0.90  : " << path_length[2] << endl;

	
	



}

int main()
{

	//the functions all called using main and are process in this way
	//to prevent data corruption and minimize erros
	read();



	
	
	


}











