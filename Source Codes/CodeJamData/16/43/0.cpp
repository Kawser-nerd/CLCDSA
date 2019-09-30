#include <iostream>
#include <cstring>

using namespace std;

const int maxR = 100;
const int maxN = maxR * 4;
const int maxM = maxN / 2;

int m1[maxM], m2[maxM];
int d[maxM];

char map[maxR][maxR];
int r, c;
int n;

const int fx[4] = {-1, 0, 1, 0};
const int fy[4] = {0, -1, 0, 1};

void getXyf(int i, int& x, int& y, int& f)
{
    if (i < c)
    {
        x = -1;
        y = i;
        f = 2;
    }
    else if (i < c + r)
    {
        x = i - c;
        y = c;
        f = 1;
    }
    else if (i < c + r + c)
    {
        x = r;
        y = c - 1 - (i - (c + r));
        f = 0;
    }
    else
    {
        x = r - 1 - (i - (c + r + c));
        y = -1;
        f = 3;
    }
}

bool draw(int from, int to)
{
    int x1, y1, f1, x2, y2, f2;

    getXyf(from, x1, y1, f1);
    getXyf(to, x2, y2, f2);
    
    while (true)
    {
        // move
        x1 += fx[f1];
        y1 += fy[f1];

        if (x1 < 0 || x1 >= r || y1 < 0 || y1 >= c)
        {
            if (x1 == x2 && y1 == y2)
            {
                return true;
            }
            return false;
        }

        if (map[x1][y1] == ' ')
        {
            if (f1 & 1)
            {
                map[x1][y1] = '/';
            }
            else
            {
                map[x1][y1] = '\\';
            }
        }

        if (map[x1][y1] == '/')
        {
            f1 = f1 ^ 3;
        }
        else if (map[x1][y1] == '\\')
        {
            f1 = f1 ^ 1;
        }
    }
}

bool draw(int j)
{
    if ((m2[j] - m1[j] + n) % n <= n / 2)
    {
        return draw(m1[j], m2[j]);
    }
    else
    {
        return draw(m2[j], m1[j]);
    }
}

int main()
{
    int ct, t;
    cin >> ct;
    for (int t = 1; t <= ct; t++)
    {
        cin >> r >> c;
        n = r * 2 + c * 2;

        for (int i = 0; i < n / 2; i ++)
        {
            cin >> m1[i] >> m2[i];
            m1[i] --;
            m2[i] --;
            d[i] = (m1[i] + n - m2[i]) % n;
            if (n - d[i] < d[i])
            {
                d[i] = n - d[i];
            }
        }

        memset(map, ' ', sizeof(map));
        for (int i = 1; i <= n / 2; i ++)
            for (int j = 0; j < n / 2; j ++)
                if (d[j] == i)
                {
                    if (!draw(j))
                    {
                        goto impossible;
                    }
                }

        cout << "Case #" << t << ":" << endl;
        for (int i = 0; i < r; i ++)
        {
            for (int j = 0; j < c; j ++)
            {
                cout << (map[i][j] == ' ' ? '/' : map[i][j]);
            }
            cout << endl;
        }
        continue;
impossible:
        cout << "Case #" << t << ":" << endl;
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
