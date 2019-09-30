#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

using namespace std;
 
typedef long long int ll;

const ll INF=(ll)1e18;

int main(){
    int H,W;

    cin >> H >> W;

    int c[10][10];

    REP(i,10)REP(j,10){
        int tmp;
        cin >> tmp;
        c[i][j] = tmp; 
    }


    REP(i,10)REP(j,10)REP(k,10){
        c[j][k] = min(c[j][k], c[j][i] + c[i][k]);
    }
    // REP(i,10)REP(j,10){
    //     printf("%d %d: %d\n",i,j,c[i][j]);
    // }
    int ans = 0;
    REP(i,H)REP(j,W){
        int a;
        cin >> a;
        if(a != -1 && a != 1){
            ans += c[a][1];
        }
    }

    cout << ans << endl;

}