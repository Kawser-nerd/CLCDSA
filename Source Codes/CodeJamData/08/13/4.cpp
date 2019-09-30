/*
TASK:
LANG: C++
*/

#include<stdio.h>
#include<stdlib.h>

FILE *fin,*fout;
int a[5000];
long long n;

int main()
{
    int ss,sss;
    int i;
    fin = fopen("C-large.in","r");
    fout = fopen("C-large.out","w");
    fscanf(fin,"%d",&sss);
    ////////////////////////////////////////
    a[0] = 2; a[1] = 6;
    i = 2;
    while(i<5000)
    {
        a[i] = (6*a[i-1] - 4*a[i-2] + 40000)%1000;
        //printf("%d: %d\n",i,a[i]);
        i++;
    }
    for(i=0;i<5000;i++) a[i] = (a[i]+999)%1000;
    ///////////////////////////////////////
    for(ss=1;ss<=sss;ss++)
    {
        fscanf(fin,"%lld",&n);
        printf("--%d--:%lld\n",ss,n);
        if(n<3) fprintf(fout,"Case #%d: %03d\n",ss,a[(int)n]);
        else
        {
            n = (n%100) + 100;
            fprintf(fout,"Case #%d: %03d\n",ss,a[(int)n]);
        }
    }
    system("PAUSE");
    return 0;
}
