#include <iostream>
#include <map>
using namespace std;

int main() {
	int n, m, a;
	cin >> n >> m;
	int city[51] = {0};
	for(int i = 0; i < m * 2; i++){
		cin >> a;
		city[a-1]++;
	}
	for(int i = 0; i < n; i++){
		cout << city[i] << endl;
	}
	
	return 0;
}