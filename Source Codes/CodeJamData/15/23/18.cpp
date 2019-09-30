#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PI;
typedef double D;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define R(I,N) for(int I=0;I<N;I++)
#define F(I,A,B) for(int I=A;I<B;I++)
#define FD(I,N) for(int I=N-1;I>=0;I--)
#define make(A) scanf("%lld",&A)
#define make2(A,B) scanf("%d%d",&A,&B)
#define ALL(x) (x).begin(), (x).end()
#define db if(1)printf
template<typename C> void MA(C& a,C b){if(a<b)a=b;}
template<typename C> void MI(C& a,C b){if(a>b)a=b;}
#define MAX 1000001
LL n,m;
LL a[MAX];
LL b[MAX];
multiset<PI> s;
void add(LL aa,LL bb){
  a[m] = 360 - aa;
  b[m] = bb;
  s.insert({a[m]*b[m],m});
  b[m] *= 360;
  m++;
}
void test(){
  static int cas = 0;cas++;
  printf("Case #%d: ",cas);
  make(n);
  s.clear();
  m = 0;
  R(i,n){
    LL a,il,b;
    make(a);make(il);make(b);
    R(i,il)add(a,b+i);
  }
  LL ak = m;
  LL wyn = m;
  LL lim = m;
  while(ak - lim < wyn){
    auto x = s.begin();
    LL nr = x->SE;
    LL gd = x->FI;
    s.erase(x);
    if(nr >= 0){
      lim --;
      ak --;
      MI(wyn,ak);
      s.insert(MP(gd+b[nr],-b[nr]));
    }else{
      ak++;
      s.insert(MP(gd-nr,nr));
    }
  }
  printf("%lld\n",wyn);
}
main(){
  LL _;make(_);while(_--)test();
}