#include <stdio.h>
long xor(long n){
  if (n%4==0){
    return n;
  }
  if (n%4==1){
    return 1;
  }
  if (n%4==2){
    return n^1;
  }
  if (n%4==3){
    return 0;
  }
}
int main(){
  long a,b;
  scanf("%ld%ld",&a,&b);
  if (a==0){
    printf("%ld\n",xor(b));
  }
  else{
    printf("%ld\n",xor(a-1)^xor(b));
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld%ld",&a,&b);
   ^