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
	rep(i,0,n+3){
		a[i]=0;
	}
	long long int sum=0;
	long long int ans=0;
	rep(i,0,n){
		cin>>a[i];
		if(i!=0&&a[i]>0&&a[i-1]>0){
			sum++;
			a[i]--;
			a[i-1]--;
		}		
		sum+=(a[i]/2);
		a[i]-=a[i]/2*2;	
	}
	cout<<sum<<endl;
}