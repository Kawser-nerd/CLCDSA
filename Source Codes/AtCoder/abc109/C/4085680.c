#include<stdio.h>
#include<stdlib.h>

int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int euclid(int a, int b){
  if(a < b){
    int tmp = a;a = b;b = tmp;
  }
  int r = a % b;
  if(r < 0) r += b;
  while(r != 0){
    a = b;b = r;r = a % b;
    if(r < 0) r += b;
  }
  return b;
}

int main(){
  int N,X,d;
  scanf("%d %d",&N,&X);
  int x[N];
  for(int i=0;i<N;i++) scanf("%d",&x[i]);
  d= abs(x[0]-X);
  for(int i=1;i<N;i++){
    d=euclid(d,abs(x[i]-X));
  }
  printf("%d\n",d );
  } ./Main.c: In function ‘main’:
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&N,&X);
   ^
./Main.c:26:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i=0;i<N;i++) scanf("%d",&x[i]);
                        ^