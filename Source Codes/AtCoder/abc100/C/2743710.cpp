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
	int N;
	cin >> N;
	int sum = 0;
	rep(i, 0, N) {
		int j;
		cin >> j;
		while (j % 2 == 0) {
			j /= 2;
			++sum;
		}
	}
	cout << sum << endl;
}