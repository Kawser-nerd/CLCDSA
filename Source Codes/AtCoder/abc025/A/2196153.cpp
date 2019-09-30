#include<iostream>
#include <string>
#include<vector>

using namespace std;

int main(){

	string s;
	string d;
	int n;
	cin >> s >> n;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			d = d + s[i];
			d = d + s[j];
		}
	}
	cout << d[n*2-2] << d[n*2-1] << endl;

	return 0;

}