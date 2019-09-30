#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef long long int int64;

int64 dinic_dfs(int v,int64 *g,int n,int t,int *level,int *iter,int64 e){
  if(v==t) return e;
  for(int u=iter[v];u<n;u++,iter[v]++){
    if(level[v]+1!=level[u] || g[v*n+u]==0) continue;
    int64 f=dinic_dfs(u,g,n,t,level,iter,g[v*n+u]<e?g[v*n+u]:e);
    if(f>0){
      g[v*n+u]-=f;
      g[u*n+v]+=f;
      return f;
    }
  }
  return 0;
}

int64 dinic(const int64 *ing,const int n,const int s,const int t){
  int64 *g=(int64 *)calloc(n*n,sizeof(int64));
  memcpy(g,ing,n*n*sizeof(int64));
  int *level=(int *)calloc(n,sizeof(int));
  int *array=(int *)calloc(n,sizeof(int));
  int *iter=(int *)calloc(n,sizeof(int));
  int64 flow=0;
  while(1){
    memset(level,0,n*sizeof(int));
    int front=0,last=0;
    level[s]=1;
    array[last++]=s;
    while(front<last && level[t]==0){
      const int v=array[front++];
      for(int u=0;u<n;u++){
	if(g[v*n+u]>0 && level[u]==0){
	  level[u]=level[v]+1;
	  array[last++]=u;
	}
      }
    }
    if(level[t]==0) break;
    memset(iter,0,sizeof(int)*n);
    while(1){
      const int64 inf=9223372036854775807LL;
      int64 f=dinic_dfs(s,g,n,t,level,iter,inf);
      if(f==0) break;
      flow+=f;
    }
  }
  free(level);
  free(array);
  free(g);
  free(iter);
  return flow;
}

int64 calc(int *a,int n){
  int64 *g=(int64 *)calloc((n+2)*(n+2),sizeof(int64));
  int i,j;
  for(i=1;i<=n;i++){
    if(a[i]>=0){
      g[i*(n+2)+(n+1)]=a[i];
    } else {
      g[0*(n+2)+i]=-a[i];
    }
  }
  for(i=1;i<=n;i++){
    for(j=2*i;j<=n;j+=i){
      g[i*(n+2)+j]=1000000000LL*1000;
    }
  }
  int64 ans=dinic(g,n+2,0,n+1);
  free(g);
  return ans;
}

void run(void){
  int n;
  scanf("%d",&n);
  int i;
  int a[101];
  for(i=1;i<=n;i++) scanf("%d",a+i);
  int64 sum=0;
  for(i=1;i<=n;i++) if(a[i]>=0) sum+=a[i];
  int64 ans=sum-calc(a,n);
  printf("%lld\n",ans);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:80:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:83:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=1;i<=n;i++) scanf("%d",a+i);
                     ^