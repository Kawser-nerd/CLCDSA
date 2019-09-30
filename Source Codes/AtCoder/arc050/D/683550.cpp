#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

const int N = 200011;
const int mxn = N;

void radix(int *s, int *a, int *b, int n, int m) {
	static int c[mxn];
	fill(c, c + m + 1, 0);
	for (int i = n; i--;)
		++c[s[a[i]]];
	partial_sum(c, c + m + 1, c);
	for (int i = n; i--;)
		b[--c[s[a[i]]]] = a[i];
}

int s[N], sa[N], h[N];

void SA(int *s, int *sa, int *h, int n, int m) {
	static int a[mxn * 2], t[mxn];
	fill(a, a + n * 2, 0);
	copy(s, s + n, a);
	for (int len = 1; len / 2 < n; len *= 2) {
		auto b = a + len / 2;
		iota(sa, sa + n, 0);
		radix(b, sa, t, n, m);
		radix(a, t, sa, n, m);
		t[sa[0]] = (len < n); // ?????0?????height???????1??
		for (int i = 1; i < n; ++i)
			t[sa[i]] = t[sa[i - 1]]
				+ (a[sa[i]] != a[sa[i - 1]] || b[sa[i]] != b[sa[i - 1]]);
		copy(t, t + n, a);
		m = n;
	}
	
	int k = 0;
	for (int i = 0; i < n; ++i) {
		if (k)
			--k;
		if (a[i])
			while (s[i + k] == s[sa[a[i] - 1] + k])
				++k;
		h[a[i]] = k;
	}
}

int rk[N];
int p[N];
int st[N][20];

int rmq(int a, int b)
{
	int log2 = 31 - __builtin_clz(b - a);
	return min(st[a][log2], st[b - (1 << log2)][log2]);
}

int n;

int cc(int a, int b)
{
	int ra = rk[a];
	int rb = rk[b];
	if(ra > rb)
	{
		swap(ra, rb);
		if(rmq(ra + 1, rb + 1) == min(n - a, n - b))
			return false;
		swap(ra, rb);
	}
	else if(rmq(ra + 1, rb + 1) == min(n - a, n - b))
		return false;
	if(ra < rb)
		return -1;
	return 1;
}

bool cmp(int a, int b)
{
	bool swp = false;
	if(a < b)
	{
		swp = true;
		swap(a, b);
	}
	if(cc(a, b) > 0)
		return swp;
	else if(cc(a, b) < 0)
		return !swp;
	if(cc(b, n - a + b) > 0)
		return swp;
	else if(cc(b, n - a + b) < 0)
		return !swp;
	return false;
}

int main()
{
	ios :: sync_with_stdio(false);
	string str;
	cin >> n >> str;
	for(int i = 0; i < n; i ++)
		s[i] = str[i];
	s[n] = 0;
	SA(s, sa, h, n, 128);
	for(int i = 0; i < n; i ++)
		rk[sa[i]] = i;
	for(int i = 0; i < n; i ++)
		st[i][0] = h[i];
	for(int j = 1; j < 20; j ++)
		for(int i = 0; i < n; i ++)
			if(i + (1 << (j - 1)) < N)
				st[i][j] = min(st[i][j - 1], st[(i + (1 << (j - 1)))][j - 1]);
	iota(p, p + n, 0);
	sort(p, p + n, cmp);
	/*
	for(int i = 0; i < n; i ++)
		for(int j = i + 1; j < n; j ++)
			cout << i << ' ' << j << ' ' << cc(i, j) << '\n';
	*/
	for(int i = 0; i < n; i ++)
		cout << p[i] + 1 << '\n';
	return 0;
}