#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1001

int m[MAX_SIZE];
int ti[MAX_SIZE];
int n,b;

int min_index()
{
    int i,min,r;
    min=0x7fffffff;
    for (i=0; i<b; i++)
    {
        if (min>ti[i]){
            r=i;
            min=ti[i];
        }
    }
    for (i=0; i<b; i++)
    {
        ti[i] -= min;
    }
    return r;
}

int main(void)
{
    int i,k,t,c,j,r,temp;

    FILE *in = fopen("input.txt","r");
    FILE *out = fopen("output.txt","w");

    fscanf(in,"%d",&t);

    for (c=1; c<=t; c++)
    {
        fscanf(in,"%d %d",&b,&n);
        for (i=0; i<b; i++)
            fscanf(in,"%d",&m[i]);

        for (i=0; i<b; i++)
            ti[i] = 0;

        for (i=0; i<n-1; i++)
        {
            k = min_index();
            for (j=0; j<b; j++)
                if (ti[j] != 0)
                    break;
            if (j==b && i!=0 && i!=n-2)
                break;

            temp = k;
            ti[temp]+=m[temp];
        }

        if (i<n-1)
        {
            r=i;
            for (i=0; i<n%r-1; i++)
            {
                k = min_index();
                ti[k]+=m[k];
            }
            k = min_index();

            if (n%r == 0)
                k=temp;
        }
        else
        {
            k = min_index();
        }


        fprintf(out,"Case #%d: %d\n",c,k+1);
    }

    return 0;
}
