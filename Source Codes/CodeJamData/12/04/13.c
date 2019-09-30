#include <stdio.h>



int gcd(int a, int b)
{
    if (a<0) a=-a;
    if (b<0) b=-b;
    int c;

    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }

    return a;
}


int main()
{
    int T,tt;
    scanf("%d",&T);

    for(tt=1;tt<=T;tt++)
    {
        int h,w,d;
        int x,y;
        int i,j;
        char niz[50][50];
        int bio[200][200]={0};
        scanf("%d %d %d", &h,&w, &d);

        for(i=0;i<h;i++)
            scanf("%s",niz[i]);

        for(i=1;i<h-1;i++)
            for(j=1;j<w-1;j++)
                if (niz[i][j]=='X')
                {
                    x=i-1;y=j-1;
                }


        double x0=x+0.5;
        double y0=y+0.5;

        int ukupno=0;
        for(i=-d;i<=d;i++)
            for(j=-d;j<=d;j++)
            {
                double xx,yy;

                if (i==0 && j==0)
                    continue;

                xx=!(i&1)?x0:h-2-x0;xx+=i*(h-2);
                yy=!(j&1)?y0:w-2-y0;yy+=j*(w-2);
                if ((xx-x0)*(xx-x0)+(yy-y0)*(yy-y0)<=d*d)
                {
                    int ux=xx-x0;
                    int uy=yy-y0;
                    int g=gcd(ux,uy);
                    ux/=g;uy/=g;
                    ux+=100;uy+=100;
                    if (!bio[ux][uy])
                        ukupno++;
                    bio[ux][uy]=1;
                }
            }



        printf("Case #%d: %d\n",tt,ukupno);
    }




    return 0;
}
