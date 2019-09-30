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
	char d[4] = {a[0],b[0],c[0],'\0'};
	string f = d;
	transform (f.begin (), f.end (), f.begin (), ::toupper);
	cout << f;
    return 0;
 }