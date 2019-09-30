#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>

#define INF 1000000000
#define EPS 1E-8
#define PI 3.14159265358979

using namespace std;

typedef long long ll;

int fib[40];
double hoge;

ll co(int a, int b) {
	return min((int)(hoge * a), b);
}

int main() {
	int N;
	cin >> N;
	fib[0] = 1; fib[1] = 2;
	for(int i = 2; i < 40; ++i) fib[i] = fib[i - 1] + fib[i - 2];
	hoge = (-1 + sqrt(5)) / 2;
	for(int t = 0; t < N; ++t) {
		printf("Case #%d: ", t + 1);
		int a1, a2, b1, b2;
		cin >> a1 >> a2 >> b1 >> b2;
		ll res = 0;
		for(int i = a1; i <= a2; ++i) if(b1 < i) {
			res -= co(i, min(i - 1, b1 - 1));
			res += co(i, min(i - 1, b2));
		}
		for(int i = b1; i <= b2; ++i) if(a1 < i) {
			res -= co(i, min(i - 1, a1 - 1));
			res += co(i, min(i - 1, a2));
		}
		cout << res << endl;
	}
	return 0;
}
