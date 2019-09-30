#include <stdio.h>
#include <stdlib.h>
#define MAX 100000
#define mod 1000000007
int n;
typedef struct list{
  int i;
  struct list *next;
}edge;
edge *hashi[MAX]={NULL};
long long int dp_w[MAX];
long long int dp_b[MAX];
long long int dfs_w(int parent,int child);
long long int dfs_b(int parent,int child);
void tree(int a,int b);

void tree(int a,int b){
  edge *p;
  p=hashi[a];
  if(hashi[a]==NULL){
    hashi[a]=malloc(sizeof(edge));
    p=hashi[a];
  }
  else{
    while(p->next!=NULL){
      p=p->next;
    }
    p->next=malloc(sizeof(edge));
    p=p->next;
  }
  p->i=b;
  p->next=NULL;
}

long long int dfs_w(int parent,int child){
  edge *p=hashi[child];
  long long int ret=1;

  if(dp_w[child])return dp_w[child];

  while(p!=NULL){
    if(p->i!=parent){
      ret=(ret*dfs_b(child,p->i))%mod;
    }
    p=p->next;
  }
  dp_w[child]=ret;
  //printf("%d %d ",parent,child);
  //printf("dp_w[%d]=%d\n",child,dp_w[child]);
  return ret;
}

long long int dfs_b(int parent,int child){
  edge *p=hashi[child];
  long long int ret1=1,ret2=1;

  if(dp_b[child]) return dp_b[child];
  while(p!=NULL){
    if(p->i!=parent){
      ret1=(ret1*dfs_w(child,p->i))%mod;
      ret2=(ret2*dfs_b(child,p->i))%mod;
    }
    p=p->next;
  }
  dp_b[child]=(ret1+ret2)%mod;
  //printf("%d %d ",parent,child);
  //printf("dp_b[%d]=%d\n",child,dp_b[child]);
  return (ret1+ret2)%mod;
}
int main(){
  int a,b;
  int i;
  edge *p;
  scanf("%d",&n);
  for(i=0;i<n-1;i++){
    scanf("%d %d",&a,&b);
    tree(a-1,b-1);
    tree(b-1,a-1);
  }

  printf("%lld\n",dfs_b(0,0));

 
  /*
  for(i=0;i<11;i++){
    printf("%d ga oya ",i);
    if(hashi[i]!=NULL){
      p=hashi[i];
      printf("%d ",p->i);
      while(p->next!=NULL){
	p=p->next;
	printf("%d ",p->i);
      }
    }
    printf("\n");
  }
  */
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:74:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:76:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a,&b);
     ^