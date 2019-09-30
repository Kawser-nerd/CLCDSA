// ?????????
// K????????????A?K???????????????B???
// A -> B -> A -> B -> ... ?????????????
// ???A?????B -> A??????????
// B???????????????K?????A?????????K???????
// ???????????


#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iomanip>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair
#define mt make_tuple

using P = pair<int,int>;

int H, W, K;
vector<string> cells;
vector<vector<int>> reach;
const int MAX = 10000;

bool within_board(int w, int h) {
	return (0 <= w && w < W && 0 <= h && h < H);
}

void debug_print_reach(){
    cout << endl;
    REP(h,H) {
        REP(w,W) {
            cout << reach[h][w] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int dh[4] = { 1, -1, 0, 0 };
int dw[4] = { 0, 0, 1, -1 };
void fill_room(P start, int turn) {
	set<P> poses{ start };
	REP(k, K) {
		set<P> new_poses;
        for (auto& pos: poses) {
            auto w = pos.first;
            auto h = pos.second;
            REP(d, 4) {
                auto w2 = w + dw[d];
                auto h2 = h + dh[d];
				if (within_board(w2, h2)
                    && cells[h2][w2] != '#'
                    && reach[h2][w2] > k) {
                    new_poses.insert(P(w2,h2));
                    reach[h2][w2] = k;
                }
            }
        }
        poses = new_poses;
    }
}

int main(void)
{
    cin.sync_with_stdio(false);
    cin >> H >> W >> K;
    cells.resize(H);
    reach.resize(H);
	P start;
    REP(h,H) {
        cin >> cells[h];
        reach[h].resize(W, MAX);
        auto loc = cells[h].find('S');
        if (loc != string::npos) {
            start = mp(loc, h);
            reach[h][loc] = 0;
            cells[h][loc] = '.';
        }
    }

	fill_room(start, 0);
    // debug_print_reach();

    int min_dist = 1e9;
    REP(h,H) {
        REP(w,W) {
            if (reach[h][w] < MAX) {
                auto dist = min(w, min(h, min(W-1-w, H-1-h)));
                min_dist = min(min_dist, dist);
            }
        }
    }


    cout << ((min_dist + K - 1) / K) + 1 << endl;
    return 0;
}