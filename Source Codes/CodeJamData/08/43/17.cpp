//{{{
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <valarray> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <complex> 
#include <memory> 
#include <new> 
#include <iterator> 
#include <limits> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 
#include <cassert> 
#include <cctype> 
using namespace std;
//}}}

double A[1000],x[1000],y[1000],z[1000],p[1000];
double LX,LY,LZ,RX,RY,RZ;
int n;
inline double get(double X,double Y,double Z){
	double ret=0;
	for(int i=0;i<n;i++)
		ret>?=(A[i]+fabs(Z-z[i]))*p[i];
	return ret;
}
inline double get(double X,double Y){
	for(int i=0;i<n;i++)
		A[i]=fabs(X-x[i])+fabs(Y-y[i]);
	double lo=LZ,hi=RZ;
	for(int it=0;it<40;++it){
		double mid1=lo*.55+hi*.45;
		double mid2=lo*.45+hi*.55;
		if(get(X,Y,mid1)<get(X,Y,mid2))
			hi=mid2;
		else
			lo=mid1;
	}
	return get(X,Y,lo);
}
double get(double X){
	double lo=LY,hi=RY;
	for(int it=0;it<40;++it){
		double mid1=lo*.55+hi*.45;
		double mid2=lo*.45+hi*.55;
		if(get(X,mid1)<get(X,mid2))
			hi=mid2;
		else
			lo=mid1;
	}
	return get(X,lo);
}
int main(){
	int tests;
	scanf("%d",&tests);
	for(int t=1;t<=tests;t++){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%lf%lf%lf%lf",x+i,y+i,z+i,p+i),p[i]=1./p[i];
		LX=RX=x[0],LY=RY=y[0],LZ=RZ=z[0];
		for(int i=0;i<n;i++){
			LX<?=x[i],RX>?=x[i];
			LY<?=y[i],RY>?=y[i];
			LZ<?=z[i],RZ>?=z[i];
		}
		double lo=LX,hi=RX;
		for(int it=0;it<40;++it){
			double mid1=lo*.55+hi*.45;
			double mid2=lo*.45+hi*.55;
			if(get(mid1)<get(mid2))
				hi=mid2;
			else
				lo=mid1;
		}
		printf("Case #%d: %.10lf\n",t,get(lo));
	}
scanf("%*s");
	return 0;
}
