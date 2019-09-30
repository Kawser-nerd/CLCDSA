#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int main(void){
  int n,k,l[50],i,j;
  scanf("%d%d",&n,&k);
  for(i=0;i<n;i++){
    scanf("%d",&l[i]);
  }
  int max,tmp,index;
  for(i=0;i<n-1;i++){
    index=i;
    max=0;
    for(j=i;j<n;j++){
      if(l[j]>max) {
        max=l[j];
        index=j;
      }
    }
    tmp=l[i];
    l[i]=max;
    l[index]=tmp;
  }
  int sum=0;
  for(i=0;i<k;i++){
    sum+=l[i];
  }
  printf("%d",sum);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&l[i]);
     ^