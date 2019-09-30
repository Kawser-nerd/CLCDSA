#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>


 long long int max(long long int a ,long long int b){
  if(a<b){
    return b;
  }
  return a;
}

int compare(const void *p0,const void *p1){
  long long int *P0=(long long int*)p0;
  long long int *P1=(long long int*)p1;
  if(*P0>*P1)return 1;
  if(*P0<*P1)return -1;
  return 0;
}


int main(){
  long long int p=0,q=0,r=0;
  int i,n=0,m=0,w;
  scanf("%d %d",&n,&m);
  long long int x[n];
  long long int y[n];
  long long int z[n];
  for (i = 0; i <n; i++) {
    scanf("%lld %lld %lld",&x[i],&y[i],&z[i]);
  }

  for (int i=-1;i<=1;i+=2){
    for(int j=-1;j<=1;j+=2){
      for(int k=-1;k<=1;k+=2){
        p=0;
        long long int a[n];
        for (int l = 0; l < n; l++) {
          a[l]=i*x[l]+j*y[l]+k*z[l];
        }
        qsort(a,n,sizeof(long long int),compare);
    /*    for (int l = n-1; l>=0; l--) {
           printf("%lld ",a[l]);
         }
         printf("\n");*/
        for (int l = n-1; l >n-m-1; l--) {
          p+=a[l];
        }
        q=max(p,q);
      }
    }
  }

  printf("%lld",q);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:28:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^
./Main.c:33:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld %lld",&x[i],&y[i],&z[i]);
     ^