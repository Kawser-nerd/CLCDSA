#include <iostream>
#include <stdio.h>
using namespace std;

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
		
		switch (a){
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
	int xans = xmax - xmin;
	int yans = ymax - ymin;
	if (xans >= 0 && yans >= 0) printf("%d\n", xans*yans);
	else printf("%d\n", 0);
	return 0;
}