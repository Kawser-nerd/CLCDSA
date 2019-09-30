#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
typedef long long ll;

const int N=1100000;
int _,n,c;
ll l,t,a[N],ans;

int main() {
   scanf("%d",&_);
   REP(test,_) {
      scanf("%lld%lld%d%d",&l,&t,&n,&c);
      REP(i,c) scanf("%lld",&a[i]);
      REP(i,n) a[i] = a[i % c];

      vector<ll> v;
      ll tot=0;
      REP(i,n) {
	 tot += a[i]*2;
	 if (tot > t) v.push_back( min(a[i]*2,tot-t) );
      }
      sort(v.begin(),v.end(),greater<int>());
      ans=tot  *2;
      REP(i,v.size()) {
	 if (l > 0) --l, ans -= v[i];
      }

      printf("Case #%d: %lld\n",test+1,ans/2);
   }
}
