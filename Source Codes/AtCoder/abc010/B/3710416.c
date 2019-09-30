#include<stdio.h>
int N, a, ans, i;
int main(){
  scanf("%d", &N);
  for(i=0; i<N; i++){
    scanf("%d", &a);
    switch(a%6){
      case 0: ans+=3; break;
      case 1: ans+=0; break;
      case 2: ans+=1; break;
      case 3: ans+=0; break;
      case 4: ans+=1; break;
      case 5: ans+=2; break;
    }
  }
  printf("%d\n", ans);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a);
     ^