#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

typedef struct nodP{
  int k;
  int v;
} node;

node *deque;
int front;
int last;
int size;
int len;

void push(int k,int v){
  size++;
  front=(front-1+len)%len;
  deque[front].k=k;
  deque[front].v=v;
  return;
}

void append(int k,int v){
  size++;
  deque[last].k=k;
  deque[last].v=v;
  last=(last+1)%len;
  return;
}

void pop(int *k,int *v){
  if(size==0){
    printf("ERROR\n");
    exit(1);
  }
  *k=deque[front].k;
  *v=deque[front].v;
  front=(front+1)%len;
  return;
}

void init(int n){
  deque=(node *)malloc(sizeof(node)*n);
  front=last=0;
  len=n;
  size=0;
  return;
}

void run(void){
  int n;
  scanf("%d",&n);
  while(n%2==0) n/=2;
  while(n%5==0) n/=5;
  if(n==1){
    printf("1\n");
    return;
  }
  const int m=n;
  int *dp=(int *)calloc(m,sizeof(int));
  init(4*m);
  push(1,1);
  while(dp[0]==0){
    int k,v;
    pop(&k,&v);
    if(dp[v]>0) continue;
    dp[v]=k;
    push(k,10*v%m);
    append(k+1,v+1);
  }
  printf("%d\n",dp[0]);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:59:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^