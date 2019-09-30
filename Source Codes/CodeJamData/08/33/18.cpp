#include <iostream>

using	namespace	std;

const	int	maxm = 100;
const	int	maxn = 500000;
const	int	moder = 1000000007;

int	n, cases;
int	a[maxm + 1];
int	x[maxn + 1];
int	f[maxn + 1];

struct	node
{
	int	l, r, w, v, s;
};

const	int	maxnode = maxn + 1;

int	root, size;
node	t[maxnode + 1];

void	rttr(int &i)
{
	int j = t[i].l;
	t[i].l = t[j].r;
	t[j].r = i;
	t[j].s = t[i].s;
	t[i].s = ((t[t[i].l].s + t[t[i].r].s) % moder + f[t[i].v]) % moder;
	i = j;
}

void	rttl(int &i)
{
	int j = t[i].r;
	t[i].r = t[j].l;
	t[j].l = i;
	t[j].s = t[i].s;
	t[i].s = ((t[t[i].l].s + t[t[i].r].s) % moder + f[t[i].v]) % moder;
	i = j;
}

void	insert(int &i, int idx)
{
	if (!i)
	{
		i = ++size;
		t[i].l = t[i].r = 0;
		t[i].v = idx;
		t[i].s = f[idx];
		t[i].w = rand();
	}
	else if (x[idx] < x[t[i].v])
	{
		insert(t[i].l, idx);
		t[i].s = (t[i].s + f[idx]) % moder;
		if (t[t[i].l].w < t[i].w)	rttr(i);
	}
	else
	{
		insert(t[i].r, idx);
		t[i].s = (t[i].s + f[idx]) % moder;
		if (t[t[i].r].w < t[i].w)	rttl(i);
	}
}

void	init()
{
	int	m;
	long long X, Y, Z;
	scanf("%d%d%lld%lld%lld", &n, &m, &X, &Y, &Z);
	for (int i = 0; i < m; ++i)	scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i)
	{
		x[i] = a[i % m];
		a[i % m] = (X * a[i % m] + Y * (i + 1)) % Z;
	}
	root = size = 0;
}

long long	calc(int i, int xx)
{
	if (i == 0)	return	0;
	if (xx <= x[t[i].v])
		return	calc(t[i].l, xx);
	else
		return	((t[t[i].l].s + f[t[i].v]) % moder + calc(t[i].r, xx)) % moder;
}

void	solve()
{
	f[0] = 1;
	insert(root, 0);
	for (int i = 1; i < n; ++i)
	{
		f[i] = (calc(root, x[i]) + 1) % moder;
		insert(root, i);
	}
	long long       ans = 0;
	for (int i = 0; i < n; ++i)
		ans = (ans + f[i]) % moder;
	printf("Case #%d: %lld\n", ++cases, ans);
}


int	main()
{
	int	t;
	scanf("%d", &t);
	while (t--)
	{
		init();
		solve();
	}
	return	0;
}

