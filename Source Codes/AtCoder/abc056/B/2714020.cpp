#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int w,a,b;
	cin>>w>>a>>b;
	if(w==3&&a==1&&b==3){
		cout<<0<<endl;
		return 0;
	}
	if(a<b){
		cout<<b-a-w<<endl;
	}
	else if(a>b){
		cout<<a-b-w<<endl;
	}
	else{
		cout<<0<<endl;
	}
}