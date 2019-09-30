#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, l, ans;
string a[200], b[200];

int f(int aa, int bb) {
	int r[100] = {}, sr = 0;
	for(int i = 0; i < l; ++i)
		if(a[aa][i] != b[bb][i]) r[i] = 1, sr++;
	//cout << a[aa] << ' ' << b[bb];
	//for(int i = 0; i < l; ++i) printf(" %d", r[i]); printf(", %d\n", sr);
	string ta[200], tb[200];
	for(int i = 0; i < n; ++i) {
		ta[i] = a[i], tb[i] = b[i];
		for(int j = 0; j < l; ++j)
			if(r[j]) {
				ta[i][j] = ta[i][j] == '0' ? '1' : '0';
			}
		//cout << ta[i] << ' ' << a[i] << endl;
	}
	sort(ta, ta+n); sort(tb, tb+n);
	for(int i = 0; i < n; ++i) if(ta[i] != tb[i]) return 10000;
	return sr;
}

int main() {
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase) {
		scanf("%d%d", &n, &l);
		for(int i = 0;  i < n; ++i) cin >> a[i];
		for(int i = 0;  i < n; ++i) cin >> b[i];
		ans = 10000;
		for(int i = 0; i < n; ++i)
			ans = min(ans, f(0, i));
		printf("Case #%d: ", kase);
		if(ans == 10000) puts("NOT POSSIBLE");
		else printf("%d\n", ans);
	}
	return 0;
}