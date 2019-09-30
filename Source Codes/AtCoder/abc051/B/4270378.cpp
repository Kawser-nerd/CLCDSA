#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#define ll long long
int main()
{
    ll k,s;
    ll x,y=0,z;
    cin>>k>>s;
    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<=k;j++)
        {
            x=s-i-j;
            if(x>=0&&x<=k)
            {
                y++;
            }
        }
    }
    cout<<y;


    return 0;
}