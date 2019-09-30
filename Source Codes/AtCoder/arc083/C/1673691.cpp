#include<iostream>
#include<climits>
#include<vector>

#define MAX 1100
#define INF 5000000

using namespace std;

int n,x[MAX],p[MAX];
int dp[MAX][5500];

int main(void)
{
    cin>>n;
    for(int i = 2;i <= n;i++) {
        cin>>p[i];
    }

    for(int i = 1;i <= n;i++)
    {
        cin>>x[i];
    }

    bool flag = true;
    for(int i = n;i >= 1;i--)
    {
        int f = INF;
        for(int j = 0;j <= x[i];j++)
            f = min(f,dp[i][j]);
        if(f == INF)
        {
            flag = false;
            break;
        }
        for(int j = x[p[i]];j >= 0;j--)
        {
            dp[p[i]][j] = min((j < f) ? INF : (dp[p[i]][j-f]+x[i]), (j < x[i]) ? INF : (dp[p[i]][j-x[i]]+f));
        }
    }

    if(flag)
    {
        cout<<"POSSIBLE"<<endl;
    } else {
        cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
}