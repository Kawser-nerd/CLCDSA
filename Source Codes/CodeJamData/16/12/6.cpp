#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pct __builtin_popcount

#define N 110
#define M 2510

int n; 
int a[N][N]; 
bool v[M]; 

int main() {
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		cin >> n;
		memset(v, 0, sizeof v);
		for (int i = 0; i < n*2-1; i ++) {
			for (int j = 0; j < n; j ++) {
				cin >> a[i][j]; 
				v[a[i][j]] ^= 1;
			}
		}
		int l = 0;
		for (int i = 0; i < M; i ++) 
			if (v[i]) a[n*2-1][l++] = i;
		printf ("Case #%d: ", __);
		for (int i = 0; i < n; i ++) 
			printf ("%d%c", a[n*2-1][i], i == n-1?'\n': ' ');
	}
	return 0;
}
