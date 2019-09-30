#include<iostream>
#include <string>
#include<vector>

using namespace std;

int main(){

	int a, b, c, k, s, t;
	cin >> a >> b >> c >> k >> s >> t;
	if(s+t < k ){
		cout << s*a + t*b << endl;
	}
	else{
		cout << s*a + t*b -(s+t)*c <<endl;
	}

	return 0;

}