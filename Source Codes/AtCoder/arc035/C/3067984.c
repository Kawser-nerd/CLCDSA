#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

#define POS(i,j) ((i)*n+(j))

const int inf=400*1000;

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  int *e=(int *)malloc(sizeof(int)*n*n);
  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      e[POS(i,j)]=(i==j?0:inf);
    }
  }
  for(i=0;i<m;i++){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    a--;b--;
    e[POS(a,b)]=c;
    e[POS(b,a)]=c;
  }
  int k;
  for(k=0;k<n;k++){
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	if(e[POS(i,k)]+e[POS(k,j)]>=e[POS(i,j)]) continue;
	e[POS(i,j)]=e[POS(i,k)]+e[POS(k,j)];
      }
    }
  }
  scanf("%d",&k);
  while(k--){
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    x--;y--;
    if(e[POS(x,y)]>z){
      e[POS(x,y)]=z;
      e[POS(y,x)]=z;
      for(i=0;i<n;i++){
	for(j=0;j<n;j++){
	  int min=MIN(e[POS(x,i)]+e[POS(y,j)],e[POS(x,j)]+e[POS(y,i)])+z;
	  e[POS(i,j)]=MIN(min,e[POS(i,j)]);
	}
      }
    }
    int64 sum=0;
    for(i=0;i<n;i++){
      for(j=i+1;j<n;j++){
	sum+=e[POS(i,j)];
      }
    }
    printf("%lld\n",sum);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:27:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&c);
     ^
./Main.c:41:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&k);
   ^
./Main.c:44:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&x,&y,&z);
     ^