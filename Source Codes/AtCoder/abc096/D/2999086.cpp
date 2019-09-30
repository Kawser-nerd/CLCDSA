#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX 60000


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
	int i = 0, j = 0;
	vector<int> ans;
	while(true){
		++i;
		if(p[i]){
			if(i%5==1){
				ans.push_back(i);
				++j;
			}
		}
		if(j==n)break;
	}

	for(int i = 0; i < n; ++i){
		cout << ans[i] << " ";
	}

	cout << endl;
	return 0;
}