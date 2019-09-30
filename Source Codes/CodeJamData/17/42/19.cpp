
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

pii solve(int n, int c, int m, VP &ticket) {
    VI posCnt(n, 0);
    for (auto &t : ticket) {
        posCnt[t.st]++;
    }
    
    VI posCntPref = posCnt;
    FOR(i,1,n-1) posCntPref[i] += posCntPref[i-1];
    
    VI customerCnt(c, 0);
    for (auto &t : ticket) {
        customerCnt[t.nd]++;
    }
    
    int rides = *max_element(customerCnt.begin(), customerCnt.end());
    
    FOR(i,0,n-1) {
        while (rides * (i + 1) < posCntPref[i]) {
            rides++;
        }
    }
    
    int promo = 0;
    FOR(i,0,n-1) {
        promo += max(0, posCnt[i] - rides);
    }
    
    return {rides, promo};
}

/*************************************************************************/

int main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    cin >> t;
    
    FOR(i,1,t) {
        cout << "Case #" << i << ": ";
        
        int n, c, m;
        cin >> n >> c >> m;
        
        VP ticket(m);
        FOR(i,0,m-1) {
            cin >> ticket[i].st >> ticket[i].nd;
            
            ticket[i].st--;
            ticket[i].nd--;
        }
        
        auto ans = solve(n, c, m, ticket);
        
        cout << ans.st << ' ' << ans.nd << '\n';
    }

    return 0;
}

/*************************************************************************/

