#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		string s; cin >> s;
		int n = (int) s.size();
		string A = "", B = "", C = "";
		if (s[0] == s[n-1]) {
			A = s[0];
			B = s.substr(1, n-2);
			C = s[n-1];
		} else {
			if (s[0] == 'a') {
				if (s[1] == 'b') {
					A = s[0];
					B = s.substr(1, n-2);
					C = s[n-1];
				} else {
					A = s[0];
					B = s[1];
					C = s.substr(2, n-2);
				}
			} else {
				if (s[1] == 'b') {
					A = s[0];
					B = s.substr(1, n-2);
					C = s[n-1];
				} else {
					A = s[0];
					B = s[1];
					C = s.substr(2, n-2);
				}
			}
		}
		cout << A << " " << B << " " << C << "\n";
	}

	return 0;
}
