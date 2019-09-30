#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int max(int a, int b){
  return a >= b ? a : b;
}
int min(int a, int b){
  return b >= a ? a : b;
}
int factorial(int n) {
    if (n > 0) return n*factorial(n - 1);
		else return 1;
}
int compare_up_int(const void *a, const void *b){
   return *(int*)a - *(int*)b;
}
int compare_down_int(const void *a, const void *b){
   return *(int*)b - *(int*)a;
}
int euclid(int a, int b){
  if(a < b){int tmp = a;a = b;b = tmp;}
  int r = a % b;
  if(r < 0) r += b;
  while(r != 0){
    a = b;b = r;r = a % b;
    if(r < 0) r += b;
  }
  return b;
}

int main(){
  int H,W;
  scanf("%d %d",&H,&W);
  char a[H][W];
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      scanf("%1s",&a[i][j]);
    }
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(a[i][j] == '#'){
        if(i-1<0)i=1;
        if(j-1<0)j=1;
        if(i+1>H-1)i=H-1;
        if(j+1>W-1)j=W-1;
        if(a[i-1][j] == '.' && a[i+1][j] == '.' && a[i][j-1] == '.' && a[i][j+1] == '.'){
          printf("No\n");
          return 0;
        }
      }
    }
  }
  //printf("%c",a[0][0]);
  printf("Yes\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:35:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&H,&W);
   ^
./Main.c:39:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%1s",&a[i][j]);
       ^