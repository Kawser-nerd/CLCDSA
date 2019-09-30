#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void){
	int a,b;
	cin >> a >> b;
	if(a<=b){
		cout << a << endl;
	}else{
		cout << a-1 << endl;
	}

	return 0;
}