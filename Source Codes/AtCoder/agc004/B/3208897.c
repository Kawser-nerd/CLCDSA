#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

#define MIN(a,b) ((a)<(b)?(a):(b))

typedef int node;

typedef struct segmentTreePointUpdateRangeAns{
  node *array;
  int size;
  node e;
  void (*func)(node *c,const node *a,const node *b);
} segTree;

segTree* newSegmentTree(int n,const node *e,void (*f)(node *c,const node *a,const node *b)){
  segTree *res=(segTree *)malloc(sizeof(segTree));
  int k=1;
  while(k<n) k*=2;
  res->array=(node *)malloc(sizeof(node)*2*k);
  res->size=k;
  res->e=*e;
  res->func=f;
  int i;
  for(i=1;i<2*k;i++) res->array[i]=*e;
  return res;
}

void update(segTree *seg,int index,node *v){
  node *s=seg->array;
  int k=seg->size+index;
  s[k]=*v;
  k/=2;
  while(k>=1){
    seg->func(s+k,s+2*k,s+2*k+1);
    k/=2;
  }
  return;
}

//[l,r)
void query(segTree *seg,int l,int r,node *res){
  int size=seg->size;
  node *a=seg->array;
  node s=seg->e;
  node t=seg->e;
  for(l+=size,r+=size;l<r;l/=2,r/=2){
    if(l&0x01) seg->func(&s,&s,a+l++);
    if(r&0x01) seg->func(&t,a+(--r),&t);
  }
  seg->func(res,&t,&s);
  return;
}

void func(node *c,const node *a,const node *b){
  *c=MIN(*a,*b);
  return;
}

void run(void){
  int n,x;
  scanf("%d%d",&n,&x);
  int *a=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  int e=1000000000;
  segTree *seg=newSegmentTree(2*n,&e,func);
  for(i=0;i<2*n;i++){
    update(seg,i,a+i%n);
  }
  int64 ans=(int64)e*n;
  int k;
  for(k=0;k<n;k++){
    int64 local=(int64)k*x;
    for(i=n;i<2*n;i++){
      int t;
      query(seg,i-k,i+1,&t);
      local+=t;
    }
    ans=MIN(ans,local);
  }
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:63:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&x);
   ^
./Main.c:66:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^