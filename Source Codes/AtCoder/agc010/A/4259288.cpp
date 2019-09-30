#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<iostream>
using namespace std;
int main(){
	int n,ans=0,m;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;if(m%2==1)ans++;
	}
	if(ans%2==1)cout<<"NO";
	else cout<<"YES";
	return 0;
}