#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int euku(int,int);

int main(){
  int i;
  long long n,m;
  long long p;
  long long q;
  int l=0;

  scanf("%lld %lld",&n,&m);

  unsigned char s[1000000];
  unsigned char t[1000000];

  scanf("%s",s);
  scanf("%s",t);

  if(s[0]!=t[0]){
    l++;
  }
  q = euku(n,m);
  p = n*m/euku(n,m);

    for(i=0; i<=q; i++){
      if(s[i*n/q]!=t[i*m/q]){
        l++;
      }
    }

  if(l==0){
    printf("%lld\n",p);
  }else if(l>0){
    printf("-1\n");
  }

  return 0;
}

int euku(int a,int b){
  int r;
  if(a>=b){
    r = a % b;
    while(r!=0){
      a = b;
      b = r;
      r = a % b;
    }
    return b;
  }else{
    r = b % a;
    while(r!=0){
      b = a;
      a = r;
      r = b % a;
    }
    return a;
  }
} ./Main.c: In function ‘main’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld",&n,&m);
   ^
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",t);
   ^