#include <stdio.h>

int MIN(int a,int b){return a<b?a:b;}
int MAX(int a,int b){return a<b?b:a;}

int main() {
  int n;
  int niku[5];
  int i, j, ans = 999999;
  int ykk_1, ykk_2;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &niku[i]);
  }

  for(i = 0; i < (1 << n); i++){ //bit????????????
    ykk_1 = ykk_2 = 0;
    for(j = 0; j < n; j++){
      if(i>>j &1){
        ykk_1 += niku[j];
      }else{
        ykk_2 += niku[j]; //??????????????
      }
    }

    ans = MIN(MAX(ykk_1, ykk_2), ans);

  }

  printf("%d\n", ans);
  // for(i = 0; i < n; i++){
  //   printf("%d", niku[i]);
  // }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &niku[i]);
     ^