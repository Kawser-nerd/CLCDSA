#include <stdio.h>
#include <string.h>

int maxi(int a,int b){if(a>b){return a;}return b;}

int main(void){
  int n, m, i, j;
  scanf("%d", &n);
  char s[n][11];
  for(i = 0; i < n; i++){
    scanf("%s", s[i]);
  }
  scanf("%d", &m);
  char t[m][11];
  int count = 0;
  int max = 0;
  for(i = 0; i < m; i++){
    scanf("%s", t[i]);
  }
  
  for(i = 0; i < n; i++){
    count = 0;
    for(j = 0; j < n; j++){
      if(strcmp(s[i], s[j]) == 0) count++;
    }
    for(j = 0; j < m; j++){
      if(strcmp(s[i], t[j]) == 0) count--;
    }
    max = maxi(max, count);
  }
  printf("%d\n", max);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s[i]);
     ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &m);
   ^
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", t[i]);
     ^