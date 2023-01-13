namespace sieve {

using std::vector;
using std::pair;
using std::min;
using std::iota;

vector<int> primes;
vector<int> sdiv;

void init(int n) {
	sdiv.resize(n, 1);
	iota(sdiv.begin(), sdiv.end(), 0);
	for (long long i = 2; i < n; i++) {
		if (sdiv[i] == i) {
			primes.push_back(i);
			for (long long j = i * i; j < n; j += i) {
				sdiv[j] = min(sdiv[j], (int) i);
			}
		}
	}
}

vector<pair<int, int>> factor(int x) {
	vector<pair<int, int>> pfactors;
	while (x > 1) { 
		int p = sdiv[x], cnt = 0;
		while (x % p == 0) {
			x /= p;
			cnt++;
		}
		pfactors.emplace_back(p, cnt);
	}
	return pfactors;
}

vector<int> prime_factors(int x) {
	vector<pair<int, int>> pfactors = factor(x);
	vector<int> unq_factors;
	for (auto& [p, f] : pfactors) {
		unq_factors.push_back(p);
	}
	return unq_factors;
}

bool is_prime(int x) {
	return sdiv[x] == x;
}

} // namespace sieve
