#include <bits/stdc++.h>
using namespace std;

char dat[55][55];

int main()
{
    int T;
    scanf("%d",&T);
    for (int tt = 1; tt <= T; tt++)
    {
        printf("Case #%d:\n", tt);

        int r, c;
        scanf("%d%d",&r,&c);
        for (int i = 1; i <= r; i++) scanf("%s",dat[i] + 1);

        map<int, vector<int>> vt;

        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                if (dat[i][j] != '?') vt[i].push_back(j);
            }
        }

        auto itr = vt.begin();
        for (int i = 1; i <= r; i++)
        {
            while (next(itr) != vt.end() && i > itr->first) ++itr;
            int idx = 0;
            for (int j = 1; j <= c; j++)
            {
                while (idx + 1 < itr->second.size() && j > itr->second[idx]) ++idx;
                printf("%c", dat[itr->first][itr->second[idx]]);
            }
            printf("\n");
        }
    }
}

