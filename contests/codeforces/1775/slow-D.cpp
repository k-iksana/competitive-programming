#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Graph {
        struct Edge {
                int from, to; 
                T weight;
                Edge(int _from, int _to, T _weight) : from(_from), to(_to), weight(_weight) {};
        };
        int n; 
        int idx = 0;
        vector<vector<int>> adj;
        Graph(int _n) : n(_n) {
		adj.resize(n);
	};
        void add_directed_edge(int from, int to, T weight = 1) {
                adj[from].push_back(to);
        }
        void add_undirected_edge(int from, int to, T weight = 1) {
                add_directed_edge(from, to, weight);
                add_directed_edge(to, from, weight);
        }
	int bfs(int s, int t) {
		vector<bool> seen(n);
		vector<int> dist(n, 1e9);
		queue<int> q;
		dist[s] = 0;
		q.push(s);
		while (!q.empty()) {
			 int u = q.front(); q.pop();
			 if (seen[u]) continue;
			 seen[u] = true;
			 for (auto v : adj[u]) {
				if (!seen[v]) {
					q.push(v);
				}
				if (dist[v] > dist[u] + 1) {
					dist[v] = dist[u] + 1;
				}
			 }
		}
		return dist[t] == 1e9 ? -1 : dist[t] + 1;
	}
};

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n);
	for (auto& x : a) cin >> x;
	int s, t;
	cin >> s >> t; --s; --t;
	Graph<int> graph(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (gcd(a[i], a[j]) >= 2) {
				graph.add_undirected_edge(i, j);
			}
		}
	}
	cout << graph.bfs(s, t) << "\n";

	return 0;
}
