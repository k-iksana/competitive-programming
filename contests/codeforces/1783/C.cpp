#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	
	using ll = long long;
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		ll m; cin >> m;
		vector<array<ll, 2>> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i][0];
			a[i][1] = i;
		}
		vector<array<ll, 2>> b = a;
		sort(b.begin(), b.end());
		int low = 1, high = n;
		int best = 0;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			ll x = m;
			ll y = m;
			int cnt1 = 0;
			int cnt2 = 0;
			if (x >= a[mid-1][0]) {
				cnt2++;
				x -= a[mid-1][0];
			} else {
				cnt2 = -1e6;
			}
			for (int i = 0; i < n; i++) {
				if (y - b[i][0] >= 0) {
					cnt1++;
					y -= b[i][0];
				}
				if (b[i][1] != mid-1) {
					if (x - b[i][0] >= 0) {
						x -= b[i][0];
						cnt2++;
					}
				}
			}
			if ((cnt2 >= mid - 1) || (cnt1 >= mid)) {
				low = mid + 1;
				best = max(best, mid);
			} else {
				high = mid - 1;
			}
			// cout << mid << " " << cnt1 << " " << cnt2 << " " << best << "\n";
		}
		cout << n+1 - best << "\n";
	}

	return 0;
}
