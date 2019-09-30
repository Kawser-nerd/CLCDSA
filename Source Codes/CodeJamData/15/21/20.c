#include<stdio.h>
int a[1000001];
int rever(int i)
{
    int rev=0,mod,ior,revt,re;
    ior=i;
    while(i)
    {
        mod=i%10;
        rev=rev*10+mod;
        i=i/10;
    }
    revt=rev;
    re=0;
    while(revt)
    {
        mod=revt%10;
        re=re*10+mod;
        revt=revt/10;
    }

    if(re!=ior)
        return 0;

    //printf("%d\n",rev);
    if(rev<ior)
        return rev;
    return 0;

}
int main()
{
    FILE *in,*op;
    in=fopen("input.in","r");
    op=fopen("output.txt","w");
    int t,n,t1,i,rev;
    fscanf(in,"%d",&t);
    for(t1=1;t1<=t;t1++)
    {
        fscanf(in,"%d",&n);
        a[0]=0;
        for(i=1;i<=n;i++)
        {
            rev=rever(i);

            if(!rev)
            {
                a[i]=a[i-1]+1;
            }
            else
            {
                if(a[rev]<a[i-1])
                    a[i]=a[rev]+1;
                else
                    a[i]=a[i-1]+1;
            }

        }

       // for(i=1;i<=n;i++)
         //   printf("%d ",a[i]);
        fprintf(op,"Case #%d: %d\n",t1,a[n]);

    }



    return 0;

}
