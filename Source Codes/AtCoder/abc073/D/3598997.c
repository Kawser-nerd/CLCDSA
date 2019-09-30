#include<stdio.h>
#include<stdlib.h>

#define MIN(a,b) ((a)<(b)?(a):(b))
#define POS(i,j) ((i)*n+(j))

inline void swap(int *a,int *b){
  int t=*a;
  *a=*b;
  *b=t;
}

int calc(int index,int *v,int r,int *d,int n){
  if(index==r){
    int sum=0;
    for(int i=0;i+1<r;i++) sum+=d[POS(v[i],v[i+1])];
    return sum;
  }
  int res=calc(index+1,v,r,d,n);
  for(int i=index+1;i<r;i++){
    swap(v+index,v+i);
    int local=calc(index+1,v,r,d,n);
    res=MIN(res,local);
    swap(v+index,v+i);
  }
  return res;
}

void run(void){
  int n,m,r;
  scanf("%d%d%d",&n,&m,&r);
  int v[8];
  int i,j,k;
  for(i=0;i<r;i++){
    scanf("%d",v+i);
    v[i]--;
  }
  int *d=(int *)calloc(n*n,sizeof(int));
  for(i=0;i<n;i++) for(j=0;j<n;j++) d[POS(i,j)]=(i==j?0:100000*200);
  for(i=0;i<m;i++){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    a--;b--;
    d[POS(a,b)]=d[POS(b,a)]=c;
  }
  for(k=0;k<n;k++){
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	d[POS(i,j)]=MIN(d[POS(i,j)],d[POS(i,k)]+d[POS(k,j)]);
      }
    }
  }
  int ans=calc(0,v,r,d,n);
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:31:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&m,&r);
   ^
./Main.c:35:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",v+i);
     ^
./Main.c:42:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&c);
     ^