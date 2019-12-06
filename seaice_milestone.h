#pragma once
//storage
struct node
{
	float data;
};
struct node_data
{
	//week allWeeks[832]; //height third dimension
	node* one_node = new node[832];
};
//actual graph for conections
struct graph
{
	float array[63][63];
};
struct Node
{
	int vertex;
	struct Node* next;
};
struct Node* createNode(int);
struct Graph
{
	int numVertices;
	struct Node** adjLists;
};
struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);
struct Sum
{
	float S;
	float mean;
};
//week name = new week();
//node node_name = new node();
//all_weeks total = new all_weeks();