#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
 
double bekijo(double a,double n){
	return n? bekijo(a,n-1)*a:1;
}
 
double fanc(double x,double p){
	return x + p/(pow(2,x/1.5));
}
int main(){
	double p;
	cin>>p;
	double t=100;
 
	while(fanc(t,p)>fanc(t-0.01,p)){
		t=t-0.01;
		//cout<<fixed<<setprecision(9)<<t<<endl;
	}
	while(fanc(t,p)>fanc(t+0.001,p)){
		t=t+0.001;
		//cout<<fixed<<setprecision(9)<<t<<endl;
	}
	while(fanc(t,p)>fanc(t-0.000001,p)){
		t=t-0.000001;
		//cout<<fixed<<setprecision(9)<<t<<endl;
	}
	while(fanc(t,p)>fanc(t+0.000000001,p)){
		t=t+0.000000001;
		//cout<<fixed<<setprecision(9)<<t<<endl;
	}
	while(fanc(t,p)>fanc(t-0.0000000001,p)){
		t=t-0.0000000001;
		//cout<<fixed<<setprecision(9)<<t<<endl;
	}
	if(t<=0){
		cout<<fixed<<setprecision(9)<<p<<endl;
		return 0;
	}
 
	cout<<fixed<<setprecision(9)<<fanc(t,p)<<endl;
	return 0;
}