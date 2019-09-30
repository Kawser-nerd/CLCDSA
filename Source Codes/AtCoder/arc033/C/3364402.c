#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct scapegoatTreeNode{
  void *val;
  int size;
  struct scapegoatTreeNode *left;
  struct scapegoatTreeNode *right;
} sNode;

typedef struct scapegoatTreeHead{
  sNode *root;
  int del;
  size_t size;
  int (*cmp)(const void *,const void *);
} sTree;

sTree* newSTree(size_t size,int (*cmp)(const void *,const void *)){
  sTree *res=(sTree *)malloc(sizeof(sTree));
  res->root=NULL;
  res->del=0;
  res->size=size;
  res->cmp=cmp;
  return res;
}

sNode* newNode(const void *v,size_t size){
  sNode *res=(sNode *)malloc(sizeof(sNode));
  res->val=malloc(size);
  memcpy(res->val,v,size);
  res->size=1;
  res->left=NULL;
  res->right=NULL;
  return res;
}

void freeNode(sNode *t){
  free(t->val);
  free(t);
  return;
}

void freeAllNode(sNode *r){
  if(r==NULL) return;
  freeAllNode(r->left);
  freeAllNode(r->right);
  freeNode(r);
  return;
}

int getSize(sNode *r){
  return r==NULL?0:r->size;
}

void update(sNode *r){
  if(r==NULL) return;
  r->size=1+getSize(r->left)+getSize(r->right);
  return;
}

int packToArray(sNode *r,void *array,size_t size){
  if(r==NULL) return 0;
  int cnt=packToArray(r->left,array,size);
  memcpy(array+size*cnt++,r->val,size);
  return cnt+packToArray(r->right,array+size*cnt,size);
}

sNode* buildBalanced(void *array,int n,size_t size){
  if(n<=0) return NULL;
  int m=n/2;
  sNode *res=newNode(array+size*m,size);
  res->left=buildBalanced(array,m,size);
  res->right=buildBalanced(array+size*(m+1),n-1-m,size);
  update(res);
  return res;
}

sNode* rebuild(sNode *r,size_t size){
  void *array=malloc(size*getSize(r));
  int n=packToArray(r,array,size);
  freeAllNode(r);
  sNode *res=buildBalanced(array,n,size);
  free(array);
  return res;
}

sNode* insert_func(sNode *r,const void *v,sTree *t,int *cond){
  if(r==NULL) return newNode(v,t->size);
  if(t->cmp(r->val,v)>=0){
    r->left=insert_func(r->left,v,t,cond);
  } else {
    r->right=insert_func(r->right,v,t,cond);
  }
  update(r);
  if(*cond && (2*getSize(r)<3*getSize(r->left) || 2*getSize(r)<3*getSize(r->right))){
    r=rebuild(r,t->size);
    *cond=0;
  }
  return r;
}

void insert(sTree *t,const void *v){
  int cond=1;
  t->root=insert_func(t->root,v,t,&cond);
}

sNode* erase_func_findMax(sNode *r,sNode **max){
  if(r->right==NULL){
    *max=r;
    return r->left;
  }
  r->right=erase_func_findMax(r->right,max);
  update(r);
  return r;
}

sNode* erase_func(sNode *r,const void *v,sTree *t){
  if(r==NULL) return NULL;
  int c=t->cmp(r->val,v);
  if(c==0){
    sNode *f=r;
    if(r->left==NULL){
      r=r->right;
    } else if(r->right==NULL){
      r=r->left;
    } else {
      sNode *max;
      r->left=erase_func_findMax(r->left,&max);
      max->left=r->left;
      max->right=r->right;
      r=max;
    }
    freeNode(f);
  } else if(c>0){
    r->left=erase_func(r->left,v,t);
  } else {
    r->right=erase_func(r->right,v,t);
  }
  update(r);
  return r;
}

void erase(sTree *t,const void *v){
  t->root=erase_func(t->root,v,t);
  t->del++;
  if(t->del*2>getSize(t->root)){
    t->root=rebuild(t->root,t->size);
    t->del=0;
  }
}

void search(sTree *t,int k,void *v){
  sNode *r=t->root;
  while(1){
    if(getSize(r->left)<k){
      k-=getSize(r->left);
      if(k==1){
	memcpy(v,r->val,t->size);
	return;
      }
      k--;
      r=r->right;
    } else {
      r=r->left;
    }
  }
}

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

void run(void){
  int q;
  scanf("%d",&q);
  sTree *t=newSTree(sizeof(int),cmp);
  while(q--){
    int c,x;
    scanf("%d%d",&c,&x);
    if(c==1){
      insert(t,&x);
    } else {
      search(t,x,&x);
      printf("%d\n",x);
      erase(t,&x);
    }
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:176:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&q);
   ^
./Main.c:180:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&c,&x);
     ^