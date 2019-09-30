#include <iostream>
#include "string.h"
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	for(int i = 1;i < s.size();i++){
		string sPrime = s.substr(0,s.size() - i);
		if(sPrime.size() % 2 != 0) continue;
		if(sPrime.substr(0,sPrime.size()/2) == sPrime.substr(sPrime.size()/2)){
			cout << sPrime.size() << endl;
			return 0;
		}
	}

	return 0;
}