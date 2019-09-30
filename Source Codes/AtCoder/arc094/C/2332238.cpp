#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2*1e5+5;
long long n,a[N],b[N];
long long ans=0;
int main()
{
    cin>>n;
    int f=0;
    ans=0;
    for(int i=0;i<n;i++)
        {
            cin>>a[i]>>b[i];
            ans+=a[i];
            if(a[i]!=b[i])
                f=1;
        }
    if(!f)
    {
        cout<<0<<endl;
    }
    else
    {
        //sort(a,a+n);
        //sort(b,b+n);
        long long p=2000000000+7;
        for(int i=0;i<n;i++)
        {
            if(a[i]>b[i])
                p=min(p,b[i]);
        }
        cout<<ans-p<<endl;
    }
    return 0;
}