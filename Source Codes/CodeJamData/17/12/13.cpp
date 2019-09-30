#include <bits/stdc++.h>
using namespace std;

int r[55];
int dat[55][55];
int ptr[55];

int main()
{
    int T;
    scanf("%d",&T);
    for (int tt = 1; tt <= T; tt++)
    {
        printf("Case #%d: ", tt);

        int n, p;
        scanf("%d%d",&n, &p);
        for (int i = 0; i < n; i++) scanf("%d",&r[i]);
        int maxr = *max_element(r, r + n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < p; j++)
            {
                scanf("%d",&dat[i][j]);
            }
            sort(dat[i], dat[i] + p);
        }

        memset(ptr, 0, sizeof(ptr));
        int ans = 0;

        for (int mul = 1; mul * maxr <= 2000000;)
        {
            bool wrong = false;
            for (int i = 0; i < n; i++)
            {
                while (ptr[i] < p && dat[i][ptr[i]] * 10 < 9 * r[i] * mul) ++ptr[i];
                if (ptr[i] == p || dat[i][ptr[i]] * 10 > 11 * r[i] * mul)
                {
                    wrong = true;
                    break;
                }
            }

            if (wrong)
            {
                ++mul; continue;
            }

            ++ans;
            for (int i = 0; i < n; i++) ++ptr[i];
        }

        printf("%d\n", ans);
    }
}

