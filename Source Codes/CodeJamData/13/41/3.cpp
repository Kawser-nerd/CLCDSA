#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <bitset>
#include <complex>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <sys/time.h>
using namespace std;
#define li        long long int
#define rep(i,to) for(li i=0;i<((li)(to));++i)
#define pb        push_back
#define sz(v)     ((li)(v).size())
#define bit(n)    (1ll<<(li)(n))
#define all(vec)  (vec).begin(),(vec).end()
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define MP        make_pair
#define F         first
#define S         second


#define MAX 1050
li l[MAX];
li r[MAX];
li p[MAX];
li n, m;
const li mod = 1000002013;

li cal(li d){ return (n * d - d * (d + 1) / 2) % mod; }

int main()
{
	li T;
	cin >> T;
	rep(loop, T){
		cin >> n >> m;
		rep(i, m) cin >> l[i] >> r[i] >> p[i];
		vector<pair<li, li> > in_out;
		rep(i, m) in_out.pb(MP(l[i], -p[i]));
		rep(i, m) in_out.pb(MP(r[i], p[i]));
		sort(all(in_out));
		li ans = 0;
		vector<pair<li, li> > stack;
		rep(i, sz(in_out)){
			li pos = in_out[i].F;
			li num = abs(in_out[i].S);
			if(in_out[i].S < 0){
				stack.pb(MP(pos, num));
			}else{
				while(0 < num){
					li use = min(num, stack.back().S);
					ans = (ans - cal(pos - stack.back().F) * (use % mod)) % mod;
					num -= use;
					stack.back().S -= use;
					if(stack.back().S == 0) stack.pop_back();
				}
			}
		}
		rep(i, m) ans = (ans + cal(r[i] - l[i]) % mod * (p[i] % mod)) % mod;
		cout << "Case #" << loop + 1 << ": " << (ans + mod) % mod << endl;
	}
}












