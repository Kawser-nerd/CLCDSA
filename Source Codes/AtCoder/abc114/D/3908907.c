#include <stdio.h>

int main(){
  int N;
  scanf("%d",&N);
  int count=0;
  int prime[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
  int count_prime[25]={};
  int i,temp,j,k,l;
  int count_2=0, count_4=0, count_14=0, count_24=0, count_74=0;

  //N!?????????
  //i?N!?1~N?j?prime[]?index?
  //temp?i???????
  for(i=1;i<=N;i++){
    temp=i;
    j=0;
    while(temp!=1){
      if(temp%prime[j]==0){
        temp=temp/prime[j];
        count_prime[j]++;
      }else{
        j++;
      }
    }
  }

  /*for(j=0;j<25;j++){
    printf("count_prime[%2d] = number of %2d = %2d\n",j,prime[j],count_prime[j]);
  }*/

  //75????????
  //count_2???count_74?????
  for(j=0;j<25;j++){
    if(2<=count_prime[j]) count_2++;
    if(4<=count_prime[j]) count_4++;
    if(14<=count_prime[j]) count_14++;
    if(24<=count_prime[j]) count_24++;
    if(74<=count_prime[j]) count_74++;
  }
  /*printf("count_2=%d\n",count_2);
  printf("count_4=%d\n",count_4);
  printf("count_14=%d\n",count_14);
  printf("count_24=%d\n",count_24);
  printf("count_74=%d\n",count_74);*/

  //count_2?????75??????
  //case1 74
  count+=count_74;
  //case2 24,4
  count+=count_24*(count_2-1);
  //case3 14,4
  count+=count_14*(count_4-1);
  //case4 4,4,2
  count+=(count_4*(count_4-1)/2)*(count_2-2);

  printf("%d\n",count);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^