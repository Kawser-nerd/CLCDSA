#include<stdio.h>
int degree(int x){
  int i,count;
  count=0;
  for(i=1;i<100000;i=i*10){
    if(x%i==x) break;
    count++;
  }
  return count;
}

int tasizann(int x,int y){
  int i,ten,count;
  count = 0;
  ten=1;
  for(i=y;i>1;i--){
    ten=ten*10;
  }
  for(i=ten;i>0;i=i/10){
    count=count + (x/i);
    x=x%i;
  }
  return count;
  
}

int main(){
  int  A,B,N,a,b,sum1,sum2,i,k;
  scanf("%d",&N);
  b=100000;
  A=N-1;
  B=1;
  while(A>=B){
    sum1=tasizann(A,degree(A));
    sum2=tasizann(B,degree(B));
    a=sum1+sum2;
    if(b>a) b=a;
    A--;
    B++;
    }
  printf("%d",b);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:29:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^