#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>

using namespace std;

char s[5000];
int p[5000];

int main(void) {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int i, j, k, x, n, m;

	scanf("%d\n", &n);

	for(x = 0; x < n; x++) {
		gets(s);
		m = strlen(s);
		for(i = 0; i < m; i++) p[i] = -1;
		k = -1;
		for(i = 0; i < m; i++) 
			if (p[i] == -1) {
				if (k == -1) {
					k = 1; 
				} else if (k == 1) {
					k = 0;	
				} else if (k == 0) {
					k = 2;
				}
				else k++;
				for(j = 0; j < m; j++)
					if (s[j] == s[i]) p[j] = k;
			}
		if (k < 2) k = 2; else k++;

		long long sol = 0;
		for(i = 0; i < m; i++)
			sol = sol * k + p[i];
		printf("Case #%d: %lld\n", x+1, sol);
	}

	exit(0);
}