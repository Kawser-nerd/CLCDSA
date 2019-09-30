#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int can(void){
  int n;
  scanf("%d",&n);
  int *cnt=(int *)calloc(n,sizeof(int));
  int max=0;
  int min=n;
  int i;
  for(i=0;i<n;i++){
    int a;
    scanf("%d",&a);
    cnt[a]++;
    max=MAX(max,a);
    min=MIN(min,a);
  }
  if((max+1)/2!=min) return 0;
  if(max&1){
    if(cnt[min]!=2) return 0;
    for(i=max;i>min;i--) if(cnt[i]<2) return 0;
  } else {
    if(cnt[min]!=1) return 0;
    for(i=max;i>min;i--) if(cnt[i]<2) return 0;
  }
  return 1;
}

void run(void){
  puts(can()?"Possible":"Impossible");
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘can’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^