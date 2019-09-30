#include <stdio.h>

int main(){
  int c[3][3],a[3],b[3];
  int flag = 0;
  for(int i = 0; i < 3; ++i) scanf("%d %d %d",&c[i][0],&c[i][1],&c[i][2]);
    //(1,j)check
  b[0] = 0;//a,b? <-> a+b0,b-b0?
  a[0] = c[0][0];
  b[1] = c[0][1] - a[0];
  b[2] = c[0][2] - a[0];
    //(2,j)check
  a[1] = c[1][0] - b[0];
  if(c[1][1] != a[1] + b[1] || c[1][2] != a[1] + b[2]) flag = 1;
    //(3,j)check
  a[2] = c[2][0] - b[0];
  if(c[2][1] != a[2] + b[1] || c[2][2] != a[2] + b[2]) flag = 1;
  
  if(flag == 0) printf("Yes\n");
  else printf("No\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:30: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 0; i < 3; ++i) scanf("%d %d %d",&c[i][0],&c[i][1],&c[i][2]);
                              ^