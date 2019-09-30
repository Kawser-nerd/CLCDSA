#include <stdio.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 999999999
using namespace std;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int main(void){
	int h, w;
	int can_paint_sharp = 0;
	int sharp_cnt = 0;
	int nx, ny;
	cin >> h >> w;
	char v[h][w];
	REP(i, h){
		REP(j, w){
			cin >> v[i][j];
			if(v[i][j] == '#'){
				sharp_cnt += 1;
			}
		}
	}

	REP(i, h){
		REP(j, w){
			int nx = i;
			int ny = j;
			REP(p, 4){
				int tx = nx + dx[p];
				int ty = ny + dy[p];
				if(v[nx][ny] == '#' && v[tx][ty] == '#'){
					can_paint_sharp += 1;
					break;
				}
			}
		}
	}
	if(can_paint_sharp >= sharp_cnt) cout << "Yes" << "\n";
	else cout << "No" << "\n";


}