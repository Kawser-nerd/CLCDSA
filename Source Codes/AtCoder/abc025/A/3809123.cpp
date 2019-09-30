#include <iostream>
#include <string>
#include <vector>
#include <boost/format.hpp>
using namespace std;

int main() {
	string s; cin >> s;
	int n; cin >> n;
	vector<string> c(25);
	int indx = 0;
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
//			cout << s[i] << " " << s[j] << endl;
			c[indx++] = (boost::format("%1%%2%") % s[i] %s[j]).str();
		}
	}
//	for(int i = 0; i < 25; i++) {
//		cout << c[i] << endl;
//	}
	cout << c[n-1] << endl;
}