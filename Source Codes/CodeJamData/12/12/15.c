#include<stdio.h>


typedef struct
{
    int a,b;
} zapis;

int fja(const void *a, const void *b)
{
    int aa=((zapis *)a)->b-((zapis *)b)->b;
    if (aa<0)
        return -1;
    if (aa>0)
        return 1;
    aa=((zapis *)a)->a-((zapis *)b)->a;
    if (aa>0)
        return -1;
    if (aa<0)
        return 1;
    return 0;
}


int main()
{
    int T;

    scanf("%d",&T);

    int tt;

    for(tt=1;tt<=T;tt++)
    {
        int rez;
        int rez1,rez2;
        int koliko;
        int n;
        zapis z[1000];
        int bio[1000]={0};
        int i;

        int temp;

        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d %d",&z[i].a,&z[i].b);


        rez=0;rez1=0;rez2=0;
        koliko=0;
        int broj=0;
        qsort(z,n,sizeof(zapis),fja);


        int ii=0;


        while(1)
        {
            int i,j;
            int pomak=0;

            for(i=ii;i<n && z[i].b<=rez;i++)
            {
                if (bio[i]==2)
                    continue;
                if (bio[i]==0)
                    rez+=2;
                else
                    rez++;
                broj++;
                koliko++;
                pomak=1;
                bio[i]=2;
            }
            ii=i;


            for(i=n-1;i>=0;i--)
            {
                if (bio[i]==0 && z[i].a<=rez)
                {
                    pomak=1;
                    broj++;
                    rez++;
                    bio[i]=1;
                    break;
                }
            }

            if (!pomak)
                break;
        }

        printf("Case #%d: ",tt);
        if (koliko<n)
            printf("Too Bad\n");
        else
            printf("%d\n",broj);
    }

    return 0;
}
