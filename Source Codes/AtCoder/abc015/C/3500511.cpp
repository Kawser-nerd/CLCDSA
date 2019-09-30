#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int t[5][5];
bool ans = false;

void found(int c, int bit){
	if(c == n){
		if(bit == 0){
			ans = true;
		}
		return;
	}
	for(int i = 0; i < k; ++i){
		found(c+1 , bit ^ t[c][i]);
	}
}

int main(void){
	cin >> n >> k;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < k; ++j){
			cin >> t[i][j];
		}
	}
	found(0, 0);
	if(ans){
		cout << "Found" << endl;
	}else{
		cout << "Nothing" << endl;
	}
	return 0;
}