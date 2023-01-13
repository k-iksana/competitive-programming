#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int n, k; 
		cin >> n >> k;
		vector<int> p(n);
		for (auto& x : p) cin >> x;
		int target = 1;
		for (int i = 0; i < n; i++) {
			if (p[i] == target) target++;
		}
		cout << (n - target + k) / k << "\n";
	}

	return 0;
}
