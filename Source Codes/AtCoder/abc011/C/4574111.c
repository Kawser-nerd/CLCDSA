#include <stdio.h>

int ng[3];

int check(int N){
  if(N != ng[0] && N != ng[1] && N != ng[2]){
    return 0;
  }
  return 1;
}

int main(void){
  int N;
  scanf("%d",&N);

  for(int i = 0;i < 3;i++) scanf("%d",&ng[i]);


  if(check(N) == 1){
    printf("NO");
    return 0;
  }

  int cnt = 0;
  while(++cnt <= 100){
    if(check(N-3) == 0){
      N -= 3;
      continue;
    }
    if(check(N-2) == 0){
      N -= 2;
      continue;
    }
    if(check(N-1) == 0){
      N--;
      continue;
    }
  }

  if(N <= 0) printf("YES\n");
  else printf("NO\n");
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:16:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 0;i < 3;i++) scanf("%d",&ng[i]);
                            ^