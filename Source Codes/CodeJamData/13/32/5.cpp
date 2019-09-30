/**
 * Blunt, break!
 * Actual solution is very slow
 * @author Slow Poke (slowpoke@localhost)
 */
#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
#include <ctime>
#include <bitset>
using namespace std;

#pragma comment(linker, "/stack:64000000")

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<pair<int, int > > vii;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<ld> vld;

typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vll> vvll;
typedef vector<vs> vvs;

typedef map<int, int> mpii;
typedef map<int, string> mpis;
typedef map<string, int> mpsi;
typedef map<string, string> mpss;

#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(a) (int)((a).size())
#define len(a) (int)((a).length())

#define forr(i,n) for (int i = 0; i < (n); ++i)
#define fori(n) forr(i,n)
#define forj(n) forr(j,n)
#define fork(n) forr(k,n)
#define forin fori(n)
#define forjn forj(n)
#define forjm forj(m)
#define forkm fork(m)
#define foria(a) fori(sz(a))
#define foriv foria(v)
#define foris fori(len(s))
#define forja(a) forj(sz(a))
#define forjv forj(v)
#define forjs forj(len(s))

#define read cin>>
#define write cout<<
#define writeln write endl

#define readt int aaa; read aaa;
#define gett (bbb+1)
#define fort forr(bbb,aaa)

#define issa(a,s) istringstream a(s);
#define iss(s) issa(ss,s);

ld dis(ld x, ld y) {return sqrt(x*x+y*y);}
const ld PI = acos(ld(0.0))*2;

ll gcd(ll a, ll b){return b ? gcd(b,a%b) : a;}

template<class T>
struct makev
{
    vector<T> v;
    makev& operator << (const T& x)
    {
        v.push_back(x);
        return *this;
    }
    operator vector<T>& ()
    {
        return v;
    }
};

void assert(bool b)
{
    if (!b)
        throw 0;
}

template <int n>
struct nbest
{
    vector<pair<ll, int> > p;
    nbest():p(n+1)
    {
        foria(p) p[i].first = p[i].second = -1;
    }
    void add(ll value, int key)
    {
        p[n] = make_pair(value, key);
        sort(rall(p));
    }
    ll getValue(int pos, int exceptKey = -2)
    {
        if (exceptKey == -1)
            exceptKey = -2;
        if (p[pos].second == exceptKey)
            ++pos;
        return p[pos].first;
    }
    int getKey(int pos, int exceptKey = -2)
    {
        if (exceptKey == -1)
            exceptKey = -2;
        if (p[pos].second == exceptKey)
            ++pos;
        return p[pos].second;
    }
    bool has(int pos, int exceptKey = -2)
    {
        if (exceptKey == -1)
            exceptKey = -2;
        if (p[pos].second == exceptKey)
            ++pos;
        return p[pos].second != -1;
    }
};

string solve(int x, int y, bool f, bool f2)
{
//	if (x == 1 && y == 6)
//		return "NNNWE";
	int d = abs(x) + abs(y);
	int c = 0, s = 0;
	while ((s < d) || (s % 2 != d % 2))
	{
		++c;
		s += c;
	}
	int n = c;
	vector<char> v(n + 1);

	for (int i = n; i >= 1; i--) if (v[i] == 0)
	{
		if (abs(x) >= i)
		{
			if (x >= 0)
			{
				x -= i;
				v[i] = 'E';
			}
			else
			{
				x += i;
				v[i] = 'W';
			}
		}
		else if (abs(y) >= i)
		{
			if (y >= i)
			{
				y -= i;
				v[i] = 'N';
			}
			else if (y <= -i)
			{
				y += i;
				v[i] = 'S';
			}
		}
		else
		{
			break;
		}
	}
	for (int i = n; i >= 1; i--) if (v[i] == 0)
	{
		if (y >= i || (f && y > 0))
		{
			y -= i;
			v[i] = 'N';
			if (f2)
				--i;
		}
		else if (y <= -i || (f && y < 0))
		{
			y += i;
			v[i] = 'S';
			if (f2)
				--i;
		}
	}
	if (y != 0)
		throw 0;
		//return "";

	for (int i = n; i >= 1; i--) if (v[i] == 0)
	{
		if (x >= 0)
		{
			x -= i;
			v[i] = 'E';
		}
		else
		{
			x += i;
			v[i] = 'W';
		}
	}
	if (abs(x) > 2)
		throw 0;
	if (x != 0)
		return "";
	string ans;
	foriv if (i) ans += char(v[i]);
	return ans;
}



bool check(string s, int x, int y)
{
	int ax = 0, ay = 0;
	foris
	{
		if (s[i] == 'N')
			ay += i + 1;
		else if (s[i] == 'S')
			ay -= i + 1;
		else if (s[i] == 'E')
			ax += i + 1;
		else if (s[i] == 'W')
			ax -= i + 1;
		else
			throw 0;
	}
	if (x != ax || y != ay)
		return false;
	return true;
}

string reallySolve(int xx, int yy)
{
	string ans = solve(xx, yy, false, false);
	if (ans == "")
	{
		ans = solve(yy, xx, false, false);
		if (ans == "")
		{
			ans = solve(xx, yy, true, false);
			if (ans == "")
			{
				ans = solve(xx, yy, true, true);
				if (ans == "")
					throw 0;
			}
		}
		else
		{
			fori(len(ans))
			{
				if (ans[i] == 'N')
					ans[i] = 'E';
				else if (ans[i] == 'S')
					ans[i] = 'W';
				else if (ans[i] == 'E')
					ans[i] = 'N';
				else if (ans[i] == 'W')
					ans[i] = 'S';
			}
		}
	}
	if (!check(ans, xx, yy))
	{
		throw 0;
		//cout << xx << ' ' << yy << endl;
	}
	return ans;
}

int main()
{
#ifdef _MSC_VER
	ifstream cin("input.txt");
	//freopen("input.txt", "r", stdin);
	ofstream cout("output.txt");
#else
	//ifstream cin("input.txt");
	//freopen("input.txt", "r", stdin);
	//ofstream cout("output.txt");
#endif

	/*for (int xx = 1; xx < 10000; xx++)
	{
		std::cout << xx << endl;
		for (int yy = -10000; yy < 10000; yy++) if (xx != 0 || yy != 0)
		{
			reallySolve(xx,yy);
		}
	}*/
	readt;
	fort
	{
		string ans;
		int x,y;
		read x;
		read y;


		ans = reallySolve(x,y);
		//check(ans, x, y);

		cout << "Case #" << gett << ": " << ans << endl;
		std::cout << "Case #" << gett << ": " << ans << endl;
	}

	return 0;
}