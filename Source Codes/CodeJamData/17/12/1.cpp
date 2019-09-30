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
	int n, p;
	vector<int> r;
	vector<vector<int> > a;

	int result;
	int mx;

	void read() {
		cin >> n >> p;
		r.resize(n);
		for (int &x : r) {
			cin >> x;
		}
		a.resize(n, vector<int>(p));
		mx = 0;
		for (int i = 0; i < n; ++i) {
			for (int &x : a[i]) {
				cin >> x;
			}
			sort(all(a[i]));
			int cur = a[i].back();
			cur += cur / 9;
			mx = max(mx, cur / r[i]);
		}
	}

    void solve() {
		mx += mx / 9;
		vector<int> indexes(n, 0);
		result = 0;
		for (int i = 1; i <= mx; i) {
			bool can = true;
			for (int j = 0; j < n; ++j) {
				i64 need = i * i64(r[j]);
				i64 at_least = (need * 9 + 9) / 10;
				i64 at_most = need + need / 10;
				int &index = indexes[j];
				while (index < p && a[j][index] < at_least) {
					++index;
				}
				if (index == p) {
					return;
				}
				if (a[j][index] > at_most) {
					can = false;
					break;
				}
			}
			if (can) {
				for (int j = 0; j < n; ++j) {
					++indexes[j];
				}
				++result;
			}
			else {
				++i;
			}
		}
	}

	void print() {
		cout << result;
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
