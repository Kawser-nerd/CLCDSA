#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

typedef struct naiveVector{
  void *array;
  size_t size;
  int maxLen;
  int len;
} vector;

void push_back(vector *vec,const void *v){
  if(vec->len==vec->maxLen){
    vec->maxLen=vec->maxLen*2+1;
    vec->array=realloc(vec->array,vec->size*vec->maxLen);
  }
  memcpy((char *)vec->array+vec->size*vec->len,v,vec->size);
  vec->len++;
  return;
}

void* getAtRef(const vector *vec,const size_t index){
  return (char *)vec->array+vec->size*index;
}

void getAt(const vector *vec,const size_t index,void *res){
  memcpy(res,getAtRef(vec,index),vec->size);
}

void run(void){
  int n;
  scanf("%d",&n);
  vector *next=(vector *)calloc(n+1,sizeof(vector));
  int i,j;
  for(i=1;i<=n;i++) next[i]=(vector){NULL,sizeof(int),0,0};
  for(i=0;i<n-1;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    push_back(next+a,&b);
    push_back(next+b,&a);
  }
  int *index=(int *)calloc(n,sizeof(int));
  int *parent=(int *)calloc(n+1,sizeof(int));
  int len=0;
  index[len++]=1;
  parent[1]=n+1;
  for(i=0;len<n;i++){
    int k=index[i];
    for(j=0;j<next[k].len;j++){
      int u;
      getAt(next+k,j,&u);
      if(parent[u]) continue;
      parent[u]=k;
      index[len++]=u;
    }
  }
  int *min=(int *)calloc(n+1,sizeof(int));
  int *max=(int *)calloc(n+1,sizeof(int));
  int *cond=(int *)calloc(n+1,sizeof(int));
  const int inf=10000000;
  for(i=1;i<=n;i++){
    min[i]=-inf;
    max[i]=inf;
    cond[i]=3;
  }
  int k;
  scanf("%d",&k);
  while(k--){
    int v,p;
    scanf("%d%d",&v,&p);
    min[v]=max[v]=p;
    cond[v]&=1<<(p&1);
  }
  for(i=n-1;i>0;i--){
    int k=index[i];
    int u=parent[k];
    min[u]=MAX(min[u],min[k]-1);
    max[u]=MIN(max[u],max[k]+1);
    cond[u]&=((cond[k]&1)<<1)|((cond[k]&2)>>1);
  }
  if(cond[1]==0){
    printf("No\n");
    return;
  }
  for(i=0;i<n;i++){
    int k=index[i];
    for(j=0;j<next[k].len;j++){
      int u;
      getAt(next+k,j,&u);
      if(parent[u]!=k) continue;
      min[u]=MAX(min[u],min[k]-1);
      max[u]=MIN(max[u],max[k]+1);
    }
  }
  for(i=1;i<=n;i++){
    if(max[i]<min[i]){
      printf("No\n");
      return;
    }
  }
  printf("Yes\n");
  for(i=1;i<=n;i++){
    printf("%d\n",min[i]);
  }
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:35:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:41:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^
./Main.c:70:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&k);
   ^
./Main.c:73:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&v,&p);
     ^