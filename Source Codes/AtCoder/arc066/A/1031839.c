#include <stdio.h>

const int mod = 1000000007;

int mod2pow(int k){
  if(k == 0) return 1;
  if(k & 0x1) return (mod2pow(k-1) << 1) % mod;
  else {
    long long int x = mod2pow(k/2);
    return x * x % mod;
  }
}

int a[100000];

int main(){
  int i;
  int n;
  scanf("%d", &n);
  for(i=0;i<n;i++){
    int x;
    scanf("%d", &x);
    a[x]++;
  }
  if(n & 0x1){
    if(a[0] != 1){
      putchar('0');
      return 0;
    }
    for(i=1;i<n;i+=2){
      if(a[i] != 0 || a[i+1] != 2){
        putchar('0');
        return 0;
      }
    }
  }
  else {
    for(i=0;i<n;i+=2){
      if(a[i] != 0 || a[i+1] != 2){
        putchar('0');
        return 0;
      }
    }
  }
  printf("%d", mod2pow(n/2));
} ./Main.c: In function ‘main’:
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &x);
     ^