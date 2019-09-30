#include<algorithm>
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<cmath>
#include<map>
using namespace std;

int M , A , V;
double winprob[21];
int in[21];

double win(int x)
{
    if(x <= 0)return 0;
    if(x >= V)return 1;
    return winprob[x];
}

void solve()
{
    cin >> A >> M >> V;
    memset(winprob , 0 , sizeof(winprob));
    for(int times = 1 ; times <= 10000 ; times ++)
        for(int i = 1 ; i < V ; i++)
        {
            for(int j = 1 ; j <= i ; j++)
                for(int k = 1 ; j * k <= M ; k *= 2)
                {
                    double winp = 1.0 - 1.0 / double(2 * k);
                    int lose = 2 * k - 1;
                    winprob[i] = max(winprob[i] , winp * win(i + j) + (1.0 - winp) * win(i - j * lose));
                }
        }
    int choice = 0;
    for(int i = A ; i <= A ; i++)
    {
        for(int j = 1 ; j <= i ; j++)
            for(int k = 1 ; j * k <= M ; k *= 2)
            {
                double winp = 1.0 - 1.0 / double(2 * k);
                int lose = 2 * k - 1;
                double thisans = winp * win(i + j) + (1.0 - winp) * win(i - j * lose);
                if(abs(thisans - winprob[A]) <= 1e-6)
                    choice = max(choice , j);
            }
    }
    cout << " " << winprob[A] << " " << choice << endl;
}

int main()
{
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    cout << fixed << setprecision(10);
    int TestCase;
    cin >> TestCase;
    for(int CaseID = 1 ; CaseID <= TestCase ; CaseID++)
    {
        cout << "Case #" << CaseID << ":";
        solve();
    }
    return 0;
}
