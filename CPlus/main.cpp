#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include "optimalShortest.h"
#include <climits>
using namespace std;

class Node {
    public:
        int vertex;
        int weight;
        Node(int v, int w) : vertex(v), weight(w) {
            std::cout << "vertex " << vertex << " weight " << weight << '\n';
        }
        bool operator > (const Node &otherNode) const {
            return weight > otherNode.weight;
        }
};

void printSolution(const std::vector<int>& distances) {
    std::cout << "Vertex\t| Distance from Source" <<
    std::endl;
    for (int i = 0; i < distances.size(); i++) {
        std::cout << i << "\t|\t" 
            << (distances[i] == INT_MAX ? "INF" : std::to_string(distances[i])) <<
        std::endl;
    }
}

void Dijkstra(const vector< vector<int> > &graph, int source) {
    
    vector <bool> visited(graph.size(), false);
    vector <int> distances(graph.size(), INT_MAX);
    priority_queue< Node, vector<Node>, greater<Node> > queue;

    distances[source] = 0;
    queue.emplace(Node(source, 0));
    while( !queue.empty() ) {
        Node current = queue.top();
        queue.pop();

        int current_vertex = current.vertex;
        if(visited[current_vertex]) 
        {
            continue;
        }
        visited[current_vertex] = true;
        for ( int i = 0; i < graph.size(); i++ ) {
            if(graph[current_vertex][i] > 0 && !visited[i]) {
                int newDist = distances[current_vertex] + graph[current_vertex][i]; //he quy chieu
                if (newDist < distances[i]) {
                    distances[i] = newDist;
                    queue.emplace(Node(i, distances[i]));
                }
            }
        }

    }
    printSolution(distances);
}
int main() {
    
   int source = 0;
    std::vector<std::vector<int>> graph = {
    {0, 6, 0, 1, 0},
    {6, 0, 5, 2, 2},
    {0, 5, 0, 0, 5},
    {1, 2, 0, 0, 1},
    {0, 2, 5, 1, 0}
    };
    Dijkstra(graph, source);



    return 0;
}