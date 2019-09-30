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
#define rep1(i,n) for (int i=1;i<=(n);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
using namespace std;
typedef long double ld;
typedef long long int  lli;
typedef complex <double> P;
const double eps = 1e-11;
int vex[4]={1,0,-1,0};
int vey[4]={0,1,0,-1};
int main(){
	int n,k;
	vector<int> data;
	int a;
	cin >> n >> k;
	rep(i,k){
		cin >> a;
		data.push_back(a);
	}
	while(1){
		a = n;
		bool flag = true;
		while (a !=0 ){
			rep(i,k){
				if(a %10==data[i]){
					flag = false;
				}
			}
			a/=10;
		}
		if(flag){
			cout << n;
			return 0;
		}
		n++;
	}
}