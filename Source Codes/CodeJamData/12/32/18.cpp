#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

double getT(double a, double b, double c){
	return (-b+sqrt(b*b-4*a*c))/a/2;
}

int main(){
	int i,j,k,m,n,r,c;
	double t[2048],x[2048],a[300],ans[300];
	double D,N,A,v,s1,tt,vv,t1,x1;
	
	freopen("B-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	cin>>r;
	for(c=1;c<=r;++c){
		cin>>D>>N>>A;
		for(i=0;i<N;++i)	cin>>t[i]>>x[i];
		for(i=0;i<A;++i)	cin>>a[i];
		for(k=0;k<A;++k){
			if(x[0]>=D){
				ans[k]=sqrt(2*D/a[k]);
				continue;
			}
			vv=sqrt(2*x[0]*a[k]);
			tt=sqrt(2*x[0]/a[k]);
			for(i=1;i<N;++i){
				if(x[i]>=D){
					t1=t[i-1]+(t[i]-t[i-1])*(D-x[i-1])/(x[i]-x[i-1]);
					x1=D;
					if(getT(a[k]/2,vv,x[i-1]-D)+tt>t1){
						tt=getT(a[k]/2,vv,x[i-1]-D)+tt;
					}
					else{
						tt=t1;
					}
					ans[k]=tt;	
					break;
				}
				else{
					if(getT(a[k]/2,vv,x[i-1]-x[i])+tt>t[i]){
						tt=getT(a[k]/2,vv,x[i-1]-x[i])+tt;
					}
					else{
						tt=t[i];
					}
					vv=vv+getT(a[k]/2,vv,x[i-1]-x[i])*a[k];
				}
			}
/*				
			else{
				tt=t[0]+(t[1]-t[0])*(D-x[0])/(x[1]-x[0]);
				ans[k]=sqrt(2*D/a[k]);
				if(ans[k]<tt)	ans[k]=tt;
			}
			*/
		}
		printf("Case #%d:\n",c);
		for(k=0;k<A;++k)	printf("%.7lf\n",ans[k]);
	}
	return 0;
}
