#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<int> a(n);
		for (auto& x : a) {
			cin >> x;
			--x;
		}
		set<int> p, q;
		for (int i = 0; i < n; i++) {
			p.insert(i);
			q.insert(i);
		}
		vector<int> where(n);
		iota(where.begin(), where.end(), 0);
		sort(where.begin(), where.end(), [&](const auto& i, const auto& j){ return a[i] < a[j]; });
		vector<int> p_ans(n), q_ans(n);
		bool sat = true;
		for (int i = 0; i < n; i++) {
			int idx = where[i];
			if (p.count(a[idx])) {
				if (*q.begin() <= a[idx]) {
					p_ans[idx] = a[idx];
					q_ans[idx] = *q.begin();
					p.erase(a[idx]);
					q.erase(*q.begin());
				} else {
					sat = false;
					break;
				}
			} else if (q.count(a[idx])) {
				if (*p.begin() <= a[idx]) {
					p_ans[idx] = *p.begin();
					q_ans[idx] = a[idx];
					p.erase(*p.begin());
					q.erase(a[idx]);
				} else {
					sat = false;
					break;
				}
			} else {
				sat = false;
				break;
			}
		}
		if (sat) {
			cout << "YES\n";
			for (int i = 0; i < n; i++) {
				cout << p_ans[i] + 1 << (i == n - 1 ? '\n' : ' ');
			}
			for (int i = 0; i < n; i++) {
				cout << q_ans[i] + 1 << (i == n - 1 ? '\n' : ' ');
			}
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}
