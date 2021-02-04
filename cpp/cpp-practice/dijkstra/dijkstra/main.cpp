//
//  main.cpp
//  dijkstra
//
//  Created by Yue Zhang on 23/1/21.
//

#include <iostream>
#include <vector>
using namespace std;
#define V 9

int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                    { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                    { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                    { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                    { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                    { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                    { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                    { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                    { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

vector<bool> visited(V, false);
vector<int> weights(V, INT_MAX);
vector<int> connects[V];

void dijkstra_algorithm(int start) {
    for (int i=0; i<V; ++i) {
        for (int j=0; j<V; ++j) {
            if (graph[i][j] > 0) {
                connects[i].push_back(j);
            }
        }
    }
        
    weights[start] = 0;
    int cnt = 0;
    int pos = start;
    while (find(visited.begin(), visited.end(), false) != visited.end()) {
        int min = INT_MAX;
        for (int i=0; i<weights.size(); ++i) {
            if (!visited[i] && weights[i] < min) {
                min = weights[i];
                pos = i;
            }
        }
        visited[pos] = true;
        int weight = weights[pos];
        for (int i=0; i<connects[pos].size(); ++i) {
            int to = connects[pos][i];
            if (!visited[to] && weight + graph[pos][to] < weights[to]) {
                weights[to] = weight + graph[pos][to];
            }
        }
        cnt++;
        cout << "iteration: " << cnt << " position: " << pos << endl;
    }
}

void printWeights() {
    for (int i=0; i<weights.size(); ++i) {
        printf("index %d has weights %d\n", i, weights[i]);
    }
}


int main() {
    // insert code here...
    dijkstra_algorithm(0);
    printWeights();
    
    return 0;
    
}
