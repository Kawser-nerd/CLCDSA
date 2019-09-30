#include<stdio.h>

int main(void){
  int num[100001]={0};
  int N,i,j,k,tmp;
  int two=0,ans=0;
  
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&tmp);
    num[tmp]++;
  }

  for(i=0;i<100001;i++){
    if(num[i]==0) continue;
    ans++;
    num[i]=(num[i]%2)?1:2;
    if(num[i]==2) two++;
  }

  ans-=two%2;
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&tmp);
     ^