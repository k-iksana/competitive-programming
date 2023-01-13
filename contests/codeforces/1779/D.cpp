#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T, class F = function<T(T&, T&)>>
struct SparseTable {
	int n = 0;
	vector<vector<T>> data;
	F func;
	SparseTable(const vector<T>& v, F f) : n((int) v.size()), func(f) {
		int k = 32 - __builtin_clz(n);
		data.resize(k);
		data[0] = v;
		for (int i = 1; i < k; i++) {
			data[i].resize(n - (1 << i) + 1);
			for (int j = 0; j + (1 << i) <= n; j++) {
				data[i][j] = func(data[i-1][j], data[i-1][j + (1 << (i-1))]);
			}
		}
	}
	T query(int l, int r) {
		int lg = 32 - __builtin_clz(r - l + 1) - 1;
		return func(data[lg][l], data[lg][r - (1 << lg) + 1]);
	}
};

auto get_min = [](int i, int j) { return min(i, j); };
auto get_max = [](int i, int j) { return max(i, j); };

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<ll> a(n), b(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];

		int m; cin >> m;
		vector<ll> razors(m);
		for (int i = 0; i < m; i++) cin >> razors[i];

		SparseTable qmax(b, get_max);

		auto find_left = [&](int idx) {
			int lo = 0, hi = idx;
			int best = hi;
			while (lo <= hi) {
				int md = lo + (hi - lo) / 2;
				ll x = qmax.query(md, idx);
				if (x > b[idx]) {
					lo = md + 1;
				} else {
					hi = md - 1;
					best = md;
				}
			}
			return best;
		};

		auto find_right = [&](int idx) {
			int lo = idx, hi = n - 1;
			int best = idx;
			while (lo <= hi) {
				int md = lo + (hi - lo) / 2;
				ll x = qmax.query(idx, md);
				if (x > b[idx]) {
					hi = md - 1;
				} else {
					lo = md + 1;
					best = md;
				}
			}
			return best;
		};

		bool sat = true;
		map<ll, vector<int>> mp;
		for (int i = 0; i < n; i++) {
			if (a[i] == b[i]) continue;
			if (a[i] < b[i]) { sat = false; break; }
			if (mp.count(b[i])) mp[b[i]].push_back(i);
			else {
				mp[b[i]] = vector<int>(0);
				mp[b[i]].push_back(i);
			}
		}

		auto merge = [&](ll v) {
			vector<pair<ll, ll>> intervals;
			for (auto idx : mp[v]) {
				int left = find_left(idx);
				int right = find_right(idx);
				intervals.emplace_back(left, right);
			}
			sort(intervals.begin(), intervals.end());
			ll left = intervals[0].first;
			ll right = intervals[0].second;
			int cnt = 1;
			for (auto [a, b] : intervals) {
				if (left >= a && a <= right) right = max(right, b);
				else {
					cnt++;
					left = a;
					right = b;
				}
			}
			return cnt;
		};

		map<ll, int> amount;
		for (int i = 0; i < m; i++) amount[razors[i]]++;
		for (auto& [x, _] : mp) {
			if (amount[x] < merge(x)) sat = false;
		}
		cout << (sat ? "YES" : "NO") << "\n";
	}

	return 0;
}
