#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 1000 + 10;
const int px[4] = {1, 0, -1, 0};
const int py[4] = {0, 1, 0, -1};

char field[size][size];
bool good[size][size][4];
int dirs[256];
int tc, n, m;

bool onfield(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> tc;
    for (int tnum = 0; tnum < tc; tnum++) {
    	cin >> n >> m;
    	for (int i = 0; i < n; i++)
    		cin >> field[i];

    	for (int i = 0; i < n; i++)
    		for (int j = 0; j < m; j++) {
    			if (field[i][j] != '.') {
    				for (int k = 0; k < 4; k++) {
    					good[i][j][k] = false;
    					int cx = i + px[k];
    					int cy = j + py[k];
    					while (onfield(cx, cy)) {
    						if (field[cx][cy] != '.') {
    							good[i][j][k] = true;
    							break;
    						}
    						cx += px[k];
    						cy += py[k];
    					}
    				}
    			}	
    		}

    	bool flag = true;
    	int ans = 0;

    	for (int i = 0; i < n; i++)
    		for (int j = 0; j < m; j++)
    			if (field[i][j] != '.') {
    				if (!flag)
    					continue;
    				int d;
    				if (field[i][j] == 'v')
    					d = 0;
    				if (field[i][j] == '>')
    					d = 1;
    				if (field[i][j] == '^')
    					d = 2;
    				if (field[i][j] == '<')
    					d = 3;

    				if (!good[i][j][d]) {
    					flag = false;
    					for (int p = 0; p < 4; p++)
    						if (good[i][j][p]) {
    							ans++;
    							flag = true;
    							break;
    						} 
    				}
    			}

    	if (flag)
    		printf("Case #%d: %d\n", tnum + 1, ans);
    	else
    		printf("Case #%d: IMPOSSIBLE\n", tnum + 1); 
    }

    return 0;
}