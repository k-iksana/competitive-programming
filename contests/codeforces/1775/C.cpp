#include <bits/stdc++.h>

int main() {
	using namespace std;
	using ll = long long;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		ll n, x;
		cin >> n >> x;
		
		auto toBin = [](ll x) {
			string s = "";
			for (int i = 0; i < 60; i++) {
				if ((1LL << i) & x) s = "1" + s;
				else s = "0" + s;
			}
			return "0" + s;
		};

		auto toDec = [](string s) {
			ll x = 0;
			int p = 0;
			int n = (int) s.length();
			for (int i = n - 1; i >= 0; i--) {
				if (s[i] == '1') x += (1LL << p);
				p++;
			}
			return x;
		};

		if ((n & x) != x) {
			cout << -1 << "\n";
			continue;
		} 

		if (n == x) {
			cout << n << "\n";
			continue;
		}

		string s = toBin(n), t = toBin(x);

		int miss = -1;
		for (int i = 0; i <= 60; i++) {
			if (s[i] != t[i]) {
				miss = i;
				break;
			}
		}
		
		if (miss == -1) {
			cout << n << "\n";
			continue;
		}
		
		if (s[miss-1] != '0') {
			cout << -1 << "\n";
			continue;
		}

		bool bad = false;
		for (int i = miss + 1; i < 61; i++) {
			if (t[i] == '1') {
				bad = true;
			}
		}

		if (bad) {
			cout << -1 << '\n';
			continue;
		}


		string r = string(61, '0');
		for (int i = 0; i < miss - 1; i++) {
			r[i] = s[i];
		}
		r[miss-1] = '1';
		
		cout << toDec(r) << '\n';
	}

	return 0;
}
