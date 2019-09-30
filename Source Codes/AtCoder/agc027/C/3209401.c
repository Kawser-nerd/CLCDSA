#include<stdio.h>
#include<stdlib.h>

#define POS(c,i) (((c)-'A')*n+(i))

void assign(int a,int b,int *vertex,int *next,int *start,int index){
  vertex[index]=b;
  next[index]=start[a];
  start[a]=index;
  return;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  char *s=(char *)malloc(sizeof(char)*(n+1));
  scanf("%s",s);
  int *vertex=(int *)malloc(sizeof(int)*2*m);
  int *next=(int *)malloc(sizeof(int)*2*m);
  int *start=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) start[i]=-1;
  for(i=0;i<m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--;b--;
    assign(a,b,vertex,next,start,2*i);
    assign(b,a,vertex,next,start,2*i+1);
  }
  int *cond=(int *)malloc(sizeof(int)*n);
  int *cnt=(int *)calloc(2*n,sizeof(int));
  for(i=0;i<n;i++) cond[i]=1;
  int *q=(int *)malloc(sizeof(int)*n);
  int front=0;
  int last=0;
  for(i=0;i<n;i++){
    int p;
    for(p=start[i];p!=-1;p=next[p]){
      int u=vertex[p];
      cnt[POS(s[u],i)]++;
    }
    if(cnt[POS('A',i)]==0 || cnt[POS('B',i)]==0){
      q[last++]=i;
      cond[i]=0;
    }
  }
  while(front<last){
    int v=q[front++];
    int p;
    for(p=start[v];p!=-1;p=next[p]){
      int u=vertex[p];
      if(!cond[u]) continue;
      cnt[POS(s[v],u)]--;
      if(cnt[POS(s[v],u)]==0){
	cond[u]=0;
	q[last++]=u;
      }
    }
  }
  printf("%s\n",last==n?"No":"Yes");
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^
./Main.c:25:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^