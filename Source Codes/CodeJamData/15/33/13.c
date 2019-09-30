#include<stdio.h>
int main()
{
    long int t,c,d,v,j,a[100],n,i,y,x,sum;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%ld",&t);
    for(j=1;j<t+1;j++)
    {
        scanf("%ld%ld%ld",&c,&d,&v);
        for(i=0;i<d;i++)
            scanf("%ld",&a[i]);
        y=0;
        sum=0;
        x=1;
        for(i=0;x<=v && i<d;x++)
        {
            if(x>=a[i])
            {
                sum=sum+c*a[i];
                i++;
            }
            else if(x>sum)
            {
                sum=sum+x*c;
                y++;
            }
        }
        for(;x<=v;x++)
        {
            if(x>sum)
            {
                sum=sum+x*c;
                y++;
            }
        }
        printf("Case #%ld: %ld\n",j,y);
    }
    return 0;
}
