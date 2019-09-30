#include<stdio.h>
int main(){
  int n,m,h=0,mi,a,b=0,i;
  scanf("%d %d %d",&n,&m,&b);
  for(i=1;i<n;i++){
    scanf("%d",&a);
    if(a+b>=m&&h==0){
      h=1;
      mi=i;
    }
    b=a;
  }
  if(h==0){
    printf("Impossible\n");
    return 0;
  }
  printf("Possible\n");
  for(i=1;i<mi;i++)printf("%d\n",i);
  for(i=n;i>mi;i--)printf("%d\n",i-1);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&n,&m,&b);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^