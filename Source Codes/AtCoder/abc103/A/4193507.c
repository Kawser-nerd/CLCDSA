#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int cmp(const void *a,const void *b){
  return *(int*)a - *(int*)b;
}

int main(void){
  int a[3],b[3],i,ans=0;
  for(i=0;i<3;i++){
    scanf("%d",&a[i]);
  }
  b[0] = abs(a[0]-a[1]);
  b[1] = abs(a[1]-a[2]);
  b[2] = abs(a[2]-a[0]);
  
  qsort(b,3,sizeof(int),cmp);
  
  for(i=0;i<2;i++){
    ans+=b[i];
  }
  
  printf("%d\n",ans);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^