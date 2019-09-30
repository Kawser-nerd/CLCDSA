#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <numeric>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define REP(i,n) FOR(i,0,n)

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)

#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 1000000000
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;

#define TEST_NAME "C-large"

VI pr;
VVI ans;

int solve(int b,int e) {
     if(e-b<=1)return 0;
     if(ans[b][e]<0) {
          int &res=ans[b][e];
          res=INF;
          FOR(i,b+1,e)
               res=min(res,pr[e]-pr[b]-2+solve(b,i)+solve(i,e));
     }
     return ans[b][e];
}

int main() {
     freopen(TEST_NAME ".in","r",stdin);
     freopen(TEST_NAME ".out","w",stdout);
     int tn,test;
	
     for(cin>>tn,test=1;test<=tn;++test) {
          int p,q;
          scanf("%d%d",&p,&q);
          pr.resize(q+2);
          pr[0]=0;pr[q+1]=p+1;
          REP(i,q)scanf("%d",&pr[i+1]);
          SORT(pr);
          ans=VVI(q+2,VI(q+2,-1));
          printf("Case #%d: %d\n",test,solve(0,q+1));
     }
	
     fprintf(stderr,"running time=%.3lf\n",clock()/(double)CLOCKS_PER_SEC);
     return 0;
} 
