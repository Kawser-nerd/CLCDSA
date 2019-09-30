#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MIN(x,y) (((x)<(y))?(x):(y))
#define MAX(x,y) (((x)>(y))?(x):(y))

int x[50],y[50];
int N,K;

long long calc(int p0,int p1,int p2,int p3);

int main(void){
  int j,i[4];
  long long S=LLONG_MAX,ans;
  scanf("%d%d",&N,&K);
  for(j=0;j<N;j++) scanf("%d%d",&x[j],&y[j]);
  for(i[0]=0;i[0]<N;i[0]++){
    for(i[1]=i[0];i[1]<N;i[1]++){
      for(i[2]=i[1];i[2]<N;i[2]++){
	for(i[3]=i[2];i[3]<N;i[3]++){
	  ans=calc(i[0],i[1],i[2],i[3]);
	  if(S>ans) S=ans;
	}
      }
    }
  }
  printf("%Ld\n",S);
  return 0;
}

long long calc(int p0,int p1,int p2,int p3){
  int xmin,xmax,ymin,ymax;
  int i,j,k=0;
  xmin=MIN(MIN(x[p0],x[p1]),MIN(x[p2],x[p3]));
  xmax=MAX(MAX(x[p0],x[p1]),MAX(x[p2],x[p3]));
  ymin=MIN(MIN(y[p0],y[p1]),MIN(y[p2],y[p3]));
  ymax=MAX(MAX(y[p0],y[p1]),MAX(y[p2],y[p3]));

  for(i=0;i<N;i++)
    if(xmin<=x[i] && x[i]<=xmax && ymin<=y[i] && y[i]<=ymax) k++;

  if(k<K) return LLONG_MAX;
  return (long long)(xmax-xmin)*(long long)(ymax-ymin);  
} ./Main.c: In function ‘main’:
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&K);
   ^
./Main.c:17:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(j=0;j<N;j++) scanf("%d%d",&x[j],&y[j]);
                    ^