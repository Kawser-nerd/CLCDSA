#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;
int x,y;
int main(){
	cin>>x>>y;
	if(x==y)cout<<0;
	else if(x==-y)cout<<1;
	else if(x==0||y==0){
		int ans=y==0?x:y;
		ans=ans>=0?ans:-ans;
		if(x>0&&y==0)ans++;
		if(x==0&&y<0)ans++;
		cout<<abs(ans);
	}
	else if(x>=0&&y>=0){
		int ans=abs(y-x);
		if(y<x)ans+=2;
		cout<<ans;
	}
	else if(x<0&&y<0){
		if(x<y)cout<<y-x;
		else cout<<x-y+2;
	}
	else if(x<0&&y>=0){
		if(-x<y)cout<<y+x+1;
		else cout<<-x-y+1;
	}
	else if(x>=0&&y<0){
		if(x>-y)cout<<x+y+1;
		else cout<<-y-x+1;
	}
	return 0;
}