#include <iostream>
#include "DV_Sim.h"
#include <string>
#include <vector>
#include <algorithm> 

namespace DV_Sim {


	Network::Network(vector<Edge> edges, int rounds)
	{

		this->rounds = rounds;

		for (size_t i = 0; i < edges.size(); i++) {
			//returns a new object of node a rather than a point to edge's node A
			Node A = edges[i].GetNodeA();
			Node B = edges[i].GetNodeB();

			if (!NodeInNetwork(A.id)) {
				network.push_back(A);
			}
			if (!NodeInNetwork(B.id)) {
				network.push_back(B);
			}


			//after pushing nodes a and b into the network node list, need to add links to each node
			network[GetNodePositionByID(A.id)].links.push_back(B);
			network[GetNodePositionByID(B.id)].links.push_back(A);

			this->edges = edges;


		}
		//debugs
		//std::cout << this->edges[0].Stringify();
		
		//sort network vector by ascending order of node ID
		SortNetwork();

		//main functions
		SetUpDV();
		//main function that fills out table
		FloodRoutingTables();
		PrintRoutingTables();



	}

	bool Network::NodeInNetwork(int nodeID) {
		for (size_t i = 0; i < network.size(); i++) {
			if (network[i].id == nodeID) {
				return true;
			}
		}

		//node not in list
		return false;

	}

	size_t Network::GetNetworkSize()
	{
		return network.size();
	}

	Node Network::GetNode(int id)
	{
		return network[id];

	}

	vector<Node> Network::GetNetworkList()
	{
		return network;
	}

	int Network::GetCost(int x, int y)
	{
		for (size_t i = 0; i < edges.size(); i++) {
			int aID = edges[i].GetNodeA().id;
			int bID = edges[i].GetNodeB().id;

			if (aID == x && y == bID)
				return edges[i].GetCost();

			if (bID == x && y == aID)
				return edges[i].GetCost();
		}

		std::cerr << '\n' << "Warning, no edge with a cost matching " << x << " and " << y << " was found.";
		return 0;
	}

	void Network::PrintNetwork() {
		using namespace std;
		cout << "Network size: " << network.size() << endl;
		for (size_t i = 0; i < network.size(); i++) {
			cout << network[i].id << endl;
		}

	}



	int Network::GetNodePositionByID(int id) {
		for (size_t i = 0; i < network.size(); i++) {
			if (network[i].id == id) {
				return i;
			}
		}

		//not found
		return -1;

	}

	void Network::SortNetwork()
	{

		for (int i = 0; i < network.size() - 1; i++)

			// Last i elements are already in place  
			for (int j = 0; j < network.size() - i - 1; j++)
				if (network[j].id > network[j + 1].id)
				{
					swap(&network[j], &network[j + 1]);
				}


	}

	void Network::swap(Node *xp, Node *yp)
	{
		Node temp = *xp;
		*xp = *yp;
		*yp = temp;
	}

	void Network::SetUpDV()
	{
		for (size_t i = 0; i < network.size(); i++) {
			network[i].SetUpDV(this);
		}
	}

	void Network::FloodRoutingTables()
	{
		for (int i = 0; i < rounds; i++) {
			if (converged) {
				roundsTaken = i;
				return;
			}
		
			for (size_t n = 0; n < GetNetworkSize(); n++) {
				//node n sends a dvpacket to neighbors
				network[n].Flood(this);
			}

			if (!converged) {
				roundsTaken++;
			}

		}

	}

	void Network::PrintRoutingTables() {
		for (size_t id = 0; id < network.size(); id++) {
			network[id].dv->PrintStats();
		}

	}

	

}
	 


