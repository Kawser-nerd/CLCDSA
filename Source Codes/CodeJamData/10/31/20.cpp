#include<iostream>
#define fr(i,a,b) for(i=a;i<=b;++i)
using namespace std;
const int maxn=1002;
int a[maxn],b[maxn],i,j,n,ans,ti,ca;
int main(){
	freopen("a1.in","r",stdin);
	freopen("a1.out","w",stdout);
	cin>>ca;
	fr(ti,1,ca){
		cin>>n;
		fr(i,1,n)
			scanf("%d%d",a+i,b+i);
		ans=0;
		fr(i,1,n)
			fr(j,i+1,n)
				if((a[i]-a[j])*(b[i]-b[j])<0)
					++ans;
		cout<<"Case #"<<ti<<": "<<ans<<endl;
	}
}