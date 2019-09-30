#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double ldouble;

struct tribe
{
	int d, n, l, r, s, dd, dp, ds;
};

struct attack
{
	int d, t, n;
};

const int k2 = (1 << 21) - 1;

tribe a[1010];
int n, tr[2 * k2 + 1], dv[2 * k2 + 1], xs[2000200], sz = 0, xsz = 0;
attack p[1000100];

bool operator<(const attack &a, const attack &b) { return (a.d != b.d ? a.d < b.d : a.t < b.t); }

void push(const int &x)
{
	tr[x] = max(tr[x], dv[x]);
	if (x < k2) dv[2 * x + 1] = max(dv[2 * x + 1], dv[x]), dv[2 * x + 2] = max(dv[2 * x + 2], dv[x]);
	dv[x] = 0;
}

void add(const int &x, const int &l, const int &r, const int &lt, const int &rt, const int &v)
{
	if (lt <= l && r <= rt) { dv[x] = max(dv[x], v); push(x); return; }
	push(x); if (r <= lt || rt <= l) return;
	add(2 * x + 1, l, (l + r) >> 1, lt, rt, v); add(2 * x + 2, (l + r) >> 1, r, lt, rt, v);
	tr[x] = min(tr[2 * x + 1], tr[2 * x + 2]);
}

int get(const int &x, const int &l, const int &r, const int &lt, const int &rt)
{
	push(x); if (lt <= l && r <= rt) return tr[x];
	if (r <= lt || rt <= l) return 1000000000;
	return min(get(2 * x + 1, l, (l + r) >> 1, lt, rt), get(2 * x + 2, (l + r) >> 1, r, lt, rt));
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	int ts; scanf("%d", &ts);
	for (int tst = 0; tst < ts; tst++)
	{
		int ANS = 0;
		scanf("%d", &n); sz = 0; xsz = 0;
		fill(tr, tr + 2 * k2 + 1, 0); fill(dv, dv + 2 * k2 + 1, 0);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d%d%d%d%d%d", &a[i].d, &a[i].n, &a[i].l, &a[i].r, &a[i].s, &a[i].dd, &a[i].dp, &a[i].ds);
			for (int j = 0; j < a[i].n; j++)
				xs[2 * sz] = a[i].l + j * a[i].dp, xs[2 * sz + 1] = a[i].r + j * a[i].dp,
				p[sz].d = a[i].d + j * a[i].dd, p[sz].t = i, p[sz].n = j, sz++;
		}
		sort(xs, xs + 2 * sz); xsz = unique(xs, xs + 2 * sz) - xs;
		sort(p, p + sz);
		int l = 0, r = 0;
		while (l < sz)
		{
			r = l; while (r < sz && p[r].d == p[l].d) r++;
			int lt, rt;
			for (int i = l; i < r; i++)
			{
				lt = lower_bound(xs, xs + xsz, a[p[i].t].l + a[p[i].t].dp * p[i].n) - xs;
				rt = lower_bound(xs, xs + xsz, a[p[i].t].r + a[p[i].t].dp * p[i].n) - xs;
				int s = get(0, k2, 2 * k2 + 1, lt + k2, rt + k2);
				if (s < a[p[i].t].s + a[p[i].t].ds * p[i].n) ANS++;
			}
			for (int i = l; i < r; i++)
			{
				lt = lower_bound(xs, xs + xsz, a[p[i].t].l + a[p[i].t].dp * p[i].n) - xs;
				rt = lower_bound(xs, xs + xsz, a[p[i].t].r + a[p[i].t].dp * p[i].n) - xs;
				add(0, k2, 2 * k2 + 1, lt + k2, rt + k2, a[p[i].t].s + a[p[i].t].ds * p[i].n);
			}
			l = r;
		}
		printf("Case #%d: %d\n", tst + 1, ANS);
	}
	return 0;
}