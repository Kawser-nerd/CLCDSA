#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define MP make_pair
#define PB push_back
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin(); e!=x.end(); ++e)

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int, int> PII;
struct bigInt
{
	int a[110];
	int operator < (const bigInt &that) const {
		if (a[0] != that.a[0])
			return a[0] < that.a[0];
		for(int i = a[0]; i >= 1; -- i)
			if (a[i] != that.a[i])
				return a[i] < that.a[i];
		return false;
	}
};

int debug = 1, ret = 0;
bigInt b[42000];
int a[110];

void output(int c)
{
	if (debug) {
		for(int i = 1; i <= c; ++ i)
			if (a[i])
				for(int j = 1; j <= c; ++ j)
					if (a[j])
						b[ret].a[i + j - 1] += a[i] * a[j];
		b[ret].a[0] = c * 2 - 1;
		/*
		for(int i = c; i >= 1; -- i)
			printf("%d", a[i]);
		printf("\n");
		for(int i = c + c - 1; i >= 1; -- i)
			printf("%d", b[ret].a[i]);
		printf("\n");
		*/
	}
	++ ret;
}

void dfs(int p, int c, int s)
{
	int st = (p == 1) ? 1 : 0;
	if (p * 2 == c) {
		for(int i = st; i <= 3; ++ i)
			if (s + 2 * i * i < 10) {
				a[p] = i;
				a[c + 1 - p] = i;
				output(c);
			}
		return;
	}
	if (p * 2 - 1 == c) {
		for(int i = st; i <= 3; ++ i)
			if (s + i * i < 10) {
				a[p] = i;
				output(c);
			}
		return;
	}
	for(int i = st; i <= 2; ++ i)
		if (s + 2 * i * i < 10) {
			a[p] = i;
			a[c + 1 - p] = i;
			dfs(p + 1, c, s + 2 * i * i);
		}
}

void prepare()
{
	for(int i = 1; i <= 50; ++ i)
		dfs(1, i, 0);
	sort(b, b + ret);
}

int l;
char buf[110];
bigInt x;

int calc(bigInt x)
{
	int l = -1, r = ret, mid;
	for( ; l + 1 < r; ) {
		mid = l + r >> 1;
		if (x < b[mid]) 
			r = mid;
		else
			l = mid;
	}
	return l + 1;
}

void solve(int test)
{
	printf("Case #%d: ", test);
	
	scanf("%s", buf);
	l = strlen(buf);
	x.a[0] = l;
	for(int i = 0; i < l; ++ i)
		x.a[l - i] = buf[i] - '0';
	int p;
	for(int i = 1; i <= l; ++ i)
		if (x.a[i] != 0) {
			p = i;
			break;
		}
	-- x.a[p];
	for(int i = 1; i < p; ++ i)
		x.a[i] = 9;
	if (x.a[x.a[0]] == 0) -- x.a[0];
	
	int ret = - calc(x);
	scanf("%s", buf);
	l = strlen(buf);
	x.a[0] = l;
	for(int i = 0; i < l; ++ i)
		x.a[l - i] = buf[i] - '0';
	ret += calc(x);
	
	cout << ret << endl;
}

int main()
{
	//freopen("C.in", "r", stdin); freopen("C.out", "w", stdout);
	//freopen("C-small-attempt0.in", "r", stdin); freopen("C-small-attempt0.out", "w", stdout);
	//freopen("C-large-1.in", "r", stdin); freopen("C-large-1.out", "w", stdout);
	freopen("C-large-2.in", "r", stdin); freopen("C-large-2.out", "w", stdout);
	prepare();
	int testcase; scanf("%d", &testcase);
	for(int i = 1; i <= testcase; ++ i) solve(i);
	fclose(stdout);
	return 0;
}
