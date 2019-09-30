#include <iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int quick_pow(int a,int b)
{
    int r=1,base=a;
    while(b)
    {
        if(b&1)
        r*=base;
        base*=base;
        b>>=1;
    }
    return r;
}
int main()
{
    ll x,y;
    scanf("%lld%lld",&x,&y);
    ll len=0;
    while(x<=y)
    {
        len++;
        x*=2;
    }
    cout<<len<<endl;
    return 0;
}