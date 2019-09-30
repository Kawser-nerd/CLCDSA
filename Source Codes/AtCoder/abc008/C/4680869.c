#include<stdio.h>

int main(void)
{
  int n;
  int c[100];
  int i,j;
  int s[100]={0};
  double sum;
  

  scanf("%d",&n);
  for(i=0;i<n;i++){
  scanf("%d",&c[i]);
  }

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(c[i]%c[j]==0&&i!=j){
	s[i]++;
      }
    }
  }

  for(i=0;i<n;i++){
    if(s[i]%2==0){
      sum+=(s[i]/2.0+1.0)/(s[i]+1.0);
    }else{
      sum+=1.0/2.0;
    }
  }

  printf("%f\n",sum);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&c[i]);
   ^