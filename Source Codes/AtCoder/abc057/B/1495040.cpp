#include <iostream>
#include "string.h"
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	vector<int>A;
	vector<int>B;
	vector<int>C;
	vector<int>D;
	int N,M;
	int a,b,c,d;
	cin >> N >> M;
	for(int i = 0;i < N;i++){
		cin >> a >> b;
		A.push_back(a);
		B.push_back(b);
	}
	for(int j = 0;j < M;j++){
		cin >> c >> d;
		C.push_back(c);
		D.push_back(d);
	}
	long long int minDis = 10e16;
	int dis = 0;
	int index = 0;
	for(int i = 0;i < N;i++){
		for(int j = 0;j < M;j++){
			dis = abs(A[i] - C[j]) + abs(B[i] - D[j]);
			if(minDis > dis){
				minDis = dis;
				index = j + 1;
			}
		}
		cout << index << endl;
		minDis = 10e16;
		index = 0;
	}

	return 0;
}