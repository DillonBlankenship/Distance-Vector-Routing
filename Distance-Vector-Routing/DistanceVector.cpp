#include "DV_Sim.h"
#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib> 
namespace DV_Sim{

	DistanceVector::DistanceVector(Network * net, Node * source)
	{
		//assign class variables
		this->net = net;
	    nodeCount = net->GetNetworkSize();
		this->source = source;
		shortestPath = new int[nodeCount];
		
		//construct 2d array table for converted
		converged = new bool*[nodeCount];
		for (int i = 0; i < nodeCount; i++)
			converged[i] = new bool[nodeCount];

		
		//set distances to all other nodes to infinity
		InitializeTable();
		

		//store initial distances
		for (size_t i = 0; i < source->links.size(); i++) {
			int link = source->links[i].id;
			int cost = net->GetCost(source->id, link);
			shortestPath[source->links[i].id] = cost;
		}

		shortestPath[source->id] = 0;
	}

	//calcuate shortest from source node to all other nodes in network
	void DistanceVector::CalculateShortestPath(Node source)
	{
		
		
		
		
		
		
		
		
		
		
		
		
		//int cost = net->GetCost(3,4);
		//std::cout << "Cost from 4 to 3: " << cost;
		
		/*
		const int sID = source.id;
		
		size_t numNode = net->GetNetworkSize();
		int start = source.id;
		int lowestCost = std::numeric_limits<int>::max();
		int lowestCostIndex = -1;
		
		for (size_t i = 0; i < 900; i++) {
			for (size_t n = 0; n < net->GetNode(start).links.size(); n++) {
				int linkedNode = net->GetNode(start).links[n].id;
				int cost = net->GetCost(start, linkedNode);
				if (table[sID][start] + cost < table[sID][linkedNode]) {
					table[sID][linkedNode] = table[sID][start] + cost;
			
					if (table[sID][linkedNode] < lowestCost) {
						lowestCost = table[sID][linkedNode];
						lowestCostIndex = linkedNode;
					}

				}
				
			}

			start = lowestCostIndex;
		}
		
		//old part
		for (size_t i = 0; i < count; i++) {
			//get current shortest distance from packet node to all other nodes in network
			int toCost = packet->shortestPath[i];
			cout << "ToCost from node " << packet->source->id << " to node "  << i << ": "<< toCost << endl;
			if (toCost != 0) {
				int newCost = packet->shortestPath[i] + net->GetCost(source->id, packet->source->id);
				cout << "newCost from node " << packet->source->id << ": " << newCost << endl;
				if (table[via][i] == newCost) {
					numberConverged++;
					converged[via][i] = true;
				}
				else {
					numberConverged--;
					table[via][i] = newCost;
				}

			}
		}

		if (CheckConvergence())
			net->converged = true;
		*/
	}

	
	void DistanceVector::InitializeTable()
	{
		//set each entry in table to infinity 
		for (int r = 0; r < nodeCount; r++) {
			shortestPath[r] = std::numeric_limits<int>::max();
		}
		
	
	}
	
	void DistanceVector::PrintStats() {
		using namespace std;
		cout << "Print column results for Node " << net->GetNode(source->id).id << ": ";
		for (int to = 0; to < nodeCount; to++) {
			cout << shortestPath[to] << '\t';

		}

		cout << endl;
	}

	bool DistanceVector::CheckConvergence() {
		size_t size = net->GetNetworkSize();
		for (size_t r = 0; r < size; r++) {
			for (size_t c = 0; c < size; c++) {
				if (!converged[r][c])
					return false;
			}
		}

		return true;

	}

	void DistanceVector::Update(DistanceVector * packet)
	{
		using namespace std;
		int via = packet->source->id;
		size_t linkedNodesCount = packet->source->links.size();

		for (size_t i = 0; i < linkedNodesCount; i++) {
			int nodeLink = packet->source->links[i].id;
			int cost = packet->shortestPath[nodeLink] + shortestPath[packet->source->id];
			if (cost < shortestPath[nodeLink]) {
				shortestPath[nodeLink] = cost;
			}
		}
		
	}
	




}