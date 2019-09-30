#include<iostream>
#include<stdio.h>
#define fr(i,a,b) for(i=a;i<=b;++i)
#define ll long long
using namespace std;
const int maxn=202;
ll ca,ti,m,f,n,p[maxn],s[maxn],newn,i,j,ans,lft,now,step;
ll cal(ll r,ll &left){
	ll tot=0,i,buy,add;
	left=m-r*f;
	fr(i,1,n){
		buy=left/p[i];
		if(buy==0)
			break;
		if((s[i]-s[i-1])<=buy/r)
			add=(s[i]-s[i-1])*r;
		else
			add=buy;
		tot+=add;
		left-=p[i]*add;
	}
	return tot;		
}
bool cmp(ll a,ll b){
	ll la,lb,ta,tb;
	ta=cal(a,la);
	tb=cal(b,lb);
	if(ta!=tb)
		return ta>tb;
	else
		return la>lb;
}
int main(){
	freopen("c2.in","r",stdin);
	freopen("c2.out","w",stdout);
	cin>>ca;
	fr(ti,1,ca){
		cin>>m>>f>>n;
		fr(i,1,n)
			cin>>p[i]>>s[i];
		fr(i,1,n)
			fr(j,i+1,n)
				if(p[i]>p[j]){
					swap(p[i],p[j]);
					swap(s[i],s[j]);
				}
		newn=1;
		fr(i,2,n)
			if(p[i]==p[newn])
				s[newn]=max(s[newn],s[i]);
			else
				if(s[i]>s[newn]){
					s[++newn]=s[i];
					p[newn]=p[i];
				}
		n=newn;
		s[0]=-1;
		now=1;
		for(step=m/f/2;step>=1;step/=2){
			while(now+step<=m/f&&cmp(now+step,now))
				now+=step;
			while(now-step>=1&&cmp(now-step,now))
				now-=step;
		}
		cout<<"Case #"<<ti<<": "<<cal(now,lft)<<endl;
	}
}