#include <stdio.h>

int main()
{
    int T;
    int tt;

    scanf("%d",&T);

    for(tt=1;tt<=T;tt++)
    {
            double p[100000];

            double rez,temp,prod;
            int i;
            int a,b;
            scanf("%d %d",&a,&b);



            for(i=0;i<a;i++)
                scanf("%lf",p+i);

            rez=2+b;


            int k;
            prod=1;
            for(k=0;k<=a;k++)
            {
                temp=(2*(a-k)+b-a+1)+(1-prod)*(b+1);

                if (temp<rez)
                    rez=temp;

                if (k<a)
                    prod*=p[k];
            }


            printf("Case #%d: %lf\n",tt,rez);
    }




    return 0;
}
