#include <iostream>
#include "DV_Sim.h"
#include <string>
namespace DV_Sim {
	
	
	Edge::Edge(Node *A = 0, Node *B = 0, int cost = 0)
	{
		this->A = A;
		this->B = B;
		this->cost = cost;
	}

	Node Edge::GetNodeA()
	{
		return *A;
	}


	Node Edge::GetNodeB()
	{
		return *B;
	}
	
	int Edge::GetCost()
	{
		return cost;
	}

	std::string Edge::Stringify()
	{
		using namespace std;
		string s;
		
		s = "Node: " + to_string(A->id) + '\n';
		s += "Node: " + to_string(B->id) + '\n';
		s += "Cost: " + to_string(cost) + '\n';
		
		return s;
	}
}