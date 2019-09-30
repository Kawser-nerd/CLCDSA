#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int main()
{
    ll n, m;
    cin>>n>>m;
    ll ans = n+(m-2*n)/4;
    if(n >= m)ans = m/2;
    cout<<ans;

    return 0;
}