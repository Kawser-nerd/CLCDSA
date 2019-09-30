#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(i=0;i<n;i++)
#define F1(i,n) for(i=1;i<=n;i++)
const int inf = 1000000009;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;

int i, j, k, m, n, l, p[1000002], sz[1000002], composite[1000001];

ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }

int main() {
	for (i = 2; i * i <= 1000000; i++)
		if (!composite[i]) {
			for (j = i + i; j <= 1000000; j += i)
				composite[j] = 1;
		}


	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int tn, tt;
	cin >> tn;
	F1(tt,tn) {
		ll A, B, P;
		cin >> A >> B >> P;
		n = (int)(B - A + 1);
		F1(i,n) { p[i] = i; sz[i] = 1; }
		int ans = n;

		for (int prime = P; prime <= 1000000 && prime <= B; prime++)
		if (!composite[prime]) {
			int first = prime - (A-1) % prime;
			int other = first;
			while (1) {
				other += prime;
				if (other > n) break;
				j = other;
				while (p[first] != first) {
					first = p[first];
				}
				while (p[j] != j) j = p[j];
				if (j != first) {
					ans--;
					k = first;
					if (sz[j] < sz[k]) swap(k, j);
					sz[j] += sz[k];
					p[k] = j;
				}
			}
		}

		printf("Case #%d: %d\n", tt, ans);
	}

	return 0;
}
