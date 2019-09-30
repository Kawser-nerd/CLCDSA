#include <iostream>
#include <vector>
#include <utility>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>

#define rep(i, m, n) for (int (i)(m); (i)<(n); ++(i))
#define repv(i, v) for (int (i)(0); (i)<(v.size()); ++(i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vb>;

int main(){
	int D, N;
	cin >> D >> N;
	int t = 0;
	int i = 0;
	int d = 100;
	while (t < N) {
		++i;
		int j = i;
		int n = 0;
		while (j % d == 0) {
			j /= d;
			++n;
		}
		if (n == D) {
			++t;
		}
	}
	cout << i << endl;
	return 0;
}