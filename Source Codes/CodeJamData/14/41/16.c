#include <stdio.h>


int f(const void *a, const void *b)
{
    int p=*(int *)a;
    int q=*(int *)b;

    if (p>q)
        return -1;
    return p<q;
}


int s[10000];
int bio[10000];

int main()
{
    int t,T;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        int n,x;
        scanf("%d %d",&n,&x);

        int i,j;
        int koliko=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",s+i);
            bio[i]=0;
        }

        qsort(s,n,sizeof(int),f);



        for(i=0;i<n;i++)
        {
            if (bio[i])
                continue;
            koliko++;
            for(j=i+1;j<n;j++)
            {
                if (bio[j])
                    continue;
                if (s[i]+s[j]<=x)
                {
                    bio[j]=1;
                    break;
                }
            }
        }

        printf("Case #%d: %d\n",t,koliko);
    }

    return 0;



}
