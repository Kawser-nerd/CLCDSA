#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

typedef struct idexedval{
  int a;
  int index;
} node;

int cmp(const node *a,const node *b){
  return a->a<=b->a;
}

node *seg=NULL;
int size=0;
const int inf=1000000000;
void rmq_init(int *array,int n){
  int t=1;
  while(t<n) t*=2;
  seg=(node *)malloc(sizeof(node)*2*t);
  size=t;
  int i;
  for(i=0;i<n;i++){
    seg[i+size].a=array[i];
    seg[i+size].index=i;
  }
  for(;i<size;i++) seg[i+size].a=inf;
  for(i=size-1;i>=1;i--) seg[i]=cmp(seg+2*i,seg+2*i+1)?seg[2*i]:seg[2*i+1];
  return;
}

//[l,r)
void calc(int l,int r,node *res){
  for(l+=size,r+=size;l<r;l>>=1,r>>=1){
    if(r&0x01){
      --r;
      *res=cmp(res,seg+r)?*res:seg[r];
    }
    if(l&0x01){
      *res=cmp(res,seg+l)?*res:seg[l];
      l++;
    }
  }
  return;
}

void run(void){
  int n;
  scanf("%d",&n);
  int *array=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",array+i);
  rmq_init(array,n);
  int64 sum=0;
  int *sl=(int *)malloc(sizeof(int)*n);
  int *sr=(int *)malloc(sizeof(int)*n);
  sl[0]=0;
  sr[0]=n;
  int top=1;
  while(top>0){
    top--;
    int l=sl[top];
    int r=sr[top];
    if(l>=r) continue;
    node t;
    t.a=inf;
    calc(l,r,&t);
    int min=t.a;
    int m=t.index;
    sum+=(int64)min*(m+1-l)*(r-m);
    sl[top]=l;sr[top]=m;top++;
    sl[top]=m+1;sr[top]=r;top++;
  }
  printf("%lld\n",sum);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:50:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:53:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",array+i);
                    ^