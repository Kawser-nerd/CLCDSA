#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n;
  scanf("%d",&n);
  int *way=(int *)calloc(100*100+1,sizeof(int));
  way[0]=1;
  int sum=0;
  int i;
  for(i=0;i<n;i++){
    int s;
    scanf("%d",&s);
    int j;
    for(j=sum;j>=0;j--){
      if(way[j]==1) way[j+s]=1;
    }
    sum+=s;
  }
  i=sum;
  while(i>0 && (i%10==0 || way[i]==0)) i--;
  printf("%d\n",i);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&s);
     ^