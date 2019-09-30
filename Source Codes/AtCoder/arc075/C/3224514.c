#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

int64 *tmp=NULL;
int64 calc(int64 *a,int n){
  if(n<=1) return 0;
  int m=n/2;
  int64 res=calc(a,m)+calc(a+m,n-m);
  int i=0;
  int j=m;
  int k=0;
  while(i<m && j<n){
    if(a[i]<=a[j]){
      tmp[k++]=a[i++];
    } else {
      res+=i;
      tmp[k++]=a[j++];
    }
  }
  while(i<m) tmp[k++]=a[i++];
  while(j<n){
    res+=i;
    tmp[k++]=a[j++];
  }
  for(i=0;i<n;i++) a[i]=tmp[i];
  return res;
}

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  int64 *a=(int64 *)malloc(sizeof(int64)*(n+1));
  a[0]=0;
  int i;
  for(i=1;i<=n;i++){
    int x;
    scanf("%d",&x);
    a[i]=a[i-1]+x-k;
  }
  tmp=(int64 *)malloc(sizeof(int64)*(n+1));
  int64 ans=calc(a,n+1);
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:33:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
./Main.c:39:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&x);
     ^