#include<stdio.h>

typedef long long int int64;

void run(void){
  int n;
  scanf("%d",&n);
  int64 a[50];
  int i;
  for(i=0;i<n;i++) scanf("%lld",a+i);
  int64 cnt=0;
  while(1){
    int flg=1;
    for(i=0;i<n;i++){
      if(a[i]<n) continue;
      flg=0;
      int64 t=a[i]/n;
      cnt+=t;
      for(int j=0;j<n;j++){
	a[j]+=t;
      }
      a[i]-=t;
      a[i]%=n;
    }
    if(flg) break;
  }
  printf("%lld\n",cnt);
}


int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:10:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%lld",a+i);
                    ^