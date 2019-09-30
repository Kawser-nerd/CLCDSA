#include <stdio.h>
int main(void){
int a,b,c,k;
  scanf("%d %d %d",&a,&b,&c);
  scanf("%d",&k);
  for(;;){
    if(a>=b&&a>=c){c=c*2; k--;}
      else if(b>=a&&b>=c){b=b*2; k--;}
  		else if(c>=a&&c>=b){c=c*2; k--;}
  if(k==0){break;}
}
  printf("%d",a+b+c);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&a,&b,&c);
   ^
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&k);
   ^