#include <iostream>
#include <set>
#include <vector>
#include "ladder.h"

using namespace std;

int main() {
    string filename = "small.txt";
    
    Graph G;
    file_to_graph(filename, G);
    
    int source = 0;
    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, source, previous);
    
    for (int i = 0; i < G.numVertices; i++) {
        cout << "To node " << i << ": ";
        print_path(extract_shortest_path(distances, previous, i), distances[i]);
    }
    
    return 0;
}
