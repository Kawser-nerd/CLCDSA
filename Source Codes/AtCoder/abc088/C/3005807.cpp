#include <iostream>
using namespace std;
int main() {
	int c[3][3];
	int a1, a2, a3;
	int flg = 0;
	int max = 0;
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> c[i][j];
			if (c[i][j] > max)
				max = c[i][j];
		}
	}

	for (a1 = 0;a1 <= max && flg == 0;a1++) {
		for (a2 = 0;a2 <= max && flg == 0;a2++) {
			for (a3 = 0;a3 <= max && flg == 0;a3++) {
				if (c[0][0] - a1 == c[0][1] - a2 && c[0][2] - a3 == c[0][1] - a2) {
					if (c[1][0] - a1 == c[1][1] - a2 && c[1][2] - a3 == c[1][1] - a2) {
						if (c[2][0] - a1 == c[2][1] - a2 && c[2][2] - a3 == c[2][1] - a2) {
							flg = 1;
						}
					}
				}
			}
		}
	}

	if (flg == 0)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;

	return 0;
}