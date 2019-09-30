#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void) {
  int N,radius;
  int rs[1001];
  double area;
  scanf("%d",&N);
  for(int i=0; i<N; i++) {
    scanf("%d",&radius);
    rs[i]=radius;
  }
  
  //Bubble sort
  int k=0,tmp,flag;
  
  do {
    flag = 0;
    for(int i=0; i<N-1-k; i++) {
      if(rs[i]>rs[i+1]) {
        flag=1;
        tmp=rs[i];
        rs[i]=rs[i+1];
        rs[i+1]=tmp;
      }
    }
    k++;
  } while(flag==1);
  
  if(N%2) {
    for(int i=0; i<N; i++) {
      if(i%2) area-=rs[i]*rs[i]*M_PI;
      else area+=rs[i]*rs[i]*M_PI;
    }
  }
  else {
    for(int i=0; i<N; i++) {
      if(i%2) area+=rs[i]*rs[i]*M_PI;
      else area-=rs[i]*rs[i]*M_PI;
    }
  }
  printf("%.8lf\n",area);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&radius);
     ^