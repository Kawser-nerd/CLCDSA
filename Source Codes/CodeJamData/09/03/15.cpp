#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;

#define rep(i,b) for(int i=(0);i<(b);++i)
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(a,b) for(__typeof((b).begin()) a = (b).begin();a!=(b).end();++a)
#define vv vector
#define pb push_back
#define ll long long
#define ld long double
#define ss(a) (int)(a).size()
#define all(x) (x).begin(),(x).end()
#define clr(x,a) memset(x,a,sizeof(x))
#define vi vv<int>
#define vs vv<string>

int cond = (ll)1;
#define db(x) { if (cond > 0) { cond--; rep (xxx, 1) cerr << __LINE__ << " " << #x << " " << x << endl; cerr.flush(); } }


const int buf_len = 600;
char buf[buf_len];
int dp[22];
string tmp = "welcome to code jam";

int main(int argc, char ** argv) {
    ios::sync_with_stdio(false);
    cond = argc >= 2 && argv[1][0] == 'q' ? 1 << 30 : 0;
    int N;
    gets(buf);
    sscanf(buf,"%d", &N);
    int K = tmp.size();
    rep (iiii, N) { 
	    gets(buf);
	    clr(dp, 0);
	    dp[0] = 1;
	    int len = strlen(buf);
	    rep (i, len) {
		    fo (j, 0, K) db(i<<" "<<j<<" "<<dp[j]);
		    ford (j, K - 1, 0) {
			    if (tmp[j] == buf[i]) {
				    dp[j+1] += dp[j];
				    dp[j+1] %= 10000;
			    }
		    }
	    }
	    printf("Case #%d: %04d\n", iiii + 1, dp[K]);
    }
    return 0;
}

