#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define show(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll dist[51][51];
int a[50];
int b[50];
int main(){
    int n;
    cin >> n;
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n){
        cin >> b[i];
    }
    rep(i,51)rep(j,51)dist[i][j] = 1LL<<60;
    rep(i,51)dist[i][i] = 0;
    for(int i = 1;i <= 50; i++){
        for(int j = 1; j <= 50; j++){
            dist[i][i%j] = min(dist[i][i%j],1LL<<j);
        }
    }
    ll ans = 0;
    for(;;){
        rep(k,51){
            rep(j,51){
                rep(i,51){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        ll temp = 0;
        rep(i,n){
            temp = max(temp,dist[a[i]][b[i]]);
        }
        if(temp==1LL<<60){
            cout << -1 << endl;
            return 0;
        }
        if(temp == 0)break;
        int k = (int)log2(temp);
        ans += 1LL<<k;
        rep(i,51){
            dist[i][i%k] = 0;
        }
    }
    cout << ans << endl;
}