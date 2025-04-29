#include <bits/stdc++.h>
using namespace std;

int mst(int v, int e, vector<vector<pair<int, int>>>& adj){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    vector<int> visited(v, 0);
    int cost = 0;

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        int weight = it.first;
        int node = it.second;

        if(visited[node] == 1) continue;

        visited[node] = 1;
        cost += weight;

        for(auto it: adj[node]){
            int adjNode = it.first;
            int edgeWeight = it.second;

            if(visited[adjNode] == 0){
                pq.push({edgeWeight, adjNode});
            }
        }
    }

    return cost;
}

void createAdjacencyList(int v, int e, vector<vector<int>>& edges, vector<vector<pair<int, int>>>& adj) {
    for (int i = 0; i < e; i++) {
        int node1 = edges[i][0];
        int node2 = edges[i][1];
        int edgeWeight = edges[i][2];

        adj[node1].push_back({node2, edgeWeight});
        adj[node2].push_back({node1, edgeWeight});
    }
}

int main() {
    int v = 5;
    int e = 6;

    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 2, 1},
        {1, 2, 1},
        {2, 3, 2},
        {2, 4, 2},
        {3, 4, 1}
    };

    vector<vector<pair<int, int>>> adj(v); 
    createAdjacencyList(v, e, edges, adj);
    int cost = mst(v, e, adj);

    cout << cost << endl;

    return 0;
}
