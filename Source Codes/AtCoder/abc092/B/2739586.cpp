#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n,d,x;
	int a[110];
	cin>>n>>d>>x;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=x;
	for(int i=0;i<n;i++){
		ans+=(d-1)/a[i]+1;
	}
	cout<<ans<<endl;
			
}