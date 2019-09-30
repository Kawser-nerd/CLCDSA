#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
  int i,j,N,x,a[100],m,s=0;
  scanf("%d%d",&N,&x);
  for(i=0;i<N;i++)
    scanf("%d",&a[i]);
  while(i--){
    for(m=0;m<N&&!a[m];m++)
    if(m==N)break;
    for(j=m+1;j<N;j++)
      if(a[j]<a[m]&&a[j]>0)m=j;
    if(x<a[m])break;
    x-=a[m];
    if(i>0)s++;
    else if(x==0)s++;
    a[m]=0;
  }
  printf("%d\n",s);
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&x);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^