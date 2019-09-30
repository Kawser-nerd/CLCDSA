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
  int64 l,r;
  node v;
  struct segmentNode *left,*right;
} segNode;

segNode* newNode(int64 l,int64 r){
  segNode *res=(segNode *)malloc(sizeof(segNode));
  res->l=l;
  res->r=r;
  res->v=ini;
  res->left=NULL;
  res->right=NULL;
  return res;
}

void update(segNode *r,const int64 index,const node *v){
  if(r->l==index && r->r==index){
    r->v=*v;
    return;
  }
  int64 m=(r->l+r->r)/2;
  if(index<=m){
    if(r->left==NULL){
      r->left=newNode(r->l,m);
    }
    update(r->left,index,v);
  } else {
    if(r->right==NULL){
      r->right=newNode(m+1,r->r);
    }
    update(r->right,index,v);
  }
  func(&r->v,r->left?&r->left->v:&ini,r->right?&r->right->v:&ini);
  return;
}

void run(void){
  int64 n;
  int m;
  scanf("%lld%d",&n,&m);
  if(m==0){
    printf("1\n1\n");
    return;
  }
  segNode *root=newNode(1,1000000000000LL);
  double min=1;
  double max=1;
  int i;
  for(i=0;i<m;i++){
    int64 p;
    double a,b;
    scanf("%lld%lf%lf",&p,&a,&b);
    node v={a,b};
    update(root,p,&v);
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
./Main.c:63:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%d",&n,&m);
   ^
./Main.c:75:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lf%lf",&p,&a,&b);
     ^