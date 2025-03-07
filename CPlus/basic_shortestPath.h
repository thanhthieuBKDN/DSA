#include <iostream>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
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
namespace G1 {
    using namespace std;

    class UnWeightGraph {
        public:
            int m_vertex;
            vector< vector<int> > adj;
            UnWeightGraph(int v) {
                this->m_vertex = v;
                for (int i = 0; i < v; i++) {
                    adj.emplace_back();
                }
            }
            void addEdge(int u, int v) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            void addVetex() {
                m_vertex++;
                adj.emplace_back();
            }
    };

    void findShortestPath(vector< vector<int> > adj, int start, int end) {
        //implement BFS to tralverse
        //keep track of vertex's predecessor
        std::queue<int> queue;
    }

    

    void run() {
        cout << "Hello from G1" << endl;

    }
}