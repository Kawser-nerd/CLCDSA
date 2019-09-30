#include<stdio.h>
#include<math.h>

int main(){
  int len = 0, x = 0, y = 0, T, count = 0, d;
  char s[100000];
  
  scanf("%s", &s);
  scanf("%d", &T);
  
  while(s[len]){
    if(s[len] == 'L'){
      x--;
    }
    if(s[len] == 'R'){
      x++;
    }
    if(s[len] == 'U'){
      y++;
    }
    if(s[len] == 'D'){
      y--;
    }if(s[len] == '?'){
      if(T == 1){
        count++;
      } else {
        count--;
      }
    }
    len++;
  }
  
  d = (int)fabs(x) + (int)fabs(y) + count;
  while(d < 0){
    d += 2;
  }
  printf("%d\n", d);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100000]’ [-Wformat=]
   scanf("%s", &s);
         ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", &s);
   ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &T);
   ^