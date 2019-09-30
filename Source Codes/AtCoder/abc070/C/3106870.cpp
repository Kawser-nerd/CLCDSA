#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;





ll gcd(ll a, ll b){
    if(a<b) swap(a,b);
    if(!b) return a;
    ll r;
    while((r = a%b)){
        a = b;
        b = r;
    }
    return b;
}

ll lcm(ll a, ll b){
    return (a/gcd(a, b))*b;
}


int main() {
    int N; cin >> N;
    vector<ll> T(N);
    for(ll& t:T) cin >> t;

    if(T.size()==1){
        cout << T[0] << endl;
        return 0;
    }

    vector<ll> l(N-1);
    for(int i=0; i<N-1; i++){
        if(i==0) l[i] = lcm(T[i], T[i+1]);
        else l[i] = lcm(l[i-1], T[i+1]);
    }

    cout << l[N-2] << endl;
    return 0;
}