#include<iostream>
#include<cmath>
#include<stdio.h>
#define fr(i,a,b) for(i=a;i<=b;++i)
using namespace std;
const int maxn=1002;
const double zero=1e-6;
int ca,ti,i,j,n,w[maxn];
double l[maxn],p[maxn],c1,c2;
bool found;
double cal(int i,int j){
	return ((l[i]+l[j])*p[i]*p[j]+p[i]*(1-p[j])*(l[i]+l[j])+(1-p[i])*l[i])/(1-p[i]*(1-p[j])-(1-p[i]));
}
int main(){
	freopen("a2.in","r",stdin);
	freopen("a2.out","w",stdout);
	cin>>ca;
	fr(ti,1,ca){
		cin>>n;
		fr(i,1,n)
			cin>>l[i];
		fr(i,1,n){
			cin>>p[i];
			p[i]=(100-p[i])/100.0;
			w[i]=i;
		}
		do{
			found=false;
			fr(i,1,n)
				fr(j,i+1,n){
					c1=cal(w[i],w[j]);
					c2=cal(w[j],w[i]);
					if(c1-c2>zero||fabs(c1-c2)<zero&&w[i]>w[j]){
						swap(w[i],w[j]);
						found=true;
					}
				}
		}while(found);
		cout<<"Case #"<<ti<<":";
		fr(i,1,n)
			cout<<" "<<w[i]-1;
		cout<<endl;
	}
}