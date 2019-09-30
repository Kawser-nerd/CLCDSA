#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int f[200000];

int main(void){
  int n, q, l, r, i;
  scanf("%d %d",&n,&q);
  for(i=0;i<n;i++) f[i]=0;
  for(i=0;i<q;i++){
    scanf("%d %d",&l,&r);
    f[l-1]++; f[r]--;
  }
  printf("%d",f[0]%2);
  for(i=1;i<n;i++){
    f[i]+=f[i-1];
    printf("%d",f[i]%2);
  }
  printf("\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&q);
   ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&l,&r);
     ^