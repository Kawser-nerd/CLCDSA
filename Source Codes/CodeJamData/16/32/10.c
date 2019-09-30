#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
int main()
{
    FILE *fp;
    FILE *fo;
    fp = fopen("B-large.in","r");
    fo = fopen("outputa.txt","w");
   long long int i,j,T,io,array[101][101],b,m,tada,minus,max;
    fscanf(fp,"%lld",&T);
    for (io=1; io<=T; io++){
    fprintf(fo,"Case #");
    fprintf(fo,"%lld",io);
    fprintf(fo,":");
    fprintf(fo," ");
    //-----------
    fscanf(fp,"%lld",&b);
    fscanf(fp,"%lld",&m);
    max=(long long int) pow(2, b-2)+0.5;
    if(m>max){fprintf(fo,"IMPOSSIBLE");fprintf(fo,"\n");}
    else {
            fprintf(fo,"POSSIBLE");
            fprintf(fo,"\n");
          for(i=1; i<=b; i++){
        for(j=1; j<=b; j++){
            array[i][j]=0;
        }
       }
       for(i=1; i<=b; i++){
        for(j=i+1; j<=b; j++){
            array[i][j]=1;
        }
       }
       minus=max-m;

       j=b-3;
       while (minus>0){
           tada=(long long int) pow(2, j)+0.5;
        if (tada<=minus){minus=minus-tada;  array[1][b-1-j]=0; }
        j=j-1;
       }
    for(i=1; i<=b; i++){
        for(j=1; j<=b; j++){
            fprintf(fo,"%lld",array[i][j]);
        }
        fprintf(fo,"\n");
       }
    }
}
    return 0;
}
