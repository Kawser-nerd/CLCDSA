#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n],b[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	int c[m],d[m];
	for(int i=0;i<m;i++){
		cin>>c[i]>>d[i];
	}
	int l=1000000000;
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int ll=abs(a[i]-c[j])+abs(b[i]-d[j]);
			if(ll<l){
				l=ll;
				ans=(j+1);			
			}
		}
		cout<<ans<<endl;
		l=1000000000;
	}
}