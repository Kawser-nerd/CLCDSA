#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <queue>


using namespace std;

typedef long long ll;
int c[505];
int s[505];
int f[505];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<n; i++)
        scanf("%d%d%d",&c[i],&s[i],&f[i]);
    for(int i=1; i<n; i++)
    {
        int ans=0;
        for(int j=i; j<n; j++)
        {
            if(ans<s[j])
                ans=s[j];
            if(ans%f[j]!=0)
                ans=ans+f[j]-ans%f[j];
            ans+=c[j];
        }
        printf("%d\n",ans);
    }
    cout<< 0 <<endl;
    return 0;
}