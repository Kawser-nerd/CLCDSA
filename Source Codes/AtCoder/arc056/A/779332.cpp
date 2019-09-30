#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include "math.h"
#include <complex>
#include <iomanip>
#define ifor(i,a,b) for (int i=(a);i<(b);i++)
#define rfor(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define rep(i,n) for (int i=0;i<(n);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
using namespace std;
typedef long double ld;
typedef long long int  lli;
typedef complex <double> P;
const double eps = 1e-11;
long long vex[4]={1,0,-1,0};
long long vey[4]={0,1,0,-1};
int main(){
long long A,B,K,L;
cin >> A >> B >> K>> L;
long long a = K/L;
long long b = (K+L)%L;
long long c = a*B + b*A;
long long d = (a+1)*B;
if(K<L){cout << min(K*A,B)<<endl;} 
	else cout << min(c,d)<<endl;
return 0 ;
}