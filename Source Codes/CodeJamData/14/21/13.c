#include<stdio.h>

int main(){
	int t, u;
	scanf("%d", &t);
	for (u = 1 ; u <= t ; ++u){
		int n, a[100][100] = {}, i, j, k, mtop = 0, f = 0, cnt = 0;
		char s[101], c[100][100];
		scanf("%d%*c", &n);
		for (i = 0 ; i < n ; ++i){
			int top = 0;
			gets(s);
			for (j = 0, k = -1 ; s[j] ; ++j){
				if (s[j] == s[j + 1])continue;
				a[i][top] = j - k;
				c[i][top]= s[j];
				k = j, ++top;
			}
			if (!i)mtop = top;
			else if (mtop != top)f = 1;
		}
		if (f){
			printf("Case #%d: Fegla Won\n", u);
			continue;
		}
		for (j = 0 ; j < mtop && !f; ++j){
			int sum = 0, avg;
			for (i = 0 ; i < n && !f; ++i){
				if (c[i][j] != c[0][j]){
					f = 1;
				}
				sum += a[i][j];
			}
			if (sum % n > n - sum % n)avg = sum / n + 1;
			else avg = sum / n;
			for (i = 0 ; i < n && !f ; ++i){
				cnt += abs(a[i][j] - avg);
			}
		}
		if (f)
			printf("Case #%d: Fegla Won\n", u);
		else printf("Case #%d: %d\n", u, cnt);
	}
}
