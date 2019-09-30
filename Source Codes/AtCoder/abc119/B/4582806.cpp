#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(void){
	int N;
	cin >> N;
	vector<double> x(N);
	vector<string> u(N);
	long double max = 0;
	for(int i = 0; i < N;i++){
		cin >> x[i];
		cin >> u[i];
	}
	for(int i = 0; i < N; i++){
		if(u[i][0] == 'B')
			max += x[i] * 380000.0;
		else
			max += x[i];
	}
	cout << max << endl;
	return 0;
}