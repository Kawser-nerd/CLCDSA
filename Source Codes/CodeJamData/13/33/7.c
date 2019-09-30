#include<stdio.h>
#include<string.h>
#define mx 100000
typedef long long ll;
struct act
{
    int d,n,w,e,s,dd,dp,ds;
}a[20];
int w1[mx],w2[mx],n;
void sort()
{
    int i,j,k;
    struct act tmp;
    for(i=0;i<n;i++)
    {
        if(a[i].n==0)
        {
            tmp=a[n-1];
            a[n-1]=a[i];
            a[i]=tmp;
            i--;
            n--;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            if(a[j].d<a[j-1].d)
            {
                tmp=a[j];
                a[j]=a[j-1];
                a[j-1]=tmp;
            }
        }
    }
}
int main()
{
    freopen("C:\\TC\\BIN\\codejam2013\\in.txt","r",stdin);
    freopen("C:\\TC\\BIN\\codejam2013\\out.txt","w",stdout);


    int t,cs;
    int i,j,k,r;
    struct act tmp;

    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
        printf("Case #%d: ",cs);
        memset(&w1,0,sizeof(w1));
        memset(&w2,0,sizeof(w2));

        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d %d %d %d %d %d",&a[i].d,&a[i].n,&a[i].w,&a[i].e,&a[i].s,&a[i].dd,&a[i].dp,&a[i].ds);
        }
        sort();
        r=0;
        while(1)
        {
            for(i=0;;)
            {
                for(j=2*a[i].w;j<=(2*a[i].e);j++)
                {
                    if(j<0)
                    {
                        if(w2[-j]<a[i].s)
                        {
                            r++;
                            break;
                        }
                    }
                    else
                    {
                        if(w1[j]<a[i].s)
                        {
                            r++;
                            break;
                        }
                    }
                }
                if(((i+1)<n)&&(a[i+1].n)&&(a[i+1].d==a[i].d))
                i++;
                else
                break;
            }
            for(j=0;j<=i;j++)
            {
                for(k=2*a[j].w;k<=(2*a[j].e);k++)
                {
                    if(k<0)
                    {
                        if(w2[-k]<a[j].s)w2[-k]=a[j].s;
                    }
                    else
                    {
                        if(w1[k]<a[j].s)w1[k]=a[j].s;
                    }
                }
                a[j].n--;
                a[j].d+=a[j].dd;
                a[j].w+=a[j].dp;
                a[j].e+=a[j].dp;
                a[j].s+=a[j].ds;
            }
            sort();
            if(n==0)break;
        }
        printf("%d\n",r);
    }
    return 0;
}
