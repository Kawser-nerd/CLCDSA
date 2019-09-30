#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int LEN = 40;
char str[LEN];

const int REPETITION = -1;
const int DISJUNCTION = -2;
const int CONCATENATION = -3;

const int L = 20;


struct Node
{
	vector <pair<char, Node*> > edges;
	Node() : edges() {}
};

const int ALP = 10;
const int SZ = 63;
const int V = (int) 1e5;
bool used[SZ];
map <Node *, int> M;
int sz;
map <long long, int> NM;
vector <pair <char, int> > g[SZ];
int ng[V][ALP];
bool nused[V];
bool fin[V];
long long cnt[L][V][3];
int nsz;
int ns;

void clearNM()
{
	for (int i = 0; i < nsz; i++)
	{
		nused[i] = false;
	}
	nsz = 0;
	NM.clear();
}


void clearM()
{
	for (int i = 0; i < sz; i++)
	{
		used[i] = false;
		g[i].clear();
	}
	sz = 0;
	M.clear();
}

int getNid(long long mask)
{
	if (!NM.count(mask) )
	{
		NM[mask] = nsz++;
	}
	return NM[mask];
}

int getId(Node * x)
{
	if (!M.count(x) )
	{
		M[x] = sz++;
	}
	if (M[x] >= SZ) throw;
	return M[x];
}

int makeG(Node *s)
{
	int id = getId(s);
	if (used[id] ) return id;
	used[id] = true;
	for (auto to : s->edges)
	{
		int nxt = makeG(to.second);
		g[id].emplace_back(to.first, nxt);
	}
	return id;
}

long long bit(long long mask, int i)
{
	return (mask >> i) & 1LL;
}

long long closure(long long mask)
{
	for (int v = 0; v < sz; v++)
		if (bit(mask, v) )
		{
			for (auto p : g[v] )
			{
				if (p.first == 10 && !bit(mask, p.second) )
					return closure(mask | (1LL << p.second) );
			}
		}
	return mask;
}

int makeNG(long long mask, int t)
{
	mask = closure(mask);
	for (int i = 0; i < sz; i++)
		eprintf("%lld", bit(mask, i) );
	eprintf("\n");
	int v = getNid(mask);
	fin[v] = bit(mask, t);
	if (nused[v] ) return v;
	nused[v] = true;

	for (int i = 0; i < ALP; i++)
	{
		long long to = 0LL;
		for (int nv = 0; nv < sz; nv++)
			if (bit(mask, nv) )
			{
				for (auto p : g[nv] )
				{
					if (p.first == i)
						to |= (1LL << p.second);
				}
			}
		ng[v][i] = makeNG(to, t);
	}

	return v;
}


void determinateG(int s, int t)
{
	clearNM();
	eprintf("sz = %d, s = %d, t = %d\n", sz, s, t);
	ns = makeNG(1LL << s, t);
}

bool isRepetition(char s[], int l, int r)
{
	if (s[l] != '(' || s[r] != '*') return false;
	int balance = 1;
	for (int i = l + 1; i < r; i++)
	{
		if (s[i] == '(') balance++;
		if (s[i] == ')' || s[i] == '*') balance--;
		if (balance == 0) return false;
	}
	return true;
}

bool isDisjunction(char s[], int l, int r)
{
	if (s[l] != '(' || s[r] != ')') return false;
	int balance = 1;
	for (int i = l + 1; i < r; i++)
	{
		if (s[i] == '(') balance++;
		if (s[i] == ')' || s[i] == '*') balance--;
		if (balance == 0) return false;
	}
	return true;
}
		
// long long ans = solve(x, nsz, ng, ns, fin);


long long solveX(long long x, int SIZ, int G[V][ALP], int S, bool FIN[V] )
{
	if (x == 0) return 0;
	eprintf("S = %d\n", S);
	for (int i = 0; i < SIZ; i++)
	{
		eprintf("%d|%d|", i, FIN[i] );
		for (int j = 0; j < ALP; j++)
			eprintf(" %c:%d", '0' + j, G[i][j] );
		eprintf("\n");
	}

	memset(cnt, 0, sizeof cnt);
	cnt[S][0][2] = 1;

	char xx[L];
	sprintf(xx, "%lld", x);
	int len = strlen(xx);

	eprintf("len = %d\n", len);
	for (int pos = 0; pos < len; pos++)
	{
		for (int v = 0; v < SIZ; v++)
		{
			cnt[pos + 1][v][2] += cnt[pos][v][2];

			if (pos == 0)
			{
				for (int a = 1; a < xx[pos] - '0'; a++)
					cnt[pos + 1][G[v][a] ][0] += cnt[pos][v][2];
				cnt[pos + 1][G[v][xx[pos] - '0'] ][1] += cnt[pos][v][2];
			}
			else
			{
				for (int a = 1; a < 10; a++)
					cnt[pos + 1][G[v][a] ][0] += cnt[pos][v][2];
			}

			eprintf("%d, %d : %lld, %lld\n", pos, v, cnt[pos][v][0], cnt[pos][v][1] );
			for (int a = 0; a < 10; a++)
				cnt[pos + 1][G[v][a] ][0] += cnt[pos][v][0];
			
			for (int a = 0; a < xx[pos] - '0'; a++)
			{
				cnt[pos + 1][G[v][a] ][0] += cnt[pos][v][1];
			}
			cnt[pos + 1][G[v][(int) xx[pos] - '0'] ][1] += cnt[pos][v][1];
		}
	}
	long long ans = 0;
	for (int v = 0; v < SIZ; v++)
		if (FIN[v] )
			ans += cnt[len][v][0] + cnt[len][v][1];
	return ans;
}

