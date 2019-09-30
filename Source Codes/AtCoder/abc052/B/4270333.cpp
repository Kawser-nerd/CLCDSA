#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#define ll long long
int main()
{
    ll x=0,n,max=0;
    char s[100];
    cin>>n;
    cin>>s;
    for(int i=0;s[i];i++)
    {
        if(s[i]=='I')
            x++;
        else
            x--;
        if(max<x)
            max=x;
    }
    cout<<max;

    return 0;
}