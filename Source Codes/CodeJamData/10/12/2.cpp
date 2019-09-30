#include<algorithm>
#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

int T , n , limit , Del , Ins , ans;
int dp[101][256];
int x[101];

int main()
{
    freopen("B.in" , "r" , stdin);
    freopen("B.out" , "w" , stdout);
    cin>>T;
    for(int caseID = 1 ; caseID <= T ;caseID ++)
    {
        cin>>Del>>Ins>>limit>>n;
        memset(dp , 0 , sizeof(dp));
        ans = ~0U>>1;
        for(int i = 1 ; i <= n ; i++)
        {
            cin>>x[i];
            for(int j = 0 ; j <= 255 ; j++)
            {
                dp[i][j] = dp[i-1][j] + Del;
                for(int k = 0 ; k <= 255 ; k++)
                    if(abs(j - k) <= limit)
                        dp[i][j] = min(dp[i][j] , dp[i-1][k] + abs(x[i] - j));
            }
            for(int j = 0 ; j <= 255 ; j++)
                for(int k = 0 ; k <= 255 ; k++)
                    if(abs(j - k) <= limit)
                        dp[i][j] = min(dp[i][j] , dp[i][k] + Ins);
            for(int j = 255 ; j >= 0 ; j--)
                for(int k = 0 ; k <= 255 ; k++)
                    if(abs(j - k) <= limit)
                        dp[i][j] = min(dp[i][j] , dp[i][k] + Ins);
            if(i == n)
                for(int j = 0 ; j <= 255 ; j++)
                    ans = min(ans , dp[i][j]);
        }
        cout<<"Case #"<<caseID<<": "<<ans<<endl;
    }
    return 0;
}
