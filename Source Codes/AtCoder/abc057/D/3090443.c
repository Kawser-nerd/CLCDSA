#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int64 comb(int n,int k){
  if(k<0 || n<k) return 0;
  int64 res=1;
  int i;
  for(i=1;i<=k;i++) res=res*(n+1-i)/i;
  return res;
}

int cmp(const void *a,const void *b){
  int64 p=*(int64 *)a;
  int64 q=*(int64 *)b;
  return p==q?0:p<q?-1:1;
}

void run(void){
  int n,a,b;
  scanf("%d%d%d",&n,&a,&b);
  int64 v[50];
  int i;
  for(i=0;i<n;i++) scanf("%lld",v+i);
  qsort(v,n,sizeof(int64),cmp);
  double sum=0;
  for(i=n-1;i>=n-a;i--) sum+=v[i];
  printf("%.10lf\n",sum/a);
  for(i=n-1;i>=0 && v[i]==v[n-1];i--);
  i++;
  if(n-i>=a){
    int64 ans=0;
    int j;
    for(j=a;j<=b;j++) ans+=comb(n-i,j);
    printf("%lld\n",ans);
  } else {
    int l,r;
    for(l=n-a;l>=0 && v[l]==v[n-a];l--);
    l++;
    for(r=n-a;r<n  && v[r]==v[n-a];r++);
    r--;
    printf("%lld\n",comb(r-l+1,a-(n-1-r)));
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:27:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&a,&b);
   ^
./Main.c:30:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%lld",v+i);
                    ^