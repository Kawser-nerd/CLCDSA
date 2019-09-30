#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i,a,n)	for(int i=a;i<n;i++)
int main(){
	int a,b;
	cin>>a>>b;
	bool can;
	if((a+b)%3==0||a%3==0||b%3==0){
		can=true;
	}
	else{
		can=false;
	}
	if(can==true){
		cout<<"Possible"<<endl;
	}
	else{
		cout<<"Impossible"<<endl;
	}
}