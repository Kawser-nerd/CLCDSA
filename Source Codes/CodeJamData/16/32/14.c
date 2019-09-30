#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
int main()
{
    FILE *fp;
    FILE *fo;
    fp = fopen("inputa.in","r");
    fo = fopen("outputa.txt","w");
    int i,j,T,io,array[60][60],b,m,tada,minus,max;
    fscanf(fp,"%d",&T);
    for (io=1; io<=T; io++){
    fprintf(fo,"Case #");
    fprintf(fo,"%d",io);
    fprintf(fo,":");
    fprintf(fo," ");
    //-----------
    fscanf(fp,"%d",&b);
    fscanf(fp,"%d",&m);
    max=(int) pow(2, b-2)+0.5;
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
       printf("%d",minus);
       j=b-3;
       while (minus>0){
           tada=(int) pow(2, j)+0.5;
        if (tada<=minus){minus=minus-tada;  array[1][b-1-j]=0; }
        j=j-1;
       }
    for(i=1; i<=b; i++){
        for(j=1; j<=b; j++){
            fprintf(fo,"%d",array[i][j]);
        }
        fprintf(fo,"\n");
       }
    }
}
    return 1;
}
