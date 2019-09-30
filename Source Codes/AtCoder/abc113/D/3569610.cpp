#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

#define M 1000000007ULL

unsigned long long dp[201][10];
unsigned long long fibt[10];

int main()
{

    fibt[1] = 1;
    fibt[2] = 1;
    for (int i = 3; i < 10; i++)
    {
        fibt[i] = fibt[i - 1] + fibt[i - 2];
    }

    int H, W, K;

    cin >> H >> W >> K;

    if(W == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    dp[0][0] = 1ULL;
    for (int h = 1; h <= H; h++)
    {
        for (int x = 0; x < W;x++)
        {
            unsigned long long X, Y, Z;
            X = Y = Z = 0ULL;

            if (x > 0)
            {
                if(x == 1 || x == W - 1)
                {
                    X = fibt[W - 1];
                }
                else
                {
                    X = fibt[x] * fibt[W - x];
                }
                dp[h][x - 1] += dp[h - 1][x] * X;
                dp[h][x - 1] %= M;
            }

            if (x == 0 || x == W - 1)
            {
                Y = fibt[W];
            }
            else
            {
                Y = fibt[x + 1] * fibt[W - x];
            }
            dp[h][x] += dp[h - 1][x] * Y;
            dp[h][x] %= M;

            if(x < W - 1)
            {
                if (x == W - 2 || x == 0)
                {
                    Z = fibt[W - 1];
                }
                else
                {
                    Z = fibt[x + 1] * fibt[W - x - 1];
                }
                dp[h][x + 1] += dp[h - 1][x] * Z;
                dp[h][x + 1] %= M;
            }
        }
    }

    cout << dp[H][K - 1] << endl;

    return 0;
}