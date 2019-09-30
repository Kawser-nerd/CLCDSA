#include<math.h>
#include<stdio.h>
int zettaiti(int n){
  if(n<0){n=-n;}
  return n;
}


int main (){
  int n,i,j;
  int S[100];
  for(i=0;i<100;i++){S[i]=0;}
  scanf("%d", &n);

  if(n==0){printf("0");return 0;}

  i=0;
  while(n!=0){
    if((zettaiti(n))%2==0){
      S[i]=0;}else{S[i]=1;}
    n=n-S[i]*pow(-1,i);
    n=n/2;
    i++;
  }

  for(j=i-1;j>=0;j--){
    printf("%d",S[j]);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^