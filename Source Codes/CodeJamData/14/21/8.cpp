#include <iostream>
#include <algorithm>
using namespace std;

int Tn, Ti, n, i, j, k, dp[105], fa, sz[105], t;
string a[105], smallest;

string pattern (string s) {
	string smallest = "";
	for(int i = 0; i < s.length(); i++) if (i == 0 || s[i] != s[i - 1]) smallest += s[i];
	return smallest;
}

int gsize (string s, int gn) {
	int groups, gsz;
	groups = gsz = 0;
	for(int i = 0; i < s.length(); i++) if (i == 0 || s[i] != s[i - 1]) {
		++groups;
		if (groups > gn) return gsz;
		gsz = 1;
	} else ++gsz;
	return gsz;
}

int main (int argc, char * const argv[]) {
	freopen("input.txt", "r", stdin);
	cin >> Tn;
	for(Ti = 1; Ti <= Tn; Ti++) {
		cin >> n;
		for(i = 1; i <= n; i++) cin >> a[i];		
		smallest = pattern(a[1]);
		fa = 0;
		for(i = 2; i <= n; i++) if (smallest != pattern(a[i])) {
			fa = 1;
			break;
		}
		if (fa) {
			printf("Case #%d: Fegla Won\n", Ti);
			continue;
		}
		for(i = 0; i <= 105; i++) dp[i] = 1000000000;
		dp[0] = 0;
		for(i = 0; i < smallest.length(); i++) {
			for(j = 1; j <= n; j++) sz[j] = gsize(a[j], i + 1);
			for(j = 1; j <= 100; j++) {
				t = dp[i];
				for(k = 1; k <= n; k++) t += abs(sz[k] - j);
				dp[i + 1] = min(dp[i + 1], t);
			}
		}
		printf("Case #%d: %d\n", Ti, dp[smallest.length()]);
	}
    return 0;
}
