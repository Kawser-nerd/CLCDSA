#pragma comment(linker, "/STACK:64777216")

#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <iostream>
#include <functional>
#include <numeric>
#include <sstream>
#include <exception>
#include <cassert>
#include <thread>
#include <mutex>
#include <iomanip>

typedef long long i64;
typedef unsigned long long u64;
typedef unsigned int u32;
using namespace std;

typedef vector<int> VI;
#define endl '\n'

#define all(a) a.begin(),a.end()

template<class T>
int size(const T &a) {
    return int(a.size());
}

template<class T>
T abs(const T &a) {
    return (a < 0 ? -a : a);
}

template<class T>
T sqr(const T &a) {
    return a * a;
}

const double pi = acos(-1.0);

int mod = int(1e9 + 7.1);

inline int msum(int a, int b) {
    return (a + b < mod ? a + b : a + b - mod);
}

inline int mdiff(int a, int b) {
    return (a < b ? a - b + mod : a - b);
}

inline void madd(int &a, int b) {
    a = msum(a, b);
}

inline void msub(int &a, int b) {
    a = mdiff(a, b);
}

inline i64 mmul(int a, int b) {
    return i64(a) * b % mod;
}

struct Solver {
	//define only input data & result
	i64 hd, ad, hk, ak, b, d;

	i64 result;

	void read() {
		cin >> hd >> ad >> hk >> ak >> b >> d;
	}

	i64 calc_attack_turns() {
		i64 h = hk;
		i64 a = ad;
		i64 res = (h + a - 1) / a;
		for (int x = 1; x < res; ++x) {
			a += b;
			i64 cur = x + (h + a - 1) / a;
			if (cur > res) {
				break;
			}
			res = cur;
		}
		return res;
	}

	i64 calc(i64 h, i64 attacks, i64 ak) {
		if (ak <= 0) {
			return attacks;
		}
		i64 first_turns = min(attacks, (h + ak - 1) / ak - 1);
		attacks -= first_turns;
		if (attacks <= 1) {
			return first_turns + attacks;
		}
		i64 turns = first_turns;
		h = hd - ak;
		if (h <= 0) {
			return -1;
		}
		i64 cycle_turns = (h + ak - 1) / ak - 1;
		if (cycle_turns == 0) {
			return -1;
		}
		i64 cycles = (attacks - 1) / cycle_turns;
		turns += cycles * (cycle_turns + 1);
		attacks -= cycles * cycle_turns;
		if (attacks <= 1) {
			return turns + attacks;
		}
		return turns + 1 + attacks;
	}

    void solve() {
		i64 attacks = calc_attack_turns();
		result = -1;
		i64 health = hd;
		i64 addition_turns = 0;
		for (int x = 0; ; ++x) {
			i64 cur = calc(health, attacks, ak);
			if (cur != -1) {
				cur += addition_turns;
			}
			if (result == -1 || cur != -1 && cur < result) {
				result = cur;
			}
			if (ak <= 0 || d == 0) {
				break;
			}
			if (health <= ak - d) {
				++addition_turns;
				health = hd - ak;
			}
			if (health > ak - d) {
				++addition_turns;
				ak -= d;
				health -= ak;
			}
			else {
				break;
			}
		}
	}

	void print() {
		if (result == -1) {
			cout << "IMPOSSIBLE";
		} else {
			cout << result;
		}
	}
};

vector<Solver> res;

struct Thread {
	thread t;
	int rem, mod;
	void solve(int rem, int mod) {
		this->rem = rem;
		this->mod = mod;
		t = thread(&Thread::run, this);
	}

	void run() {
		int n = res.size();
		for (int i = rem; i < n; i += mod) {
			res[i].solve();
		}
	}

};


int main() {

#ifdef pperm
    freopen("input.txt", "r", stdin);
    //freopen("input.txt", "w", stdout);
    freopen("output.txt", "w", stdout);
#endif
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    cin >> T;
	res.resize(T);
    for (int iTest = 0; iTest < T; ++iTest) {
		res[iTest].read();
    }
	int nThreads = 4;
#ifdef _DEBUG
	nThreads = 1;
#endif
	vector<Thread> threads(nThreads);
	for (int i = 0; i < nThreads; ++i) {
		threads[i].solve(i, nThreads);
	}
	for (int i = 0; i < nThreads; ++i) {
		threads[i].t.join();
	}
    for (int i = 0; i < T; i++) {
		cout << "Case #" << (i + 1) << ": ";
		res[i].print();
		cout << endl;
    }
#ifdef pperm
    flush(cout);
    cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif
    return 0;
}
