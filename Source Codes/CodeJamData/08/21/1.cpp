#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

static ll cnt[3][3];

int main()
{
    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        ll n, A, B, C, D, X, Y, M;

        cin >> n >> A >> B >> C >> D >> X >> Y >> M;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++)
        {
            cnt[X % 3][Y % 3]++;
            X = (A * X + B) % M;
            Y = (C * Y + D) % M;
        }

        ll ans = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                ans += cnt[i][j] * (cnt[i][j] - 1) * (cnt[i][j] - 2) / 6;
        for (int i = 0; i < 3; i++)
        {
            ans += cnt[i][0] * cnt[i][1] * cnt[i][2];
            ans += cnt[0][i] * cnt[1][i] * cnt[2][i];
        }
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                {
                    if (i != j && i != k && j != k)
                        ans += cnt[0][i] * cnt[1][j] * cnt[2][k];
                }
        cout << "Case #" << cas + 1 << ": " << ans << "\n";
    }
    return 0;
}
