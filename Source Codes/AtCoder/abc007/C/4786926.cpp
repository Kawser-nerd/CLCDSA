#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<map>

#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i,a,b) for (ll i=(a);i<(ll)b; i++)

typedef long long ll;

using namespace std;

int main(void) {
	int R, C;
	cin >> R >> C;

	int sy, sx, gy, gx;
	cin >> sx >> sy;
	cin >> gx >> gy;

	vector<vector<int>> Map(R);
	REP(i, R) {
		Map[i].resize(C);
		string str;
		cin >> str;
		REP(j, C) {
			Map[i][j] = (str[j] == '.' ? 0 : 1);
		}
	}

	Map[gx - 1][gy - 1] = 2; //Goal

	class Coord
	{
	public:
		int x, y;
		Coord(int x_, int y_) { x = x_; y = y_; };
		string ToString() {
			return x + ":" + y;
		}
	};

	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { -1,0,1,0 };

	vector<Coord> taiki;
	taiki.push_back(Coord(sx - 1, sy - 1));

	int res;
	for (res = 0;; res++) {
		vector<Coord> Newtaiki;
		for (int ind = 0; ind < taiki.size(); ind++) {
			Map[taiki[ind].x][taiki[ind].y] = 3; //?????
		}
		for (int ind = 0; ind < taiki.size(); ind++) {
			for (int dir = 0; dir < 4; dir++) {
				int x = taiki[ind].x + dx[dir];
				int y = taiki[ind].y + dy[dir];
				int d = Map[x][y];
				switch (d)
				{
				case 0: //???????
					Newtaiki.push_back(Coord(taiki[ind].x + dx[dir], taiki[ind].y + dy[dir]));
					Map[taiki[ind].x + dx[dir]][taiki[ind].y + dy[dir]] = 3;
					break;
				case 1: //????????
					break;
				case 2: //Goal!!
					goto ProgramEndPointLabel;
					break;
				case 3: //?????????
					break;
				default:
					break;
				}
			}
		}
		/*
		REP(i, R) {
			REP(j, C) {
				printf("%d", Map[i][j]);
			}
			printf("\n");
		}

		printf("\n");
		printf("%d\n", Newtaiki.size());
		*/
		//system("pause");

		taiki = Newtaiki;
	}

ProgramEndPointLabel:;

	cout << res + 1 << endl;

	system("pause");

	return 0;
} ./Main.cpp:42:13: warning: adding 'int' to a string does not append to the string [-Wstring-plus-int]
                        return x + ":" + y;
                               ~~^~~~~
./Main.cpp:42:13: note: use array indexing to silence this warning
1 warning generated.