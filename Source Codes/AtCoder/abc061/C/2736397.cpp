#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n;
	long long int k;
	cin>>n>>k;
	long long int a[100010],b[100010];
	long long int c[100010];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		c[a[i]]+=b[i];
	}
	sort(a,a+n);
	for(int i=1;i<=100010;i++){
		if(k<=c[i]){
			cout<<i<<endl;
			return 0;
		}
		k-=c[i];
	}
}