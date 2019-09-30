#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i,n)	for(int i=0;i<n;i++)
int main(){
	int a,b;
	cin>>a>>b;
	if(a<=0&&b>=0){
		cout<<"Zero"<<endl;
	}
	else if(a>0&&b>0){
		cout<<"Positive"<<endl;
	}
	else{
		if((abs(a-b)+1)%2==0){
			cout<<"Positive"<<endl;
		}
		else{
			cout<<"Negative"<<endl;
		}
	}
	
}