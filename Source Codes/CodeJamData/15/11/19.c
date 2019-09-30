#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1001

int m[MAX_SIZE];

int main(void)
{
    int n,c,k,i,sum,ans,max,rate;
    int y,z;

    FILE *in = fopen("input.txt","r");
    FILE *out = fopen("output.txt","w");

    fscanf(in,"%d",&n);

    for (c=1; c<=n; c++)
    {
        y=0; z=0; sum=0;

        fscanf(in,"%d",&k);
        for (i=0; i<k; i++)
        {
            fscanf(in,"%d",&m[i]);
        }

        //first method
        max=0;
        for (i=1; i<k; i++)
        {
            if (m[i]<m[i-1])
            {
                y+=m[i-1]-m[i];
                if (m[i-1]-m[i] > max){
                    max = m[i-1]-m[i];
                }
            }
        }

        //second method
        rate = max;

        for (i=0; i<k-1; i++)
        {
            if (m[i] < rate)
                z+= m[i];
            else
                z+=rate;
        }

        //result
        fprintf(out,"Case #%d: %d %d\n", c, y, z);
    }
}
