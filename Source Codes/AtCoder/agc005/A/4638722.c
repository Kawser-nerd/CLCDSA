#include <stdio.h>

int main(){
  int s_cnt = 0;
  int ans = 0;
  while(1){
    char c = getchar();
    if(c == 'S'){
      s_cnt++;
      ans++;
    }else if(c == 'T' && s_cnt > 0){
      s_cnt--;
      ans--;
    }else if(c == 'T'){
      ans++;
    }else{
      break;
    }
  }
  printf("%d\n",ans);
  return 0;
}