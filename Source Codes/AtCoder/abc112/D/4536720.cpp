#include <iostream>
#include <algorithm>
using namespace std;
long long int n,m,sum;
int main() {
	// your code goes here
	cin>>n>>m;
	sum=n;
	long long int ans=-1;
	for(long long int i=1;i*i<=m;i++){
		if(m%i==0&&i>=sum){
			ans=max(ans,m/i);
		}
		if(m%i==0&&m/i>=sum){
			ans=max(ans,i);
		}
	}
	cout<<ans<<"\n";
	return 0;
}