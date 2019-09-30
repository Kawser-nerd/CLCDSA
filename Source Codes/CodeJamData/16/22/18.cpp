#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <string>
#include <iostream>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int _,__;
string s1,s2,rs1,rs2;
ll ret;
int n;
bool rev;

void upd(string t1,string t2) {
	ll x1=0,x2=0;
	rep(i,0,n) {
		if (t1[i]=='?') t1[i]='9'; x1=x1*10+t1[i]-'0';
		if (t2[i]=='?') t2[i]='0'; x2=x2*10+t2[i]-'0';
	}
	if (x2-x1<ret) {
		ret=x2-x1;
//		cout<<" owo "<<t1<<" "<<t2<<endl;
		rs1=t1; rs2=t2;
		if (rev) swap(rs1,rs2);
	} else if (x2-x1==ret) {
		if (rev) swap(t1,t2);
		if (t1<rs1||(t1==rs1&&t2<rs2)) rs1=t1,rs2=t2;
	}
}
void solve(string s1,string s2) {
	rep(i,0,n) {
		string t1=s1,t2=s2;
		bool val=1;
		if (s2[i]=='?'&&s1[i]=='?') {
			t1[i]='0'; t2[i]='1';
		} else if (s2[i]=='?') {
			if (s1[i]=='9') val=0;
			else t2[i]=t1[i]+1;
		} else if (s1[i]=='?') {
			if (s2[i]=='0') val=0;
			else t1[i]=t2[i]-1;
		} else if (s1[i]>=s2[i]) val=0;
		if (val) {
			upd(t1,t2);
		}
		if (s2[i]=='?'&&s1[i]=='?') s1[i]=s2[i]='0';
		else if (s2[i]=='?') s2[i]=s1[i];
		else if (s1[i]=='?') s1[i]=s2[i];
		else if (s1[i]!=s2[i]) return;
	}
//	cout<<" owo "<<s1<<" "<<s2<<endl;
	if (s1==s2) {
		ret=0;
		rs1=s1; rs2=s2;
	}
}
int main() {
	for (scanf("%d",&_);_;_--) {
		cin>>s1>>s2;
		n=SZ(s1);
		printf("Case #%d: ",++__);
		ret=1ll<<60;
		rev=0;
		solve(s1,s2);
		rev=1;
		solve(s2,s1);
		cout<<rs1<<" "<<rs2<<endl;
	}
}
