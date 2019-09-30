#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <numeric>
using namespace std;
#define rep(i,n) for(int (i)=0;(i) < (n); (i)++)
#define x first
#define y second

int main(){
    int n,K; cin >> n >> K;
    vector<pair<long long,long long> > v(n);
    rep(i,n) cin >> v[i].x >> v[i].y; 
    long long ans = 7999999996000000001;
    rep(i,n) rep(j,n) rep(k,n) rep(l,n){
        long long int upper = v[i].y, lower = v[j].y;
        long long int left = v[k].x, right = v[l].x;
        if(upper < lower || left > right) continue;
        int c = 0;
        rep(m,n){
            if(upper >= v[m].y && lower <= v[m].y && left <= v[m].x && right >= v[m].x) c++;
        }
        if(c >= K){
            ans = min(ans, (upper - lower) * (right - left));
        }
    }
    cout << ans << endl;
    return 0;
}