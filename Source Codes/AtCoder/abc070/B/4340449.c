#include<stdio.h>

int main(){
  int A[101];
  int B[101];
  
  int i,j,k;
  
  for(i=0;i<=101;i++){
    A[i]=B[i]=0;
  }
  
  int a,b,c,d;
  
  scanf("%d %d %d %d",&a,&b,&c,&d);
  
  for(i = a;i<b;i++)
    A[i]=1;
  for(i=c;i<d;i++)
    B[i]=1;
  
  int ans=0;
  
  for(i=0;i<101;i++){
    if(A[i] == 1 && B[i] == 1)
      ans++;
  }
  
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d",&a,&b,&c,&d);
   ^
./Main.c:10:14: warning: iteration 101u invokes undefined behavior [-Waggressive-loop-optimizations]
     A[i]=B[i]=0;
              ^
./Main.c:9:3: note: containing loop
   for(i=0;i<=101;i++){
   ^