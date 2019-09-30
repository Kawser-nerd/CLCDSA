
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

double solve() {
    int n, k;
    cin >> n >> k;
    
    double u;
    cin >> u;
    
    vector <double> prob(n);
    FOR(i,0,n-1) {
        cin >> prob[i];
    }
    
    sort(prob.begin(), prob.end());
    
    prob.pb(1.0);
    
    FOR(i,0,n-1) {
        double sum = 0.0;
        FOR(j,0,i) sum += prob[i+1] - prob[j];
        
        if (i < n-1 && sum < u) continue;
        
        FOR(j,0,i-1) {
            u -= prob[i] - prob[j];
            prob[j] = prob[i];
        }
        
        double rest = u / (i + 1);
        FOR(j,0,i) {
            prob[j] += rest;
        }
        
        double ans = 1.0;
        FOR(j,0,n-1) {
            ans *= prob[j];
        }
        
        return ans;
    }
}

/*************************************************************************/

int main() {
    ios_base::sync_with_stdio(0);
    cout << setprecision(9) << fixed;
    
    int t;
    cin >> t;
    
    FOR(i,1,t) {
        cout << "Case #" << i << ": " << solve() << '\n';
    }

    return 0;
}

/*************************************************************************/

