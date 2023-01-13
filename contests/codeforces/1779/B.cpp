#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int n; 
		cin >> n;
		if (n & 1) {
			if (n == 3) {
				cout << "NO\n";
			} else {
				cout << "YES\n";
				vector<int> a(n);
				for (int i = 0; i < n; i++) {
					if (i & 1) a[i] = n/2;
					else a[i] = -n/2+1;
				}
				for (int i = 0; i < n; i++) {
					cout << a[i] << (i == n - 1 ? '\n' : ' ');
				}
			}
		} else {
			cout << "YES\n";
			for (int i = 0; i < n; i++) {
				if (i & 1) cout << 1 << (i == n - 1 ? '\n' : ' ');
				else cout << -1 << (i == n - 1 ? '\n' : ' ');
			}
		}
	}

	return 0;
}
