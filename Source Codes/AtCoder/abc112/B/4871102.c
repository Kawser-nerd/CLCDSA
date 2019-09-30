#include <stdio.h>

int
main(int argc,char *argv[])
{
  int N, T, c[100], t[100];
  scanf("%d%d", &N, &T);
  for(int i = 0; i < N; i++)
  {
    scanf("%d%d", &c[i], &t[i]);
  }
  
  int min_cost = 1001;
  
  for(int i = 0; i < N; i++){
    if(t[i] <= T && min_cost > c[i]){
      min_cost = c[i];
    }
  }
  
  if(min_cost == 1001){
    printf("%s\n", "TLE");
  }
  else{
    printf("%d\n", min_cost);
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &N, &T);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &c[i], &t[i]);
     ^