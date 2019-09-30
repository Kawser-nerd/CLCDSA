#include <stdio.h>
int main (){
int k=0,o=0,a[8]={0},yo=0,max=0,min=0,l,i;
  scanf ("%d",&k);
  for (i=0;i<k;i++){scanf ("%d",&o);
if (0<o && o<400){a[0]=1;}
else if (399<o && o<800){a[1]=1;}
else if (799<o && o<1200){a[2]=1;}
else if (1199<o && o<1600){a[3]=1;}
else if (1599<o && o<2000){a[4]=1;}
else if (1999<o && o<2400){a[5]=1;}
else if (2399<o && o<2800){a[6]=1;}
else if (2799<o && o<3200){a[7]=1;}
else if (3199<o){yo=yo+1;}}
 for (l=0;l<8;l++){
 min=min+a[l];
 }
   max=min+yo;
  if (min==0){
    min=1;
  max=yo;
  }
  printf ("%d %d",min,max);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%d",&k);
   ^
./Main.c:5:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for (i=0;i<k;i++){scanf ("%d",&o);
                     ^