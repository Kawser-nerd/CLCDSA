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
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b)-1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MAX = 2 * 100000 + 47;
const int MOD = 1000 * 1000 * 1000 + 7;

int A[MAX];
void sim(string& s)
{
	int p = 0;
	int d = 1;
	while (1)
	{
		if (p == -1 || p == SZ(s)) break;
		if (s[p] == 'A')
		{
			s[p] = 'B';
			d *= -1;
			p += d;
			continue;
		}
		else
		{
			s[p] = 'A';
			p += d;
		}
	}
}

void sim(string& s, int k)
{
	FOR(i, 0, k)
	{
		sim(s);
	}
}

void calc(string& s, int k)
{
	int rev = 0;
	int p = 0;
	int n = SZ(s);
	if (n == 1)
	{
		s[0] = ((s[0] - 'A') ^ (k & 1)) + 'A';
		return;
	}

	FOR(i, 0, n) A[i] = s[i] == 'B';

	FOR(i, 0, min(k, 4 * n + k % 2))
	{
		if (A[p] ^ rev == 0)
		{
			A[p] ^= 1;
			continue;
		}

		rev ^= 1;
		A[p] = rev;
		p++;
		if (p == n) p = 0;
	}

	FOR(k, 0, n)
	{
		int i = p + k;
		if (i >= n) i -= n;

		s[k] = (A[i] ^ rev) + 'A';
	}
}

string s;
int k, n;
void gen()
{
	n = rand() % 10 + 1;
	s.clear();
	FOR(i, 0, n)
	{
		s.push_back(rand() % 2 + 'A');
	}

	k = rand() % 10 + 1;
}

//#define TEST

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);

#ifdef TEST
	while (1)
	{
		gen();
		cout << s << " " << k << endl;
		string s1 = s;
		calc(s, k);
		sim(s1, k);
		if (s1 != s)
		{
			cout << "fail" << endl;
			cout << s << endl;
			cout << s1 << endl;
			return 0;
		}
	}
#else
	cin >> n >> k >> s;
	calc(s, k);
	cout << s << endl;
#endif

} ./Main.cpp:91:12: warning: ^ has lower precedence than ==; == will be evaluated first [-Wparentheses]
                if (A[p] ^ rev == 0)
                         ^~~~~~~~~~
./Main.cpp:91:12: note: place parentheses around the '==' expression to silence this warning
                if (A[p] ^ rev == 0)
                         ^
                           (       )
./Main.cpp:91:12: note: place parentheses around the ^ expression to evaluate it first
                if (A[p] ^ rev == 0)
                         ^
                    (         )
1 warning generated.