#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getnp(char* team,int n)
{
    int i;
    int count=0;
    for(i=0;i<n;i++)
    {
        if (team[i]!='.')
        {
            count++;
        }
    }
    return count;
}
int getnw(char* team,int n)
{
    int i;
    int count=0;
    for(i=0;i<n;i++)
    {
        if (team[i]=='1')
        {
            count++;
        }
    }
    return count;
}

int getnnw(char* team,int n, int teamn)
{
    int i;
    int count=0;
    for(i=0;i<n;i++)
    {
        if(i!=teamn)
        {


        if (team[i]=='1')
        {
            count++;
        }
        }
    }
    return count;
}

int main()
{
    int cases,casenum=1;
    scanf("%d",&cases);
    while(cases--)
    {
        int n;
        scanf("%d",&n);
        double* wp;
        double* owp;
        double* oowp;
        double* rpi;
        int* np;

        wp=(double *)malloc(sizeof(double)*n);
        owp=(double *)malloc(sizeof(double)*n);
        oowp=(double *)malloc(sizeof(double)*n);
        rpi=(double *)malloc(sizeof(double)*n);
        np=(int *)malloc(sizeof(int)*n);

        char** grid;
        grid = (char **)malloc (sizeof(char*)*n);
        int i,j;
        char c;
        for (i=0;i<n;i++)
        {
            grid[i]=(char *)malloc(sizeof(char)*n);
            scanf("%c",&c);
            for(j=0;j<n;j++)
            {
                scanf("%c",&grid[i][j]);
            }


        }
        for(i=0;i<n;i++)
        {
            np[i]=getnp(grid[i],n);
            wp[i]=getnw(grid[i],n)*1.0/np[i];
        }
        for(i=0;i<n;i++)
        {
            double twp=0;
            double *nwp;
			nwp=(double *)malloc(sizeof(double)*(n-1));

            for(j=0;j<n;j++)
            {
                nwp[j]=getnnw(grid[j],n,i)*1.0/(np[j]-1);
            }
            for(j=0;j<n;j++)
            {

                if (grid[i][j]!='.')
                {
                    twp+=nwp[j];
                }

            }
            owp[i]=twp/(np[i]);
        }

        for(i=0;i<n;i++)
        {
            double towp=0;
            for(j=0;j<n;j++)
            {
                if (grid[i][j]!='.')
                {
                    towp+=owp[j];
                }
            }
            oowp[i]=towp/np[i];
        }

        printf("Case #%d:\n",casenum++);
        for(i=0;i<n;i++)
        {
            rpi[i]=0.25*wp[i]+0.5*owp[i]+0.25*oowp[i];
            printf("%.12g\n",rpi[i]);
        }
    }
    return 0;
}
