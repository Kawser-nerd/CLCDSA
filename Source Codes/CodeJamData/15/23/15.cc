#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
typedef long long i64;
#define fu(i,m,n) for(int i=m; i<n; i++)
#define fr(i,m,n) for(typeof(m) i=m; i!=n; i++)
#define fa(i,c) fr(i,(c).begin(),(c).end())


int main(void) {
	int T;
	cin >> T;
	for(int ts=1; ts<=T; ts++) {
		cout << "Case #" << ts << ": ";
        priority_queue<pair<long,pair<int,long> > > q;
        int N; cin >> N;
        int H=0;
        fu(i,0,N) {
            long Di,Hi,Mi;
            cin >> Di >> Hi >> Mi;
            H += Hi;
            fu(h,0,Hi) {
                long D = Di;
                long M = Mi + h;
                long t0 = M*(360-D);
                q.push(make_pair(-t0,make_pair(-1,360*M)));
            }
        }
        int best=H;
        int cur=H;
        fu(i,0,H*2) {
            if(q.empty()) break;
            auto e = q.top();
            q.pop();
            cur += e.second.first;
            q.push(make_pair(e.first-e.second.second, make_pair(1, e.second.second)));

            best = min(best, cur);
        }
        cout << best << endl;
	}
}
