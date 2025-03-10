#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Graph2 {
    public:
        vector< vector<int> >  adjMaxtrix;
        int m_vertex;
        Graph2(int v) {
            m_vertex = v;
            for (int i = 0; i < v; i++) {
                adjMaxtrix.emplace_back(v, 0);
            }
        }
        void addEdge(int i, int j) {
            adjMaxtrix[i][j] = 1;
            adjMaxtrix[j][i] = 1;
        }
        void addVertex() {
            m_vertex++;
            adjMaxtrix.emplace_back(m_vertex, 0);
            for (auto &i : adjMaxtrix) {
                i.push_back(0);
            }
        }

        void print() {
            for (auto &i : adjMaxtrix) {
                for (auto &j : i) {
                    cout << j << " ";
                }
                cout << endl;
            }
        }
    };

    vector <int> contrucPath(int end, unordered_map<int, int> &order) {
        vector <int> path;
        for (int i = end; i != -1; i = order[i]) {
            path.push_back(i);
        }
        reverse(path.begin(), path.end());
        return path;
        
    }
    vector<int> finsShortestPathAdjMaxtrix (const Graph2 &graph, int start, int end ) {
        //BFS traversal
        //Keep track of the predecessor
        //Keep track of the visited nodes
        queue <int> q;
        unordered_map<int, int> preVertex;
        vector<bool> visited (graph.m_vertex, false);

        const vector <vector<int>> &adjMaxtrix = graph.adjMaxtrix;

        q.push(start);
        visited[start] = true;
        preVertex[start] = -1;
        while( !q.empty() ) {
            int current = q.front();
            q.pop();
            if (current == end) {
                return contrucPath(end, preVertex);
            }

            for (int next = 0 ; next < graph.m_vertex; next++) {
                if (adjMaxtrix[current][next] != 0) {
                    if (visited[next] == false) {
                        q.push(next);
                        visited[next] = true;
                        preVertex[next] = current;
                    }
                }
            }
        }
        return {};
        
    }