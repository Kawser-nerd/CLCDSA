#include<iostream>
#include <string>
#include<vector>

using namespace std;

int main(){

	int a, b,count = 1, tmp;
	cin >> a >> b;
	tmp = a;
	while(a<b){
		count++;
		a = a + tmp;
	}

	cout << count << endl;

	return 0;

}