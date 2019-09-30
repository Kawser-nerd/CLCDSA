#include <stdio.h>
#include <math.h>

int abs(int a){
  if(a>=0) return a;
  else return -a;
}

int max(int a, int b){
  if(a>=b) return a;
  else return b;
}

int main(){
  int N;
  int x[101],y[101],h[101];
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    scanf("%d%d%d",&x[i],&y[i],&h[i]);
  }

  //h[i]?0???i???????
  int pi;
  for(int i=1;i<=N;i++){
    if(h[i]!=0) pi=i;
  }

  //??????
  for(int i=0;i<=100;i++){
    for(int j=0;j<=100;j++){
      int H;
      H=h[pi]+abs(x[pi]-i)+abs(y[pi]-j);
      int A=1;
      for(int k=1;k<=N;k++){
        if(h[k]==max(H-abs(x[k]-i)-abs(y[k]-j),0)) A=1;
        else{
          A=0;
          break;
        }
      }
      if(A==1){
        printf("%d %d %d\n",i,j,H);
      }
    }
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&x[i],&y[i],&h[i]);
     ^