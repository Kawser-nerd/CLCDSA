#include <iostream>
using namespace std;
#include <algorithm>
#include <string>
#include <vector>
#define ll long long
struct s1
{
    int timu;
    int time;
};
int main()
{

    ll n,m;
    cin>>n;
    int a[n];
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum=sum+a[i];
    }
    cin>>m;
    s1 s[m];
    for(int i=0;i<m;i++)
    {
        cin>>s[i].timu>>s[i].time;
    }
    ll t=sum;
    for(int i=0;i<m;i++)
    {
        sum=sum-a[s[i].timu-1]+s[i].time;
        cout<<sum<<endl;
        sum=t;
    }
    return 0;
}