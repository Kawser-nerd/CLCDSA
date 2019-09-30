#include <cstdio>

int main()
{
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++)
    {
        int a1, a2, g1[4][4], g2[4][4];
        scanf("%d", &a1);
        for(int r=0; r<4; r++)
        for(int c=0; c<4; c++)
            scanf("%d", &g1[r][c]);
        scanf("%d", &a2);
        for(int r=0; r<4; r++)
        for(int c=0; c<4; c++)
            scanf("%d", &g2[r][c]);
        int cnt[17] = {};
        for(int c=0; c<4; c++)
        {
            cnt[g1[a1-1][c]]++;
            cnt[g2[a2-1][c]]++;
        }
        int res=-1, u=0;
        for(int j=1; j<=16; j++)
        {
            if(cnt[j]==2)
            {
                res=j;
                u++;
            }
        }
        if(u>1)
            printf("Case #%d: Bad magician!\n", i);
        else if(u==0)
            printf("Case #%d: Volunteer cheated!\n", i);
        else
            printf("Case #%d: %d\n", i, res);
    }
    return 0;
}
