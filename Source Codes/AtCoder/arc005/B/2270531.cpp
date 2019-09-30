#include <iostream>
#include <fstream>
#include <string> 
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#include <cctype>

#define BIT(a) (1 << (a))

using namespace std;

long long MOD = 1000000007;


long long mod_pow(long long x, long long n){
    long long res = 1;
    for(int i = 0;i < 60; i++){
        if(n >> i & 1) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

int main(void){
	int x, y;
	string W;
	cin >> x >> y >> W;
	x--;
	y--;
	char field[9][9];
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			scanf(" %c", &field[j][i]);
		}
	}
	string dir[10] = {"R", "L", "U", "D", "RU", "RD", "LU", "LD"};
	int dirX[10] = {1, -1, 0, 0, 1, 1, -1, -1};
	int dirY[10] = {0, 0, -1, 1, -1, 1, -1, 1};
	int moveX;
	int moveY;
	for (int i = 0; i < 8; i++){
		if (dir[i] == W){
			moveX = dirX[i];
			moveY = dirY[i];
		}
	}
	char ans[5];
	ans[0] = field[x][y];

	for (int i = 0; i < 3; i++){
		int nextX = x+moveX;
		int nextY = y+moveY;
		if ((nextX == -1 && nextY == -1) || (nextX == -1 && nextY == 9) || (nextX == 9 && nextY == -1) || (nextX == 9 && nextY == 9)){
			moveX *= -1;
			moveY *= -1;
		}else if (nextX == -1 || nextX == 9){
			moveX *= -1;
		}else if (nextY == -1 || nextY == 9){
			moveY *= -1;
		}
		nextX = x+moveX;
		nextY = y+moveY;
		x = nextX;
		y = nextY;
		ans[i+1] = field[x][y];
	}
	ans[4] = '\0';
	cout << ans << endl;
	return 0;
}