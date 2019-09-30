#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, g, p;
	int vg, vp;
	int point = 0;
	string s;
	g = p = vg = vp = 0;

	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) == 'g') {
			vg++;
		}
		else {
			vp++;
		}
	}

	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) == 'g') {
			vg--;
			if (vp < g-p) {
				p++;
				point++;
			}
			else {
				g++;
			}
		}
		else {
			vp--;
			if (p < g) {
				p++;
			}
			else {
				g++;
				point--;
			}
		}
	}

	cout << point << endl;
}