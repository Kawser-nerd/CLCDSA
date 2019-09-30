#include<iostream>
using namespace std;

int main(){
	freopen("B-large.in","r",stdin);
	freopen("pb.txt","w",stdout);
	long long t,l,p,c,tt,ans,i,j,k;
	cin >> tt;
	for(t=1 ; t<=tt ; t++){
		cin >> l >> p >> c;
		k=0;
		for(i=l ; i<p ; i*=c){
			k++;
		}
		ans=0;
		for(i=1 ; i<k ; (i<<=1)){
			ans++;
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
}
