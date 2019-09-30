#include <stdio.h>

int main(){
  char c1, c2;
  c1 = getchar();
  c2 = getchar();
  int ans = 999;
  while(1){
    char c3 = getchar();
    if (c3 == EOF || c3 == 10) {
      break;
    }
    int tmp = ((int)(c1-'0'))*100+((int)(c2-'0'))*10+((int)(c3-'0'));
    if (tmp > 753){
      if(tmp - 753 < ans){
        ans = tmp - 753;
      }
    }else{
      if(753 - tmp < ans){
        ans = 753 - tmp;
      }
    }
    c1 = c2;
    c2 = c3;
  }
  printf("%d\n", ans);
  return 0;
}