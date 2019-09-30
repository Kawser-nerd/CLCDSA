#include <stdio.h>

int main()
{
  int A,B,C,X,Y;
  int i=0;
  int result =0;
  scanf("%d %d %d %d %d",&A,&B,&C,&X,&Y);
  if(X<Y && 2*C<B){
    printf("%d\n",2*C*Y);
  }
  else if(Y<X && 2*C<A){
    printf("%d\n",2*C*X);
  }
  else if(X<Y){
    if(A+B>=2*C){
      while(i<X){
        result += 2*C;
        ++i;  --Y;
      }
      while(Y>0){
        result+=B;
        --Y;
      }
      printf("%d\n",result);
    }
    else  printf("%d\n", A*X+B*Y);
  }
  else if(X>Y){
    if(A+B>=2*C){
      while(i<Y){
        result += 2*C;
        ++i;  --X;
      }
      while(X>0){
        result+=A;
        --X;
      }
      printf("%d\n",result);
    }
    else  printf("%d\n", A*X+B*Y);
  }
  else{
    if(A+B>=2*C) printf("%d\n",2*C*X);
    else printf("%d\n",(A+B)*X);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d %d",&A,&B,&C,&X,&Y);
   ^