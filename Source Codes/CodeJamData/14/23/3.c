#include<stdio.h>
#include<string.h>

int n;

void dfs(char s[][6], int a[][50], int v[], int p[], char zip[], char mzip[], int now, int l){
	strcat(zip, s[now]);
	//printf("%d %d, %s\n", now, l, zip);
	if (l == n - 1){
		if (strcmp(zip, mzip) < 1)
			memcpy(mzip, zip, 251);
	}
	else {
		int i, lv[50] = {}, nnow;
		v[now] = 1, nnow = now;
		do {
			for (i = 0 ; i < n ; ++i)
				if (a[nnow][i] && !v[i] && !lv[i])
					p[i] = nnow, lv[i] = 1, dfs(s, a, v, p, zip, mzip, i, l + 1);
		}while ((nnow = p[nnow]) >= 0);
		v[now] = 0;
	}
	zip[l * 5] = 0;
	return;
}

int main(){
	int t, u;
	scanf("%d", &t);
	for (u = 1 ; u <= t ; ++u){
		int m, x, y, i;
		int a[50][50] = {}, v[50] = {}, p[50] = {};
		char s[50][6], zip[251] = {}, mzip[251] = "a";
		scanf("%d%d%*c", &n, &m);
		for (i = 0 ; i < n ; ++i)
			gets(s[i]);
		while (m--){
			scanf("%d%d", &x, &y);
			a[x-1][y-1] = a[y-1][x-1] = 1;
		}
		for (i = 0 ; i < n ; ++i){
			if (strcmp(s[i], mzip) > 0)
				continue;
			p[i] = -1;
			dfs(s, a, v, p, zip, mzip, i, 0);
		}
		printf("Case #%d: %s\n", u, mzip);
	}
	return 0;
}
