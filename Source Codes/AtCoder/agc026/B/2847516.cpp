#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

long long gcd( long long m, long long n )
{
  long long a=m, b=n, tmp, r;
  /* ??? a > b ?????? */
if(a<b){
  tmp = a;
  a = b;
  b = tmp;
}

/* ?????????? */
r = a % b;
while(r!=0){
  a = b;
  b = r;
  r = a % b;
}
  return b;

}//gcd

int main() {
  int t;
  scanf("%d", &t);
  long long A[t], B[t], C[t], D[t];
  for (int i = 0; i < t; i++) {
    scanf("%lld %lld %lld %lld", &A[i], &B[i], &C[i], &D[i]);
  }

  for (int i = 0; i < t; i++) {
    long long d = gcd(B[i], D[i]);
    long long cri;
    if ((C[i]-A[i])%d == 0) {
      cri = (C[i]-A[i])/d+1;
    } else {
      cri = (C[i]-A[i])/d;
    }
    if (cri > 0) cri++;

    if (A[i]<B[i] || D[i]<B[i]) {
      printf("No\n");
    } else if (C[i]-A[i] < cri*d && cri*d < B[i]-A[i]) {
      printf("No\n");
    } else {
      printf("Yes\n");
    }
  }

  return 0;
}