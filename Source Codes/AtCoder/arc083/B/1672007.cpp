#include<iostream>
#include<vector>

#define MAX 300

using namespace std;

int g[MAX][MAX];

int main(void)
{
    int n;

    cin>>n;

    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            cin>>g[i][j];


    long long ans = 0;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < i;j++)
            ans += g[i][j];

    for(int s = 0;s < n;s++) {
        for(int e = 0;e < s;e++) {
            for(int i = 0;i < n;i++) {
                if(s == i || e == i)
                    continue;
                if(g[s][e] == g[s][i]+g[i][e]) {
                    ans -= g[s][e];
                    break;
                }
                else if(g[s][i]+g[i][e] < g[s][e])
                {
                    cout<<-1<<endl;

                    return 0;
                }
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}