#include<stdio.h>
int main()
{
    freopen("out.txt","w",stdout);
    long long a,b,k,t,i,j,counter,z;
    scanf("%lld",&t);
    for(z=0;z<t;z++)
    {
        counter=0;
        scanf("%lld %lld %lld",&a,&b,&k);
        if(k>=a||k>=b)
            printf("Case #%lld: %lld\n",z+1,(a*b));
        else
        {
        if(b<a)
        {
            int temp;
            temp=a;
            a=b;
            b=temp;
        }
        for(i=k;i<a;i++)
        {
            for(j=k;j<b;j++)
            {
                if((i&j)<k)
                    counter++;
            }
        }
            printf("Case #%lld: %lld\n",z+1,counter+(k*b+(a-k)*k));
        }

    }

    return 0;
}
