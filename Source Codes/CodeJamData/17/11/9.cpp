#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 110
int n, m;
string a[N];

int main() {
	int _;
	cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		cin >> n >> m;
		for (int i = 0; i < n; i ++) cin >> a[i];
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < m; j ++)
				if (a[i][j] != '?') {
					int k = j-1;
					while (k >= 0 && a[i][k] == '?') {
						a[i][k] = a[i][j];
						k--;
					}
					k = j+1;
					while (k < m && a[i][k] == '?') {
						a[i][k] = a[i][j];
						k++;
					}
				}
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < m; j ++)
				if (a[i][j] != '?') {
					int k = i-1;
					while (k >= 0 && a[k][j] == '?') {
						a[k][j] = a[i][j];
						k--;
					}
					k = i+1;
					while (k < n && a[k][j] == '?') {
						a[k][j] = a[i][j];
						k++;
					}
				}
		printf ("Case #%d:\n", __);
		for (int i = 0; i < n; i ++)
			cout << a[i] << endl;
	}
	return 0;
}