#include<stdio.h>
#include<string.h>

int main(){
  int A, B, len = 0;
  char s[12];
  
  scanf("%d %d", &A, &B);
  scanf("%s", s);
  
  while(s[len]){
    if(len == A && s[len] != '-'){
      break;
    } else if(len != A && (s[len] < '0' || s[len] > '9')){
      break;
    }
    len++;
  }
  
  if(len == strlen(s)){
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &A, &B);
   ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^