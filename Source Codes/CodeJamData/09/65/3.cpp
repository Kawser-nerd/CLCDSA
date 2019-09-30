#define _CRT_SECURE_NO_WARNINGS
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
#define INF 1000000
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define PB push_back
#define M_PI       3.14159265358979323846
#define eps 1.0e-11

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;


#define NAME "E-large"
#define N 1024
int n;
map<string,int> names;
vector<PII> a;
int side[N];

bool inside(PII a, int b)
{
	return a.first < b && b < a.second;
}

bool intersect(PII a, PII b)
{
	return inside(a,b.first) ^ inside(a,b.second);
}

bool fullins(PII a, PII b)
{
	return (b.first < a.first && a.second < b.second);
}

class Group
{
public:
	VPII otrs[2];
	VPII qqoo;
	int dominatedby;
	int mnx,mxx,len;
	vector<pair<Group*,PII> > children;
	int d[N],dinv[N];
	Group()
	{
		mnx=INF;
		mxx=-INF;
		len=0;
		qqoo.clear();
		REP(i,2)
			otrs[i].clear();
		children.clear();
		dominatedby=0;
	}
	void dfs(int v, int s)
	{
		if (side[v]==-1)
		{
			side[v]=s;
			otrs[s].push_back(a[v]);
			qqoo.push_back(a[v]);
			mnx=min(mnx,a[v].first);
			mxx=max(mxx,a[v].second);
			len=mxx-mnx;
		}
		else
		{
			if (side[v]!=s)
				throw 123;
			return;
		}
		REP(i,n) if (i!=v && intersect(a[i],a[v]))
			dfs(i,1-s);
	}
	PII first()
	{
		if (otrs[0].empty())
			return otrs[1].front();
		else
			return otrs[0].front();
	}
	void calc()
	{
		REP(i,SZ(children))
			children[i].first->calc();
		int top[2];
		CLEAR(top);
		REP(is,2)
		{
			REP(i,SZ(otrs[is]))
			{
				int q = 1;
				REP(j,SZ(otrs[is]))
					if (fullins(otrs[is][i], otrs[is][j]))
						q++;
				top[is]=max(top[is],q);
			}
		}
		REP(maxh1,N)
		{
			d[maxh1]=INF;
			if (maxh1 < top[0])
				continue;
			int best=top[1];
			REP(i,SZ(children))
			{
				int cur=INF;
				if (children[i].second.first <= maxh1)
				{
					cur = min(cur, children[i].second.second+children[i].first->d[maxh1-children[i].second.first]);
					cur = min(cur, children[i].second.second+children[i].first->dinv[maxh1-children[i].second.first]);
				}
				best=max(best,cur);
			}
			d[maxh1]=best;
		}
		REP(i,N-1)
			d[i+1] = min(d[i+1],d[i]);
		REP(i,N)
			dinv[i] = INF;
		REP(i,N) if (d[i]<INF)
			dinv[d[i]] = min(dinv[d[i]],i);
		REP(i,N-1)
			dinv[i+1] = min(dinv[i+1],dinv[i]);
	}
};

vector<Group*> b;

bool cmp(const Group*a, const Group*b)
{
	return a->len > b->len;
}

int stupid(vector<string> a)
{
	map<string,int> q;
	q.clear();
	bool primary[2*N];
	CLEAR(primary);
	REP(i,SZ(a))
		if (q.find(a[i])==q.end())
		{
			int w = SZ(q);
			q[a[i]]=w;
			primary[i]=true;
		}
	int res=INF;
	VI qq;
	REP(i,2*n)
		qq.push_back(q[a[i]]);
	REP(mask,1<<n)
	{
		VI stack[2];
		int mx[2];
		bool bad=false;
		CLEAR(mx);
		REP(i,2*n)
		{
			int side = (mask&(1<<qq[i]))>0?1:0;
			if (primary[i])
			{
				stack[side].push_back(qq[i]);
			}
			else
			{
				if (stack[side].empty() || stack[side].back()!=qq[i])
				{
					bad=true;
					break;
				}
				stack[side].pop_back();
			}
			REP(j,2)
				mx[j]=max(mx[j],SZ(stack[j]));
		}
			if (!bad)
				res=min(res,mx[0]+mx[1]);
	}
	if (res>=INF) res=-1;
	return res;
}

int main()
{
	freopen(NAME ".in","r",stdin);
	freopen(NAME ".out","w",stdout);

	int tests;
	scanf("%d",&tests);
	REP(tst,tests)
	{
		fprintf(stderr,"Test #%d\n",tst+1);
		names.clear();
		scanf("%d",&n);
		a.clear();
		vector<string> data;
		REP(i,2*n)
		{
			char buf[100];
			scanf("%s",buf);
			string s = string(buf);
			data.push_back(s);
			if (names.find(s)==names.end())
				names[s]=i;
			else
				a.push_back(PII(names[s],i));
		}
//int stans = n<=20?stupid(data):0;
		FILL(side,-1);
		b.clear();
		int answer;
		try
		{
			REP(i,n) if (side[i]==-1)
			{
				Group* g = new Group();
				g->dfs(i,0);
				b.push_back(g);
			}
			sort(ALL(b),cmp);
			REP(j,SZ(b)) for (int i = j-1; i>=0; i--)
			{
				int ins[2];
				CLEAR(ins);
				PII fst = b[j]->first();
				REP(is,2) REP(ii,SZ(b[i]->otrs[is]))
					if (fullins(fst,b[i]->otrs[is][ii]))
						ins[is]++;
				if (ins[0]+ins[1]>0)
				{
					b[j]->dominatedby++;
					b[i]->children.push_back(make_pair(b[j],PII(ins[0],ins[1])));
					break;
				}
			}
			REP(i,SZ(b)) if (b[i]->dominatedby==0)
			{
				b[i]->calc();
			}
			answer=INF;
			REP(top,N)
			{
				int curbot=0;
				REP(i,SZ(b)) if (b[i]->dominatedby==0)
					curbot=max(curbot,min(b[i]->d[top],b[i]->dinv[top]));
				answer = min(answer,curbot+top);
			}
			if (answer>=INF)
				answer=-1;
		} catch (int)
		{
			answer=-1;
		}
		printf("Case #%d: %d\n",tst+1,answer);
		/*if (stans!=answer&&n<=20)
			fprintf(stderr,"FUCK! %d %d\n",stans,answer);*/
	}
	return 0;
}