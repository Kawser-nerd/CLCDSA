#include <cstdio>
#include <cstring>
using namespace std;

const int max_m = 1024;
const int max_n = 128;
const int max_l = 128;
const int max_cnt = max_l * max_m;

int m, n;
char buf[max_l];
int trie[max_cnt][32], cnt;
int flag[max_cnt];

int go(int nd, char ch)
{
	int &res = trie[nd][ch - 'A'];
	if(res == -1)
		res = cnt++;
	return res;
}

void upd_flag(int nd)
{
	if(!flag[nd])
	{
		for(int ch = 0; ch < 32; ch++)
		{
			int nv = trie[nd][ch];
			if(nv != -1)
			{
				upd_flag(nv);
				flag[nd] += flag[nv];
			}
		}
	}
}

typedef long long ll;
const int mod = 1000000007;
int plus(int a, int b) {return (a + b) % mod;}
int minus(int a, int b) {return (a - b + mod) % mod;}
int times(ll a, ll b) {return int(a * b % ll(mod));}
int binom[max_n][max_n];
int perm[max_n][max_n];

int ans0, ans1;
void calc0(int nd)
{
	if(flag[nd] > n)
		ans0 += n;
	else
		ans0 += flag[nd];
	for(int ch = 0; ch < 32; ch++)
		if(trie[nd][ch] != -1)
			calc0(trie[nd][ch]);
}

void calc1(int nd)
{
	if(flag[nd] > n)
	{
		bool ok = true;
		for(int ch = 0; ch < 32; ch++)
			if(trie[nd][ch] != -1 && flag[trie[nd][ch]] > n)
				ok = false;
		if(ok)
		{
			int cans = 0;
			for(int i = 0; i <= n; i++)
			{
				int iterm = (i % 2) ? (mod - 1) : 1;
				iterm = times(iterm, binom[n][i]);
				for(int j = 0; j < 32; j++)
				{
					int nv = trie[nd][j];
					if(nv != -1)
						iterm = times(iterm, perm[n - i][flag[nv]]);
				}
				cans = plus(cans, iterm);
			}
			ans1 = times(ans1, cans);
		}
		else
		{
			for(int ch = 0; ch < 32; ch++)
				if(trie[nd][ch] != -1)
					calc1(trie[nd][ch]);
		}
	}
	else
		ans1 = times(ans1, perm[n][flag[nd]]);
}

int main()
{
	memset(binom, 0, sizeof(binom));
	binom[0][0] = 1;
	for(int i = 1; i < max_n; i++)
	{
		binom[i][0] = 1;
		for(int j = 1; j <= i; j++)
			binom[i][j] = plus(binom[i - 1][j - 1], binom[i - 1][j]);
	}
	memset(perm, 0, sizeof(perm));
	for(int i = 0; i < max_n; i++)
	{
		perm[i][0] = 1;
		for(int j = 1; j <= i; j++)
			perm[i][j] = times(perm[i][j - 1], i - (j - 1));
	}

	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%d %d", &m, &n);
		memset(trie, -1, sizeof(trie));
		memset(flag, 0, sizeof(flag));
		cnt = 1;
		for(int i = 0; i < m; i++)
		{
			scanf("%s", buf);
			int cnd = 0;
			for(int j = 0; buf[j]; j++)
				cnd = go(cnd, buf[j]);
			cnd = go(cnd, '[');
			flag[cnd] = 1;
		}
		upd_flag(0);
		/*
		for(int i = 0; i < cnt; i++)
		{
			printf("node %d flag %d\n", i, flag[i]);
			for(int j = 0; j < 32; j++)
				if(trie[i][j] != -1)
					printf("%c %d -> %d\n", 'A' + j, i, trie[i][j]);
		}
		*/
		ans0 = 0; ans1 = 1;
		calc0(0); calc1(0);
		printf("Case #%d: %d %d\n", t, ans0 - m, ans1);
	}
	return 0;
}
