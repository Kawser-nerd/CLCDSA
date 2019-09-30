#include <stdio.h>



void citaj(int *moze)
{
    int i,j;
    int q,r;
    scanf("%d",&q);
    q--;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        {
            scanf("%d",&r);
            if (q==i)
                moze[r]++;
        }
}



int main()
{
    int t,T;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        int moze[17]={0};

        citaj(moze);
        citaj(moze);

        int i,q,k=0;
        for(i=1;i<=16;i++)
            if (moze[i]==2)
            {
                q=i;
                k++;
            }

        printf("Case #%d: ",t);
        if (k==0)
            printf("Volunteer cheated!");
        if (k==1)
            printf("%d",q);
        if (k>1)
            printf("Bad magician!");
        printf("\n");
    }
    return 0;
}
