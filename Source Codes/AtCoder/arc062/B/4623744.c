#include <stdio.h>

int main(){
  int count = 0;
  int ans = 0;
  while (1) {
    char c = getchar();
    if(c == 'p'){
      ans--;
    }else if(c != 'g'){
      break;
    }
    if(count % 2 == 1){
      ans++;
    }
    count++;
  }
  printf("%d\n", ans);
  return 0;
}