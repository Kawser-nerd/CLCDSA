#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 25;
const int maxM = 50;
const int maxM2 = 16;
int data[maxN][maxN];
int xf[maxN], yf[maxN];
int x[maxM], y[maxM], n, m;
int subset_x[1 << maxM2];
int subset_y[1 << maxM2];
int dp[1 << maxM2][maxM + 1];

void dfs_y(int i, int m);

void dfs_x(int i, int m)
{
    x[m]++;
    xf[i]=1;
    for (int j = 0; j < n; j++)
    {
        if (!yf[j] && data[i][j])
            dfs_y(j, m);
    }
}

void dfs_y(int i, int m)
{
    y[m]++;
    yf[i]=1;
    for (int j = 0; j < n; j++)
    {
        if (!xf[j] && data[j][i])
            dfs_x(j, m);
    }
}

void update(int &a, int b)
{
    if (a == -1 || b < a)
    {
        a = b;
    }
}

int main()
{
    int t, ct;

    cin >> ct;
    for (t = 1; t <= ct; t++)
    {
        int ones = 0;

        cin >> n;
        for (int i = 0; i < n; i ++)
        {
            for (int j = 0; j < n; j ++)
            {
                char ch;
                cin >> ch;
                data[i][j] = ch == '1';
                ones += data[i][j];
            }
        }

        for (int i = 0; i < n; i ++)
        {
            xf[i] = 0;
            yf[i] = 0;
        }

        for (int i = 0; i < n * 2; i ++)
        {
            x[i] = 0;
            y[i] = 0;
        }
        
        m = 0;
        for (int i = 0; i < n; i ++)
        {
            if (xf[i] == 0)
            {
                dfs_x(i, m);
                m ++;
            }
            if (yf[i] == 0)
            {
                dfs_y(i, m);
                m ++;
            }
        }

        int ans = 0;
        int m2 = 0;
        int zeroone = 0, onezero = 0;
        for (int i = 0; i < m; i ++)
            if (x[i] == y[i])
            {
                ans += x[i] * y[i];
            }
            else if (x[i] == 1 && y[i] == 0)
            {
                onezero ++;
            }
            else if (x[i] == 0 && y[i] == 1)
            {
                zeroone ++;
            }
            else
            {
                x[m2] = x[i];
                y[m2] = y[i];
                m2++;
            }

        subset_x[0] = 0;
        subset_y[0] = 0;

        for (int i = 0; i < m2; i ++)
        {
            for (int j = 0; j < (1 << i); j++)
            {
                subset_x[j + (1 << i)] = subset_x[j] + x[i];
                subset_y[j + (1 << i)] = subset_y[j] + y[i];
            }
        }

        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        int dpans = -1;
        for (int i = 0; i < (1 << m2); i ++)
            for (int j = 0; j <= onezero + zeroone; j++)
                if ((j + subset_x[i] + subset_y[i]) % 2 == 0)
                {
                    int oz = (j + subset_y[i] - subset_x[i]) / 2;
                    int zo = (j + subset_x[i] - subset_y[i]) / 2;

                    if (oz >= 0 && oz <= onezero && zo >= 0 && zo <= zeroone && dp[i][j] != -1)
                    {
                        int anti_i = (1 << m2) - 1 - i;
                        for (int k = anti_i; k > 0; k = (k - 1) & anti_i)
                        {
                            int new_oz = oz;
                            int new_zo = zo;

                            if (subset_x[k] < subset_y[k])
                            {
                                new_oz += subset_y[k] - subset_x[k];
                            }
                            else
                            {
                                new_zo += subset_x[k] - subset_y[k];
                            }

                            if (new_oz <= onezero && new_zo <= zeroone)
                            {
                                update(dp[i + k][new_oz + new_zo],
                                    dp[i][j] + std::max(subset_x[k], subset_y[k]) * std::max(subset_x[k], subset_y[k]));
                            }
                        }

                        if (i == (1 << m2) - 1)
                        {
                            update(dpans, dp[i][j] + (onezero - oz));
                        }
                    }
                }

        cout << "Case #" << t << ": " << ans + dpans - ones << endl;
    }

    return 0;
}
