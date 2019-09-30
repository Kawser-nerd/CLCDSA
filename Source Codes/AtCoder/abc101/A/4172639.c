#include <stdio.h>

int main(void){
  int ans = 0;
  char data[4];

  scanf("%s",data);

  for(int i = 0;i < 4;i++){
    if(data[i] == '+')
      ans++;
    else
      ans--;
  }

  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",data);
   ^