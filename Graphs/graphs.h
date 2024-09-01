#ifndef Graph_H
#define Graph_H

#include <vector>
#include <queue>
#include <functional>
#include <iostream>

using namespace std;

int dfs_timer = 0;
const int INF = 1000000000;

// All credit goes to https://cp-algorithms.com/ 
// Only modified or added extra steps 

void dfs(int v, vector<bool>& visited, vector<vector<int>>& adj) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u, visited, adj);
        }
    }
}

void dfs_color(int v, vector<bool>& visited, vector<vector<int>>& adj, 
                vector<int>& time_in, vector<int>& time_out, vector<int>& color) {
    time_in[v] = dfs_timer++;
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            dfs_color(u, visited, adj, time_in, time_out, color);
        }
    }
    color[v] = 2;
    time_out[v] = dfs_timer++;
}

void bfs(int s, vector<vector<int>>& adj, vector<bool>& used, vector<int>& d, 
            vector<int>& p, bool print_path = false, int t = 0) {
    queue<int> q;
    q.push(s);
    used[s] = true;
    p[s] = -1;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u : adj[v]) {
            if (!used[u]) {
                q.push(u);
                used[u] = true;
                p[u] = v;
                d[u] = d[v] + 1;
            }
        }
    }

    if (print_path) {
        if (!used[t]) {
            cout << "No path!";
        } else {
            vector<int> path;
            for (int v = t; v != -1; p[v]) {
                path.push_back(v);
            }
            reverse(path.begin(), path.end());
            cout << "Path: ";
            for (int v : path) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
}


void topological_sort(int v, int n, vector<bool>& visited, vector<vector<int>>& adj, vector<int> topo) {
    topo.clear();

    function<void(int)> dfs_ = [&](int u) {
        visited[u] = true;
        for (int w : adj[u]) {
            if (!visited[w]) {
                dfs_(w);
            }
        }
        topo.push_back(u);
    };

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs_(i);
        }
    }
    reverse(topo.begin(), topo.end());
} 

void dijkstra(int s, vector<vector<pair<int, int>>>& adj, vector<int>& d, vector<int>& p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n , -1);
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v])) v = j;
        }

        if (d[v] == INF) break;
        u[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}

void dijkstra_2(int start, vector<vector<pair<int,int>>>& neighbors, vector<long long>& dist) {
    using T = pair<long long, int>; 
    priority_queue<T, vector<T>, greater<T>> pq; 
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        const auto [cdist, node] = pq.top(); pq.pop();
        if (cdist != dist[node]) {continue;}
        for (const auto& i : neighbors[node]) {
            if (cdist + i.second < dist[i.first]) {
                dist[i.first] = cdist + i.second;
                pq.push({dist[i.first], i.first});
            }
        }
    }
}

#endif // Graph_H