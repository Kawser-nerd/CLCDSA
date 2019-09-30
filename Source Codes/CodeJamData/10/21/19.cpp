#include <algorithm>
#include <iostream>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(),(a).end()
#define sz(a) int((a).size())
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)
#define UN(v) sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b) memset(a,b,sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int n,m, k, nv;
string s;
map<string, int> a[50000];

void add ()
{
	s.erase(0,1);
	int v=0;
	string x;
	int p;
	while(!s.empty())
	{
		p = s.find_first_of('/');
		if(p==-1) p=sz(s);
		x = s.substr(0, p);
//		printf("%d %s\n", p, x.c_str());
		if(!a[v].count(x)) ++k, a[v][x]=nv++;
		v = a[v][x];
		s.erase(0, p+1);
	}
}

int main()
{
#ifdef LocalHost
freopen("a-large.in", "r", stdin);//-small-attempt
freopen("a-large.out", "w", stdout);//-large
#endif
	int T;
	scanf("%d", &T);
REP(it, T)
{
	REP(i, 50000) a[i].clear();
	nv=1;
	scanf("%d%d", &n, &m);
	REP(i, n) cin>>s, add();
	k=0;
	REP(i, m) cin>>s, add();
	printf("Case #%d: %d\n", it+1, k);
}
	return 0;
}
