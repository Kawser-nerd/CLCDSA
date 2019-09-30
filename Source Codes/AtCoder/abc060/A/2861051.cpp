#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
using namespace std;
typedef long long ll;
#define rep(i,a,n)	for(int i=a;i<n;i++)
#define rrep(i,a,n) for(int i=(a-1);i>=n;i--)
 
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
ll lcm(ll a,ll b){
	ll g=gcd(a,b);
	return a/g*b;
}
 
ll digitsum(ll a){
	ll x=0;
	while(a>0){
		x+=a%10;
		a/=10;
	}
	return x;
}
int main(){
	string s,t,u;
	cin>>s>>t>>u;
	if(s[s.size()-1]==t[0]&&t[t.size()-1]==u[0])cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
}