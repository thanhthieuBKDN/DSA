#include <iostream>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <string>
#include "basic_shortestPath.h"
using namespace std;


int main() {
    std::cout << "Hello, World!" << std::endl;

    int s = 0;
    vector < vector <int> > graph1 = {
        {0, 6, 0, 1, 0},
        {6, 0, 5, 2, 2},
        {0, 5, 0, 0, 5},
        {1, 2, 0, 0, 1},
        {0, 2, 5, 1, 0}
    };
    G1::run();
    //findShortTestPath(graph1, s);
    return 0;
}