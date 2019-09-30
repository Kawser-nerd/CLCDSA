#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	string s;
	cin>>s;
	int ans=700;
	if(s[0]=='o')ans+=100;
	if(s[1]=='o')ans+=100;
	if(s[2]=='o')ans+=100;
	cout<<ans<<endl;
}