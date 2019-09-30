#include<stdio.h>
#include<stdlib.h>

int gcd(int a,int b){
  int r=a%b;
  while(r>0){
    a=b;b=r;r=a%b;
  }
  return b;
}

void run(void){
  int n;
  scanf("%d",&n);
  int v=(n-1)%8;
  int cnt=0;
  if(v>=6){
    for(int i=2;cnt<n;i++) if(i%2==0 || i%3==0) cnt++,printf("%d ",i);
    printf("\n");
    return;
  }
  int sum=0;
  int i;
  for(i=2;cnt<n-1;i++){
    if(i%2==0 || i%3==0){
      printf("%d ",i);
      cnt++;
      sum+=i;
    }
  }
  if(sum%6==5){
    for(i=7;1;i+=6){
      if(gcd(sum,i)>1){
	printf("%d\n",i);
	return;
      }
    }
  } else {
    for(;1;i++){
      if((sum+i)%6==0 && gcd(sum,i)>1){
	printf("%d\n",i);
	return;
      }
    }
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^