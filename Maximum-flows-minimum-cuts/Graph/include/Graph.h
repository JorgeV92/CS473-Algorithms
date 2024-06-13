// Graph.h
// template for int : float 

#ifndef GRAPH_H
#define GRAPH_H


#include <vector>
#include <list>
#include <utility> 	// for std::pair

namespace graph {

	template <typename T>
	class Graph {
	public:
		Graph() { adjList.resize(20)} ;		//  initialize size of 20 vertices
		Graph(int n) {adjList.resize(n) };	// intialize size with n vertices	
		void addEdge(int u, int v, T w, bool directed = false) {
			adjList[u].push_back(std::make_pair(v, w));
			if (!directed) {
				adjList[v].push_back(std::make_pair(u, w));
			}
		}
		constexpr std::list<std::pair<int, T>>& getAdjList(int u) const {
			return adjList[u];
		}
		int E() {};
		int V() { return adjList.size() };
		void printGraph() {
			int v = 0;
			for (auto& neighbors : adjList) {
				std::cout << "Node " << v << ";";
				for (auto& pair : neighbors) {
					std::cout << "(to " << pair.first << " with wieght " << pair.second << ")";
				}
				std::cout << std::endl;
				v++;
			}
		}
	private:
		std::vector<std::list<std::pair<int, T>>> adjList;

	};

}

#endif // GRAPH_H
