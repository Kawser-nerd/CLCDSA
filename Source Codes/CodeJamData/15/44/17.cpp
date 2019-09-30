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

int n, m;
int mp[10][10];
int fbmask[10][10];
int ans;
set<string> ansCert;

bool normalize(int &x, int &y)
{
	if (y < 0)
		y += m;
	if (y >= m)
		y -= m;
	return x >= 0 && x < n;
}

void normalize2(int &x, int &y)
{
	if (y >= m)
	{
		y -= m;
		++x;
	}
	if (x >= n)
	{
		x -= n;
	}
}

bool check(int i, int j)
{
	int cnt = 0;
	for (int dx = -1; dx <= 1; dx += 1)
		for (int dy = -1; dy <= 1; dy += 1)
			if ((dx == 0) ^ (dy == 0))
			{
				int in = i + dx, jn = j + dy;
				if (normalize(in, jn))
					if (mp[i][j] == mp[in][jn])
						++cnt;
			}
	if (mp[i][j] != cnt)
		return false;
	return true;
}


string dump(int r)
{
	string s;
	forin forjm s += char('0' + mp[i][(j + r) % m]);
	return s;
}

string dump()
{
	string r = dump(0);
	forjm r = min(r, dump(j));
	return r;
}

void check()
{
	forin forjm
	{
		if (!check(i, j)) return;
	}

	//++ans;
	ansCert.insert(dump());
}

void gen(int x, int y)
{
	if (!(x == 0 && y == 0))
	{
		normalize2(x, y);
		if (x == 0 && y == 0)
		{
			check();
			return;
		}
	}
	for (int i = 3; i >= 1; i--) if (!(fbmask[x][y] & (1 << i))) 
	{
		mp[x][y] = i;
		if (x == 0  || check(x - 1, y))
			gen(x, y + 1);
	}
}


int main()
{
	ios::sync_with_stdio(false);
#ifdef _MSC_VER
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#else
//	ifstream cin("input.txt");
//	ofstream cout("output.txt");
#endif

	cout.setf(ios::fixed);
	cout.precision(20);

	readt;
	fort
	{
		read n >> m;
		ans = 0;
		ansCert.clear();
		gen(0, 0);
		cout << "Case #" << gett << ": " << sz(ansCert) << endl;
		std::cout << "Case #" << gett << ": " << sz(ansCert) << endl;
	}

	return 0;
}