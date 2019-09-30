#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<utility>
#include<map>
#include<set>
#include<string>

using namespace std;

#define ll long long

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b){
	return a / gcd(a, b) * b;
}


int main(){
    ll ans = 1;
    ll N;
    cin >> N;
    vector<ll> T(N);
    for(int i = 0; i < N; i++) cin >> T[i];
    for(int i = 0; i < N; i++){
        ans = lcm(ans, T[i]);
    }
    cout<< ans << endl;
}