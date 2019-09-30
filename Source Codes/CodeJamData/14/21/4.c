#include <stdio.h>


int fja(const void *a, const void *b)
{
    int p=*(int *)a;
    int q=*(int *)b;

    if (p<q)
        return -1;
    if (p>q)
        return 1;
    return 0;
}


int rez(int *a, int n)
{
    int i;
    qsort(a,n,sizeof(int),fja);
    int ukupno=0;

    for(i=0;2*i<n;i++)
        ukupno+=a[n/2]-a[i];
    for(;i<n;i++)
        ukupno+=a[i]-a[n/2];

    return ukupno;
}


int main()
{
    int t,T;

    scanf("%d",&T);

    for(t=1;t<=T;t++)
    {
        char niz[100][200];
        char *p[100];
        int a[100];
        int n,i;
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            scanf("%s",niz+i);
            p[i]=niz[i];
        }


        int ukupno=0;
        while(1)
        {
            char znak=*(p[0]);
            for(i=0;i<n;i++)
            {
                a[i]=0;
                while(*(p[i])==znak)
                {
                    p[i]++;
                    a[i]++;
                    if (!znak)
                        break;
                }
                if (a[i]==0)
                    break;
            }

            ukupno+=rez(a,n);
            if (i<n)
            {
                ukupno=-1;
                break;
            }
            if (znak==0)
                break;
        }
        printf("Case #%d: ",t);
        if (ukupno<0)
            printf("Fegla won\n");
        else
            printf("%d\n",ukupno);


    }
    return 0;
}
