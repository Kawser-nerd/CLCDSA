#include <iostream>
#include <vector>

const int H = 3;
const int W = 3;
const int C_MAX = 100;

int main() {
	std::vector<std::vector<int>> c(H, std::vector<int>(W));
	for(int h = 0; h < H; h++) {
		for(int w = 0; w < W; w++) {
			std::cin >> c[h][w];
		}
	}

	bool result = false;

	for(int i = 0; i <= c[0][0]; i++) {
		std::vector<int> a(H);
		std::vector<int> b(W);
		a[0] = i;
		b[0] = c[0][0] - a[0];

		for(int h = 1; h < H; h++) {
			// ?????????
			a[h] = c[h][0] - b[0];
		}
		for(int w = 1; w < W; w++) {
			b[w] = c[0][w] - a[0];
		}

		bool ok = true;
		for(int h = 1; h < H; h++) {
			for(int w = 1; w < W; w++) {
				if(c[h][w] != a[h] + b[w]) {
					ok = false;
					break;
				}
			}
			if(!ok) {
				break;
			}
		}
		if(ok) {
			result = true;
			break;
		}
	}

	std::cout << (result ? "Yes" : "No") << std::endl;

	return 0;
}