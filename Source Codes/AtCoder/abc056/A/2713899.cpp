#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	char a,b;
	cin>>a>>b;
	if(a=='H'){
		if(b=='H'){
			cout<<'H'<<endl;
		}
		else{
			cout<<'D'<<endl;
		}
	}
	else if(a=='D'){
		if(b=='H'){
			cout<<'D'<<endl;
		}
		else{
			cout<<'H'<<endl;
		}
	}
}