#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

typedef struct WBTNode{
  int64 cnt;
  int val;
  int size;
  struct WBTNode *left;
  struct WBTNode *right;
} WBTNode;

WBTNode* newNode(int64 cnt,int val){
  WBTNode *res=(WBTNode *)calloc(1,sizeof(WBTNode));
  res->cnt=cnt;
  res->val=val;
  res->size=1;
  res->left=res->right=NULL;
  return res;
}

int getWeight(const WBTNode *t){
  return 1+(t==NULL?0:t->size);
}

int getBias(const WBTNode *t,int b){
  if(t==NULL) return 0;
  int l=getWeight(t->left);
  int r=getWeight(t->right);
  if(l<=b*r && b*l>=r) return 0;
  return l>b*r?1:-1;
}

void update(WBTNode *t){
  t->size=getWeight(t->left)+getWeight(t->right)-1;
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
  int b=getBias(t,3);
  if(b==0) return t;
  if(b==1){
    b=getBias(t->left,2);
    if(b<0) t->left=leftRotate(t->left);
    t=rightRotate(t);
  } else {
    b=getBias(t->right,2);
    if(b>0) t->right=rightRotate(t->right);
    t=leftRotate(t);
  }
  return t;
}

WBTNode* insert(WBTNode *t,int64 cnt,int val){
  if(t==NULL) return newNode(cnt,val);
  if(val==t->val){
    t->cnt+=cnt;
    return t;
  }
  if(val<t->val){
    t->left=insert(t->left,cnt,val);
  } else {
    t->right=insert(t->right,cnt,val);
  }
  update(t);
  return balance(t);
}

int64 count(const WBTNode *t,const int val){
  while(t!=NULL){
    if(val==t->val) return t->cnt;
    if(val<t->val){
      t=t->left;
    } else {
      t=t->right;
    }
  }
  return 0;
}

int gcd(int a,int b){
  int r=a%b;
  while(r>0){
    a=b;b=r;r=a%b;
  }
  return b;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  WBTNode *dp=NULL;
  int val[32],cnt[32];
  int len=0;
  while(n--){
    int a;
    scanf("%d",&a);
    int i,j;
    for(i=0;i<len;i++) val[i]=gcd(val[i],a);
    val[len]=a;
    cnt[len]=1;
    len++;
    i=j=0;
    while(i<len){
      val[j]=val[i];
      cnt[j]=cnt[i];
      i++;
      while(i<len && val[j]==val[i]) cnt[j]+=cnt[i++];
      j++;
    }
    len=j;
    for(i=0;i<len;i++) dp=insert(dp,cnt[i],val[i]);
  }
  while(m--){
    int x;
    scanf("%d",&x);
    printf("%lld\n",count(dp,x));
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:109:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:115:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^
./Main.c:134:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&x);
     ^