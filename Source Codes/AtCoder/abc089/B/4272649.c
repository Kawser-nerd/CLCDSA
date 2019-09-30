#include <stdio.h>
int main(){
  int n;
  scanf("%d", &n);
  char c[4]="0000" , d;
  for (int i = 0; i < n; i++){
    scanf(" %c", &d);
    if (d == 'P'){
      c[0]='1';
    }
    if (d == 'W'){
      c[1]='1';
    }
    if (d == 'G'){
      c[2]='1';
    }
    if (d == 'Y'){
      c[3]='1';
    }
  }
  if (c[0]=='1' && c[1]=='1' &&c[2]=='1' &&c[3]=='1'){
    printf("Four\n");
  }
  else{
    printf("Three\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf(" %c", &d);
     ^