#include <stdio.h>

int main(){
  int m;
  scanf("%d",&m);
  int vv;
  if(m < 100) vv = 0;
  else if(m <= 5000) vv = m / 100;
  else if(m <= 30000) vv = m / 1000 + 50;
  else if(m <= 70000) vv = (m / 1000 - 30) / 5 + 80;
  else vv = 89;
  int ten = 0;
  if(vv < 10){
    printf("%d%d\n",ten,vv);
  }else printf("%d\n",vv);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&m);
   ^