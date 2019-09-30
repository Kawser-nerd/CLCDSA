#include<stdio.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

void run(void){
  int n;
  scanf("%d",&n);
  int ans=0;
  while(n--){
    int x[3];
    int i;
    for(i=0;i<3;i++) scanf("%d",x+i);
    int m;
    scanf("%d",&m);
    int min[3]={1000000000,1000000000,1000000000};
    int max[3]={0,0,0};
    while(m--){
      int p[3];
      for(i=0;i<3;i++) scanf("%d",p+i);
      for(i=0;i<3;i++){
	min[i]=MIN(min[i],p[i]);
	max[i]=MAX(max[i],p[i]+1);
      }
    }
    for(i=0;i<3;i++) ans^=min[i]^(x[i]-max[i]);
  }
  puts(ans?"WIN":"LOSE");
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:13:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i=0;i<3;i++) scanf("%d",x+i);
                      ^
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&m);
     ^
./Main.c:20:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       for(i=0;i<3;i++) scanf("%d",p+i);
                        ^