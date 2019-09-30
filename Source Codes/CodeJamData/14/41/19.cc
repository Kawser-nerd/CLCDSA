//By Lin
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>

#define X first
#define Y second
#define mp make_pair
#define sqr(x) ((x) * (x))
#define Rep(i, n) for(int i = 0; i<(n); i++)
#define foreach(it, n) for(__typeof(n.begin()) it = n.begin(); it != n.end(); it++)

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

#define esp 1e-8
#define N 100010

int data[N], n, X;
int main() {
	int cas, tt = 0;
	scanf("%d", &cas);
	while (cas --) {
		scanf("%d%d", &n, &X);
		Rep(i, n) scanf("%d", &data[i]);
		sort(data, data + n);
		int l = 0, r = n - 1;
		int ans = 0;
		while (l <= r) {
			ans++;
			if (l == r) break;
			if (data[r] + data[l] <= X) r--, l++;
			else r--;
		}
		printf("Case #%d: %d\n", ++tt, ans);
	}
	return 0;
}