struct Automaton
{
	Node *s, *t;
	
	Automaton() : s(), t() {}


	vector <Automaton> getChildsOr(char ss[], int l, int r)
	{
		vector <Automaton> ans;
		int balance = 0;
		int st = l + 1;
		for (int i = l + 1; i < r; i++)
		{
			if (ss[i] == '(') balance++;
			if (ss[i] == ')' || ss[i] == '*') balance--;
			if (balance == 0 && ss[i] == '|')
			{
				ans.push_back(Automaton(ss, st, i - 1) );
				st = i + 1;
			}
		}
		ans.push_back(Automaton(ss, st, r - 1) );
		return ans;
	}
	vector <Automaton> getChilds(char ss[], int l, int r)
	{
		vector <Automaton> ans;
		int balance = 0;
		int st = l;
		for (int i = l; i <= r; i++)
		{
			eprintf("i = %d, balance = %d\n", i, balance);
			if (ss[i] == '(') balance++;
			if (ss[i] == ')' || ss[i] == '*') balance--;
			if (balance == 0)
			{
				ans.push_back(Automaton(ss, st, i) );
				st = i + 1;
			}
		}
		return ans;
	}

	Automaton(char ss[], int l, int r) : s(), t()
	{
		eprintf("built %d - %d\n", l, r);
		for (int i = l; i <= r; i++)
			eprintf("%c", ss[i] );
		eprintf("\n");
		if (l == r)
		{
			s = new Node();
			t = new Node();
			s->edges.emplace_back(ss[l] - '0', t);
			return;
		}
		if (isRepetition(ss, l, r) )
		{
			s = new Node();
			t = new Node();
			Automaton nx = Automaton(ss, l + 1, r - 1);
			s->edges.emplace_back(10, nx.s);
			nx.t->edges.emplace_back(10, t);
			s->edges.emplace_back(10, t);
			t->edges.emplace_back(10, s);
			return;
		}
		if (isDisjunction(ss, l, r) )
		{
			s = new Node();
			t = new Node();
			vector <Automaton> childs = getChildsOr(ss, l, r);
			for (auto nx : childs)
			{
				s->edges.emplace_back(10, nx.s);
				nx.t->edges.emplace_back(10, t);
			}
			return;
		}
		eprintf("concatenation!\n");
		vector <Automaton> childs = getChilds(ss, l, r);
		s = childs[0].s;
		t = childs.back().t;
		for (int i = 0; i < (int) childs.size() - 1; i++)
			childs[i].t->edges.emplace_back(10, childs[i + 1].s);
	}



	void normalize()
	{
		clearM();
		sz = 0;
		makeG(s);
		eprintf("G build\n");
		eprintf("s = %d, t = %d\n", getId(s), getId(t) );
		for (int i = 0; i < sz; i++)
		{
			eprintf("%d|", i);
			for (auto p : g[i] )
				eprintf(" %c:%d", p.first + '0', p.second);
			eprintf("\n");
		}
		determinateG(getId(s), getId(t) );
	}

	long long solve(long long x)
	{
		long long ans = solveX(x, nsz, ng, ns, fin);
		return ans;
	}
};


struct RegEx
{
	Automaton A;
	RegEx() {}
	RegEx(char s[] )
	{
		int len = strlen(s);
		int pos = 0;
		for (int i = 0; i < len; i++)
		{
			if (s[i] != '*')
				s[pos++] = s[i];
			else
				s[pos - 1] = s[i];
		}
		len = pos;
		A = Automaton(s, 0, len - 1);
		eprintf("ready for normalization\n");
		A.normalize();
	}
	long long solve(long long x)
	{
		return A.solve(x);
	}
};


void solve()
{
	long long a, b;
	scanf("%lld%lld", &a, &b);
	scanf("%s", str);
	RegEx r = RegEx(str);
	eprintf("build finished\n");
	long long ans = r.solve(b) - r.solve(a - 1);
	printf("%lld\n", ans);
}

void multitest()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		printf("Case #%d: ", i);
		eprintf("Case #%d .. %d\n", i, n);
		solve();
	}


}

int main(int argc, char **)
{
	if (argc == 1)
		multitest();
	else
		solve();

	return 0;
}


