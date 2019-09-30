#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i,a,n)	for(int i=a;i<n;i++)
bool a[100001];
int n[100002];
int main(){
	int q;
	cin>>q;
	for(int i=2;i<=100000;i++)if(!a[i])for(int j=i+i;j<=100000;j+=i){
		a[j]=true;
	}
	for(int i=3;i<=100000;i+=2)if(a[i]==false&&a[(i+1)/2]==false)n[i]++;
	for(int i=3;i<=100000;i++)n[i]+=n[i-1];
	for(int i=0;i<q;i++){
		int a,b;
		cin>>a>>b;
		cout<<n[b]-n[a-1]<<endl;
	}
}