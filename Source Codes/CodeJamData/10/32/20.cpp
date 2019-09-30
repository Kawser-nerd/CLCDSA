#include<iostream>
#define fr(i,a,b) for(i=a;i<=b;++i)
using namespace std;
long long ca,ti,l,p,c,ans;
int main(){
	freopen("b1.in","r",stdin);
	freopen("b1.out","w",stdout);
	cin>>ca;
	fr(ti,1,ca){
		cin>>l>>p>>c;
		ans=0;
		while(l*c<p){
			ans++;
			if(l*c>=(p-1)/c+1)
				break;
			c=c*c;
		}
		cout<<"Case #"<<ti<<": "<<ans<<endl;
	}
}