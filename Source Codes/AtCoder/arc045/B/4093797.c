#include<stdio.h>
#include<stdlib.h>

#define MIN(a,b) ((a)<(b)?(a):(b))

typedef struct RAQandRMQSegmentTree{
  int add;
  int min;
  struct RAQandRMQSegmentTree *l;
  struct RAQandRMQSegmentTree *r;
} segNode;

segNode* newNode(void){
  segNode *res=(segNode *)malloc(sizeof(segNode));
  *res=(segNode){0,0,NULL,NULL};
  return res;
}

segNode* construct(int l,int r){
  if(r==l+1) return newNode();
  segNode *res=newNode();
  int m=(l+r)/2;
  res->l=construct(l,m);
  res->r=construct(m,r);
  return res;
}

int getMin(segNode *s){
  return s->min+s->add;
}

void add(segNode *s,int l,int r,int x,int y,int v){
  if(y<=l || r<=x) return;
  if(x<=l && r<=y){
    s->add+=v;
    return;
  }
  int m=(l+r)/2;
  add(s->l,l,m,x,y,v);
  add(s->r,m,r,x,y,v);
  s->min=MIN(getMin(s->l),getMin(s->r));
}

int queryMin(segNode *s,int l,int r,int x,int y){
  if(y<=l || r<=x) return 1000000000+1;
  if(x<=l && r<=y) return getMin(s);
  int m=(l+r)/2;
  int ll=queryMin(s->l,l,m,x,y);
  int rr=queryMin(s->r,m,r,x,y);
  return MIN(ll,rr)+s->add;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  int l=1;
  int r=n+1;
  segNode *seg=construct(l,r);
  int *s=(int *)calloc(m,sizeof(int));
  int *t=(int *)calloc(m,sizeof(int));
  int i;
  for(i=0;i<m;i++){
    scanf("%d%d",s+i,t+i);
    add(seg,l,r,s[i],t[i]+1,1);
  }
  int cnt=0;
  for(i=0;i<m;i++) if(queryMin(seg,l,r,s[i],t[i]+1)>1) cnt++;
  printf("%d\n",cnt);
  for(i=0;i<m;i++) if(queryMin(seg,l,r,s[i],t[i]+1)>1) printf("%d\n",i+1);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:55:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:63:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",s+i,t+i);
     ^