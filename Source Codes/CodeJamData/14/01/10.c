#include <stdio.h>

int main()
{
    int cn, cc;

    freopen("A-small-attempt0.in", "r", stdin);
    freopen("a.out", "w", stdout);

    scanf("%d", &cn);

    for (cc=1; cc<=cn; cc++)
    {
        int arr[17] = {0};
        int row;
        int mtr[4][4];
        int i,j;
        int rep = 1;
        int cnt;
        int num;

    REP:
        scanf("%d", &row);
        for (i=0; i<4; i++)
            for (j=0; j<4; j++)
            {
                scanf("%d", mtr[i]+j);
                if (i==row-1)
                    arr[mtr[i][j]]++;
            }
        if (rep)
        {
            rep = 0;
            goto REP;
        }

        cnt = 0;
        for (i=0; i<=16; i++)
            if (arr[i] == 2)
            {
                cnt++;
                num = i;
            }

        printf("Case #%d: ", cc);

        switch(cnt)
        {
        case 0:
            puts("Volunteer cheated!");
            break;
        case 1:
            printf("%d\n", num);
            break;
        default:
            puts("Bad magician!");
        }        
    }

    return 0;
}
