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
  int a[100000];
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  int c0,c1,c2;
  c0=c1=c2=0;
  for(i=0;i<n;i++){
    if(a[i]%4==0){
      c2++;
    } else if(a[i]%2==0){
      c1++;
    } else {
      c0++;
    }
  }
  if(c0>c2+1){
    printf("No\n");
    return;
  }
  if(c0==c2+1){
    printf("%s\n",c1==0?"Yes":"No");
  } else {
    printf("Yes\n");
  }
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:16:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^