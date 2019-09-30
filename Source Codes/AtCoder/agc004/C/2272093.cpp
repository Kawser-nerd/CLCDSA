//?????
#include <iostream>
#include <string>
using namespace std;

int h, w;
string s[500];
bool red[500][500];
bool blue[500][500];

int main() {
	int i, j;
	
	cin >> h >> w;
	for (i = 0; i < h; i++) cin >> s[i];
	
	//????(???????????????????????)
	for (i = 1; i < h; i += 2) for (j = 0; j < w - 1; j++) red[i][j] = true;
	for (i = 0; i < h; i++) red[i][0] = true;
	for (i = 0; i < h; i += 2) for (j = 1; j < w; j++) blue[i][j] = true;
	for (i = 0; i < h; i++) blue[i][w - 1] = true;
	
	//#???
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			if (s[i][j] == '.') continue;
			if (red[i][j]) blue[i][j] = true;
			else red[i][j] = true;
		}
	}
	
	//????
	for (i = 0; i < h; i++) { for (j = 0; j < w; j++) cout << ".#"[red[i][j]]; cout << endl; }
	cout << endl;
	for (i = 0; i < h; i++) { for (j = 0; j < w; j++) cout << ".#"[blue[i][j]]; cout << endl; }
	return 0;
}