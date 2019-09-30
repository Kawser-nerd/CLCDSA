#include <iostream>
#include "string.h"
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string S;
	cin >> S;
	bool flag = true;
	int count = 0;
	for(int i = 0;i < S.size();i++){
		if(S[i] != '+'){
			if(S[i] == '0') flag = false;
		}else{
			if(flag) count += 1;
			flag = true;
		}	
	}
	if(flag) count += 1;
	cout << count << endl;
	return 0;
}