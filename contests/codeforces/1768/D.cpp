#include <bits/stdc++.h>
#include <atcoder/dsu>

int main() {
	using namespace std;
	using namespace atcoder;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<int> p(n);
		for (auto& x : p) { cin >> x; --x; }
		dsu d(n);
		vector<int> where(n);
		for (int i = 0; i < n; i++) {
			d.merge(p[i], i);
		}
		vector<vector<int>> g = d.groups();
		int moves = 0;
		for (auto v : g) {
			moves += (int) v.size() - 1;
		}
		int opt = moves + 1;
		for (int i = 0; i < n-1; i++) {
			if (d.same(i, i+1)) opt = moves - 1;
		}
		cout << opt << "\n";
	}
	

	return 0;
}
