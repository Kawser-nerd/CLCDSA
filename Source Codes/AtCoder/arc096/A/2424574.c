#include <stdio.h>

int main(void){
  int a,b,c,x,y;
  int money,selectA,selectB;

  scanf("%d",&a);
  scanf("%d",&b);
  scanf("%d",&c);
  scanf("%d",&x);
  scanf("%d",&y);

  if(x>y){
    if(b+a>2*c){
      selectA=2*c*y+(x-y)*a;
      selectB=c*2*x;
      if(selectA>selectB){
        printf("%d\n",selectB);
      }else{
        printf("%d\n",selectA);
      }
    }
    else{
      money=a*x+b*y;
      printf("%d\n",money);
    }
    }else{
      if(b+a>2*c){
        selectA=2*c*x+(y-x)*b;
        selectB=c*2*y;
        if(selectA>selectB){
          printf("%d\n",selectB);
        }else{
          printf("%d\n",selectA);
        }
      }
      else{
        money=a*x+b*y;
        printf("%d\n",money);
      }
    }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&b);
   ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&c);
   ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&x);
   ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&y);
   ^