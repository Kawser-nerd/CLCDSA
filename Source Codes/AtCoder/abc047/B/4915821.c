#include <stdio.h>

int max(int a,int b){
  if(a > b) return a;
  else return b;
}

int main(){
  int w,h,n;
  scanf("%d%d%d",&w,&h,&n);
  int white[4] = {0,w,0,h};
  int x,y,a;
  int bin;
  for(int i = 0; i < n; ++i){
    scanf("%d%d%d\n",&x,&y,&a);
    if(a <= 2) bin = x;
    else bin = y;
    if(a % 2 == 1){
      if(white[a-1] < bin) white[a-1] = bin;
    }
    else{
      if(white[a-1] > bin) white[a-1] = bin;
    }
  }
  int area = max(white[1] - white[0], 0)*max(white[3] - white[2], 0);
  printf("%d\n",area);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&w,&h,&n);
   ^
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d\n",&x,&y,&a);
     ^