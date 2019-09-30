#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX_N 100000
#define INF 1e15
using namespace std;
typedef long long ll;

int N;
ll H[MAX_N], S[MAX_N];

bool judge(ll border){
    vector<double> v;
    for(ll i = 0; i < N; ++i){
        double limit = (border - H[i]) / S[i];
        if(border < H[i]) return false;
        else v.push_back(limit);
    }

    sort(v.begin(), v.end());

    for(ll i = 0; i < N; ++i){
        if(v[i] < i) return false;
    }

    return true;
}

void solve(){
    ll l = 0, r = INF;
    ll ans = 0;
    while(r - l >= 1){
        ll i = (l + r) / 2;
        if(!judge(i) && judge(i+1)){
            ans = i+1;
            break;
        }
        else if(judge(i) && judge(i+1)) r = i;
        else l = i + 1;
    } 
    if(ans) cout << ans << endl;
    else while(1);
}

int main(){
    cin >> N;
    for(ll i = 0; i < N; ++i){
        scanf("%lld %lld", H+i, S+i);
    }

    solve(); 

    return 0;
}