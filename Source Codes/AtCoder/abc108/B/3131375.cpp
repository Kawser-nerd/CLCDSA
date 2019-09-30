// B.

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int x3 = x2 - y2 + y1;
	int y3 = y2 + x2 - x1;
	int x4 = x3 - y3 + y2;
	int y4 = y3 + x3 - x2;
	cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
	return 0;
}