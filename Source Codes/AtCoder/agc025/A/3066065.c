#include<stdio.h>
int main(){
  int a,b,c=0;
  scanf("%d",&a);
  if(a==10){
    goto one;
  }else if (a==100){
    goto one;
  }else if (a==1000){
    goto one;
  }else if (a==10000){
    goto one;
  }else if (a==100000){
    goto one;
  }
    while(a){
      b=a%10;
      c=c+b;
      a=a/10;
    }
    goto end;
  one:c=10;
      goto end;
  end:printf("%d",c);
      return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^