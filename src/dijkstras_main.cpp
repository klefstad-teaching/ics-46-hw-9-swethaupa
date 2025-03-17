#include <iostream>
#include <vector>
#include <string>
#include "dijkstras.h"

using namespace std;

int main() {
    string filename = "small.txt";
    Graph G;
    
    try {
        file_to_graph(filename, G);
    } catch (const exception& e) {
        cerr << "Error"<< endl;
        return 1;
    }

    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);
    
    for (int i = 0; i < G.numVertices; i++) {
        cout << "node " << i << ": ";
        print_path(extract_shortest_path(distances, previous, i), distances[i]);
    }
    
    return 0;
}
