#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

typedef struct oishikunaru{
  double a,b;
} node;

const node ini={1.0,0};

//f_c = f_b $ f_a
void func(node *c,const node *a,const node *b){
  double p=a->a;
  double q=a->b;
  double r=b->a;
  double s=b->b;
  c->a=p*r;
  c->b=r*q+s;
  return;
}

typedef struct segmentNode{
  node v;
  struct segmentNode *left,*right;
} segNode;

segNode* newNode(void){
  segNode *res=(segNode *)malloc(sizeof(segNode));
  res->v=ini;
  res->left=NULL;
  res->right=NULL;
  return res;
}

segNode* update(segNode *p,int64 l,int64 r,const int64 index,const node *v){
  if(p==NULL) p=newNode();
  if(l==index && r==index){
    p->v=*v;
    return p;
  }
  int64 m=(l+r)/2;
  if(index<=m){
    p->left=update(p->left,l,m,index,v);
  } else {
    p->right=update(p->right,m+1,r,index,v);
  }
  func(&p->v,p->left?&p->left->v:&ini,p->right?&p->right->v:&ini);
  return p;
}

void run(void){
  int64 n;
  int m;
  scanf("%lld%d",&n,&m);
  if(m==0){
    printf("1\n1\n");
    return;
  }
  const int64 l=1;
  const int64 r=1000000000000LL;
  segNode *root=NULL;
  double min=1;
  double max=1;
  int i;
  for(i=0;i<m;i++){
    int64 p;
    double a,b;
    scanf("%lld%lf%lf",&p,&a,&b);
    node v={a,b};
    root=update(root,l,r,p,&v);
    double t=root->v.a+root->v.b;
    if(t<min) min=t;
    if(t>max) max=t;
  }
  printf("%.6lf\n%.6lf\n",min,max);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:55:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%d",&n,&m);
   ^
./Main.c:69:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lf%lf",&p,&a,&b);
     ^