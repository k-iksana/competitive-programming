#include <bits/stdc++.h>

int main() {
	using namespace std;
	using ll = long long;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		ll n, x;
		cin >> n >> x;

		bool sat = false;
		ll m = -1;
		for (int i = n; i < 4 * n; i++) {
			m &= i;
			if ((m & n) == x) {
				cout << m << "\n";
				sat = true;
				break;
			}
		}
		if (!sat) {
			cout << -1 << '\n';
		}
	}

	return 0;
}
