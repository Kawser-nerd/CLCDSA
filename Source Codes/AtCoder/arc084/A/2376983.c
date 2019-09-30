#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int *tmp;

void msort(int *a,int n){
  if(n<=1) return;
  int m=n/2;
  msort(a,m);
  msort(a+m,n-m);
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
  for(i=0;i<k;i++) a[i]=tmp[i];
  return;
}

void run(void){
  int n;
  scanf("%d",&n);
  int *a=(int *)malloc(sizeof(int)*n);
  int *b=(int *)malloc(sizeof(int)*n);
  int *c=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  for(i=0;i<n;i++) scanf("%d",b+i);
  for(i=0;i<n;i++) scanf("%d",c+i);
  tmp=(int *)malloc(sizeof(int)*n);
  msort(a,n);
  msort(b,n);
  msort(c,n);
  int64 *cnt=(int64 *)calloc(n,sizeof(int64));
  int j=0;
  for(i=0;i<n;i++){
    while(j<n && b[i]>=c[j]) j++;
    cnt[i]=n-j;
  }
  for(i=n-1;i>0;i--) cnt[i-1]+=cnt[i];
  int64 sum=0;
  j=0;
  for(i=0;i<n;i++){
    while(j<n && a[i]>=b[j]) j++;
    sum+=cnt[j];
  }
  printf("%lld\n",sum);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:35:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:40:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^
./Main.c:41:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",b+i);
                    ^
./Main.c:42:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",c+i);
                    ^