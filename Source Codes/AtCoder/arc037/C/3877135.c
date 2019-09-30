#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

int count(int64 m,int *a,int *b,int n){
  int res=0;
  int i,j;
  j=n-1;
  for(i=0;i<n;i++){
    while(j>=0 && (int64)a[i]*b[j]>m) j--;
    res+=j+1;
  }
  return res;
}

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  int *a=(int *)calloc(n,sizeof(int));
  int *b=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  for(i=0;i<n;i++) scanf("%d",b+i);
  qsort(a,n,sizeof(int),cmp);
  qsort(b,n,sizeof(int),cmp);
  int64 l=0;
  int64 r=1000000000000000000LL;
  while(r-l>1){
    int64 m=(l+r)/2;
    if(count(m,a,b,n)>=k){
      r=m;
    } else {
      l=m;
    }
  }
  printf("%lld\n",r);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
./Main.c:27:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^
./Main.c:28:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",b+i);
                    ^