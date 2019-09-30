#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
    ll a, b;
    char c;
    scanf("%lld %c %lld", &a, &c, &b);
    ll ans;
    if(c == '+')ans = a+b;
    else ans = a-b;
    cout<<ans;



    return 0;
}