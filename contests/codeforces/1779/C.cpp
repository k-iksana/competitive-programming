#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	using ll = long long;

	int T; cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<ll> a(n), pref(n+1);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) {
			pref[i] = pref[i-1] + a[i-1];
		}
		int ops = 0;
		priority_queue<ll> pq;
		ll delta = pref[m];
		for (int i = m; i >= 1; i--) {
			if (pref[i] < delta) {
				while (delta > pref[i]) {
					ll x = pq.top();
					pq.pop();
					delta -= 2 * x;
					ops++;
				}
			}
			pq.push(a[i-1]);
		}
		priority_queue<ll, vector<ll>, greater<ll>> mq;
		delta = 0;
		for (int i = m+1; i <= n; i++) {
			mq.push(a[i-1]);
			if (pref[i] + delta < pref[m]) {
				while (pref[i] + delta < pref[m]) {
					ll x = mq.top();
					mq.pop();
					delta += - 2 * x;
					ops++;
				}
			}
		}
		cout << ops << "\n";
	}

	return 0;
}
