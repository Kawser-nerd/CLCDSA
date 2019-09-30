#include <iostream>
using namespace std;

int main() {
	int x,temp=0,ans;
	cin>>x;
	for (int i=1;i<=x;i++){
		temp+=i;
		if (temp>=x){
			ans=i;
			break;
		}
	}
	cout<<ans;
	return 0;
}