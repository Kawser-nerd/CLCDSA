#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>

typedef struct point2d{
  int x,y;
} point;

typedef struct segmentNode{
  point left;
  point right;
  double way;
} node;

double *logFact=NULL;
void init(const int n){
  logFact=(double *)calloc(n+1,sizeof(double));
  logFact[0]=0;
  int i;
  for(i=1;i<=n;i++) logFact[i]=logFact[i-1]+log(i);
  return;
}

typedef struct psegmentTree{
  node *a;
  int size;
} segTree;

inline node func(node l,node r){
  int dx=r.left.x-l.right.x;
  int dy=r.left.y-l.right.y;
  return (node){l.left,r.right,l.way+r.way+(logFact[dx+dy]-logFact[dx]-logFact[dy])};
}

segTree* newSegmentTree(const point *p,const int n){
  int k=1;
  while(k<n) k*=2;
  segTree *s=(segTree *)calloc(1,sizeof(segTree));
  s->a=(node *)calloc(2*k,sizeof(node));
  s->size=k;
  int i;
  for(i=0;i<n;i++) s->a[i+k]=(node){p[i],p[i],0};
  for(i=n;i<k;i++){
    s->a[i+k].left=(point){1000000,1000000};
    s->a[i+k].right=(point){1000000,1000000};
    s->a[i+k].way=0;
  }
  for(i=k-1;i>=1;i--) s->a[i]=func(s->a[2*i],s->a[2*i+1]);
  return s;
}

void update(segTree *s,int index,point p){
  node *a=s->a;
  int k=index+s->size;
  a[k]=(node){p,p,0};
  k>>=1;
  while(k>=1){
    a[k]=func(a[2*k],a[2*k+1]);
    k>>=1;
  }
}

double query(segTree *s,int l,int r){
  node left[32];
  node right[32];
  int lLen=0;
  int rLen=0;
  for(l+=s->size,r+=s->size;l<r;l>>=1,r>>=1){
    if(l&1) left[lLen++]=s->a[l++];
    if(r&1) right[rLen++]=s->a[--r];
  }
  if(lLen>0){
    node t=left[0];
    int i;
    for(i=1;i<lLen;i++) t=func(t,left[i]);
    for(i=rLen-1;i>=0;i--) t=func(t,right[i]);
    return t.way;
  } else {
    node t=right[rLen-1];
    int i;
    for(i=rLen-2;i>=0;i--) t=func(t,right[i]);
    return t.way;
  }
}

void run(void){
  int n;
  scanf("%d",&n);
  init(2000000);
  point *p=(point *)calloc(n,sizeof(point));
  int i;
  for(i=0;i<n;i++) scanf("%d%d",&p[i].x,&p[i].y);
  segTree *s=newSegmentTree(p,n);
  int q;
  scanf("%d",&q);
  while(q--){
    int type;
    scanf("%d",&type);
    if(type==1){
      int k,a,b;
      scanf("%d%d%d",&k,&a,&b);
      update(s,k-1,(point){a,b});
    } else {
      int a,b,c,d;
      scanf("%d%d%d%d",&a,&b,&c,&d);
      double e=query(s,a-1,b);
      double f=query(s,c-1,d);
      printf("%s\n",e>f?"FIRST":"SECOND");
    }
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:89:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:93:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d%d",&p[i].x,&p[i].y);
                    ^
./Main.c:96:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&q);
   ^
./Main.c:99:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&type);
     ^
./Main.c:102:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d%d%d",&k,&a,&b);
       ^
./Main.c:106:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d%d%d%d",&a,&b,&c,&d);
       ^