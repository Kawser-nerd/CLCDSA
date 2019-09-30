#include <iostream>
#include <vector>

using namespace std;
int main(void){
	int N , M , C;
	cin >> N >> M >> C;
	std::vector<vector<int>> A(N);
	std::vector<int> B(M);
	for(int j = 0; j < M; j++){
		cin >> B[j];
	}
	for(int i = 0; i < N; i++){
		A[i].resize(M);
		for(int j = 0; j < M; j++){
			cin >> A[i][j];
		}
	}
	int n = 0;
	for(int i = 0; i < N; i++){
		int sum = 0;
		for(int j = 0; j < M; j++){
			sum += A[i][j]*B[j];
		}
		if(sum + C > 0){
			n++;
		}
	}
	cout << n << endl;
	
}