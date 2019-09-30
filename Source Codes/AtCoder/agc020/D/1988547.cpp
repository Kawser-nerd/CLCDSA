#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <ctime>
#include<complex>
#include<unordered_set>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); i--)
#define ITER(it, a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a, value) memset(a, value, sizeof(a))

#define SZ(a) (int) a.size()
#define ALL(a) a.begin(),a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const LL INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

//#define TEST
//#define DEBUG
int a, b;
int k;
bool ok(int na)
{
	int nb = max(0, (na - 1) / k);

	return (a - na + 1) * (LL)k >= b - nb;
}

string getFirst(int pos, int cnt)
{
	string res = "";
	while (cnt)
	{
		res += pos % (k + 1) == k ? 'B' : 'A';
		pos++;
		cnt--;
	}

	return res;
}

string getSecond(int pos, int cnt, int d)
{
	string res = "";
	while (cnt)
	{
		res += pos % (k + 1) == d ? 'A' : 'B';
		pos++;
		cnt--;
	}

	return res;
}

string solve(int c, int d)
{
	c--;
	d--;

	k = (max(a, b) + min(a, b)) / (min(a, b) + 1);
	int l = 0, r = a + 1;
	while (r - l > 1)
	{
		int c = (r + l) / 2;
		if (ok(c))
		{
			l = c;
		}
		else
		{
			r = c;
		}
	}

	int na = l;
	int nb = max(0, (na - 1) / k);

#ifdef DEBUG
	cout << "na=" << na << endl;
	cout << "nb=" << nb << endl;
#endif
	if (d < na + nb)
	{
		return getFirst(c, d - c + 1);
	}

	int cnt = b - nb - (a - na) * k;
	if (c >= na + nb)
	{
		c -= na + nb;
		d -= na + nb;
		return getSecond(c, d - c + 1, cnt);
	}

	string res = getFirst(c, na + nb - c);
	res += getSecond(0, d - (na + nb) + 1, cnt);
	return res;
}

bool check(string s)
{
	int k = (max(a, b) + min(a, b)) / (min(a, b) + 1);
	int cnt = 0;
	FOR(i, 0, SZ(s))
	{
		if (!i || s[i] != s[i - 1])
		{
			if (cnt > k) return false;
			cnt = 1;
			continue;
		}

		cnt++;
		if (cnt > k) return false;
	}

	return true;
}

string brute(int a, int b, int c, int d)
{
	string res;
	string t = "";
	FOR(i, 0, a) t += 'A';
	FOR(i, 0, b) t += 'B';
	res = t;
	int mx = max(a, b);
	do
	{
		int k = 0;
		int cur = 1;
		FOR(i, 0, SZ(t))
		{
			if (!i || t[i] != t[i - 1])
			{
				k = 1;
				continue;
			}

			k++;
			cur = max(cur, k);
		}

		if (cur < mx || cur == mx && t < res)
		{
			res = t;
			mx = cur;
		}
	} while (next_permutation(ALL(t)));

	c--;
	d--;
	//cout << "!" << res << endl;
	res = res.substr(c, d - c + 1);
	return res;
}


int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios::sync_with_stdio(false); cin.tie(0);
#ifdef TEST
	while (1)
	{
		cout << "*" << endl;
		a = rand() % 15 + 1;
		b = rand() % 15 + 1;
		int c = rand() % (a + b) + 1;
		int d = rand() % (a + b) + 1;
		if (d < c) swap(c, d);
		string res = solve(c, d);
		string br = brute(a, b, c, d);
		if (res != br)
		{
			cout << a << " " << b << " " << c << " " << d << endl;
			cout << res << endl;
			cout << br << endl;
			exit(0);
		}
	}
#else
	int q;
	cin >> q;
	while (q--)
	{
		int c, d;
		cin >> a >> b >> c >> d;
		string res = solve(c, d);
		cout << res << endl;
	}
#endif
} ./Main.cpp:169:29: warning: '&&' within '||' [-Wlogical-op-parentheses]
                if (cur < mx || cur == mx && t < res)
                             ~~ ~~~~~~~~~~^~~~~~~~~~
./Main.cpp:169:29: note: place parentheses around the '&&' expression to silence this warning
                if (cur < mx || cur == mx && t < res)
                                          ^
                                (                   )
1 warning generated.