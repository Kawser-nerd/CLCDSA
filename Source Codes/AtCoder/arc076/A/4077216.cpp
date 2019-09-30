#include<iostream>
#include<cmath>
using namespace std;
const int maxn=1e5+5;
const int mo=1e9+7;

long long a[maxn],n,m;

int main()
{
    a[1]=1;
    for(long long i=2;i<maxn;i++)
        a[i]=(a[i-1]*i)%mo;
    cin>>n>>m;
    if(n==m)
		cout<<(a[n]*a[n]*2)%mo;
    else if(abs(n-m)==1)
		cout<<(a[n]*a[m])%mo;
    else cout<<0;
    return 0;
}