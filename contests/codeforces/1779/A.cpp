#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int n;
		string s;
		cin >> n >> s;
		int p1 = n, p2 = -1;
		int x = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'R') p1 = min(i, p1);
			if (s[i] == 'L') p2 = max(i, p2);
			if (i > 0 && s[i] == 'R' && s[i-1] == 'L') x = i;
		}
		if (p1 == n || p2 == -1) {
			cout << -1 << "\n";
		} else if (p1 < p2) {
			cout << 0 << "\n";
		} else {
			cout << x << "\n";
		}
	}

	return 0;
}
