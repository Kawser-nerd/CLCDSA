#include<iostream>
#include<cstdio>
#include<string>
using namespace std; 

int main(){
	int a,b,c,d,x,y;
	cin>>a>>b>>c>>d;
	x=a*b;y=c*d;
	
	if(x>y)cout<<x;
	else cout<<y;
	return 0;
}