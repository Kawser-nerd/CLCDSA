#define rep(i,n) FOR(i,0,n)
#define FOR(i,s,n) for(int (i)=(s);(i)<(n);(i)++)
#define SCAN(k) scanf("%d",&k)
#define PI 3.14159265359
#define INF (ll)(2e18+100)
#define MOD (int)(1e9+7)
#define MAX 10000
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <math.h>
#include<algorithm>
#include<stdio.h>
#include <set>
#include <map>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

int main(){
	int n;
	double x[1000],y[1000],c[1000];
	cin>>n;
	rep(i,n) cin>>x[i]>>y[i]>>c[i];
	double tmin=0,tmax=2e8;
;
	rep(i,100000){
		double time=(tmin+tmax)/2;
		double xmin=-1e5,xmax=1e5,ymin=-1e5,ymax=1e5;
		rep(j,n){
			xmin=max(xmin,x[j]-time/c[j]);
			xmax=min(xmax,x[j]+time/c[j]);
			ymin=max(ymin,y[j]-time/c[j]);
			ymax=min(ymax,y[j]+time/c[j]);
		}
		if(xmin<=xmax && ymin<=ymax)tmax=time;
		else tmin=time;
	}
	printf("%.8f",(tmin+tmax)/2);
	return 0;
}