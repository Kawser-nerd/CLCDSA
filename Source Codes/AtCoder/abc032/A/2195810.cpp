#include<iostream>
#include <string>
#include<vector>

using namespace std;

int main(){

	int a, b, n;
	cin >> a >> b >> n;
	while(1){
		if(n%a==0 && n%b==0){
			cout << n <<endl;
			return 0;
		}
		n++;
	}

	return 0;

}