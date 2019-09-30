#define _CRT_SECURE_NO_DEPRECATE
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

struct TZombie {
	int AppearanceTime;
	int X, Y;
};

const int ZombieLifeTime = 500;

inline int distance(int x1, int y1, int x2, int y2) {
	return 100*max(abs(x1 - x2), abs(y1 - y2));
}

bool compareZombiesByTime(const TZombie& z1, const TZombie& z2) {
	return (z1.AppearanceTime < z2.AppearanceTime);
}

int main(void) {
	int testCount;
	scanf("%d", &testCount);
	for (int testNo = 1; testNo <= testCount; ++testNo) {
		vector<TZombie> zombies;
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			TZombie z;
			scanf("%d%d%d", &z.X, &z.Y, &z.AppearanceTime);
			zombies.push_back(z);
			z.AppearanceTime += ZombieLifeTime;
			zombies.push_back(z);
		}
		sort(zombies.begin(), zombies.end(), compareZombiesByTime);
		vector< vector<int> > ma(2*n, vector<int>(ZombieLifeTime + 1, -1));
		int result = 0;
		for (int i = 0; i < 2*n; ++i) {
			for (int j = 0; j <= ZombieLifeTime; ++j) {
				if (j != 0)
					ma[i][j] = ma[i][j-1];
				int currentTime = j + zombies[i].AppearanceTime;
				if (currentTime >= distance(0, 0, zombies[i].X, zombies[i].Y)) {
					ma[i][j] = max(ma[i][j], 1);
				}
				for (int prevZombie = 0; prevZombie < i; ++prevZombie) {
					if (zombies[prevZombie].X == zombies[i].X && zombies[prevZombie].Y == zombies[i].Y && zombies[prevZombie].AppearanceTime + ZombieLifeTime == zombies[i].AppearanceTime)
						continue;
					int tm = min(ZombieLifeTime, currentTime - max(750, distance(zombies[prevZombie].X, zombies[prevZombie].Y, zombies[i].X, zombies[i].Y)) - zombies[prevZombie].AppearanceTime);
					if (tm < 0)
						continue;
					if (ma[prevZombie][tm] == -1)
						continue;
					ma[i][j] = max(ma[i][j], 1 + ma[prevZombie][tm]);
				}
			}
			result = max(result, ma[i].back());
		}
		printf("Case #%d: %d\n", testNo, result);
	}
	return 0;
}
