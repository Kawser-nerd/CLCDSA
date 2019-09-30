#include <memory>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
const unsigned int N = 8192;
unsigned short buf[4][N][N];
string s;

int runTest() {
	char L[4] = {'A', 'B', 'C', 'X'};

	for (unsigned int x=0; x<s.size(); x++) {
		for (int i=0; i<4; i++)
			if (s[x]==L[i]) buf[i][x][x] = 1;
			else buf[i][x][x] = 3;
	}
	for (unsigned int len=2; len<=s.size(); len++) {
		for (unsigned int x1=0; x1+len<=s.size(); x1++) {
			for (int Li=0; Li<4; Li++) {
				int x2 = x1 + len - 1;
				int res = (unsigned short)-1;
				if (s[x1]==L[Li])
					res = buf[Li][x1+1][x2] + 1;
				int res2;
				if (s[x2]==L[Li]) {
					res2 = buf[Li][x1+1][x2] + 1;
					if (res2>res) res = res2;
				}

				for (int m=x1; m<x2; m++) {
					int c = buf[Li][x1][m] + buf[Li][m+1][x2];
					if (c<res) res = c;
					for (int Li2=0; Li2<4; Li2++) {
						int c = buf[Li2][x1][m] + buf[Li2][m+1][x2] + 2;
						if (c<res) res = c;
					}
				}
				buf[Li][x1][x2] = (unsigned short)res;
			}
		}
	}
	int best = buf[3][0][s.size()-1];
	return best;
}
//#include <stdio.h>

int main() {
	//freopen("in", "r", stdin);
	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {
		do {
			getline(cin, s);
		} while (s.empty());
		cout << "Case #" << t << ": " << runTest() << endl;
	}
	return 0;
}
