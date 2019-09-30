#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int a,b,x;
	cin>>a>>b>>x;
	if(a>x){
		cout<<"NO"<<endl;
	}
	else{
		if(a+b>=x){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}