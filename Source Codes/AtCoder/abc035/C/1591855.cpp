#include<iostream>
 
using namespace std;
 
int imos[200005]={0};
 
int main(){
	int n,q;
	cin>>n>>q;
	for(int i=0;i<q;i++){
		int l,r;
		cin>>l>>r;
		imos[l]++;
		imos[r+1]--;
	}
	
	for(int i=1;i<=n;i++){
		cout<<imos[i]%2;
		imos[i+1]+=imos[i];
	}
	cout<<endl;
}