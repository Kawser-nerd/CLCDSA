#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char * argv[])
{
    int case_max,case_num;
    int l, p, c;
    int t;
    double b,b1,b2;
    FILE *fpin,*fpout;
    fpin=fopen("B-large.in", "r");
    fpout=fopen("B-large.out", "w");
    fscanf(fpin, "%d\n", &case_max);
    for(case_num=0; case_num<case_max; case_num++)
    {
        fscanf(fpin,"%d %d %d\n", &l, &p, &c);
        b=(double)p/(double)l;
        t=0;
        while(1)
        {
            b1=pow(2.0,t);
            b2=pow((double)c,b1);
            if(b2>=b)
                break;
            t++;
        }
        fprintf(fpout, "Case #%d: %d\n", case_num+1, t);
    }
    return 0;
}
