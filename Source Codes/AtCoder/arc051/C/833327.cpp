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
int vex[4]={1,0,-1,0};
int vey[4]={0,1,0,-1};
lli powm(lli p,lli n ,lli m){
	lli ans = 1;
	while(n>0){
		if(n&1){
			ans *= p ;
			ans %=m;
		}
		n = n >>1;
		p*=p;
		p%=m;
	}
	return ans;

}
lli mod = 1000000007;
int main(){
	int N,A,B;
	cin >> N>> A >> B;
vector<lli> data (N);
int c;
rep(i,N){
	cin>> data[i];
}
int cnt=0;
sort(data.begin(),data.end());
if(A!=1){
	while(data[N-1] > data[0]*A){
		data[0]*=A;
		cnt++;
		sort(data.begin(),data.end());
		if(B-cnt==0)break;
}
int a = (B-cnt)/N;
int r = (B-cnt)%N;
for(int i =r;i<=N-1;i++){
	cout << data[i]*powm(A,a,mod)%mod<<endl;
}
for(int i =0;i<=r-1;i++){
	cout << data[i]*powm(A,a+1,mod)%mod<<endl;
}
}
else {
	rep(i,N)cout << data[i]%mod <<endl;
}
}