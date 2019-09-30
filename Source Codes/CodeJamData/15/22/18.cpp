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
int r,c,n;
int il[5];
void test(){
  static int cas = 0;cas++;
  printf("Case #%d: ",cas);
  make2(r,c);
  make(n);
  if(c == 1 || r == 1){
    c*=r;
    int zle = n - (c+1)/2;
    MA(zle,0);
    if(zle==0)
      puts("0");
    else if(c&1){
      printf("%d\n",zle * 2);
    }else{
      printf("%d\n",zle * 2 - 1);
    }
    return;
  }
  n = r*c - n;
  bool np = r*c%2 == 1;
  int all = (r * c)/2;if(np)all -= 2;
  il[4] = ((r-2) * (c-2) + 1)/2;
  il[2] = np?1:2;
  il[3] = all - il[4] - il[2];
  int wyn = r * (c-1) + c * (r-1);
  FD(i,5){
    int ak = min(n,il[i]);
    wyn -= ak * i;
    n -= ak;
  }
  if(np){
    R(i,min(n,2))
      wyn -= 3;
  }
  printf("%d\n",wyn);
  
}
main(){
  int _;make(_);while(_--)test();
}