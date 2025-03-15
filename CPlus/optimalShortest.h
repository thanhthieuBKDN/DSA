#include <iostream>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <list>
#include <unordered_map>
#include <unordered_set>
//Approach:
// 1 use queue to store the nodes
// 2 use a vector to store the distance of each node from the source
// 3 keep track of the visited nodes
// BFS that not only traverses the
// graph but also keeps track of each vertex’s predecessor . 

/*
Target:
    find shortest path with adj list
    find shortest path with adj maxtrix
*/
namespace G2 {
    using namespace std;

    class UnWeightGraph {
        public:
            int m_vertex;
            std::unordered_map<int, std::list<int>> adjList;
            UnWeightGraph(int v) {
                this->m_vertex = v;
                for (int i = 0; i < v; i++) {
                    addVertex(i);
                }
            }
            void addEdge(int u, int v) {
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
            void addVertex(int v) {
                if (adjList.find(v) == adjList.end())
                    adjList[v] = std::list<int>();
            }
          
    };

    std::vector<int> constructPath(int endVertex, std::unordered_map<int, int>& predecessors) {
        std::vector<int> path;
        for (int vertex = endVertex; vertex != -1; vertex = predecessors[vertex]) {
            path.push_back(vertex);
        }
        std::reverse(path.begin(), path.end()); // Reverse to get the correct order
        return path;
    }

    vector<int>  findShortestPath( std::unordered_map<int, std::list<int>> adjList, int start, int end) {
        //implement BFS to tralverse
        //keep track of vertex's predecessor
        std::priority_queue<int, std::vector<int>, std::greater<int>> queue;
        std::unordered_map<int, int> predecessors;
        std::unordered_set<int> visited;

        queue.push(start);
        visited.insert(start);
        predecessors[start] = -1;
        while ( !queue.empty()) {
            int current = queue.top();
            queue.pop();
            if (current == end) {
                return constructPath(end, predecessors);
                //return result
            }
            for (int next : adjList[current]) {
                //Check visited
                //if not visited, add to queue and mark as visited
                //keep track of the predecessor
                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    queue.push(next);
                    predecessors[next] = current;
                }
            }
        }
        return {};

    }

    

    void run() {
        cout << "Hello from G1" << endl;
        UnWeightGraph g(5);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.addEdge(2, 3);
        g.addEdge(3, 4);
        vector<int> v = findShortestPath(g.adjList, 4, 0);
        for (int i : v) {
            cout << i << " ";
        }

    }
}