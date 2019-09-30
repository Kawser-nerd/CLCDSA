#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i,n)	for(int i=0;i<n;i++)
int main(){
	string s;
	cin>>s;
	bool north=false;
	bool south=false;
	bool east=false;
	bool west=false;
	for(int i=0;i<s.size();i++){
		if(s[i]=='S')south=true;
		if(s[i]=='N')north=true;
		if(s[i]=='E')east=true;
		if(s[i]=='W')west=true;
	}
	bool sn=true;
	bool ew=true;
	if(south!=north)sn=false;
	if(east!=west)ew=false;
	if(sn==true&&ew==true){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
		
}