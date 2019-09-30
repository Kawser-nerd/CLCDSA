#include <iostream>
#include<map>
using namespace std;

const int maxn = 100001;
map<long long ,int> mp;
int main()
{
    int i,j,k,n,ans= 0;
    cin>>n;

    for(i=0;i<n;i++)
    {
        scanf("%d",&k);
        mp[k]++;
    }

    for(auto it = mp.begin() ; it!=mp.end();it++)
    {
        if(it->second & 1)
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}