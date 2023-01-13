#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<int> a(n), v;
		int zeros = 0;
		for (auto& x : a) {
			cin >> x;
			if (x == 0) zeros++;
			else v.push_back(x);
		}
		if (zeros == n) {
			cout << 0 << "\n";
			continue;
		}
		auto sim = [&]() {
			int m = (int) v.size();
			vector<int> b;
			int temp = 0;
			for (int i = 0; i < m - 1; i++) {
				if (v[i+1] - v[i] != 0) b.push_back(v[i+1] - v[i]);
				else temp++;
			}
			if (zeros) {
				b.push_back(v[0]);
				zeros--;
			}
			zeros += temp;
			sort(b.begin(), b.end());
			v = b;
		};
		while ((int) v.size() > 1) {
			sim();
		}
		if ((int) v.size() == 0) {
			cout << 0 << "\n";
		} else {
			cout << v[0] << "\n";
		}
	}

	return 0;
}
