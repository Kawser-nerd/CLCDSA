#include<stdio.h>
short N, num[4], min, max, i;
int main(){
  scanf("%hd\n", &N);
  for(i=0; i<N; i++){
    num[getchar()-'1']++;
  }
  min=max=num[0];
  if(num[1]<min){min=num[1];}else if(num[1]>max){max=num[1];}
  if(num[2]<min){min=num[2];}else if(num[2]>max){max=num[2];}
  if(num[3]<min){min=num[3];}else if(num[3]>max){max=num[3];}
  printf("%d %d\n", max, min);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%hd\n", &N);
   ^