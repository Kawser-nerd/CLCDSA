#include <stdio.h>
#include <stdlib.h>
typedef long long ll;

ll LayerOfBurger(int N){
  ll answer;
  if(N==0) return 1;
  else{
    answer=3+2*LayerOfBurger(N-1);
    return answer;
  }
}

ll NumberOfPatti(int N, ll X){
  if(N==0) return 1;
  if(X==1) return 0;
  else if(1<X && X<LayerOfBurger(N)/2+1){
    return NumberOfPatti(N-1,X-1);
  }
  else if(X==LayerOfBurger(N)/2+1){
    return NumberOfPatti(N-1,LayerOfBurger(N-1))+1;
  }
  else if(LayerOfBurger(N)/2+1<X && X<LayerOfBurger(N)){
    return NumberOfPatti(N-1,LayerOfBurger(N-1))+1+NumberOfPatti(N-1,X-2-LayerOfBurger(N-1));
  }
  else if(X==LayerOfBurger(N)){
    return 1+2*NumberOfPatti(N-1,LayerOfBurger(N-1));
  }
}

int main(){
  int N;
  ll X;

  scanf("%d%lld",&N,&X);
  printf("%lld\n",NumberOfPatti(N,X));

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:35:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%lld",&N,&X);
   ^