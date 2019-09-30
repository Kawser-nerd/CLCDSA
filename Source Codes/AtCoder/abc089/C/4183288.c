#include <stdio.h>

int main(void){
  long N;
  long long ans = 0;
  char S[10];
  int data[5] = {0,0,0,0,0};
  scanf("%ld",&N);

  for(int i = 0;i < N;i++){
    scanf("%s",S);
    switch(S[0]){
      case 'M':
        data[0]++;
        break;
      case 'A':
        data[1]++;
        break;
      case 'R':
        data[2]++;
        break;
      case'C':
        data[3]++;
        break;
      case 'H':
        data[4]++;
        break;
    }
  }

  for(int i = 0;i < 32;i++){
    int counter = 0;
    int sample = i;
    int flag = 0;
    long long  kari = 1;
    while(counter < 5){
      if(sample%2 == 1){
        flag++;
        kari *= data[counter];
      }
      sample /= 2;
      counter++;
    }
    if(flag == 3){
      ans += kari;
    }
  }

  printf("%lld\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld",&N);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",S);
     ^