#include<iostream>
 
using namespace std;
 
int main(){
	int n;
    cin>>n;
	int l,r,ans=0;
	for(int i=0;i<n;i++){
		cin>>l>>r;
		ans+=r+1-l;
	}
	cout<<ans<<endl;
}