#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

void run(void){
  int n;
  scanf("%d%*d",&n);
  int *a=(int *)calloc(n,sizeof(int));
  int *min=(int *)calloc(n+1,sizeof(int))+1;
  min[-1]=1000000000;
  int p=0;
  int i;
  for(i=0;i<n;i++){
    scanf("%d",a+i);
    min[i]=MIN(min[i-1],a[i]);
    p=MAX(p,a[i]-min[i]);
  }
  int ans=0;
  for(i=0;i<n;i++){
    if(a[i]-min[i]==p){
      ans++;
    }
  }
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%*d",&n);
   ^
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",a+i);
     ^