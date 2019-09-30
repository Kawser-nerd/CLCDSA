#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <numeric>


using namespace std;

typedef long long ll;
int a[200010];
bool compare(int a,int b)
{
    return a>b;
}
int main()
{
    int n,k,x;
    cin>>n>>k;
    memset(a,0,sizeof(a));
    for(int i=0; i<n; i++)
    {
        cin>>x;
        a[x]++;
    }
    int ans=0;
    sort(a,a+n,compare);
    for(int i=k; i<=n; i++)
    {
        ans+=a[i];
    }
    cout<<ans<<endl;
    return 0;
}