//???????????????????
#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include<cstdio>
#include<cstring>
#include<time.h>
#include<iomanip>
#define PB push_back
#define in scanf
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define IREP(i,n) for (int i=0;i<=(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
using	namespace std;
void solve(){
		int N,Q;
		cin >> N >> Q;
		vector <long double> x(N),r(N),h(N),A(Q),B(Q);
		vector <long double>V(N);
		REP(i,N)cin>> x[i]>>r[i]>>h[i];
		REP(i,Q)cin>>A[i]>>B[i];
		REP(i,N)V[i]=3.141592*r[i]*r[i]*h[i]/3;
		cout  << setprecision(20);
	  REP(j,Q){
			long double total =0;
			REP(i,N){
					if(B[j]<x[i]||x[i]+h[i]<A[j]){}
					else if(x[i]>=A[j]&&x[i]+h[i]<=B[j]){
						 total += V[i];
					}else if(x[i]<=A[j]&&x[i]+h[i]<=B[j]&&A[j]<=x[i]+h[i]){
									total += pow((x[i]+h[i]-A[j])/h[i],3)*V[i];
					}else if(x[i]<=B[j]&&x[i]>=A[j]&&x[i]+h[i]>=B[j]){
										total += V[i]-pow((x[i]+h[i]-B[j])/h[i],3)*V[i];
					}else total += pow((x[i]+h[i]-A[j])/h[i],3)*V[i]-pow((x[i]+h[i]-B[j])/h[i],3)*V[i];
			}

				cout << total <<endl;
		}





		}




int main(){
solve();


}