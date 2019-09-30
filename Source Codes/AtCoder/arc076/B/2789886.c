#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

typedef struct pointindex{
  int val;
  int index,next;
} node;

int cmp(const void *a,const void *b){
  node *p=(node *)a;
  node *q=(node *)b;
  return p->val-q->val;
}

int root(int x,int *u){
  if(x==u[x]) return x;
  u[x]=root(u[x],u);
  return u[x];
}

int same(int x,int y,int *u){
  return root(x,u)==root(y,u);
}

void merge(int x,int y,int *u){
  x=root(x,u);
  y=root(y,u);
  if(x==y) return;
  u[x]=y;
  return;
}

void run(void){
  int n;
  scanf("%d",&n);
  node *sortX=(node *)malloc(sizeof(node)*n);
  node *sortY=(node *)malloc(sizeof(node)*n);
  int i;
  for(i=0;i<n;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    sortX[i].val=x;
    sortY[i].val=y;
    sortX[i].index=sortY[i].index=i;
  }
  qsort(sortX,n,sizeof(node),cmp);
  qsort(sortY,n,sizeof(node),cmp);
  for(i=0;i<n-1;i++){
    sortX[i].val=sortX[i+1].val-sortX[i].val;
    sortX[i].next=sortX[i+1].index;
    sortY[i].val=sortY[i+1].val-sortY[i].val;
    sortY[i].next=sortY[i+1].index;
  }
  qsort(sortX,n-1,sizeof(node),cmp);
  qsort(sortY,n-1,sizeof(node),cmp);
  int *u=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++) u[i]=i;

  int xIndex=0;
  int yIndex=0;
  int64 cost=0;
  int cnt=0;
  while(cnt<n-1){
    if(sortX[xIndex].val<=sortY[yIndex].val){
      int a=sortX[xIndex].index;
      int b=sortX[xIndex].next;
      if(!same(a,b,u)){
	merge(a,b,u);
	cost+=sortX[xIndex].val;
	cnt++;
      }
      xIndex++;
    } else {
      int a=sortY[yIndex].index;
      int b=sortY[yIndex].next;
      if(!same(a,b,u)){
	merge(a,b,u);
	cost+=sortY[yIndex].val;
	cnt++;
      }
      yIndex++;
    }
  }
  printf("%lld\n",cost);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:42:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:48:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&x,&y);
     ^