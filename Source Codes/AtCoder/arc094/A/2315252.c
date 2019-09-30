#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int int_sort(const void *a, const void *b){//small -> big
  if(*(int *)a < *(int *)b){
    return -1;
  }else if(*(int *)a == *(int *)b){
    return 0;
  }
  return 1;
}

int main(void){
  int n[3], ans;
  scanf("%d %d %d",&n[0],&n[1],&n[2]);
  qsort((void *)n, 3, sizeof(n[0]), int_sort);
  if((n[0]%2)==(n[1]%2) && (n[1]%2)==(n[2]%2)) ans = (n[2]-n[1])/2+(n[2]-n[0])/2;
  else{
    if(n[0]%2==n[1]%2) ans = (n[2]-n[1]-1)/2+(n[2]-n[0]-1)/2+1;
    else ans = (n[2]-n[1])/2+(n[2]-n[0])/2+2;
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&n[0],&n[1],&n[2]);
   ^