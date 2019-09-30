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
int main(){
	int N ,M,a,b;
	int x [100004];
	int p [100004]={};
	p[1]=1;
	cin >> N >> M;
	for(int i = 1;i<=N;i++){
		x[i]=1;
	}
	for(int i = 0;i<M;i++){
		cin >> a >> b;
		if(p[a]){
			p[b]=1;
			x[a]--;
			x[b]++;
		}else if(p[a]==0){
			x[a]--;
			x[b]++;
		}
		if(x[a]==0)p[a]=0;
	}
	int ans = 0;
	for(int i=1;i<=N;i++){
		if(p[i])ans++;
	}
	cout << ans << endl;
	
}