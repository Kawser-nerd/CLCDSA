#include <stdio.h>

int main(void){
  int S;
  scanf("%d",&S);
  int A[4] = {S/1000,(S/100)%10,(S/10)%10,S%10};
  int ans;

  for(int i = 0;i < 8;i++){
    int j = i;
    int counter = 1;
    ans = A[0];
    while(counter < 4){
      if(j%2 == 1){
        ans += A[counter];
      }else{
        ans -= A[counter];
      }
      j /= 2;
      counter++;
    }
    counter = 1;
    if(ans == 7){
      printf("%d",A[0]);
      while(counter < 4){
        if(i%2 == 1){
          printf("+");
        }else{
          printf("-");
        }
        printf("%d",A[counter]);
        i /= 2;
        counter++;
      }
      printf("=7\n");
      break;  
    }
  }


  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&S);
   ^