#include <algorithm>
#include <bitset>
#include <cfloat>
#include <cmath>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeindex>
#include <typeinfo>
#include <vector>
#include <boost/dynamic_bitset.hpp>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define INFILE() freopen("input.txt", "r", stdin)

using ll = long long;
using ull = unsigned long long;
using i_i = pair<int, int>;
using ll_i = pair<ll, int>;
using i_ll = pair<int, ll>;
using d_i = pair<double, int>;
using ll_ll = pair<ll, ll>;
using d_d = pair<double, double>;

constexpr ll LL_MOD = 1000000009;
constexpr int I_MOD = 1000000007;
constexpr double EPS = numeric_limits<double>::epsilon();
constexpr double PI = 3.14159265358979323846264338327950288;

template <class T> void scan(vector<T> &v);
void scan(vector<string> &v, bool isWord = true);
boost::dynamic_bitset<> scan(char trueValue = 'o');

int main(int argc, char *argv[]) {
  // INFILE();
	int n, m;
	cin >> n >> m;

	vector<string> nmap(n);
	vector<string> mmap(m);

	scan(nmap);
	scan(mmap);

	int diff = n - m;
	for (int i = 0; i <= diff; i++) {
		for (int j = 0; j <= diff; j++) {
			bool judge = true;

			for (int k = 0; k < m; k++) {
				for (int l = 0; l < m; l++) {
					if (nmap[i + k][j + l] != mmap[k][l]) {
						judge = false;
					}
				}
			}

			if (judge) {
				cout << "Yes\n";
				return 0;
			}
		}
	}
	cout << "No\n";
  return 0;
}

template <class T> void scan(vector<T> &v) {
  map<type_index, const char *const> m = {{typeid(int), "%d"},
                                          {typeid(ll), "%lld"},
                                          {typeid(double), "%lf"},
                                          {typeid(char), "%c"}};

  auto tFormat = m[typeid(T)];

  for (T &n : v) {
    scanf(tFormat, &n);
  }
}

void scan(vector<string> &v, bool isWord) {
	if (isWord) {
		for (auto &n : v) {
			cin >> n;
		}
		return;
	}

  int i = 0, size = v.size();
  string s;
  getline(cin, s);

  if (s.size() != 0) {
    i++;
    v[0] = s;
  }

  for (; i < size; ++i) {
    getline(cin, v[i]);
  }
}

boost::dynamic_bitset<> scan(char trueValue) {
	string s;
	getline(cin, s);

	if (s.size() == 0) {
		getline(cin, s);
	}

	for_each(begin(s), end(s), [trueValue](char &c) { c = (c == trueValue) ? '1' : '0'; });
	return boost::dynamic_bitset<>(string(rbegin(s), rend(s)));
}