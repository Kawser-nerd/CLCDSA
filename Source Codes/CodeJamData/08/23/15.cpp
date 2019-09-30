#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define NAME "C-large"
#define N 1024000

class Tree
{
public:
	int n,root;
	int left[N],right[N],cnt[N],parent[N];
	bool killed[N];
	int Build(int l, int r)
	{
		if (l>r)
			return n;
		int root = (l+r)/2;
		cnt[root] = r-l+1;
		left[root] = Build(l,root-1);
		right[root] = Build(root+1,r);
		return root;
	}
	void Make(int n)
	{
		CLEAR(killed);
		REP(i,n)
			left[i]=right[i]=n;
		cnt[n]=0;
		this->n = n;
		root = Build(0,n-1);
		parent[root]=n;
		REP(i,n)
		{
			parent[left[i]]=i;
			parent[right[i]]=i;
		}
	}
	int Find(int v, int ind)
	{
		if (!killed[v] && ind == cnt[left[v]])
		{
			return v;
		}
		if (ind < cnt[left[v]])
			return Find(left[v],ind);
		else
		{
			ind -=cnt[left[v]];
			if (!killed[v])
				ind--;
			return Find(right[v],ind);
		}
	}
	void Delete(int v)
	{
		killed[v] = true;
		while (v!=n)
		{
			cnt[v]--;
			v=parent[v];
		}
	}
};

int a[N];
Tree qq;

void make(int n)
{
	qq.Make(n);
	int free=n;
	int curpos=0;
	for (int i = 1; i <= n; i++)
	{
		curpos += i-1;
		curpos %= free;
		int xx = qq.Find(qq.root, curpos);
		a[xx] = i;
		qq.Delete(xx);
		free--;
	}
//	REP(i,n) fprintf(stderr," %d",a[i]); fprintf(stderr,"\n");
}

bool killed[N];

void stupid(int n)
{
	CLEAR(killed);
	int x=0;
	REP(i,n)
	{
		int cnt=i+1;
		while (cnt>0)
		{
			while (killed[x])
			{
				x=(x+1)%n;
			}
			cnt--;
			if (cnt>0) x=(x+1)%n;
		}
		killed[x]=true;
		a[x]=i+1;
	}
	REP(i,n) fprintf(stderr," %d",a[i]); fprintf(stderr,"\n");
}

int main()
{
//	make(21);
//	stupid(21);

	freopen(NAME ".in","r",stdin);
	freopen(NAME ".out","w",stdout);

	int tests;
	scanf("%d",&tests);
	REP(tst,tests)
	{
		fprintf(stderr,"*");
		int k,n;
		scanf("%d%d",&k,&n);
		make(k);
		printf("Case #%d:",tst+1);
		REP(i,n)
		{
			int t;
			scanf("%d",&t);
			t--;
			printf(" %d",a[t]);
		}
		printf("\n");
	}
	return 0;
}
