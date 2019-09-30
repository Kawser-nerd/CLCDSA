#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

void run(void){
  int n,c,k;
  scanf("%d%d%d",&n,&c,&k);
  int *t=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",t+i);
  qsort(t,n,sizeof(int),cmp);
  int cnt=0;
  for(i=0;i<n;i++){
    int j=i;
    while(j<n && j-i<c && t[j]-t[i]<=k) j++;
    cnt++;
    i=j-1;
  }
  printf("%d\n",cnt);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&c,&k);
   ^
./Main.c:20:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",t+i);
                    ^