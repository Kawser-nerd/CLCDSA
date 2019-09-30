#include <map>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
const int MAXN = 2e3+55;
int a[MAXN];
int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; ++i)
        cin>>a[i];
    int ans = 1000000000;
    for(int k = -100; k <= 100; ++k)
    {
        int sum = 0;
        for(int i = 0; i < n; ++i)
        {
            sum += (a[i]-k)*(a[i]-k);
        }
        ans = min(ans,sum);
    }
    cout<<ans;
    return 0;
}