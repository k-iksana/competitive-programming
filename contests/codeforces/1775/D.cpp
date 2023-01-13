#include <bits/stdc++.h>

namespace sieve {

using std::vector;
using std::pair;
using std::min;
using std::iota;

vector<int> primes;
vector<int> sdiv;

void init(int n) {
	sdiv.resize(n, 1);
	iota(sdiv.begin(), sdiv.end(), 0);
	for (long long i = 2; i < n; i++) {
		if (sdiv[i] == i) {
			primes.push_back(i);
			for (long long j = i * i; j < n; j += i) {
				sdiv[j] = min(sdiv[j], (int) i);
			}
		}
	}
}

vector<pair<int, int>> factor(int x) {
	vector<pair<int, int>> pfactors;
	while (x > 1) { 
		int p = sdiv[x], cnt = 0;
		while (x % p == 0) {
			x /= p;
			cnt++;
		}
		pfactors.emplace_back(p, cnt);
	}
	return pfactors;
}

vector<int> prime_factors(int x) {
	vector<pair<int, int>> pfactors = factor(x);
	vector<int> unq_factors;
	for (auto& [p, f] : pfactors) {
		unq_factors.push_back(p);
	}
	return unq_factors;
}

bool is_prime(int x) {
	return sdiv[x] == x;
}

} // namespace sieve

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	sieve::init(300005);

	int m = sieve::primes.size();
	int N = 2 * m + 5;
	vector<vector<pair<int, int>>> adj(N);

	int n; cin >> n;
	vector<int> a(n);
	for (auto& x : a) cin >> x;
	int s, t;
	cin >> s >> t; --s; --t;
	
	if (s == t) {
		cout << 1 << "\n";
		cout << s + 1 << "\n";
		return 0;
	} else if (gcd(a[s], a[t]) > 1) {
		cout << 2 << "\n";
		cout << s + 1 << " " << t + 1 << "\n";
		return 0;
	}

	map<int, int> mp;
	int idx = 0;
	for (auto p : sieve::primes) {
		mp[p] = idx;
		idx++;
	}

	vector<vector<int>> factors(n);
	for (int i = 0; i < n; i++) {
		auto res = sieve::factor(a[i]);
		for (auto [p, x] : res) {
			factors[i].push_back(p);
		}
		for (int j = 0; j < (int) factors[i].size(); j++) {
			for (int k = 0; k < j; k++) {
				int p1 = factors[i][j], p2 = factors[i][k];
				adj[mp[p1] + m].emplace_back(mp[p2], i);
				adj[mp[p2] + m].emplace_back(mp[p1], i);
			}
		}
	}

	for (int i = 0; i < m; i++) {
		adj[i].emplace_back(i+m, -1);
	}

	queue<int> q;
	vector<bool> seen(N, false);
	vector<int> dist(N, 1e9);
	vector<pair<int, int>> prev(N, {-1, -1});
	dist[N-1] = 0;
	prev[N-1] = {-1, N-1};

	for (auto p : factors[s]) {
		adj[N-1].emplace_back(mp[p], s);
	}

	q.push(N-1);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (seen[u] == true) continue;
		seen[u] = true;
		for (auto [v, id] : adj[u]) {
			if (dist[v] > dist[u] + 1) {
				prev[v] = {u, id};
				dist[v] = dist[u] + 1;
			}
			if (!seen[v]) q.push(v);
		}
	}

	int mn = 1e9;
	int lst = -1;
	for (auto p : factors[t]) {
		int idx = mp[p]+m;
		if (dist[idx] < mn) {
			mn = dist[idx];
			lst = mp[p]+m;
		}
	}
	if (mn == 1e9) cout << -1 << "\n";
	else {
		vector<int> path = {t};
		for (int p = lst; p != -1;) {
			if (prev[p].second != -1 && prev[p].second != N - 1) {
				path.push_back(prev[p].second);
			}
			p = prev[p].first;
		} 
		reverse(path.begin(), path.end());
		cout << (int) path.size() << "\n";
		for (int i = 0; i < (int) path.size(); i++) {
			cout << path[i] + 1 << (i == (int) path.size() - 1 ? '\n' : ' ');
		}
	}

	return 0;
}
