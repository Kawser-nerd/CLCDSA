#include <stdio.h>
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
int main()
{
 int n,b,i,count=0,j,flag=0,a5[100000];
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
   
    scanf("%d",&a5[i]);
    
  }
qsort(a5, n, sizeof(int), cmpfunc);
  for(i=0;i<n;)
  {
      if(a5[i]==a5[i+1])
      {
          i+=2;
          
      }else{
          count++;
          i++;
      }
  }
  printf("%d",count);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:1: warning: implicit declaration of function ‘qsort’ [-Wimplicit-function-declaration]
 qsort(a5, n, sizeof(int), cmpfunc);
 ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a5[i]);
     ^