#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

typedef struct cir{
  int val;
  int index;
} node;

int cmp(const void *a,const void *b){
  return ((node *)a)->val-((node *)b)->val;
}

int func(int x,int y,int r,int c){
  if(!(x==0 || x==r || y==0 || y==c)) return -1;
  if(x==0) return y;
  if(y==c) return c+x;
  if(x==r) return r+c+(c-y);
  return 2*c+r+(r-x);
}

void run(void){
  int r,c,n;
  scanf("%d%d%d",&r,&c,&n);
  node *array=(node *)malloc(sizeof(node)*2*n);
  int len=0;
  int i;
  for(i=0;i<n;i++){
    int x1,y1,x2,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    int v1=func(x1,y1,r,c);
    int v2=func(x2,y2,r,c);
    if(v1>=0 && v2>=0){
      array[len].val=v1;
      array[len].index=i;
      len++;
      array[len].val=v2;
      array[len].index=i;
      len++;
    }
  }
  qsort(array,len,sizeof(node),cmp);
  int *stack=(int *)malloc(sizeof(int)*len);
  int top=0;
  for(i=0;i<len;i++){
    int index=array[i].index;
    if(top>0 && stack[top-1]==index){
      top--;
    } else {
      stack[top++]=index;
    }
  }
  printf("%s\n",top==0?"YES":"NO");
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:30:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&r,&c,&n);
   ^
./Main.c:36:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
     ^