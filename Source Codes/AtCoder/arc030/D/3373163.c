#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

typedef struct AVLTreeNode{
  int64 val;
  int64 lazy;
  int size;
  int rank;
  int bias;
  struct AVLTreeNode *left;
  struct AVLTreeNode *right;
} AVLNode;

int getRank(const AVLNode *t){
  return t==NULL?0:t->rank;
}

int getSize(const AVLNode *t){
  return t==NULL?0:t->size;
}

int getBias(const AVLNode *t){
  return t==NULL?0:t->bias;
}

int64 getVal(const AVLNode *t){
  return t==NULL?0:t->val+t->lazy*getSize(t);
}

AVLNode *array=NULL;
int pointer=0;
const int max=800000;
AVLNode* newAVLNode(AVLNode *l,AVLNode *r){
  AVLNode *res=array+pointer++;
  res->val=getVal(l)+getVal(r);
  res->lazy=0;
  res->size=getSize(l)+getSize(r);
  int lrank=getRank(l);
  int rrank=getRank(r);
  res->rank=1+(lrank>=rrank?lrank:rrank);
  res->bias=lrank-rrank;
  res->left=l;
  res->right=r;
  return res;
}

AVLNode* propagate(AVLNode *t){
  if(t==NULL) return NULL;
  AVLNode *l=NULL,*r=NULL;
  if(t->left!=NULL){
    l=newAVLNode(t->left->left,t->left->right);
    l->size=t->left->size;
    l->val=t->left->val;
    l->lazy=t->lazy+t->left->lazy;
  }
  if(t->right!=NULL){
    r=newAVLNode(t->right->left,t->right->right);
    r->size=t->right->size;
    r->val=t->right->val;
    r->lazy=t->lazy+t->right->lazy;
  }
  return newAVLNode(l,r);
}

AVLNode* leftRotate(AVLNode *v){
  v=propagate(v);
  AVLNode *u=v->right;
  u=propagate(u);
  return newAVLNode(newAVLNode(v->left,u->left),u->right);
}

AVLNode* rightRotate(AVLNode *u){
  u=propagate(u);
  AVLNode *v=u->left;
  v=propagate(v);
  return newAVLNode(v->left,newAVLNode(v->right,u->right));
}

AVLNode* merge(AVLNode *l,AVLNode *r){
  if(l==NULL) return r;
  if(r==NULL) return l;
  int b=getRank(l)-getRank(r);
  if(-1<=b && b<=1) return newAVLNode(l,r);
  if(b>1){
    l=propagate(l);
    AVLNode *t=merge(l->right,r);
    b=getRank(l->left)-getRank(t);
    if(-1<=b) return newAVLNode(l->left,t);
    if(getBias(t)>=1) t=rightRotate(t);
    return leftRotate(newAVLNode(l->left,t));
  } else {
    r=propagate(r);
    AVLNode *t=merge(l,r->left);
    b=getRank(t)-getRank(r->right);
    if(b<=1) return newAVLNode(t,r->right);
    if(getBias(t)<=-1) t=leftRotate(t);
    return rightRotate(newAVLNode(t,r->right));
  }
}

void split(AVLNode *t,int k,AVLNode **x,AVLNode **y){
  if(k==0){
    *x=NULL;
    *y=t;
    return;
  }
  if(k==getSize(t)){
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

void toArray(int64 *v,AVLNode *r,int *index,int64 lazy){
  if(r==NULL) return;
  if(r->left==NULL && r->right==NULL){
    v[(*index)++]=getVal(r)+lazy;
    return;
  }
  toArray(v,r->left,index,lazy+r->lazy);
  toArray(v,r->right,index,lazy+r->lazy);
  return;
}

AVLNode* arrayToTree(int64 *v,int n){
  if(n==1){
    AVLNode *res=newAVLNode(NULL,NULL);
    res->val=v[0];
    res->size=1;
    return res;
  }
  int m=n/2;
  AVLNode *l=arrayToTree(v,m);
  AVLNode *r=arrayToTree(v+m,n-m);
  return newAVLNode(l,r);
}

AVLNode* rebuild(AVLNode *r,int64 *v){
  int index=0;
  toArray(v,r,&index,0);
  pointer=0;
  return arrayToTree(v,index);
}

void run(void){
  int n,q;
  scanf("%d%d",&n,&q);
  int64 *x=(int64 *)malloc(sizeof(int64)*n);
  array=(AVLNode *)malloc(sizeof(AVLNode)*max);
  int i;
  for(i=0;i<n;i++) scanf("%lld",x+i);
  AVLNode *t=arrayToTree(x,n);
  while(q--){
    int type;
    scanf("%d",&type);
    if(type==1){
      int a,b,v;
      scanf("%d%d%d",&a,&b,&v);
      AVLNode *x,*y,*z;
      split(t,b,&y,&z);
      split(y,a-1,&x,&y);
      y->lazy+=v;
      t=merge(x,merge(y,z));
    } else if(type==2){
      int a,b,c,d;
      scanf("%d%d%d%d",&a,&b,&c,&d);
      AVLNode *x,*y,*z;
      split(t,d,&y,&z);
      split(y,c-1,&x,&y);
      AVLNode *p,*q,*r;
      split(t,b,&q,&r);
      split(q,a-1,&p,&q);
      t=merge(p,merge(y,r));
    } else {
      int a,b;
      scanf("%d%d",&a,&b);
      AVLNode *x,*y,*z;
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
./Main.c:157:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&q);
   ^
./Main.c:161:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%lld",x+i);
                    ^
./Main.c:165:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&type);
     ^
./Main.c:168:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d%d%d",&a,&b,&v);
       ^
./Main.c:176:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d%d%d%d",&a,&b,&c,&d);
       ^
./Main.c:186:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d%d",&a,&b);
       ^