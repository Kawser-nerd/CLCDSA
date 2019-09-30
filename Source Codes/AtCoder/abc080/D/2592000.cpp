#include <iostream>
#include <algorithm>

using namespace std;

int T[31][(100000 + 1) * 2];

int main()
{
    int N, C;
    cin >> N >> C;
    int s, t, c;
    for (int i = 0; i < N; i++)
    {
        cin >> s >> t >> c;
        T[c - 1][s * 2 - 1] = 1;
        T[c - 1][t * 2] = -1;
    }

    int ans = -1;
    int sum = 0;

    for (int i = 0; i < 200001; i++)
    {
        sum = 0;
        for (int j = 0; j < C; j++)
        {
            T[j][i + 1] += T[j][i];
            if(T[j][i] > 0)
            {
                sum++;
            }
        }
        ans = max(ans, sum);
    }
    sum = 0;
    for (int i = 0; i < C; i++)
    {
        if(T[i][200001] > 0)
        {
            sum++;
        }
    }
    ans = max(ans, sum);

    cout << ans << endl;

    return 0;
}