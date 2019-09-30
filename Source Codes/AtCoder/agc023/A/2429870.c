#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

typedef struct snode{
  int64 val;
  int index;
} node;

int cmp(const void *a,const void *b){
  node *aa=(node *)a;
  node *bb=(node *)b;
  if(aa->val!=bb->val) return aa->val-bb->val<0?-1:1;
  if(aa->index!=bb->index) return aa->index-bb->index<0?-1:1;
  return 0;
}

void run(void){
  int n;
  scanf("%d",&n);
  int *a=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  node *b=(node *)malloc(sizeof(node)*(n+1));
  node *c=(node *)malloc(sizeof(node)*(n+1));
  b[0].val=0;
  b[0].index=0;
  c[0]=b[0];
  for(i=1;i<=n;i++){
    b[i].val=b[i-1].val+a[i-1];
    b[i].index=i;
    c[i]=b[i];
  }
  qsort(c,n+1,sizeof(node),cmp);

  int64 cnt=0;
  for(i=0;i<n;i++){
    node t=b[i];
    int l=0;
    int r=n+1;
    while(l+1<r){
      int m=(l+r)/2;
      if(cmp(&t,&(c[m]))>=0){
	l=m;
      } else 
	r=m;{
      }
    }
    if(r<n+1 && c[r].val!=t.val) continue;
    int ll=r;
    l=0;
    r=n+1;
    while(l+1<r){
      int m=(l+r)/2;
      if(t.val-c[m].val>=0){
	l=m;
      } else {
	r=m;
      }
    }
    int rr=l;
    cnt+=rr-ll+1;
  }
  printf("%lld\n",cnt);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:29:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^