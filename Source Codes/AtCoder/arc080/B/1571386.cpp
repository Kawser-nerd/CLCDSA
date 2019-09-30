#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;


int main(){
	int H,W,N;
	cin >> H >> W >> N;
	vector<int> a(N);
	for(int i=0; i<N; i++) cin >> a[i];
	
	vector<vector<int>> map(H,vector<int>(W, 0));
	int colorp = 0;


	for(int i=0; i<H; i++){
		if(i%2 == 0) {
			for(int j=0; j<W; j++){
				map[i][j] = colorp+1;
				a[colorp]--;
				if(a[colorp] == 0) colorp++;
			}
		}else{
			for(int j=W-1; j>-1; j--){
				map[i][j] = colorp+1;
				a[colorp]--;
				if(a[colorp] == 0) colorp++;
			}
		}
	}

	for(auto v : map){
		for(auto i: v){
			cout << i << " ";
		}
		cout << endl;
	}
}