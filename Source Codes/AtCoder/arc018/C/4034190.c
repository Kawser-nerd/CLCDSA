#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

typedef struct node{
  int val;
  int index;
} node;

int cmp(const void *a,const void *b){
  return ((node *)a)->val-((node *)b)->val;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  int x,a,p;
  scanf("%d%d%d",&x,&a,&p);
  if(a%p==0){
    printf("%d\n",x>x%p?2*(n-1):0);
    return;
  }
  node *b=(node *)calloc(n*m,sizeof(node));
  int i;
  for(i=0;i<n*m;i++){
    b[i]=(node){x,i};
    x=(x+a)%p;
  }
  qsort(b,n*m,sizeof(node),cmp);
  int *cnt=(int *)calloc(m,sizeof(int));
  int64 sum=0;
  for(i=0;i<n;i++){
    memset(cnt,0,sizeof(int)*m);
    int j;
    for(j=i*m;j<i*m+m;j++){
      sum+=ABS(i-b[j].index/m);
      cnt[b[j].index%m]++;
    }
    int k=0;
    for(j=0;j<m;j++){
      if(cnt[j]>=1) continue;
      while(cnt[k]<=1) k++;
      sum+=ABS(j-k);
      cnt[j]++;
      cnt[k]--;
    }
  }
  printf("%lld\n",sum);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&x,&a,&p);
   ^