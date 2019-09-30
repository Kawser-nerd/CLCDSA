#include<iostream>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

using namespace std;
 
typedef long long int ll;

const ll INF=(ll)1e18;

int main(){
    int N;

    cin >> N;

    ll a[N][N];
    bool f[N][N];

    REP(i,N)REP(j,N)cin >> a[i][j];
    REP(i,N)REP(j,N)f[i][j] = true;

    REP(k,N)REP(i,N)REP(j,N){
        if(a[i][k] + a[k][j] < a[i][j]){
            cout << -1 << endl;
            return 0;
        }else if(a[i][k] + a[k][j] == a[i][j] && i != k && k != j){
            f[i][j] = false;
        }
    }

    ll ans = 0;
    REP(i,N)REP(j,N){
        if(f[i][j])ans+=a[i][j];
    }

    cout << ans / 2 << endl;
}