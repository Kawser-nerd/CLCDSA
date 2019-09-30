#include<stdio.h>
int main(){
  int n,m,X,Y,x[100],y[100],i;
  scanf("%d%d%d%d",&n,&m,&X,&Y);
  int max=X,min=Y;
  for(i=0;i<n;i++){
    scanf("%d",&x[i]);
    if(max<x[i]) max=x[i];
  }
  for(i=0;i<m;i++){
    scanf("%d",&y[i]);
    if(min>y[i]) min=y[i];
  }
  puts(max<min?"No War":"War");
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&n,&m,&X,&Y);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&x[i]);
     ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&y[i]);
     ^