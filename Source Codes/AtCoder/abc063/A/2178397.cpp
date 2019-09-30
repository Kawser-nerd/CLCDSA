#include<iostream>
using namespace std;

int main(){

	int a, b;
	cin >> a >> b;
	int ans;
	ans = a+b;
	if(ans >=10){
		cout << "error\n";
	}
	else{
		cout << ans << endl;
	}

	return 0;

}