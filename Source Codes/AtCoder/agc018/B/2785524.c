#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

#define POS(i,j) ((i)*m+(j))

int calcMax(int *a,int *b,int n,int m,int *maxRef){
  int cnt[301];
  int i;
  for(i=0;i<=m;i++) cnt[i]=0;
  for(i=0;i<n;i++){
    cnt[a[POS(i,b[i])]]++;
  }
  int max=0;
  int maxIndex=0;
  for(i=1;i<=m;i++){
    if(max<cnt[i]){
      max=cnt[i];
      maxIndex=i;
    }
  }
  *maxRef=max;
  return maxIndex;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  int *a=(int *)calloc(n*m,sizeof(int));
  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      scanf("%d",a+POS(i,j));
    }
  }
  int assign[300];
  for(i=0;i<n;i++) assign[i]=0;
  int can[300];
  for(i=1;i<=m;i++) can[i]=1;
  int min=n;
  for(i=0;i<m-1;i++){
    int max;
    int index=calcMax(a,assign,n,m,&max);
    can[index]=0;
    min=MIN(min,max);
    for(j=0;j<n;j++){
      while(!can[a[POS(j,assign[j])]]) assign[j]++;
    }
  }
  printf("%d\n",min);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:34:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:39:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",a+POS(i,j));
       ^