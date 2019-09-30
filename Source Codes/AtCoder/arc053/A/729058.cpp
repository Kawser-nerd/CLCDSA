#include <iostream>
using namespace std;

bool inside(int w, int h,int a, int b)
	{
		if (a >= 0 && a < w && b >= 0 && b < h) return true;
		else return false;
	};

long calc(int w, int h)
	{
	long ret = 0;
	for (int x = 0; x < w; x++) {
		for (int y = 0; y < h; y++) {
			int dx[] = { 1, 0 };
			int dy []= { 0, 1 };
				for (int i = 0; i < 2; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (inside(w, h, nx, ny) == true) ret++;
				else continue;
				}
			}
		}
	return ret;
	};

int main()
{
	int H, W;
	cin >> H >> W;
	long ans;
	ans = calc(W, H);
	cout << ans << endl;
	return 0;
}