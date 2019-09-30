#include<iostream>
#include <string>
#include<vector>

using namespace std;

int main(){

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if((double)b/a > (double)d/c){
		cout << "TAKAHASHI" <<endl;
	}
	else if((double)b/a < (double)d/c){
		cout << "AOKI" <<endl;
	}
	else if((double)b/a == (double)d/c){
		cout << "DRAW" << endl;
	}

	return 0;

}