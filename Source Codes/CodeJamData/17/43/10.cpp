#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>
using namespace std;

int tx[4] = {-1, 0, 1, 0}, ty[4] = {0, 1, 0, -1};
#define N 210
bool go[N][N];
bool used[N][N][4], U[N][N];
char ch[N][N];
bool ok[N];
int r, c; 
vector <int> pu[N][N];
int len;
bool shot;

void shoot(int x, int y, int t, bool st) {
	if (x < 1 || x > r || y < 1 || y > c)
		return ;
	if (!st && (ch[x][y] == '-' || ch[x][y] == '|'))
		shot = true;
	if (used[x][y][t])
		return ;
	if (ch[x][y] == '#')
		return ;
	used[x][y][t] = true;
	// printf("%d %d %d\n", x, y, t);
	if (ch[x][y] == '/') {
		t ^= 1;
	}else if (ch[x][y] == '\\') {
		t = 3 - t;
	}
	shoot(x + tx[t], y + ty[t], t, false);
}

bool SAT() {
	memset(go, false, sizeof go);
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			if (ch[i][j] == '.' && pu[i][j].size() == 2) {
				go[pu[i][j][0] ^ 1][pu[i][j][1]] = true;
				go[pu[i][j][1] ^ 1][pu[i][j][0]] = true;
				// printf("?? %d %d\n", pu[i][j][0] ^ 1, pu[i][j][1]);
				// printf("?? %d %d\n", pu[i][j][1] ^ 1, pu[i][j][0]);
				
			}
	for (int k = 2; k <= 2 * len + 1; k++)
		for (int i = 2; i <= 2 * len + 1; i++)
			for (int j = 2; j <= 2 * len + 1; j++) {
				go[i][j] |= (go[i][k] && go[k][j]);
			}
	// for (int i = 2; i <= 2 * len + 1; i++)
	// 	for (int j = 2; j <= 2 * len + 1; j++) {
	// 		printf("%d ", go[i][j]);
	// 	}
	for (int i = 2; i <= 2 * len + 1; i++)
		if (go[i][i ^ 1]) {
			return false;
		}

	for (int i = 2; i <= 2 * len + 1; i++)
		if (!ok[i]) {
		bool fi1 = false, fi2 = false;
		for (int j = 2; j <= 2 * len + 1; j++)
			if (!ok[j ^ 1] && go[j][i])
				fi1 = true;
		if (fi1)
			return false;
	}
	
	for (int i = 2; i <= 2 * len + 1; i++) {
		bool fi1 = false, fi2 = false;
		for (int j = 2; j <= 2 * len + 1; j++)
			if (!ok[j ^ 1] && go[j][i])
				fi1 = true;
		for (int j = 2; j <= 2 * len + 1; j++)
			if (!ok[j ^ 1] && go[j][i ^ 1])
				fi2= true;
		if (fi1 && fi2)
			return false;
	}

	return true;
}

void doit() {
	scanf("%d%d", &r, &c);
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++) {
			for (ch[i][j] = getchar(); ch[i][j] <= 32; ch[i][j] = getchar());
			pu[i][j].clear();
		}
	len  = 0;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			if (ch[i][j] == '|' || ch[i][j] == '-') {
				len += 1;
				memset(used, false, sizeof used);
				ok[len * 2] = true;
				shot = false;
				shoot(i, j, 0, 1);
				if (shot)
					ok[len * 2] = false;
				shot = false;
				shoot(i, j, 2, 1);
				if (shot)
					ok[len * 2] = false;

				for (int x = 1; x <= r; x++)
					for (int y = 1; y <= c; y++)
						U[x][y] = used[x][y][0] || used[x][y][1] || used[x][y][2] || used[x][y][3];

				for (int x = 1; x <= r; x++)
					for (int y = 1; y <= c; y++)
						if (U[x][y] && (ch[x][y] == '|' || ch[x][y] == '-') && (x != i || y != j)) {
							ok[len * 2] = false;
						}
				for (int x = 1; x <= r; x++)
					for (int y = 1; y <= c; y++)
						if (U[x][y] && ch[x][y] == '.') {
							pu[x][y].push_back(len * 2);
						}
				
				memset(used, false, sizeof used);
				ok[len * 2 + 1] = true;
				shot = false;
				shoot(i, j, 1, 1);
				if (shot)
					ok[len * 2 + 1] = false;
				shot = false;
				shoot(i, j, 3, 1);
				if (shot)
					ok[len * 2 + 1] = false;

				for (int x = 1; x <= r; x++)
					for (int y = 1; y <= c; y++)
						U[x][y] = used[x][y][0] || used[x][y][1] || used[x][y][2] || used[x][y][3];
				for (int x = 1; x <= r; x++)
					for (int y = 1; y <= c; y++)
						if (U[x][y] && (ch[x][y] == '|' || ch[x][y] == '-') && (x != i || y != j)) {
							ok[len * 2 + 1] = false;
						}
				for (int x = 1; x <= r; x++)
					for (int y = 1; y <= c; y++)
						if (U[x][y] && ch[x][y] == '.') {
							pu[x][y].push_back(len * 2 + 1);
						}
			}
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			if (pu[i][j].size() > 2) {
				// printf("?? %d %d\n", i, j);
				// for (int k = 0; k < (int) pu[i][j].size(); k++)
				// 	printf("%d\n", pu[i][j][k]);
				printf("IMPOSSIBLE\n");
				return ;
			}
	

	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			if (ch[i][j] == '.' && pu[i][j].size() == 1) {
				ok[pu[i][j][0] ^ 1] = false;
			}
	for (int i = 1; i <= len; i++)
		if (!ok[i * 2] && !ok[i * 2 + 1]) {
			printf("IMPOSSIBLE\n");
			return ;
		}
	
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			if (ch[i][j] == '.' && pu[i][j].size() == 0) {
				printf("IMPOSSIBLE\n");
				return ;
			}
	
	if (!SAT()) {
		printf("IMPOSSIBLE\n");
		return ;
	}
	for (int i = 1; i <= len; i++)
		if (ok[i * 2] && ok[i * 2 + 1]) {
			ok[i * 2] = false;
			if (SAT()) {
				continue;
			}else {
				ok[i * 2] = true;
				ok[i * 2 + 1] = false;
			}
		}
	printf("POSSIBLE\n");
	len = 0;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++)
			if (ch[i][j] != '-' && ch[i][j] != '|')
				printf("%c", ch[i][j]);
			else {
				++len;
				if (ok[len * 2])
					printf("|");
				else
					printf("-");
			}
		printf("\n");
	}
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("Case #%d: ", i);
        doit();
    }
}