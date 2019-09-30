#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;


int main(void){
	int a,b;
	string s;
	cin >> a >> b >> s;
	for(int i = 0; i < a + b; ++i){
		if(i==a){
			if(s[i]!='-'){
				cout << "No"<< endl;
				return 0;
			}
		}else{
			if(!(s[i]-'0'>=0&&'9'-s[i]>=0)){
				cout << "No"<< endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
}