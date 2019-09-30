#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long ll;

#define INF (1ll << 60)
#define MAXN 10005

char ch[MAXN]; int a[MAXN], b[4];
int g[5][5], sl[MAXN], sr[MAXN];
int cas, n; ll m, l, r, lc, rc; bool flag;

void init()
{
	g[1][1] = 1; g[1][2] = 2; g[1][3] = 3; g[1][4] = 4;
	g[2][1] = 2; g[2][2] = -1; g[2][3] = 4; g[2][4] = -3;
	g[3][1] = 3; g[3][2] = -4; g[3][3] = -1; g[3][4] = 2;
	g[4][1] = 4; g[4][2] = 3; g[4][3] = -2; g[4][4] = -1;
}

int multi(int a, int b)
{
	int res = (a * b > 0) ? 1 : -1;
	a = abs(a); b = abs(b);
	res *= g[a][b];
	return res;
}

int char2int(char c)
{
	if (c == '1') return 1;
	if (c == 'i') return 2;
	if (c == 'j') return 3;
	if (c == 'k') return 4;
}

int main()
{
	freopen("C.in", "r", stdin); freopen("C.out", "w", stdout);
	init();
	scanf("%d", &cas);
	for (int T = 1; T <= cas; T ++)
	{
		scanf("%d%lld", &n, &m);
		scanf("%s", ch + 1);
		for (int i = 1; i <= n; i ++) a[i] = char2int(ch[i]);
		sl[0] = 1;
		for (int i = 1; i <= n; i ++) sl[i] = multi(sl[i - 1], a[i]);
		sr[n + 1] = 1;
		for (int i = n; i; i --) sr[i] = multi(a[i], sr[i + 1]);
		b[0] = 1; for (int i = 1; i < 4; i ++) b[i] = multi(b[i - 1], sl[n]);
		l = INF, r = INF;
		for (int j = 1; j <= n; j ++)
			for (int i = 0; i < 4; i ++)
				if (multi(b[i], sl[j]) == 2)
					l = min(1ll * i * n + j, l);
		for (int j = 1; j <= n; j ++)
			for (int i = 0; i < 4; i ++)
				if (multi(sr[j], b[i]) == 4)
					r = min(1ll * i * n + (n - j + 1), r);
		flag = false;
		if (l + r < m * n)
		{
			l ++, r ++; r = m * n - r + 1;
			//	printf("%lld %lld\n", l, r);
			lc = (l - 1) / n + 1;
			rc = (r - 1) / n + 1;
			//	printf("%lld %lld\n", lc, rc);
			l = (l - 1) % n + 1;
			r = (r - 1) % n + 1;
			//	printf("%lld %lld\n", l, r);
			if (lc == rc)
			{
				int res = 1;
				for (int i = l; i <= r; i ++)
					res = multi(res, a[i]);
				if (res == 3) flag = true;
			} else {
				int res = sr[l]; //printf("%d\n", res);
				res = multi(res, b[(rc - lc - 1) % 4]); //printf("%d\n", res);
				res = multi(res, sl[r]); //printf("%d\n", sr[r]);
				if (res == 3) flag = true;
			}
		}
		if (flag)
			printf("Case #%d: YES\n", T);
		else
			printf("Case #%d: NO\n", T);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
