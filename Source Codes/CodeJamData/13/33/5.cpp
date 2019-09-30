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

struct attack
{
	ll time;
	ll left, right;
	ll val;
	bool ok;
	bool operator < (const attack &other) const
	{
		return time < other.time;
	}
};

struct seg
{
	ll from, to;
	seg *l, *r;
	ll val;
	ll ownval;

	static seg *seg_alloc();
	ll getval(){return max(val, ownval);}

	void init()
	{
		l = 0;
		r = 0;
		val = 0;
		ownval = 0;
	}

	void split()
	{
		if (l != 0)
			return;
		if (from == to)
			return;

		l = seg_alloc();
		r = seg_alloc();
		l->from = from;
		l->to = (from + to) / 2;
		while (l->to < from)
			++l->to;
		while (l->to + 1 > to)
			--l->to;
		r->from = l->to + 1;
		r->to = to;
	}

	void upd()
	{
		if (l == 0)
			return;
		val = min(l->getval(), r->getval());
	}

	ll get(ll x, ll y)
	{
		if (to < x || y < from)
			return 1000000000000000000LL;
		if (x <= from && to <= y)
			return getval();
		split();
		return max(min(l->get(x,y), r->get(x,y)), ownval);
	}
	void set(ll x, ll y, ll val)
	{
		if (to < x || y < from)
			return ;
		if (x <= from && to <= y)
		{
			ownval = max(val, ownval);
			return;
		}
		split();
		l->set(x,y,val);
		r->set(x,y,val);
		upd();
	}
	
};

seg segs[40000000];
int segs_cnt = 0;

seg *seg::seg_alloc()
{
	if (segs_cnt >= 40000000)
		throw 0;
	segs[segs_cnt].init();
	return &segs[segs_cnt++];
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

	readt;
	fort
	{
		segs_cnt = 0;

		int n;
		read n;

		vector<attack> v;
		forin
		{
			ll di, ni, wi, ei, si, ddi, dpi, dsi;
			read di >> ni >> wi >> ei >> si >> ddi >> dpi >> dsi;
			forj(ni)
			{
				attack a;
				a.ok = false;
				a.left = wi + dpi * j;
				a.right = ei + dpi * j - 1;
				a.time = di + ddi * j;
				a.val = si + dsi * j;
				v.push_back(a);
			}
		}
		sort(all(v));

		seg *root = seg::seg_alloc();
		root->from = -1000000000LL;
		root->to = 1000000000LL;

		int f = 0;
		foriv
		{
			if (v[i].time != v[f].time)
			{
				for (int k = f; k < i; k++)
				{
					root->set(v[k].left, v[k].right, v[k].val);
				}
				f = i;
			}
			if (!(root->from <= v[i].left  && v[i].right <= root->to))
				throw 0;
			ll val = root->get(v[i].left, v[i].right);
			if (val < v[i].val)
			{
				v[i].ok = true;
			}
		}
		int ans = 0;
		foriv if (v[i].ok) ++ans;

		cout << "Case #" << gett << ": " << ans << endl;
		std::cout << "Case #" << gett << ": " << ans << endl;
	}

	return 0;
}