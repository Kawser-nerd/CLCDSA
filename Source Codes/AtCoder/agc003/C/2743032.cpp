#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i,a,n)	for(int i=a;i<n;i++)
int main(){
	int n;
	cin>>n;
	int a[100010];
	int b[100010];
	rep(i,0,n){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b,b+n);
	int ans=0;
	rep(i,0,n){
		int s=int(lower_bound(b,b+n,a[i])-b);
		if(i%2==0&&s%2==1)ans++;
	}
	cout<<ans<<endl;
		
}