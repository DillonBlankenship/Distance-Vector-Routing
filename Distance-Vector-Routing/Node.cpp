#include "DV_Sim.h"
#include <iostream>
#include <vector>


namespace DV_Sim {
	
	Node::Node(int id) {
		this->id = id;
	}

	void Node::PrintLinks()
	{
		using namespace std;
		for (size_t i = 0; i < links.size(); i++) {
			cout << id << " connects to " << links[i].id << endl;
		}

		

	}

	
	void Node::SetUpDV(Network * net)
	{
		const size_t size = net->GetNetworkSize();
		
		dv = new DistanceVector(net, this);

	}

	void Node::Flood(Network * net)
	{
		//search through all links and have them fire their dvpackets
		for (size_t i = 0; i < links.size(); i++)
		{
			dv->Update(net->GetNode(links[i].id).dv);
		}

	}

	



}