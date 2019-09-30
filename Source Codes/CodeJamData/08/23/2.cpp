#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:64000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
//#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)((x).size()))

#define forn(i, x) for (int i = 0; i < int(x); i++)
#define fors(i, x) forn(i, sz(x))

template<typename T> T sqr(T x) { return x * x;            }
template<typename T> T abs(T x) { return (x > 0) ? x : -x; }

struct Node
{
	int data;
	int priority;
	int amount;
	Node *l, *r;
};

typedef Node *PNode;

int geta(PNode t)
{
	if (!t) return 0;
	return t->amount;
}

void upd(PNode t)
{
	if (!t) return;
	t->amount = geta(t->l) + geta(t->r) + 1;
}

void split(PNode t, int cut, PNode &l, PNode &r)
{
	assert(cut >= 0);
	assert(cut <= geta(t));
	if (!t) l = r = 0;
	else if (cut <= geta(t->l))
	{
		split(t->l, cut, l, t->l);
		r = t;
	}
	else
	{
		split(t->r, cut - geta(t->l) - 1, t->r, r);
		l = t;
	}
	upd(l);
	upd(r);
}

PNode merge(PNode l, PNode r)
{
	if (!l) return r;
	if (!r) return l;
	if (l->priority > r->priority)
	{
		l->r = merge(l->r, r);
		upd(l);
		upd(r);
		return l;
	}
	r->l = merge(l, r->l);
	upd(l);
	upd(r);
	return r;
}

int ans[1500000];

void doit(PNode t)
{
	if (!t) return;
	doit(t->l);
	cout << t->data << " ";
	doit(t->r);
}

int main()
{
	srand(0xdead);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int nt;
	cin >> nt;
	forn(it, nt)
	{
		int k, n;
		cin >> k >> n;
		vi d(n);
		forn(i, n) cin >> d[i];
		PNode root = 0;
		for (int i = 1; i <= k; i++)
		{
			PNode cur = new Node;
			cur->data = i;
			cur->priority = rand();
			cur->amount = 1;
			cur->l = cur->r = 0;
			root = merge(root, cur);
		}
		for (int i = 1; i <= k; i++)
		{
			PNode cur;
			int num = geta(root);
			split(root, (i - 1) % num, cur, root);
			/*
			doit(cur);
			cout << "\n";
			doit(root);
			cout << "\n";
			*/
			root = merge(root, cur);
			/*
			doit(root);
			cout << "\n";
			*/
			split(root, 1, cur, root);
			ans[cur->data - 1] = i;
			delete cur;
		}
		cout << "Case #" << (it + 1) << ": ";
		forn(i, n) cout << ans[d[i] - 1] << " ";
		cout << "\n";
		cerr << it << "\n";
	}
	return 0;
}
