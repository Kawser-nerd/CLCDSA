
#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=(b); i <= (e); ++i)
#define FORD(i,b,e) for(int i=(b); i >= (e); --i)
#define SIZE(c) (int) (c).size()
#define FORE(i,c) FOR(i,0,SIZE(c)-1)
#define FORDE(i,c) FORD(i,SIZE(c)-1,0)

#define pb push_back
#define mp make_pair
#define st first
#define nd second


using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;

typedef vector <int> VI;
typedef vector <bool> VB;
typedef vector <pii> VP;
typedef vector <ll> VL;
typedef vector <pll> VPL;

typedef vector <VI> VVI;
typedef vector <VL> VVL;
typedef vector <VB> VVB;
typedef vector <VP> VVP;

const int MOD = 1000000007;
const int INF = 1000000001;
const ll LINF = 1000000000000000001LL;

/*************************************************************************/

const int N = 102;

int dp[N][N][N][4];

int solve(int n, int p, VI &cnt) {
    FOR(i,0,n) FOR(j,0,n-i) FOR(k,0,n-i-j) FOR(rem,0,3) {
        dp[i][j][k][rem] = -INF;
    }
    
    dp[0][0][0][0] = 1;
    
    FOR(sum,0,n) FOR(i,0,sum) FOR(j,0,sum-i) {
        int k = sum - i - j;
        if (i > cnt[1] || j > cnt[2] || k > cnt[3] || k < 0) continue;
        
        FOR(rem,0,3) if (dp[i][j][k][rem] > -INF) {
            FOR(now,1,3) {
                int ni = i, nj = j, nk = k;
            
                if (now == 1) ni++;
                else if (now == 2) nj++;
                else nk++;
                
                if (max({ni, nj, nk}) > n) continue;
                
                int newRem = (rem + now) % p;
                int newAns = dp[i][j][k][rem] + (newRem == 0);
                
                dp[ni][nj][nk][newRem] = max(dp[ni][nj][nk][newRem], newAns);
            }
        }
    }
   
    int res = 0;
    FOR(rem,0,3) {
        res = max(res, dp[cnt[1]][cnt[2]][cnt[3]][rem] - (rem == 0));
    }
   
    return cnt[0] + res;
}

/*************************************************************************/

int main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    cin >> t;
    
    FOR(i,1,t) {
        cout << "Case #" << i << ": ";
        
        int n, p;
        cin >> n >> p;
        
        VI cnt(4, 0);
        FOR(_,1,n) {
            int v;
            cin >> v;
            
            cnt[v % p]++;
        }
        
        cout << solve(n, p, cnt) << '\n';
    }

    return 0;
}

/*************************************************************************/

