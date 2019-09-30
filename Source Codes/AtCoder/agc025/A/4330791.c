#include<stdio.h>

int sum(int a){
  if(a==0) return 0;
  else{
    return a%10+sum(a/10);
  }
}
int main(){
  int n,i,s,min=100000;
  scanf("%d",&n);
  for(i=1;i<=n/2;i++){
    s=sum(i)+sum(n-i);
    if(min>s) min=s;
  }
  printf("%d",min);
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^