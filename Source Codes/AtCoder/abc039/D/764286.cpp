#include <utility>
#include <algorithm>
#include <type_traits>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <cassert>
#include <memory>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <queue>
#include <vector>
#include <chrono>
#include <random>
#include <forward_list>
#include <iomanip>
#include <functional>
using namespace std;
#define MFOR(i,end) for(size_t i = 0, end_i = (end); i < end_i; ++ i)


char map[105][105];//H,W
char result[105][105];//H,W
short map_count[105][105];//H,W
int H, W;

int main()
{
	cin >> H >> W;
	for (auto& i : result)
	{
		for (auto& j : i) {
			j = '.';
		}
	}


	for (int i = 1; i <= H; ++i)
	{
		cin >> map[i]+1;
		for (int j = 1; j <= W; ++j)
		{
			if (map[i][j] == '#') {
				for (int x = -1; x <= 1; ++x)
				{
					for (int y = -1; y <= 1; ++y)
					{
						++map_count[i + y][j + x];
					}
				}
			}
		}
	}
	for (int i = 1; i <= H; ++i)
	{
		map_count[i][1] += 3;
		map_count[i][W] += 3;
	}
	for (int i = 1; i <= W; ++i)
	{
		map_count[1][i] += 3;
		map_count[H][i] += 3;
	}
	--map_count[1][1];
	--map_count[1][W];
	--map_count[H][1];
	--map_count[H][W];


	for (int i = 1; i <= H; ++i)
	{
		for (int j = 1; j <= W; ++j)
		{
			if (map_count[i][j] >= 9) {
				result[i][j] = '#';
				map_count[i][j] = 0;
				for (int x = -1; x <= 1; ++x)
				{
					for (int y = -1; y <= 1; ++y)
					{
						if (map_count[i + y][j + x] < 9) {
							map_count[i + y][j + x] = 0;
						}
					}
				}
			}
		}
	}

	for (int i = 1; i <= H; ++i)
	{
		for (int j = 1; j <= W; ++j)
		{
			if (map_count[i][j] != 0) {
				if (map[i][j] == '#') {
					cout << "impossible" << endl;
					return 0;
				}
			}
		}
	}

	cout << "possible" << endl;
	for (int i = 1; i <= H; ++i)
	{
		for (int j = 1; j <= W; ++j)
		{
			cout << result[i][j];
		}
		cout << endl;
	}
} ./Main.cpp:43:16: warning: operator '>>' has lower precedence than '+'; '+' will be evaluated first [-Wshift-op-parentheses]
                cin >> map[i]+1;
                    ~~ ~~~~~~^~
./Main.cpp:43:16: note: place parentheses around the '+' expression to silence this warning
                cin >> map[i]+1;
                             ^
                       (       )
1 warning generated.