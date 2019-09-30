#include<stdio.h>
#include<string.h>

int main(){
  int n,i;
  float money,total=0;
  char type[4];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%f %s",&money,type);
    if(strcmp(type,"BTC")==0) money*=380000.0;
  total+=money;
  }
    printf("%f\n",total);
    return 0;
  } ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%f %s",&money,type);
     ^