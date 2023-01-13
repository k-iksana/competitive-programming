#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	using ll = long long;
	ll x, y; cin >> x >> y;

	string b = "";
	string a = "";
	for (int i = 0; i < 60; i++) {
		if ((1LL << i) & y) b = '1' + b;
		else b = '0' + b;
		if ((1LL << i) & x) a = '1' + a;
		else a = '0' + a;
	}

	auto remove_leading = [&](string a) {
		while (a[0] == '0') a.erase(a.begin());
		return a;
	};

	auto remove_ending = [&](string a) {
		while (a[(int) a.size() - 1] == '0') a.pop_back();
		return a;
	};

	a = remove_leading(a); b = remove_leading(b);

	auto brute = [](string a, string b) {
		int n = (int) a.size();
		int m = (int) b.size();
		for (int i = 0; i <= m - n; i++) {
			bool match = true;
			for (int j = 0; j < i; j++) if (b[j] != '1') match = false;
			for (int j = i; j < i + n; j++) {
				if (b[j] != a[j-i]) match = false;
			}
			for (int j = i + n; j < m; j++) if (b[j] != '1') match = false; 
			if (match) return true;
		}
		return false;
	};

	string s1 = a;
	string s2 = a; reverse(s2.begin(), s2.end());
	s2 = remove_leading(s2);
	string s3 = a; 
	s3 = remove_ending(s3);
	string s4 = s3; reverse(s4.begin(), s4.end());
	s4 = remove_leading(s4);

	cout << s1 << "\n";
	// cout << s2 << "\n";
	// cout << s3 << "\n";
	// cout << s4 << "\n";
	cout << b << "\n";

	bool sat = false;

	cout << brute(s1, b) << "\n";
	if (sat == false && brute(s1, b) == true) cout << "1" << "\n";
	sat |= brute(s1, b);
	if (sat == false && brute(s2, b) == true) cout << "2" << "\n";
	sat |= brute(s2, b);
	if (sat == false && brute(s3, b) == true) cout << "3" << "\n";
	sat |= brute(s3, b);
	if (sat == false && brute(s4, b) == true) cout << "4" << "\n";
	sat |= brute(s4, b);

	cout << (sat ? "YES" : "NO") << "\n";

	return 0;
}
