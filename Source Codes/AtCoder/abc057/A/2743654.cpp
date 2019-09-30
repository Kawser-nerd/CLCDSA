#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i,a,n)	for(int i=a;i<n;i++)
int main(){
	int a,b;
	cin>>a>>b;
	int c=a+b;
	if(c>=24){
		c-=24;
	}
	cout<<c<<endl;
	
}