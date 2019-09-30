#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int main(){
  int n;
  scanf("%d",&n);
  int a[n];
  int i,j,k,f,limit,s;
  int so[9265]={2};
  k=1;
  for(i=3;i<55555;i+=10){
    f=0;
    limit=(int)sqrt(i);
    for(j=3;j<=limit;j+=2){
      if(i%j==0){
        f=1;
        break;
      }
    }
    if(f==0){
      so[k]=i;
      k++;
    }
  }
  for(i=0;i<n;i++){
    printf("%d ",so[i]);
  }
  printf("\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^