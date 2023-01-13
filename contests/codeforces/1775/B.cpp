#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	vector<int> cnt(200005);
	while (T--) {
		int n; cin >> n;
		vector<vector<int>> toggled(n);
		for (int i = 0; i < n; i++) {
			int k; cin >> k;
			toggled[i] = vector<int>(k);
			for (auto& x : toggled[i]) {
				cin >> x;
				cnt[x]++;
			}
		}
		bool sat = false;
		for (int i = 0; i < n; i++) {
			bool temp = true;
			for (auto p : toggled[i]) {
				if (cnt[p] == 1) temp = false;
			}
			 if (temp) sat = true;
		}
		cout << (sat ? "Yes" : "No") << "\n";
		for (int i = 0; i < n; i++) {
			for (auto p : toggled[i]) {
				cnt[p] = 0;
			}
		}
	}

	return 0;
}
