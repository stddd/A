#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Data structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Data structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Comparator function to sort edges based on their weight
bool compareEdges(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

// Utility function to find the set of an element `i`
int find(vector<Subset> &subsets, int i) {
    cout<<"find "<<subsets[i].parent<<" i"<<i<<"\n";
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// Utility function to perform union of two subsets
void Union(vector<Subset> &subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Attach smaller rank tree under root of high rank tree (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to find the minimum spanning tree using Kruskal's algorithm
void KruskalMST(vector<Edge> &edges, int V) {
    // Sort all the edges in non-decreasing order of their weight
    sort(edges.begin(), edges.end(), compareEdges);

    vector<Edge> result(V); // To store the resultant MST
    int e = 0; // An index variable, used for result[]

    // Allocate memory for creating V subsets
    vector<Subset> subsets(V);

    // Initialize subsets with single elements
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && !edges.empty()) {
        // Pick the smallest edge
        
        Edge next_edge = edges.back();
        edges.pop_back();

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge doesn't cause cycle, include it in result and increment the index of result for next edge
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    // Print the edges of MST
    cout << "Edges of MST using Kruskal's algorithm:\n";
    for (int i = 0; i < e; i++) {
        cout << result[i].src << " - " << result[i].dest << " with weight " << result[i].weight << endl;
    }
}

int main() {
    // Example graph
    int V = 4; // Number of vertices
    vector<Edge> edges = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};

    // Find the MST using Kruskal's algorithm
    KruskalMST(edges, V);

    return 0;
}