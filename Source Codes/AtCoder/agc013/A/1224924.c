#include <stdio.h>

int test(int a, int n){
  // printf("(%d, %d)\n", a, n);
  if(n<=0) return 1;
  int b=a;
  do{
    a=b;
    scanf("%d", &b);
    n--;
  }while(a==b && n>0);
  if(n==0) return 1;
  if(a>b){
    do{
      a=b;
      scanf("%d", &b);
      n--;
    }while(a>=b && n>0);
    if(a>=b && n==0) return 1;
    else return test(b, n) + 1;
  }else{
    do{
      a=b;
      scanf("%d", &b);
      n--;
    }while(a<=b && n>0);
    if(a<=b && n==0) return 1;
    else return test(b, n) + 1;
  }
}

int main()
{
  int a, b, c, n, i, f, ans=1;
  scanf("%d", &n);
  scanf("%d", &a);
  printf("%d\n", test(a, n-1));
  return 0;
} ./Main.c: In function ‘test’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &b);
     ^
./Main.c:16:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d", &b);
       ^
./Main.c:24:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d", &b);
       ^
./Main.c: In function ‘main’:
./Main.c:35:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:36:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a);
   ^