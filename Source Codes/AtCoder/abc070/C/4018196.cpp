#include <iostream>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <bitset>
#include <array>
#include <deque>
#include <queue>
#include <map>
#define all(x) (x).begin(),(x).end()

void solve(){

}
ll gcd(ll a,ll b){
    return (a%b)? gcd(b,a%b):b;
}
ll lcm(ll a, ll b) {
    ll g = gcd(a,b);
    return a / g * b;
}

int main(){
    int N;
    cin >> N;
    vector<ll> t(N);
    for (int i = 0; i < N; i++){
        cin >> t[i];
    }

    ll ans = t[0];
    for (int i = 1; i < N; i++){
        ans = lcm(ans,t[i]);
    }
    cout << ans << endl;



    return 0;
}