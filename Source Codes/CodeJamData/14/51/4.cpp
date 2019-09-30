#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

ll trans[1100000];
int T, teste;
ll n,p,q,r,s;
ll sum[1100000];

int main() {
	for (scanf("%d", &T) ;T ;T--) {
		printf("Case #%d: ", ++teste);

		scanf("%lld %lld %lld %lld %lld", &n, &p, &q, &r, &s);
		sum[0]=0; 
		for (int i = 0; i < n; i++) {
			trans[i] = ((i * p + q) % r) + s;
			//printf("trans[%d] = %lld\n", i, trans[i]);
			sum[i+1] = sum[i] + trans[i];
		}

		ll tot = sum[n];
		double best = 0;

		for (ll i = 0; i < n; i++) {
			ll prev = sum[i];
			ll rem = (tot-prev)/2;
			ll idx = lower_bound(sum+i, sum+n, prev+rem) - sum;
			
			for (ll k = max(idx-2, i); k <= min(n-1, idx+2); k++) {
				ll first = sum[k+1]-sum[i];
				ll second = sum[n]-sum[k+1];
				ll all = tot - max(first, max(second,prev));
				best = max(best, ((double)all)/tot);
			}
		}

		printf("%.15lf\n", best);
	}
}