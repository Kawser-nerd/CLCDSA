#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

typedef struct WeightBalancedTreeNode{
  int64 val;
  int64 lazy;
  int size;
  struct WeightBalancedTreeNode *left;
  struct WeightBalancedTreeNode *right;
} WBNode;

int getSize(const WBNode *t){
  return t==NULL?0:t->size;
}

int getWeight(const WBNode *t){
  return t==NULL?1:getSize(t)*2;
}

int64 getVal(const WBNode *t){
  return t==NULL?0:t->val+t->lazy*t->size;
}

WBNode *array=NULL;
int pointer=0;
const int max=800000;
WBNode* newWBNode(WBNode *l,WBNode *r){
  WBNode *res=array+pointer++;
  res->val=getVal(l)+getVal(r);
  res->lazy=0;
  res->size=getSize(l)+getSize(r);
  res->left=l;
  res->right=r;
  return res;
}

WBNode* clone(WBNode *t){
  WBNode *res=newWBNode(NULL,NULL);
  *res=*t;
  return res;
}

WBNode* propagate(WBNode *t){
  WBNode *l=t->left;
  l=clone(l);
  l->lazy+=t->lazy;
  WBNode *r=t->right;
  r=clone(r);
  r->lazy+=t->lazy;
  return newWBNode(l,r);
}

int balance(const WBNode *a,const WBNode *b){
  int wa=getWeight(a);
  int wb=getWeight(b);
  if(3*wa<wb) return -1;
  if(3*wb<wa) return 1;
  return 0;
}

WBNode* leftRotate(WBNode *v){
  v=propagate(v);
  WBNode *u=v->right;
  u=propagate(u);
  return newWBNode(newWBNode(v->left,u->left),u->right);
}

WBNode* rightRotate(WBNode *u){
  u=propagate(u);
  WBNode *v=u->left;
  v=propagate(v);
  return newWBNode(v->left,newWBNode(v->right,u->right));
}

WBNode* merge(WBNode *l,WBNode *r){
  if(l==NULL) return r;
  if(r==NULL) return l;
  int b=balance(l,r);
  if(b==0) return newWBNode(l,r);
  if(b<0){
    r=propagate(r);
    WBNode *t=merge(l,r->left);
    if(balance(t,r->right)==0) return newWBNode(t,r->right);
    if(getWeight(t->left)*2<=getWeight(t->right)) t=leftRotate(t);
    return rightRotate(newWBNode(t,r->right));
  } else {
    l=propagate(l);
    WBNode *t=merge(l->right,r);
    if(balance(l->left,t)==0) return newWBNode(l->left,t);
    if(getWeight(t->right)*2<=getWeight(t->left)) t=rightRotate(t);
    return leftRotate(newWBNode(l->left,t));
  }
}

void split(WBNode *t,const int k,WBNode **x,WBNode **y){
  if(k==0){
    *x=NULL;
    *y=t;
    return;
  }
  if(getSize(t)==k){
    *x=t;
    *y=NULL;
    return;
  }
  t=propagate(t);
  if(getSize(t->left)<k){
    split(t->right,k-getSize(t->left),x,y);
    *x=merge(t->left,*x);
  } else {
    split(t->left,k,x,y);
    *y=merge(*y,t->right);
  }
}

void treeToArray(WBNode *r,int64 *v,int *index,int64 lazy){
  if(r->left==NULL && r->right==NULL){
    v[(*index)++]=getVal(r)+lazy;
    return;
  }
  treeToArray(r->left ,v,index,lazy+r->lazy);
  treeToArray(r->right,v,index,lazy+r->lazy);
  return;
}

WBNode* arrayToTree(int64 *v,int n){
  if(n==1){
    WBNode *res=newWBNode(NULL,NULL);
    res->val=v[0];
    res->size=1;
    return res;
  }
  int m=n/2;
  WBNode *l=arrayToTree(v,m);
  WBNode *r=arrayToTree(v+m,n-m);
  return newWBNode(l,r);
}

WBNode* rebuild(WBNode *t,int64 *v){
  int index=0;
  treeToArray(t,v,&index,0);
  pointer=0;
  return arrayToTree(v,index);
}

void run(void){
  int n,q;
  scanf("%d%d",&n,&q);
  int64 *x=(int64 *)malloc(sizeof(int64)*n);
  array=(WBNode *)malloc(sizeof(WBNode)*max);
  int i;
  for(i=0;i<n;i++) scanf("%lld",x+i);
  WBNode *t=arrayToTree(x,n);
  while(q--){
    int type;
    scanf("%d",&type);
    if(type==1){
      int a,b,v;
      scanf("%d%d%d",&a,&b,&v);
      WBNode *x,*y,*z;
      split(t,b,&y,&z);
      split(y,a-1,&x,&y);
      y=clone(y);
      y->lazy+=v;
      t=merge(x,merge(y,z));
    } else if(type==2){
      int a,b,c,d;
      scanf("%d%d%d%d",&a,&b,&c,&d);
      WBNode *x,*y,*z;
      split(t,d,&y,&z);
      split(y,c-1,&x,&y);
      WBNode *p,*q,*r;
      split(t,b,&q,&r);
      split(q,a-1,&p,&q);
      t=merge(p,merge(y,r));
    } else {
      int a,b;
      scanf("%d%d",&a,&b);
      WBNode *x,*y,*z;
      split(t,b,&y,&z);
      split(y,a-1,&x,&y);
      printf("%lld\n",getVal(y));
    }
    if(max-pointer<1000) t=rebuild(t,x);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:150:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&q);
   ^
./Main.c:154:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%lld",x+i);
                    ^
./Main.c:158:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&type);
     ^
./Main.c:161:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d%d%d",&a,&b,&v);
       ^
./Main.c:170:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d%d%d%d",&a,&b,&c,&d);
       ^
./Main.c:180:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d%d",&a,&b);
       ^