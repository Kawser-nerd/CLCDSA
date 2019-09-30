#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;
typedef unsigned long long int uint64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n;
  scanf("%d",&n);
  int *a=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  int sum=0;
  for(i=0;i<n;i++) sum+=a[i];

  const int b=64;
  const int len=(sum+b-1)/b;
  uint64 *bit=(uint64 *)calloc(len,sizeof(uint64));
  bit[0]=1;
  int localSum=0;
  for(i=0;i<n;i++){
    const int aa=a[i];
    int j;
    for(j=localSum/b;j>=0;j--){
      if(aa%b!=0){
	bit[(b*j+aa)/b+1]|=bit[j]>>(b-aa%b);
      }
      bit[(b*j+aa)/b]|=bit[j]<<(aa%b);
    }
    localSum+=aa;
  }
  int median=(sum+1)/2;
  while(((bit[median/b]>>(median%b))&0x01)==0) median++;
  printf("%d\n",median);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:17:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^