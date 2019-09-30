#include<stdio.h>
int main()
{
    int test,c,d,v,j,a[5],n,m,i,s;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%d",&test);
    for(j=0;j<test;j++)
    {
        scanf("%d%d%d",&c,&d,&v);
        for(i=0;i<d;i++)
            scanf("%d",&a[i]);
        n=0;
        s=0;
        m=1;
        for(i=0;m<=v && i<d;m++)
        {
            if(m>=a[i])
            {
                s=s+c*a[i];
                i++;
            }
            else if(m>s)
            {
                s=s+m*c;
                n++;
            }
        }
        while(m<=v)
        {
            if(m>s)
            {
                s=s+m*c;
                n++;
            }
            m++;
        }
        printf("Case #%d: %d\n",j+1,n);
    }
    return 0;
}
