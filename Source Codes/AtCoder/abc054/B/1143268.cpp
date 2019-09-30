#include <stdlib.h>
#include <iostream>
using namespace std;
 
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
int main(){
	int n, m;
	cin >> n >> m;
	char a[50][50];
	char b[50][50];
	REP(i, n){
		REP(j, n){
			cin >> a[i][j];
		}
	}
 
	REP(i, m){
		REP(j, m){
			cin >> b[i][j];
		}
	}
 
	bool ans = false;
	for(int i = 0; i < n-m+1 && !ans; ++i){
		for(int j = 0; j < n-m+1 && !ans; ++j){
			bool is_exist = true;
			for(int k = 0; k < m && is_exist; ++k){
				for(int l = 0; l < m && is_exist; ++l){
					if(a[i+k][j+l] != b[k][l]){
						is_exist = false;
					}
				}
			}
			if(is_exist){
				ans = true;
			}
		}
	}
 
	if(ans){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
 
	return 0;
}