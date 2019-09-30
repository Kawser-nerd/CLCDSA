#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define mod 1000000007
#define lol(i,n) for(int i=0;i<n;i++)
typedef long long ll;
using namespace std;
ll a,b,x,y;
bool F(ll lim){
	if(min(a,b)<lim)return false;
	ll cnt=0;
	cnt+=(a-lim)/x;
	cnt+=(b-lim)/y;
	if(cnt>=lim)return true;
	return false;
}
int main(){
	cin>>a>>b>>x>>y;
	x--,y--;
	ll left=0,right=(ll)mod*(ll)mod,mid;
	lol(i,100){
		mid=(left+right)/2;
		if(F(mid)==true)left=mid;
		else right=mid;
	}
	cout<<left<<endl;
	return 0;
}