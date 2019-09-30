#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

int binary(int v,int *b,int n){
  if(b[0]>=v) return 0;
  int l=0;
  int r=n;
  while(l+1<r){
    int m=(l+r)/2;
    if(b[m]<v){
      l=m;
    } else {
      r=m;
    }
  }
  return r;
}

int calc(int a,int *b,int n,int bit){
  int shift=1<<bit;
  return (binary(2*shift-a,b,n)-binary(shift-a,b,n))+(binary(4*shift-a,b,n)-binary(3*shift-a,b,n));
}

void run(void){
  int n;
  scanf("%d",&n);
  int *a=(int *)malloc(sizeof(int)*n);
  int *b=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  for(i=0;i<n;i++) scanf("%d",b+i);
  int ans=0;
  int bit;
  for(bit=28;bit>=0;bit--){
    for(i=0;i<n;i++){
      a[i]%=(1<<(bit+1));
      b[i]%=(1<<(bit+1));
    }
    qsort(b,n,sizeof(int),cmp);
    int cnt=0;
    for(i=0;i<n;i++){
      cnt^=calc(a[i],b,n,bit);
    }
    if(cnt&0x01){
      ans|=1<<bit;
    }
  }
  printf("%d\n",ans);
  free(a);
  free(b);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:37:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:41:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^
./Main.c:42:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",b+i);
                    ^