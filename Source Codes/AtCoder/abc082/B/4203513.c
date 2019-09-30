#include<stdio.h>
#include<string.h>

int main(){
  int lens = 0, lent = 0;
  char s[101], t[101], u;
  scanf("%s %s", s, t);
  
  while(s[lens]){
    if(lens >= 1){
      u = s[lens];
      for (int i = lens - 1; i >= 0; i--){
        if(u < s[i]){
          s[i + 1] = s[i];
          if(i == 0){
            s[i] = u;
          }
        } else {
          s[i + 1] = u;
          break;
        }
      }
    }
    lens++;
  }
  while(t[lent]){
    if(lent >= 1){
      u = t[lent];
      for (int i = lent - 1; i >= 0; i--){
        if(u > t[i]){
          t[i + 1] = t[i];
          if(i == 0){
            t[i] = u;
          }
        } else {
          t[i + 1] = u;
          break;
        }
      }
    }
    lent++;
  }
  if(strcmp(s, t) < 0){
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %s", s, t);
   ^