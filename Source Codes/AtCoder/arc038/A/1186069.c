#include<stdio.h>
int main(){
  int n,d[1010],s=0,i,j,a;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a);
    for(j=i;j&&d[j-1]<a;j--)d[j]=d[j-1];
    d[j]=a;
  }
  //for(i=0;i<n;i++)printf("%d ",d[i]);printf("\n");
  for(i=0;i<n;i+=2)s+=d[i];
  printf("%d\n",s);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^