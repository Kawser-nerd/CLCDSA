#include <stdio.h>
int main() {
  int n,i,j;
  char s[55][55];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s",s[i]);
  }
  while(i--){
    for(j=0;j<n;j++){
      printf("%c",s[n-j-1][n-i-1]);
    }
    printf("\n");
  }
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s[i]);
     ^