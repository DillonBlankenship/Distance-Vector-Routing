#include <iostream>
#include <vector>


namespace DV_Sim {
	using std::vector;
	class DistanceVector;
	class Network;


	class Node
	{
	public:
		
		//vals
		int id;
		DistanceVector * dv;
		vector<Node> links;
		
		Node(int id);
		void PrintLinks();
		void SetUpDV(Network * net);
		void Flood(Network * net);
		
	private:
		
	};



	class Edge
	{
	public:
		Edge(Node*, Node*, int);
		Node GetNodeA();
		Node GetNodeB();
		int GetCost();
		std::string Stringify();

	private:
		Node* A;
		Node* B;
		int cost;
	};
	
	class Network 
	{

	public: 
		Network(vector<Edge> edges, int);
		bool NodeInNetwork(int nodeID);
		void PrintNetwork();
		
		//vars
		bool converged = false;
		int roundsTaken = 0;
		int lastNodeIDConverged = -1;
		int ** table;
		

		//getters
		size_t GetNetworkSize();	//return size
		Node GetNode(int id);
		vector<Node> GetNetworkList();	//return list
		int GetCost(int x, int y);

	private: 
		//var
		int rounds;
		
		//containers
		vector<Edge> edges;
		vector<Node> network;
		
		int GetNodePositionByID(int id);
		void SortNetwork();
		void swap(Node *xp, Node *yp);
		void SetUpDV();
		void FloodRoutingTables();
		void PrintRoutingTables();
	};
	
	class DistanceVector
	{

	public:
		//vars
		Node * source;
		bool ** converged;
		int * shortestPath;
		

		//DistanceVector();
		DistanceVector(Network * routingNetwork, Node * source);
		void CalculateShortestPath(Node source);
		void PrintStats();
		void Update(DistanceVector * packet);
		

	private:
		//private vasr
		Network* net;
		int nodeCount;
		int numberConverged;
	
		void InitializeTable();
		bool CheckConvergence();
	
	};
}
