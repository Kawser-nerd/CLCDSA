#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int h, w; cin >> h >> w;
	vector<string> a(h);
	for(int i = 0; i < h; i++) cin >> a[i];

	vector<bool> tate(h, false), yoko(w, false);

	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if(a[i][j] == '#') {
				tate[i] = true;
				yoko[j] = true;
			}	
		}
	}

	for(int i = 0; i < h; i++) {
		if(!tate[i]) continue;
		for(int j = 0; j < w; j++) {
			if(!yoko[j]) continue;
			cout << a[i][j];
		}
		cout << endl;
	}
}