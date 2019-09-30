#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void msort(int *a,int n,int *tmp){
  if(n<=1) return;
  int m=n/2;
  msort(a,m,tmp);
  msort(a+m,n-m,tmp);
  int i=0;
  int j=m;
  int k=0;
  while(i<m && j<n){
    if(a[i]<=a[j]){
      tmp[k++]=a[i++];
    } else {
      tmp[k++]=a[j++];
    }
  }
  while(i<m) tmp[k++]=a[i++];
  while(j<n) tmp[k++]=a[j++];
  for(i=0;i<n;i++) a[i]=tmp[i];
  return;
}

void run(void){
  int n,h;
  scanf("%d%d",&n,&h);
  int *a=(int *)malloc(sizeof(int)*n);
  int *b=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++){
    scanf("%d%d",a+i,b+i);
  }
  int maxA=0;
  for(i=0;i<n;i++) maxA=MAX(maxA,a[i]);
  msort(b,n,a);
  int k=0;
  i=n-1;
  while(i>=0 && h>0 && b[i]>maxA){
    h-=b[i--];
    k++;
  }
  if(h>0){
    k+=(h+maxA-1)/maxA;
  }
  printf("%d\n",k);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:34:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&h);
   ^
./Main.c:39:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",a+i,b+i);
     ^