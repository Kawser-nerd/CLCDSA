#include <iostream>
using namespace std;
int menseki(int xmin, int xmax, int ymin, int ymax) {
	int W,H;
	W = xmax - xmin;
	H=ymax - ymin;

	if (W > 0&&H>0) {
		return W*H;
	}
	else {
		return 0;
	}
}

int main() {
	int xmin, xmax, ymin, ymax;
	int W, H, N;
	int x, y, a;

	cin >> W >> H >> N;

	xmin = 0;
	xmax = W;
	ymin = 0;
	ymax = H;

	for (int i = 0;i < N;i++) {
		cin >> x >> y >> a;

		switch (a) {
		case 1:
			if (xmin < x)
				xmin = x;
			break;
		case 2:
			if (xmax > x)
				xmax = x;
			break;
		case 3:
			if (ymin < y)
				ymin = y;
			break;
		case 4:
			if (ymax > y)
				ymax = y;
			break;
		}
	}

	cout << menseki(xmin, xmax, ymin, ymax) << endl;

	return 0;
}