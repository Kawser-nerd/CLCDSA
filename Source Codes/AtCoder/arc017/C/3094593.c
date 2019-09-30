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

void func(int *w,int n,int *d){
  d[0]=0;
  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<(1<<i);j++){
      d[(1<<i)+j]=d[j]+w[i];
    }
  }
  qsort(d,1<<n,sizeof(int),cmp);
  return;
}

void run(void){
  int n,x;
  scanf("%d%d",&n,&x);
  int w[32];
  int i;
  for(i=0;i<n;i++) scanf("%d",w+i);
  int m=n/2;
  int *a=(int *)malloc(sizeof(int)*(1<<m));
  int *b=(int *)malloc(sizeof(int)*(1<<(n-m)));
  func(w,m,a);
  func(w+m,n-m,b);
  int64 ans=0;
  int l=0;
  int r=(1<<(n-m))-1;
  while(l<(1<<m) && r>=0){
    if(a[l]+b[r]==x){
      int ll=l;
      int rr=r;
      while(ll<(1<<m) && a[ll]==a[l]) ll++;
      while(rr>=0 && b[rr]==b[r]) rr--;
      ans+=(int64)(ll-l)*(r-rr);
      l=ll;
      r=rr;
    } else if(a[l]+b[r]<x){
      l++;
    } else {
      r--;
    }
  }
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:29:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&x);
   ^
./Main.c:32:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",w+i);
                    ^