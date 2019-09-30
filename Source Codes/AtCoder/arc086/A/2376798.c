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
  int n,k;
  scanf("%d%d",&n,&k);
  int *c=(int *)calloc(n+1,sizeof(int));
  tmp=(int *)calloc(n+1,sizeof(int));
  int i;
  for(i=0;i<n;i++){
    int a;
    scanf("%d",&a);
    c[a]++;
  }
  msort(c,n+1);
  int s=0;
  while(c[s]==0) s++;
  int cnt=0;
  while(n+1-s>k){
    cnt+=c[s];
    s++;
  }
  printf("%d\n",cnt);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:35:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
./Main.c:41:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^