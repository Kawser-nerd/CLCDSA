#include<stdio.h>
#include<math.h>
int main(void){
  int n,*a,i,j,tmp,min=2147483647;
  scanf("%d",&n);
  a=(int)malloc(sizeof(int)*n);
  for(i=0;i<n;i++)scanf("%d",&a[i]);
  for(i=0;i<n;i++)a[i]-=100;
  for(i=-100;i<=100;i++){
    for(j=0,tmp=0;j<n;j++)tmp+=pow(a[j],2);
    if(tmp<min)min=tmp;
    for(j=0;j<n;j++)a[j]++;
  }
  printf("%d",min);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:10: warning: implicit declaration of function ‘malloc’ [-Wimplicit-function-declaration]
   a=(int)malloc(sizeof(int)*n);
          ^
./Main.c:6:10: warning: incompatible implicit declaration of built-in function ‘malloc’
./Main.c:6:10: note: include ‘<stdlib.h>’ or provide a declaration of ‘malloc’
./Main.c:6:5: warning: cast from pointer to integer of different size [-Wpointer-to-int-cast]
   a=(int)malloc(sizeof(int)*n);
     ^
./Main.c:6:4: warning: assignment makes pointer from integer without a cast [-Wint-conversion]
   a=(int)malloc(sizeof(int)*n);
    ^
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:7:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%d",&a[i]);
                   ^