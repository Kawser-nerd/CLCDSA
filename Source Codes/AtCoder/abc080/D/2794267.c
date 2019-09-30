#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n,c;
  scanf("%d%d",&n,&c);
  const int m=100000;
  int *ss=(int *)calloc(c*(m+1),sizeof(int));
  int i;
  for(i=0;i<n;i++){
    int s,t,cc;
    scanf("%d%d%d",&s,&t,&cc);
    ss[(cc-1)*(m+1)+s]++;
    ss[(cc-1)*(m+1)+t]--;
  }
  int *cnt=(int *)calloc(2*m+1,sizeof(int));
  for(i=0;i<c;i++){
    int j;
    for(j=0;j<=m;j++){
      if(ss[i*(m+1)+j]==1){
	cnt[2*j-1]++;
      } else if(ss[i*(m+1)+j]==-1){
	cnt[2*j]--;
      }
    }
  }
  int cc=0;
  int max=0;
  for(i=0;i<=2*100000;i++){
    cc+=cnt[i];
    max=MAX(max,cc);
  }
  printf("%d\n",max);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&c);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&s,&t,&cc);
     ^