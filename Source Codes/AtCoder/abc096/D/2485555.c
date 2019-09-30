#include <stdio.h>
#include <string.h>


int check_prime_num(int num){
      /* ????? */
  int flag = 1;
    /* ????????? */
  for(int i=2;i<num;++i ) {
    if( num%i==0 ) {
      flag = 0;
      break;
    }
  }
  return flag;

}

int main(void){
    int N;
    int array[10000],a=0;
    scanf("%d",&N);
    for(int i = 6; i < 55555; i+=5){
        if(check_prime_num(i)) {
            array[a] = i;
            a++;
            if(N == a) break;
        }
    }
    for(int i = 0; i < a;i++) printf("%d ",array[i]);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^