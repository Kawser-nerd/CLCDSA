#include<iostream>
using namespace std;
typedef long long ll;
ll a[200005];
int main(){
	ll n;while(cin>>n){
	a[0]=0;
	ll sum=0;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[1]!=0||a[i]>a[i-1]+1){
			//cout<<"-1"<<endl;
			flag=false;//break;
		}
		else if(a[i-1]!=0&&a[i]==(a[i-1]+1)){
				sum+=1;//(a[i]-a[i-1]);
				}
		else sum+=a[i];}
		if(flag==true)
		cout<<sum<<endl;
	else cout<<"-1"<<endl;
	}
return 0;}