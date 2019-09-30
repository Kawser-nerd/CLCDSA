#include<iostream>
#include<cmath>
using namespace std;
int main(){
	long long a,b,c;
	cin>>a>>b>>c;
	int f;
	bool h=false;
	for(int i=0;i<=1000;i++){
		if(a%2==1||b%2==1||c%2==1){
			f=i;h=true;break;
		}
		int a1,b1,c1;
		a1=a;
		b1=b;
		c1=c;
		a=b1/2+c1/2;
		b=a1/2+c1/2;
		c=a1/2+b1/2;		
	}
	if(h==true)
		cout<<f<<endl;
	else
		cout<<"-1"<<endl;
}