#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    long long a[n];
    long long sum=0;
    for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];}
    long long x=a[0],y=sum-x,ans=abs(x-y),p;
    for(int i=1;i<n-1;i++){
        x+=a[i];
        y-=a[i];
        p=abs(x-y);
        ans=min(ans,p);
    }
    cout<<ans;
    return 0;
}