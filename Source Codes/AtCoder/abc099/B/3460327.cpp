#include <iostream>
#include <vector>
#include <map>

using namespace std;

int height(int x) {
	if(x == 1) return 1;
	return x + height(x-1);
}

int main() {
	int a, b;
    cin >> a >> b;
	cout << height(b - a) - b << endl;
}