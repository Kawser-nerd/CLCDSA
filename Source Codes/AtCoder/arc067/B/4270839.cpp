#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#define ll long long
int main()
{
    ll n,a,b,f=0,x,last;
    ll cha;
    cin>>n>>a>>b;
    cin>>x;
    last=x;
    for(int i=0;i<n-1;i++)
    {
        cin>>x;
        cha=(x-last)*a;
        if(cha<b)
        {
            f=f+cha;
        }
        else
        {
            f=f+b;
        }
        last=x;
    }
    cout<<f;
    return 0;
}