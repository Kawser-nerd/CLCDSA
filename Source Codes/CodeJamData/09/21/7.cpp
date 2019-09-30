#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cassert>
#include <sstream>

#define mp make_pair
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v.size()))

using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<string> vs;

template<class T> T abs(T x){ return x > 0 ? x : (-x); }
template<class T> T sqr(T x){ return x * x; }

string s;
int cur;

void pass()
{
	while (cur < sz(s) && isspace(s[cur])) cur++;
}

int tr[100000][2];
double w[100000];
string at[100000];
int cnt;

double parse_double()
{
	pass();
	double res;
	sscanf(s.c_str() + cur, "%lf", &res);
	while (isdigit(s[cur]) || s[cur] == '.') cur++;
	return res;
}

void go(int root)
{
	pass();
	assert(s[cur] == '(');
	cur++;
	w[root] = parse_double();
	pass();
	if (s[cur] == ')')
	{
		cur++;
		return;
	}
	string an;
	while (isalpha(s[cur])) an += s[cur], cur++;
	at[root] = an;
	pass();
	cnt++;
	tr[root][0] = cnt;
	go(cnt);
	cnt++;
	tr[root][1] = cnt;
	go(cnt);
	pass();
	assert(s[cur] == ')');
	cur++;
}

set<string> attr;

double dfs(int x, double p)
{
	p *= w[x];
	if (tr[x][0] == -1) return p;
	return attr.count(at[x]) ? dfs(tr[x][0], p) : dfs(tr[x][1], p);
}

void solve(int testnum)
{
	printf("Case #%d:\n", testnum + 1);
	char ts[1000];
	gets(ts);
	int l;
	sscanf(ts, "%d", &l);
	s = "";
	for (int i = 0; i < l; i++)
	{
		gets(ts);
		s += ts;
	}
	cur = 0;
	memset(tr, -1, sizeof(tr));
	cnt = 0;
	go(0);
	gets(ts);
	int q;
	sscanf(ts, "%d", &q);
	for (int i = 0; i < q; i++)
	{
		gets(ts);
		stringstream ss(ts);
		string tmp;
		attr.clear();
		ss >> tmp;
		ss >> tmp;
		while (ss >> tmp)
			attr.insert(tmp);
		printf("%.7lf\n", dfs(0, 1.0));
	}
}

int main()
{
//	freopen("", "r", stdin);
//	freopen("", "w", stdout);
	int nc;
	char ts[100];
	gets(ts);
	sscanf(ts, "%d", &nc);
	for (int it = 0; it < nc; it++)
	{
		solve(it);
	}
	return 0;
}
