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

#define TEST_NAME "A-large"

int main() {
     freopen(TEST_NAME ".in","r",stdin);
     freopen(TEST_NAME ".out","w",stdout);
     int n,test;
	
     for(cin>>n,test=1;test<=n;++test) {
          char used[256]={0};
          int mapped[256];
          int base=0;
          string mes;
          VI res;
          fill(mapped,mapped+256,-1);
          cin>>mes;
          REP(i,SZ(mes)) {
               if(mapped[(unsigned char)mes[i]]<0) {
                    int k;
                    for(k=(i==0?1:0);used[k];++k);
                    used[k]=1;
                    mapped[(unsigned char)mes[i]]=k;
                    base=max(base,k+1);
               }
               res.pb(mapped[(unsigned char)mes[i]]);
          }
          ll ans=0;
          REP(i,SZ(res)) {
               ans=ans*base+res[i];
               if(ans<0)cerr<<"ERROR!!!!"<<endl;
          }
          cout<<"Case #"<<test<<": "<<ans<<endl;
     }
	
     fprintf(stderr,"running time=%.3lf\n",clock()/(double)CLOCKS_PER_SEC);
     return 0;
} 
