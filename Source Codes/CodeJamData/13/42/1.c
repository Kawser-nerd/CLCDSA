#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

ll get_max(ll N, ll V){
  ll a, b;
  
  if(V==0) return 0;
  if(V==(1LL<<N)-1) return V;

  a = V-1; b = (1LL<<N)-1-a-1;
  return get_max(N-1, a/2) + (1LL<<(N-1));
}

ll get_min(ll N, ll V){
  ll a, b;
  
  if(V<=1) return V;
  if(V==(1LL<<N)-1) return V;

  a = V; b = (1LL<<N)-1-a-1;
  return get_min(N-1, a/2+a%2);
}

int main(){
  ll i, j, k, N, P;
  ll A, B, C;
  int size, count = 0;

  scanf("%d",&size);
  while(size--){
    scanf("%lld%lld",&N,&P);
    printf("Case #%d:",++count);
    P--;

    A = 0; B = (1LL<<N)-1;
    while(A<B){
      C = (A+B+1) / 2;
      k = get_max(N, C);
      if(k <= P) A=C; else B=C-1;
    }
    printf(" %lld",A);

    A = 0; B = (1LL<<N)-1;
    while(A<B){
      C = (A+B+1) / 2;
      k = get_min(N, C);
      if(k <= P) A=C; else B=C-1;
    }
    printf(" %lld\n",A);

  }

  return 0;
}
