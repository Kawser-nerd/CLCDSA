#include<iostream>
#include<stdio.h>
#include<vector>
#define fr(i,a,b) for(i=a;i<=b;++i)
using namespace std;
const int maxn=10002;
long long ti,ca,i,ans,j,n,l,h,x[maxn],y[maxn],lcm,tmp;
long long gcd(long long a,long long b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}
void update(long long r){
	if(r<l||r>h)
		return;
	if(ans==-1||ans>r)
		ans=r;
}
void dfs(vector<long long> &all,vector<long long> &list,long long r,int now){
	all.push_back(r);
	if(now>=list.size()||r==1)
		return;
	if(r%list[now]==0)
		dfs(all,list,r/list[now],now);	
	dfs(all,list,r,now+1);
}
vector<long long> get(long long r){
	vector<long long> all,list;
	long long cp=r,i=2;
	while(r>1){
		if(i*i>r)
			i=r;
		if(r%i==0){
			list.push_back(i);
			while(r%i==0)
				r/=i;
		}
		i++;
	}
	all.push_back(1);
	all.push_back(cp);
	dfs(all,list,cp,0);
	return all;
}
int main(){
	freopen("c2.in","r",stdin);
	freopen("c2.out","w",stdout);
	cin>>ca;
	fr(ti,1,ca){
		cin>>n>>l>>h;
		fr(i,1,n)
			cin>>x[i];
		fr(i,1,n)
			fr(j,i+1,n)
				if(x[i]>x[j])
					swap(x[i],x[j]);
		y[n]=x[n];
		for(i=n-1;i>=1;i--)
			y[i]=gcd(y[i+1],x[i]);
		lcm=1;
		ans=-1;
		fr(i,1,n){
			if(y[i]%lcm==0){
				vector<long long> fact=get(y[i]/lcm);
				fr(j,0,(int)fact.size()-1)
					update(lcm*fact[j]);
			}
			if(double(lcm)/gcd(x[i],lcm)*x[i]>1e16)
				break;
			lcm=lcm/gcd(x[i],lcm)*x[i];
			if(i==n){
				tmp=(l-1)/lcm+1;
				update(tmp*lcm);
			}
		}
		if(ans<0)
			cout<<"Case #"<<ti<<": NO"<<endl;
		else
			cout<<"Case #"<<ti<<": "<<ans<<endl;
	}
}