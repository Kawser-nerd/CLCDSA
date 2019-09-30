#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#define fr(i,a,b) for(i=a;i<=b;++i)
using namespace std;
const int maxn=1000002;
long long n,m,ca,ans,i,j,l,t,ti,x[maxn],c,sum=0;
int main(){
	freopen("b2.in","r",stdin);
	freopen("b2.out","w",stdout);
	cin>>ca;
	fr(ti,1,ca){
		cin>>l>>t>>n>>c;
		ans=0;
		fr(i,1,c){
			cin>>x[i];
			for(j=i;j<=n;j+=c){
				x[j]=x[i];
				ans+=x[i]*2;
			}
		}
		vector<int> list;
		sum=0;
		fr(i,1,n){
			sum+=x[i]*2;
			if(sum>t)
				list.push_back(min((sum-t)/2,x[i]));
		}
		sort(list.begin(),list.end());
		for(i=(int)list.size()-1;i>=0;i--)
			if(l){
				ans-=list[i];
				--l;
			}		
		cout<<"Case #"<<ti<<": "<<ans<<endl;
	}
}