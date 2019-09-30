#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
    ll n, a, b;
    ll ans = 0;
    ll A[100005];
    cin>>n>>a>>b;
    for(ll i = 0; i < n; i++){
        cin>>A[i];
    }
    for(ll i = 1; i < n; i++){
        if((A[i]-A[i-1])*a > b)ans += b;
        else ans += (A[i]-A[i-1])*a;
    }
    cout<<ans;


    return 0;
}