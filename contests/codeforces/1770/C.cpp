#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	vector<bool> is_prime(1005, true);
       	vector<int> primes;
	for (int i = 2; i <= 1004; i++) {
		if (is_prime[i]) {
			primes.push_back(i);
			for (int j = 2 * i; j <= 1004; j += i) {
				is_prime[j] = false;
			}
		}
	}

	int T; cin >> T;
	while (T--) {
		using ll = long long;
		int n; cin >> n;
		vector<ll> a(n);
		for (auto& x : a) cin >> x;
		bool exists = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (a[i] == a[j]) exists = false;
			}
		}
		for (auto p : primes) { 
			vector<int> cnt(p);
			for (int i = 0; i < n; i++) {
				cnt[a[i] % p]++;
			}
			bool sat = false;
			for (int i = 0; i < p; i++) {
				if (cnt[i] <= 1) sat = true;
			}
			if (!sat) exists = false;
		}
		cout << (exists ? "YES" : "NO") << "\n";
	}

	return 0;
}
