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

bool test(ld v, ld x, vld q1, vld q2, ld t)
{
	vector<pair<ld, int> > order2;
	foria(q1) order2.push_back(make_pair(q2[i] / q1[i], i));
	sort(all(order2));

	vi order;
	foria(order2) order.push_back(order2[i].second);

	ld c1, c2;
	bool ok1 = false, ok2 = false;
	//test 1
	c1 = c2 = 0;
	foria(order)
	{
		ld c1new = c1 + q1[order[i]] * t;
		ld c2new = c2 + q2[order[i]] * t;
		if (v <= c1new)
		{
			ld te1 = (v - c1) / q1[order[i]];
			ld c2v = c2 + q2[order[i]] * te1;
			if (c2v > x * (1 + 1e-13))
			{
				return false;
			}
			ok1 = true;
			break;
		}
		c1 = c1new;
		c2 = c2new;
	}

	reverse(all(order));
	//test 2
	c1 = c2 = 0;
	foria(order)
	{
		ld c1new = c1 + q1[order[i]] * t;
		ld c2new = c2 + q2[order[i]] * t;
		if (v <= c1new)
		{
			ld te1 = (v - c1) / q1[order[i]];
			ld c2v = c2 + q2[order[i]] * te1;
			if (c2v * (1 + 1e-13) < x)
			{
				return false;
			}
			ok2 = true;
			break;
		}
		c1 = c1new;
		c2 = c2new;
	}
	//assert(ok1 == ok2);
	return ok1;
}

ld solve(ld v, ld x, vld q1, vld q2)
{
	ld step = 1e20;
	ld cur = 0;
	while (step > 1e-20)
	{
		if (!test(v, x, q1, q2, cur + step))
			cur += step;
		step /= 2;
	}
	return cur + step;
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
		int n;
		ld v, x;
		read n >> v >> x;
		vld q1(n), q2(n);
		forin read q1[i] >> q2[i];
		x *= v;
		forin q2[i] *= q1[i];
		ld ans = solve(v, x, q1, q2);
		if (ans > 1e20)
			cout << "Case #" << gett << ": " << "IMPOSSIBLE" << endl;
		else
			cout << "Case #" << gett << ": " << ans << endl;
	}

	return 0;
}