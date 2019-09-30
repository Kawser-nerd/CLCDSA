#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

using namespace std;
 
typedef long long int ll;

const ll INF=(ll)1e18;

ll d[201][201];

int main(){
    int N, M, R;
    cin >> N >> M >> R;
    vector<int> r;

    REP(i,R){
        int tmp;
        cin >> tmp;
        r.push_back(tmp);
    }
    
    sort(r.begin(),r.end());

    REP(i,N+1)REP(j,N+1)d[i][j] = INF;

    REP(i,M){
        int a,b,c;
        cin >> a >> b >>c;
        d[a][b] = c;
        d[b][a] = c;
    }


    REP(i,N+1)REP(j,N+1)REP(k,N+1){
        d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
    }

    ll ans = INF;
    do {
        ll tmp = 0;
        REP(i,R-1){
            tmp += d[r[i]][r[i+1]];
        }
        ans = min(ans,tmp);
    } while (std::next_permutation(r.begin(), r.end()));

    cout << ans << endl;

}