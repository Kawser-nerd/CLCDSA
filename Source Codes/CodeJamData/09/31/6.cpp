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

int t, c, n,m;
char s[100], v[300];
ll x;

int main()
{
freopen("a-large.in", "r", stdin);
freopen("a-large.out", "w", stdout);
	scanf("%d", &t);
	REP(it, t)
	{
		scanf("%s", s);
		x=0;
		CL(v, -1);
		n=strlen(s);
		int k=0;
		REP(i, n)
		{
			bool t=1;
			REP(j, i) if(s[i]==s[j]) { t=0; break; }
			if(t) ++k;
		}
		if(k==1) ++k;
		m=0;
		REP(i, n)
		{
			if(v[s[i]]!=-1) c=v[s[i]];
			else
			{
				if(m==1) c=v[s[i]]=0, m=2;
				else
				{
					if(m==0) m=c=v[s[i]]=1;
					else c=v[s[i]]=m, ++m;
				}
			}
			x=k*x+c;
		}
		printf("Case #%d: %I64d\n", it+1, x);
	}
	return 0;
}
