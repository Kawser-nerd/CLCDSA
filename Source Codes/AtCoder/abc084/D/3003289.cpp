#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX 100100


int main(void){
	int n;
	cin >> n;
	int p[MAX+10];

	for(int i = 0; i < MAX; i++){
		p[i] = 1;
	}
	p[0]=0; p[1]=0;
	for(int i = 2; i < sqrt(MAX); ++i){
		if(p[i]){
			for(int j = 2; j*i < MAX; ++j){
				p[j*i] = 0;
			}
		}
	}
	vector<int> rui(MAX);
	int count = 0;
	for(int j = 1; j <= MAX; j+=2){
		if(p[j]&&p[(j+1)/2]){
			count++;
		}
		rui[j] = count;
	}

	for(int i = 0; i < n; ++i){
		int l,r;
		cin >> l >> r;
		cout << rui[r] - rui[l-2] << endl;
	}
	return 0;
}