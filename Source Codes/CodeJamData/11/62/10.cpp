#include<algorithm>
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<cmath>
#include<map>
using namespace std;

int n , m , LIMIT;
int height[12][12];
int water[12][12];
int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};

bool notend()
{
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            if(height[i][j])
                return true;
    return false;
}

void onedaypass()
{
    memset(water , 0 , sizeof(water));
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            water[i][j] = 100;
    for(int t = 1 ; t <= n * m ; t++)
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= m ; j++)
                for(int f = 0 ; f < 4 ; f++)
                    water[i][j] = min(water[i][j] , max(height[i][j] , water[i+dx[f]][j+dy[f]]));
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
        {
            int maxd = 0;
            for(int f = 0 ; f < 4 ; f++)
                maxd = max(maxd , water[i][j] - water[i+dx[f]][j+dy[f]]);
            maxd = min(maxd , LIMIT);
            height[i][j] -= maxd;
        }
}

void solve()
{
    int days = 0;
    memset(height , 0 , sizeof(height));
    cin >> n >> m >> LIMIT;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            cin >> height[i][j];
    while(notend())
    {
        days ++;
        onedaypass();
    }
    cout << " " << days << endl;
}

int main()
{
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    int TestCase;
    cin >> TestCase;
    for(int CaseID = 1 ; CaseID <= TestCase ; CaseID++)
    {
        cout << "Case #" << CaseID << ":";
        solve();
    }
    return 0;
}
