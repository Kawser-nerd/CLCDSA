#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
const int mod=1000000007;

//mod???????
//mod=1000000007

LL add(LL a,LL b){
  return (a+b)%mod;
}

LL sub(LL a,LL b){
  return (a+mod-b)%mod;
}

LL mul(LL a,LL b){
  return ((a % mod) * (b % mod)) % mod;
}

LL power(LL x,LL y){//??????? ?????
  if(y==0)return 1;
  else if(y==1)return x%mod;
  else if(y%2==0){
    LL tmp=power(x, y/2) % mod;
    return tmp*tmp%mod;
  }else {
    LL tmp=power(x, y/2) % mod;
    return ((tmp*tmp)%mod)*x%mod;
  }
}

LL dvs(LL a,LL b){
  return mul(a,power(b,mod-2));
}

const int SIZE_mod=200005;
int invfact[SIZE_mod];
int fact[SIZE_mod];

LL factset(int a){//a?????%mod????
  fact[0]=1;
  FORQ(i,1,a){
    fact[i]=mul(fact[i-1],i);
  }
}

LL cmbset(int a){//1~a?????????????mod(mod)??? O(a)
  factset(a);
  invfact[a]=power(fact[a],mod-2);
  invfact[0]=1;
  FORD(i,a,1){
    invfact[i]=mul(invfact[i+1],i+1);
  }

}

LL cmb(int n,int r){//nCr%mod  (cmbset????)
  if(n<r||r<0||n<0)return 0;
  return mul(fact[n],mul(invfact[r],invfact[n-r]));
}

LL prm(int n,int r){//nPr%mod
    return mul(cmb(n,r),fact[n]);
}

LL homo(int n,int r){//nHr%mod
  return cmb(n+r-1,r);
}



int prime[100002]={};
int Er_N=100001;
void Er(){//Eratosthenes  1:PRIME  0:NOT PRIME
	for(int i = 2; i < Er_N; i++){
		prime[i] = 1;
	}
	int limit_Er_roop=sqrt(Er_N);
	for(int i = 2; i < limit_Er_roop; i++){
		if(prime[i]){
			for(int j = 0; i * (j + 2) < Er_N; j++){
				prime[i *(j + 2)] = 0;
			}
		}
	}
}


int main(){
	LL n,a[1111]={};
	cin>>n;
	FORQ(i,2,n){
		int t=i;
		FORQ(j,2,n){
			while(t%j==0){
				t/=j;
				a[j]++;
			}
		}
	}
	LL ans=1;
	FORQ(i,2,n){
		//cerr<<i<<" "<<a[i]<<endl;
		ans=mul(ans,a[i]+1LL);
	}
	cout<<ans;
    return 0;
} ./Main.cpp:78:1: warning: control reaches end of non-void function [-Wreturn-type]
}
^
./Main.cpp:88:1: warning: control reaches end of non-void function [-Wreturn-type]
}
^
2 warnings generated.