#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#define ll long long
ll mod=1e9+7;
using namespace std;
map<ll,ll>q;
ll a[100];
ll solve(ll n){
    if (q[n]){
        return q[n];
    }
    if (n==0){
        return q[n]=1;
    }
    if (n==1){
        return q[n]=2;
    }
    if (n%2==0){
        return q[n]=(2*solve(n/2-1)+solve(n/2))%mod;
    }
    if (n%2){
        return q[n]=(solve(n/2-1)+2*solve(n/2))%mod;
    }
}
int main(){
    ll n;
    scanf("%lld",&n);
    solve(n);
    printf("%lld\n",q[n]);
    return 0;
} ./Main.cpp:27:1: warning: control may reach end of non-void function [-Wreturn-type]
}
^
1 warning generated.