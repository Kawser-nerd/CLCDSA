#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	char s[2];
	cin>>s[0]>>s[1]>>s[2];
	bool a=false;
	bool b=false;
	bool c=false;
	for(int i=0;i<3;i++){
		if(s[i]=='a')a=true;
		if(s[i]=='b')b=true;
		if(s[i]=='c')c=true;
	}
	if(a==true&&b==true&&c==true){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
}