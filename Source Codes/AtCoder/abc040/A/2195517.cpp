#include<iostream>
#include <string>
#include<vector>

using namespace std;

int main(){

	int n ,x;
	cin >> n >> x;
	if(x-1 >= n-x){
		cout << n-x <<endl;
	}
	else{
		cout << x-1 << endl;
	}
	return 0;

}