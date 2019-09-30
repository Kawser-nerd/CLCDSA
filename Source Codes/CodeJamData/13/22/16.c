#include <stdio.h>


int binom[21][21];

int abs(int x)
{
    if (x<0)
        return -x;
    return x;
}

int main()
{
    int T,t;

    int i,j;

    binom[0][0]=1;
    for(i=1;i<=20;i++)
        for(j=0;j<=i;j++)
            binom[i][j]=(j>0?binom[i-1][j-1]:0)+binom[i-1][j];
    scanf("%d",&T);

    for(t=1;t<=T;t++)
    {
        double rez;
        int i,temp,q;
        int sloj;
        int n,x,y;
        scanf("%d %d %d",&n,&x,&y);
        sloj=abs(x)+abs(y);
        sloj/=2;
        temp=0;
        q=-1;
        i=1;
        while(n>=i)
        {
            n-=i;
            i+=4;
            q++;
        }



        //printf("q:%d sloj:%d n:%d x:%d y:%d\n",q,sloj,n,x,y);
        if (sloj<=q)
            rez=1;
        else if (sloj>q+1 || x==0)
            rez=0;
        else
        {
            if (n<=2*sloj)
            {
                rez=0;

                for(i=y+1;i<=n;i++)
                    rez+=binom[n][i];

                rez/=1<<n;
            } else
            {
                if (2*sloj+y+1<=n)
                    rez=1;
                else
                {
                    rez=0;
                    for(i=y+1;i<2*sloj;i++)
                        rez+=binom[n][i];
                    rez/=1<<n;


                    for(i=2*sloj;i<=n;i++)
                        rez+=(double)binom[i-1][2*sloj-1]/(1<<i);


                }


            }
        }

        printf("Case #%d: %lf\n",t,rez);
    }




    return 0;
}
