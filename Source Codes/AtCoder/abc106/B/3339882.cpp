#include<iostream>
using namespace std;
typedef long long LL;
#define F(i) for(int i=0;i<n;i++)
int main(){
	int n;
	cin>>n;
	int r=0;
	for(int i=1;i<=n;i++){
		int c=0;
		for(int j=1;j<=i;j++)if(i%j==0)c++;
		if(i%2==1&&c==8)r++;
	}
	cout<<r;
	return 0;
}