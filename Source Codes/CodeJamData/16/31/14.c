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
    int i,j,T,io,n,array[50],imax,max,length,temp,left[5];
    char c;
    bool work;
    fscanf(fp,"%d",&T);
    for (io=1; io<=T; io++){
    fprintf(fo,"Case #");
    fprintf(fo,"%d",io);
    fprintf(fo,":");
    fprintf(fo," ");
    fscanf(fp,"%d",&n);
    for(i=1; i<=n; i++){
        fscanf(fp,"%d",&array[i]);
    }
    //-----------
    length=n;
    work=true;
    if(n<=2){work=false;}
    while(work){
            imax=0;
            max=0;
      for(i=1; i<=n; i++){
        if(array[i]>=max){max=array[i]; imax=i;}
        }
    if(max==1){length=length-1;}
    if (length<=2){work =false;}
    array[imax]=array[imax]-1;
    fprintf(fo,"%c",'A'+imax-1);
    fprintf(fo," ");
    }
    j=1;
    for(i=1; i<=n; i++){if (array[i] !=0){
            left[j]=i;
            j=j+1;
}}
if(array[left[2]]>array[left[1]]){temp=left[1]; left[1]=left[2]; left[2]=temp;}

for(i=1; i<=array[left[1]]-array[left[2]]; i++){
    fprintf(fo,"%c",'A'+left[1]-1);
    fprintf(fo," ");
}
for(i=1; i<=array[left[2]]; i++){
    fprintf(fo,"%c",'A'+left[1]-1);
    fprintf(fo,"%c",'A'+left[2]-1);
    fprintf(fo," ");
}



    fprintf(fo,"\n");
    }

return 1;}
