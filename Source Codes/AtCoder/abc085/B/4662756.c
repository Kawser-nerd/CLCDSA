#include<stdio.h>
int n, ans, i;
int d;
char D[101];
int main(){
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &d);
    D[d]=1;
  }
  for(i=0; i<=100; i++){
    if(D[i]){ans++;}
  }
  printf("%d\n", ans);
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &d);
     ^