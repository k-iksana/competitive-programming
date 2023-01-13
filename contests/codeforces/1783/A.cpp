#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<int> a(n);
		for (auto& x : a) cin >> x;
		sort(a.rbegin(), a.rend());
		if (a[n-1] == a[0]) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			vector<int> b(n);
			b[0] = a[n-1];
			b[1] = a[0];
			for (int i = 1; i < n-1; i++) {
				b[i+1] = a[i];
			}
			for (int i = 0; i < n; i++) {
				cout << b[i] << (i == n - 1 ? '\n' : ' ');
			}
		}
	
	}

	return 0;
}
