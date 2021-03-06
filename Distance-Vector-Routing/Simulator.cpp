//author Elijah Gaytan
//net id: e_g641
// CS4310 Project 1 
// cs4310p1.cpp : This file contains the 'main' function. Program execution begins and ends there.

//includes
#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include "DV_Sim.h"
#include <sstream>
#include <cstdlib> 

//namespaces used
using namespace std;
using namespace DV_Sim;

void PrintContentsofVector(vector<string>);
vector<Edge> ParseEdges(vector<string>);

int rounds;
string path;

int main(int argc, char* argv[])
{
	using namespace DV_Sim;
	if (argc != 3) {
		cerr << "invalid number of args detected, should be name of topology file followed by number of rounds.";
		return 1;
	}
	
	vector<string> edges;
	ifstream ifs;
	
	//convert args
	path = argv[1];
	rounds = stoi(argv[0]);

	cout << path << endl;
	cout << rounds << endl;

	ifs.open(path);
	if (ifs.is_open())
	{
		string line;
		while (getline(ifs, line))
		{
			edges.push_back(line);
		}
		ifs.close();
	}

	//PrintContentsofVector(edges);
	
	vector<Edge> networkEdges = ParseEdges(edges);
	Network * routingNetwork = new Network(networkEdges, 1);
	
}

vector<Edge> ParseEdges(vector<string> stringVector) {
	vector<Edge> network;
	//read through each line (edge) in vector and parse it
	for (size_t i = 0; i < stringVector.size(); i++) {
		
		int edge[3];
		stringstream ss(stringVector[i]);
		string token;
		int pos = 0;
		while (getline(ss, token, '\t')) 
		{
			//string to int
			edge[pos] = stoi(token);
			//cout << edge[pos] << endl;
			pos++;
			
		}

		//set up edge contents
		Node * A = new Node(edge[0]);
		Node * B = new Node(edge[1]);
		int cost = edge[2];

		Edge newEdge(A, B, cost);
		network.push_back(newEdge);

		
	}

	return network;
}

void PrintContentsofVector(vector<string> v) {
	for (int i = 0; i < static_cast<int>(v.size()); i++) {
		cout << v[i] + "\n";
	}
}


