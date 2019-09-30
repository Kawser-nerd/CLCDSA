#include<stdio.h>
#include<stdlib.h>

int root(int *u,int x){
  if(u[x]==x) return x;
  return u[x]=root(u,u[x]);
}

int same(int *u,int x,int y){
  return root(u,x)==root(u,y);
}

void unite(int *u,int *size,int x,int y){
  x=root(u,x);
  y=root(u,y);
  if(x==y) return;
  u[x]=y;
  size[y]+=size[x];
  return;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  int *a=(int *)malloc(sizeof(int)*(m+1));
  int *b=(int *)malloc(sizeof(int)*(m+1));
  int i;
  for(i=1;i<=m;i++) scanf("%d%d",a+i,b+i);
  int q;
  scanf("%d",&q);
  int *x=(int *)malloc(sizeof(int)*q);
  int *y=(int *)malloc(sizeof(int)*q);
  int *z=(int *)malloc(sizeof(int)*q);
  for(i=0;i<q;i++) scanf("%d%d%d",x+i,y+i,z+i);
  int *u=(int *)malloc(sizeof(int)*(n+1));
  int *size=(int *)malloc(sizeof(int)*(n+1));
  int *index=(int *)malloc(sizeof(int)*q);
  int *next=(int *)malloc(sizeof(int)*q);
  int *start=(int *)malloc(sizeof(int)*(m+1));
  int *l=(int *)malloc(sizeof(int)*q);
  int *r=(int *)malloc(sizeof(int)*q);
  for(i=0;i<q;i++){
    l[i]=0;
    r[i]=m;
  }
  int flag=1;
  while(flag){
    flag=0;
    for(i=0;i<=n;i++){
      u[i]=i;
      size[i]=1;
    }
    for(i=0;i<=m;i++) start[i]=-1;
    int len=0;
    for(i=0;i<q;i++){
      if(r[i]-l[i]>1){
	flag=1;
	int m=(l[i]+r[i])/2;
	index[len]=i;
	next[len]=start[m];
	start[m]=len++;
      }
    }
    for(i=1;i<=m;i++){
      unite(u,size,a[i],b[i]);
      for(int p=start[i];p!=-1;p=next[p]){
	int k=index[p];
	int s=same(u,x[k],y[k])?size[root(u,x[k])]:size[root(u,x[k])]+size[root(u,y[k])];
	if(s>=z[k]){
	  r[k]=i;
	} else {
	  l[k]=i;
	}
      }
    }
  }
  for(i=0;i<q;i++) printf("%d\n",r[i]);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:28:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=1;i<=m;i++) scanf("%d%d",a+i,b+i);
                     ^
./Main.c:30:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&q);
   ^
./Main.c:34:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<q;i++) scanf("%d%d%d",x+i,y+i,z+i);
                    ^