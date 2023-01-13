#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<vector<int>> mat(n, vector<int>(n));
		set<int> s;
		for (int i = 0; i < n * n; i++) {
			s.insert(i);
		}
		bool low = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (low) {
					mat[i][j] = *(s.begin());
				} else {
					mat[i][j] = *(s.rbegin());
				}
				s.erase(mat[i][j]);
				low ^= 1;
			}
			if (i & 1) reverse(mat[i].begin(), mat[i].end());
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << mat[i][j] + 1 << (j == n - 1 ? '\n' : ' ');
			}
		}
		
	}
	

	return 0;
}
