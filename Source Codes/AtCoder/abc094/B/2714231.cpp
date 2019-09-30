#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n,m,x;
	cin>>n>>m>>x;
	int a[m];
	int b[1000]={0};
	for(int i=1;i<=m;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	int sumN=0;
	int sumO=0;
	for(int i=x;i<=n;i++){
		if(b[i]==1){
			sumN++;
		}
	}
	for(int i=x;i>=0;i--){
		if(b[i]==1){
			sumO++;
		}
	}
	cout<<min(sumN,sumO)<<endl;
}