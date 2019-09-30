#include <iostream>
using namespace std;
#define ll long long
int mod=1000000007;
 ll arr[1000]={0};
int main()
{
    ll n;
    cin>>n;
    ll x;
   
    for(int i=2;i<=n;i++)
    {
        x=i;
        for(int j=2;j<=x;j++)
        {
            while(x%j==0)
            {
                arr[j]++;
                arr[j]=arr[j]%mod;
                x=x/j;
            }
        }
        if(x!=1)
            arr[x]++;
    }
    ll count1=1;
    for(int i=1;i<=n;i++)
    {
        if(arr[i])
        {
            count1=(count1*((arr[i]+1)%mod))%mod;
        }
    }
    cout<<count1;
    return 0;
}