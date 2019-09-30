#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int N;
    cin >> N;
	cout << (N%2==0? N : 2*N) << endl;
}