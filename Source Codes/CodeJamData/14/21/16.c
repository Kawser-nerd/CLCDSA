#include <stdio.h>
#include <stdlib.h>
#define MAXN 10000000

int main()
{
    int iCase, T, l1, l2, l3;
    int N;
    char str[110][110];
    int ptr[110];
    int flag;
    char curc;
    int num[110][110];
    int m, totalnum, maxnum, bestnum, curnum;

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    scanf("%d",&T);
    for (iCase=1;iCase<=T;iCase++)
    {
        scanf("%d",&N);
        for (l1=0;l1<N;l1++)
            scanf("%s",str[l1]);

        for (l1=0;l1<N;l1++)
            ptr[l1] = 0;

        m = -1;
        while (1)
        {
            flag = 1;
            curc = str[0][ptr[0]];
            for (l1=0;l1<N;l1++)
                if (str[l1][ptr[l1]]!=curc)
                {
                    flag = 0;
                    break;
                }
            if (flag == 0)
                break;
            if (curc==0)
                break;
            m++;
            for (l1=0;l1<N;l1++)
            {
                num[m][l1] = 1;
                while (1)
                {
                    ptr[l1]++;
                    if ( curc!=str[l1][ptr[l1]])
                        break;
                    num[m][l1]++;
                }
            }
        }
        if ( flag == 0 )
        {
            printf("Case #%d: Fegla Won\n", iCase);   continue;
        }

        totalnum = 0;
        for (l1=0;l1<=m;l1++)
        {
            maxnum = 0;
            for (l2=0;l2<N;l2++)
                if (num[l1][l2]>maxnum)
                    maxnum = num[l1][l2];
            bestnum = MAXN;
            for (l2=1;l2<=maxnum;l2++)
            {
                curnum = 0;
                for (l3=0;l3<N;l3++)
                    curnum+=abs(num[l1][l3]-l2);
                if (curnum<bestnum)
                    bestnum = curnum;
            }
            totalnum+=bestnum;
        }
        printf("Case #%d: %d\n",iCase,totalnum);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
