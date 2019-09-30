#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int cmp(const void *a,const void *b){
  int64 p=*(int64 *)a;
  int64 q=*(int64 *)b;
  return p==q?0:p<q?-1:1;
}

typedef struct oishikunaru{
  double a,b;
} node;

//f_c = f_b $ f_a
void func(node *c,node *a,node *b){
  double p=a->a;
  double q=a->b;
  double r=b->a;
  double s=b->b;
  c->a=p*r;
  c->b=r*q+s;
  return;
}

node *seg=NULL;
int size=0;
void init(int n){
  int k=1;
  while(k<n) k*=2;
  size=k;
  seg=(node *)malloc(sizeof(node)*2*size);
  int i;
  for(i=0;i<2*size;i++){
    seg[i].a=1;
    seg[i].b=0;
  }
  return;
}

void update(int index,node *p){
  int k=index+size;
  seg[k]=*p;
  k/=2;
  while(k>=1){
    func(seg+k,seg+2*k,seg+2*k+1);
    k/=2;
  }
  return;
}

int toIndex(int64 *za,int len,int64 p){
  int l=0;
  int r=len;
  while(r-l>1){
    int m=(l+r)/2;
    if(za[m]<=p){
      l=m;
    } else {
      r=m;
    }
  }
  return l;
}

void run(void){
  int64 n;
  int m;
  scanf("%lld%d",&n,&m);
  if(m==0){
    printf("1\n1\n");
    return;
  }
  int64 *p=(int64 *)malloc(sizeof(int64)*m);
  node *q=(node *)malloc(sizeof(node)*m);
  int64 *za=(int64 *)malloc(sizeof(int64)*m);
  int i;
  for(i=0;i<m;i++){
    scanf("%lld%lf%lf",p+i,&q[i].a,&q[i].b);
    za[i]=p[i];
  }
  qsort(za,m,sizeof(int64),cmp);
  int len=0;
  i=0;
  while(i<m){
    za[len++]=za[i++];
    while(i<m && za[len-1]==za[i]) i++;
  }
  init(len);
  double min=1;
  double max=1;
  for(i=0;i<m;i++){
    update(toIndex(za,len,p[i]),q+i);
    double t=seg[1].a+seg[1].b;
    min=MIN(min,t);
    max=MAX(max,t);
  }
  printf("%.7lf\n%.7lf\n",min,max);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:73:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%d",&n,&m);
   ^
./Main.c:83:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lf%lf",p+i,&q[i].a,&q[i].b);
     ^