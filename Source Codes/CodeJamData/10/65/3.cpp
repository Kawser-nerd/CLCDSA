#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include <string>
#include<sstream>   
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<memory.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<int,pii> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

int n,r;
int x[11],y[11];

double d(int i,int j){return hypot(x[i]-x[j],y[i]-y[j]);}
double s(int i,int j,int k){return -((x[k]-x[i])*(y[j]-y[i])-(y[k]-y[i])*(x[j]-x[i]));}
const double eps = 1e-8;

double getA(int a1,int a2,int a3){
	double a = d(a1,a2);
	double b = d(a1,a3);
	double c = d(a2,a3);
	return acos((a*a+b*b-c*c)/2/a/b);
}
int go(double r,int c,int p){

	vector<pair<double,int> > v;
	REP(i,n) if(i!=c && d(c,i)<r-eps){
		double sq  = s(c,p,i);
		if(sq>eps){
			double ang = sq / d(c,i);
			v.pb(make_pair(getA(c,p,i),i));
		}
	}
	SORT(v);
	if(v.size()){
		double ang = v[0].first;
		v.clear();
		REP(i,n) if(i!=c && d(c,i)<r-eps){
			double sq  = s(c,p,i);
			if(sq>eps){
				if(fabs(getA(c,p,i)-ang)<eps)
					v.pb(make_pair(d(c,i),i));
			}
		}
		SORT(v);
		if(!v.size())
			v=v;
		return 1 + go(r-d(c,v.back().second),v.back().second,c);
	}

	REP(i,n) if(i!=c && d(c,i)<r-eps){
		double sq = s(c,p,i);
		if(sq>-eps && fabs(d(p,i) - (d(p,c) + d(i,c)))<eps){
			v.pb(make_pair(d(c,i),i));
		}
	}
	SORT(v);
	if(v.size()) return 1 + go(r-d(c,v.back().second),v.back().second,c);
	REP(i,n) if(i!=c && d(c,i)<r-eps){
		double sq = s(c,p,i);
		if(sq<-eps){
			double ang = sq / d(c,i);
			v.pb(make_pair(getA(c,p,i),i));
		}
	}
	SORT(v);
	if(v.size()){
		double ang = v.back().first;
		v.clear();
		REP(i,n) if(i!=c && d(c,i)<r-eps){
			double sq  = s(c,p,i);
			if(sq<-eps){
				if(fabs(getA(c,p,i)-ang)<eps)
					v.pb(make_pair(d(c,i),i));
			}
		}
		SORT(v);
		if(!v.size())
			v=v;
		return 1 + go(r-d(c,v.back().second),v.back().second,c);
	}


	
	REP(i,n) if(i!=c && d(c,i)<r-eps){
		double sq = s(c,p,i);
		if(sq>-eps && fabs(d(p,i) - (d(p,c) + d(i,c)))>eps){
			v.pb(make_pair(d(c,i),i));
		}
	}
	SORT(v);
	if(v.size()) return 1 + go(r-d(c,v.back().second),v.back().second,c);


	return 1;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int TC;
	cin>>TC;
	REP(tc,TC){
		cin>>n>>r;
		REP(i,n) cin>>x[i]>>y[i];
		int res = 0;
		for(int i = 5*r;i;i--){
			double R = i/5.0;
			x[n]=-R;
			y[n]=0;
			res=max(res,go(R,0,n));
		}
		printf("Case #%d: %d\n",tc+1,res-1);
	}

	return 0;
}