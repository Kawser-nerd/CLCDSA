#include<stdio.h>
#include<stdlib.h>
int main(){
  int n,m,a[55],b[55],c[55],d[55],i,j;
  scanf("%d%d",&n,&m);
  for(i=0;i<n;i++){
    scanf("%d%d",&a[i],&b[i]);
  }
  for(i=0;i<m;i++){
    scanf("%d%d",&c[i],&d[i]);
  }
  for(i=0;i<n;i++){
    int min=200000000,t;
    for(j=0;j<m;j++){
      if(min>abs(a[i]-c[j])+abs(b[i]-d[j])){
        min=abs(a[i]-c[j])+abs(b[i]-d[j]);
        t=j;
      }
    }
    printf("%d\n",t+1);
  }
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a[i],&b[i]);
     ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&c[i],&d[i]);
     ^