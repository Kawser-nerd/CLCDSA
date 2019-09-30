#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;
typedef long long LL;
typedef double D;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define R(I,N) for(int I=0;I<N;I++)
#define F(I,A,B) for(int I=A;I<B;I++)
#define FD(I,N) for(int I=N-1;I>=0;I--)
#define make(A) scanf("%d",&A)
#define make2(A,B) scanf("%d%d",&A,&B)
#define ALL(x) (x).begin(), (x).end()
#define db if(1)printf
template<typename C> void MA(C& a,C b){if(a<b)a=b;}
template<typename C> void MI(C& a,C b){if(a>b)a=b;}
LL n;
LL p10[20];
LL licz(LL a,LL ak){
  LL wyn = a - ak;
  vector<int> d;
  while(a){
    d.PB(a%10);
    a/=10;
  }
  bool cz = 1;
  R(i,(d.size()+1)/2){
    if(d[i]!=0)cz = 0;
  }
  if(cz){
    d[0] = 10;
    int i = 1;
    while(d[i]==0){
      d[i] = 9;
      i++;
    }
    d[i]--;
  }
  LL wyn2 = 0;
  R(i,d.size()){
    wyn2 += d[i] * p10[min(i,(int)d.size()-i-1)];
  }
  return min(wyn,wyn2);
}
void test(){
  static int cas = 0;cas++;
  printf("Case #%d: ",cas);
  scanf("%lld",&n);
  LL wyn = 1;
  LL ak = 1;
  while(ak*10 <= n){
    wyn += licz(ak*10-1,ak);
    wyn ++;
    ak*=10;
  }
  printf("%lld\n",wyn+licz(n,ak));
  
}
main(){
  p10[0] = 1;
  F(i,1,20)p10[i] = 10 * p10[i-1];
  int _;make(_);while(_--)test();
}