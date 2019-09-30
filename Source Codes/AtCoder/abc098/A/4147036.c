# include <stdio.h>

int max(int a,int b){
  int M = a*b;
  if(M<a+b) M=a+b;
  if(M<a-b) M=a-b;
  return M;
}

int main(){
  int a,b;
  scanf("%d %d",&a,&b);
  printf("%d\n",max(a,b));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^