#define _CRT_SECURE_NO_DEPRECATE
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

struct TPoint {
	int x, y;
	bool isEven;
};

vector<TPoint> points;

inline int distance(int x, int y, int pIndex) {
	return max(abs(x - points[pIndex].x), abs(y - points[pIndex].y));
}

bool isGood(int x, int y) {
	for (int i = 0; i < (int)points.size(); ++i) {
		if ((distance(x, y, i) % 2 == 0) != points[i].isEven)
			return false;
	}
	return true;
}

bool isLess(int x1, int y1, int x2, int y2) {
	int a1 = abs(x1) + abs(y1);
	int a2 = abs(x2) + abs(y2);
	if (a1 < a2)
		return true;
	if (a1 > a2)
		return false;
	if (x1 > x2)
		return true;
	if (x2 > x1)
		return false;
	return (y1 > y2);
}

int main(void) {
	int testCount;
	scanf("%d", &testCount);
	for (int testNo = 1; testNo <= testCount; ++testNo) {
		points.clear();
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			int x, y;
			char str[2];
			scanf("%d%d%s", &x, &y, &str);
			TPoint p;
			p.x = x;
			p.y = y;
			p.isEven = (str[0] == '.');
			points.push_back(p);
		}
		int resX = -100000, resY = -100000;
		for (int x = -300; x <= 300; ++x) {
			for (int y = -300; y <= 300; ++y) {
				if (isLess(x, y, resX, resY) && isGood(x, y)) {
					resX = x;
					resY = y;
				}
			}
		}
		printf("Case #%d: ", testNo);
		if (resX != -100000) {
			printf("%d %d\n", resX, resY);
		} else
			printf("Too damaged\n");
	}
	return 0;
}
