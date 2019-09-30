#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
	string s;
	int x=0,y=0,q=0;
	int ans=0;
	int t;

	cin>>s;
	cin>>t;
	for(int i=0;i<s.size();i++){
		if(s[i]=='R')x++;
		else if(s[i]=='L')x--;
		else if(s[i]=='U')y++;
		else if(s[i]=='D')y--;
		else if(s[i]=='?')q++;
	}

	ans=abs(x)+abs(y);


	if(t==1){
		ans+=q;
	}else if(t==2){
		for(int i=0;i<q;i++){
			if(ans!=0){
				ans--;
			}else if(ans==0){
				ans++;
			}
		}

	}

	cout<<ans<<endl;

	return 0;


}