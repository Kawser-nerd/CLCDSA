#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>

using namespace std;

long long W, H, N;
long long memo[40][40][40][40];
vector<long long> X, Y;
map<long long, long long> mx, my;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

void init()
{
    for (int i = 0; i < 40; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            for (int k = 0; k < 40; k++)
            {
                for (int l = 0; l < 40; l++)
                {
                    memo[i][j][k][l] = -1LL;
                }
            }
        }
    }
}
long long rec(int x1, int y1, int x2, int y2)
{
    if(memo[mx[x1]][my[y1]][mx[x2]][my[y2]] != -1)
    {
        return memo[mx[x1]][my[y1]][mx[x2]][my[y2]];
    }
    long long opt = 0LL;
    for (int i = 0; i < N;i++)
    {
        long long topt = 0LL;
        if (x1 < X[i] && X[i] < x2 && y1 < Y[i] && Y[i] < y2)
        {
            //cout << "X[i]:" << X[i] << " Y[i]:" << Y[i] << endl;
            topt = X[i] - x1 + x2 - X[i] + Y[i] - y1 + y2 - Y[i] - 4;
            topt += rec(x1, y1, X[i], Y[i]) + rec(X[i], Y[i], x2, y2) + rec(X[i], y1, x2, Y[i]) + rec(x1, Y[i], X[i], y2);
        }
        opt = max(opt, topt);
    }
    //cout << "x1:" << x1 << " y1:" << y1 << " x2:" << x2 << " y2:" << y2 << " opt = " << opt << endl;
    return memo[mx[x1]][my[y1]][mx[x2]][my[y2]] = opt;
}

int main()
{
    init();
    cin >> W >> H >> N;
    vector<long long> xx, yy;
    xx.push_back(0);
    yy.push_back(0);
    xx.push_back(W + 1);
    yy.push_back(H + 1);
    for (int i = 0; i < N; i++)
    {
        long long x, y;
        cin >> x >> y;
        X.push_back(x);
        Y.push_back(y);
        xx.push_back(x);
        yy.push_back(y);
    }
    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());
    for (int i = 0; i < xx.size();i++)
    {
        mx[xx[i]] = i;
    }
    for (int i = 0; i < yy.size(); i++)
    {
        my[yy[i]] = i;
    }
    cout << rec(0, 0, W + 1, H + 1) + N << endl;
    return 0;
}