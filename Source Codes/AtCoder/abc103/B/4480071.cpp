#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string s,t;
	cin>>s>>t;
	int n=s.length();
	bool flag=false;
	for(int i=0;i<n;i++){
		if(s==t){
			flag=true;
			break;
		}
		reverse(s.begin(),s.begin()+n-1);
		reverse(s.begin(),s.begin()+n);
	}
	if(flag) cout<<"Yes";
	else cout<<"No";
	return 0;
}