#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

typedef struct oishikunaru{
  double a,b;
} trans;

void func(trans *c,const trans *a,const trans *b){
  double p=a->a;
  double q=a->b;
  double r=b->a;
  double s=b->b;
  c->a=p*r;
  c->b=q*r+s;
  return;
}

const trans e={1.0,0.0};

typedef struct toNode{
  int64 index;
  trans this;
  trans all;
} nodeData;

typedef struct WeightBalancedTreeNode{
  nodeData val;
  int size;
  struct WeightBalancedTreeNode *left;
  struct WeightBalancedTreeNode *right;
} WBTNode;

typedef struct WeightBalancedTreeHead{
  WBTNode *root;
  int (*cmp)(const void *,const void *);
} WBTree;

WBTNode* newWBTNode(const nodeData *v){
  WBTNode *res=(WBTNode *)malloc(sizeof(WBTNode));
  res->val=*v;
  res->size=1;
  res->left=NULL;
  res->right=NULL;
  return res;
}

int getSize(const WBTNode *t){
  return t==NULL?0:t->size;
}

int getWeight(const WBTNode *t){
  return getSize(t)+1;
}

void freeWBTNode(WBTNode *t){
  free(t);
  return;
}

WBTree* newWBTree(int (*cmp)(const void *,const void *)){
  WBTree *res=(WBTree *)malloc(sizeof(WBTree));
  res->root=NULL;
  res->cmp=cmp;
  return res;
}

void update(WBTNode *t){
  if(t==NULL) return;
  t->size=1+getSize(t->left)+getSize(t->right);
  trans x;
  func(&x,t->left==NULL?&e:&t->left->val.all,&t->val.this);
  func(&x,&x,t->right==NULL?&e:&t->right->val.all);
  t->val.all=x;
  return;
}

WBTNode* leftRotate(WBTNode *v){
  WBTNode *u=v->right;
  v->right=u->left;
  u->left=v;
  update(v);
  update(u);
  return u;
}

WBTNode* rightRotate(WBTNode *u){
  WBTNode *v=u->left;
  u->left=v->right;
  v->right=u;
  update(u);
  update(v);
  return v;
}

WBTNode* balance(WBTNode *t){
  if(t==NULL) return NULL;
  if(getWeight(t->left)*3<getWeight(t->right)){
    if(getWeight(t->right->left)>=2*getWeight(t->right->right)) t->right=rightRotate(t->right);
    t=leftRotate(t);
  } else if(getWeight(t->right)*3<getWeight(t->left)){
    if(getWeight(t->left->right)>=2*getWeight(t->left->left)) t->left=leftRotate(t->left);
    t=rightRotate(t);
  }
  return t;
}

WBTNode* insert_func(WBTNode *r,const nodeData *v,WBTree *t){
  if(r==NULL) return newWBTNode(v);
  int c=t->cmp(&r->val,v);
  if(c==0){
    r->val=*v;
  } else if(c>0){
    r->left=insert_func(r->left,v,t);
  } else {
    r->right=insert_func(r->right,v,t);
  }
  update(r);
  return balance(r);
}

void insert(WBTree *t,const nodeData *v){
  t->root=insert_func(t->root,v,t);
  return;
}

int cmp(const void *a,const void *b){
  int64 p=((nodeData *)a)->index;
  int64 q=((nodeData *)b)->index;
  return p==q?0:p-q<0?-1:1;
}

void run(void){
  int64 n;
  int m;
  scanf("%lld%d",&n,&m);
  WBTree *t=newWBTree(cmp);
  double min=1;
  double max=1;
  while(m--){
    int64 p;
    double a,b;
    scanf("%lld%lf%lf",&p,&a,&b);
    trans tr={a,b};
    insert(t,&((nodeData){p,tr,tr}));
    tr=t->root->val.all;
    if(min>tr.a+tr.b) min=tr.a+tr.b;
    if(max<tr.a+tr.b) max=tr.a+tr.b;
  }
  printf("%.6lf\n%.6lf\n",min,max);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:137:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%d",&n,&m);
   ^
./Main.c:144:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lf%lf",&p,&a,&b);
     ^