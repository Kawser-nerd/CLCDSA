#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int T;
long long int P,L,counter;
int C;
int main(void)
{
    int i;
    long long int temp;
    FILE *in,*out;
    in=fopen("B-small.in","r");
    out=fopen("B-small.out","w");
    fscanf(in," %d",&T);
    for(i=1;i<=T;i++)
    {
        fscanf(in," %lld %lld %d",&L,&P,&C);
        temp=L;
        counter=0;
        while(1)
        {
            temp=temp*C;
            if(temp<P) counter++;
            else break;
        }
        if(!counter) fprintf(out,"Case #%d: 0\n",i);
        else fprintf(out,"Case #%d: %d\n",i,1+(int)log2(counter));
    }
    fclose(in);
    fclose(out);
    return 0;
}

