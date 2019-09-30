#include<iostream>
#include<string>
#include<cmath>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

int main(){
	string s;
	int t,cnt=0,l,r,u,d,x,y;
	l=r=u=d=x=y=0;
	cin>>s>>t;
	rep(i,s.size()){
		if(s[i]=='L')l++;
		if(s[i]=='R')r++;
		if(s[i]=='U')u++;
		if(s[i]=='D')d++;
		if(s[i]=='?')cnt++;
	}
	x=r-l;
	y=u-d;
	int ans=0;
	if(t==1)cout<<abs(x)+abs(y)+cnt<<endl;
	else{
		if(cnt>=abs(x)){cnt-=abs(x);x=0;}
		else{x-=((x>0)?cnt:(-1*cnt));cnt=0;}
		if(cnt>=abs(y)){cnt-=abs(y);y=0;}
		else{y-=((y>0)?cnt:(-1*cnt));cnt=0;}
		ans=abs(x)+abs(y);
		if(cnt>0)ans=((cnt%2)?1:0);
		cout<<ans<<endl;
	}
	return 0;
}