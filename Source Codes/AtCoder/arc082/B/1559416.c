#include<stdio.h>
int main(){
  int n,i,d[100010],s=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&d[i]);
  for(i=0;i<n;i++){
    if(d[i]==i+1){
      d[i+1]=d[i];
      s++;
    }
  }
  printf("%d\n",s);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:5:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%d",&d[i]);
                   ^