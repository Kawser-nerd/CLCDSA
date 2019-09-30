#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    int a,b,c;
    int dp[10];
    memset(dp,0,sizeof(dp));
    cin>>a>>b>>c;
    dp[a]++;
    dp[b]++;
    dp[c]++;
    if(dp[5] == 2 && dp[7] == 1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}