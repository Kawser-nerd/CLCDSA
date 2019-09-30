#include <iostream>
using namespace std;
int main() {
	char S[52][52];
	bool flg = true;
	int H, W;

	cin >> H >> W;


	for (int i = 0; i < 52; i++)
	{
		for (int j = 0; j < 52; j++)
		{
			S[i][j] = '.';
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> S[i][j];
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (S[i][j] == '#') {
				if (!(S[i - 1][j] == '#' || S[i + 1][j] == '#' || S[i][j + 1] == '#' || S[i][j - 1] == '#')) {
					flg = false;
					break;
				}
			}
		}
	}

	if (flg) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}