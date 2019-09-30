#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(abs(a-b)<=d){
		if(abs(b-c)<=d){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	else if(abs(a-c)<=d){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}

}