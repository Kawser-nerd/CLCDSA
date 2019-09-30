#include<stdio.h>

int main(){
  int N, p[1000], tot = 0, i, max = 0, r;
  char s[1000][21];
  
  scanf("%d", &N);
  
  for(i = 0; i < N; i++){
    scanf("%s %d", s[i], &p[i]);
    if(max < p[i]){
      max = p[i];
      r = i;
    }
    tot += p[i];
  }
  if(max <= tot/2){
    printf("atcoder\n");
  } else {
    printf("%s\n", s[r]);
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s %d", s[i], &p[i]);
     ^