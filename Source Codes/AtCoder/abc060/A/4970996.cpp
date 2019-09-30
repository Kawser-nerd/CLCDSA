#include <iostream> 
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;
#define MAX_N 21

int main() {
	string a,b,c;
	cin >> a >> b >> c;
	if (a[a.length() - 1] == b[0]) {
		if (b[b.length() - 1] == c[0]) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
    return 0;
 }