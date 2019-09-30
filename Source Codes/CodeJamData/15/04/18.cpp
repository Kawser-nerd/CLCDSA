#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct polynomio
{
	vector<pair<int,int>> poses;

	polynomio() {}
	polynomio(vector<pair<int,int>> poses) : poses(poses){ }

	void normalize() {
		if (poses.empty()) return;
		sort(poses.begin(), poses.end());
		poses.resize(unique(poses.begin(), poses.end()) - poses.begin());

		auto m = *min_element(poses.begin(),poses.end());
		for (auto &val : poses)
		{
			val.first -= m.first;
			val.second -= m.second;
		}
		auto nposes = poses;
		for (int flip = 0; flip < 2; flip++) {
			for (int rot = 0; rot < 4; rot++) {
				for (auto &val : nposes) {
					val = make_pair(val.second, -val.first);
				}
				sort(nposes.begin(), nposes.end());
				auto m = *min_element(nposes.begin(), nposes.end());
				for (auto &val : nposes)
				{
					val.first -= m.first;
					val.second -= m.second;
				}

				if (poses > nposes)
					poses = nposes;
			}
			for (auto &val : nposes) {
				val = make_pair(val.first, -val.second);
			}
		}
	}

	bool operator <(const polynomio &other) const {
		return poses < other.poses;
	}
};

set<polynomio> polynomios[7];

int floodfill(vector<vector<int>> &board, int r, int c)
{
	if (r < 0 || r >= board.size() || c < 0 || c >= board[r].size()) return 0;
	if (board[r][c]) return 0;
	int cnt = 1;
	board[r][c] = 1;
	cnt += floodfill(board,r+1,c);
	cnt += floodfill(board,r-1,c);
	cnt += floodfill(board,r,c+1);
	cnt += floodfill(board,r,c-1);
	return cnt;
}

bool can_fill(vector<vector<int>> &board, polynomio p, int x, int r, int c)
{
	for (int dr = 0; dr < r; dr++) {
		for (int dc = 0; dc < c; dc++) {
			bool fail = false;
			for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) board[i][j] = 0;
			for (auto pos : p.poses) {
				if (pos.first + dr < 0 || pos.first + dr >= r) {
					fail = true;
					break;
				}
				if (pos.second + dc < 0 || pos.second + dc >= c) {
					fail = true;
					break;
				}
				board[pos.first + dr][pos.second + dc] = 1;
			}
			if (fail) continue;
			for (int i = 0; i < r;i++) {
				for (int j = 0; j < c; j++) {
					if (board[i][j] != 1) {
						auto area = floodfill(board, i, j);
						if (area % x) {
							fail = true;
							break;
						}
					}
				}
				if (fail) break;
			}
			if (fail) continue;

			return true;
		}
	}
	return false;
}

int solve(int x, int r, int c)
{
	if (x >= 7) return 0;
	if (r*c%x) return 0;
	vector<vector<int>> board(r, vector<int>(c));
	for (auto p : polynomios[x]) {
		bool richard_will_select = true;
		for (int flip = 0; flip < 2; flip++) {
			for (int rotation = 0; rotation < 4; rotation++) {
				if (can_fill(board, p, x, r, c)) {
					richard_will_select = false;
					break;
				}
				for (auto &pos : p.poses)
					pos = make_pair(pos.second, -pos.first);
			}
			if (!richard_will_select) break;
			for (auto &pos : p.poses)
				pos = make_pair(pos.first, -pos.second);
		}
		if (richard_will_select)
			return 0;
	}
	return 1;
}

const int dir[4][2] = {0,1,0,-1,1,0,-1,0};
void build(polynomio p)
{
	p.normalize();
	if (!polynomios[p.poses.size()].insert(p).second)
		return;
	if (p.poses.size() >= 6)
		return;
	for (auto pos : p.poses)
	{
		for (int d = 0; d < 4; d++) {
			polynomio np(p);
			np.poses.push_back(make_pair(pos.first + dir[d][0], pos.second + dir[d][1]));
			build(np);
		}
	}
}

int main(){
	build(vector<pair<int,int>>(1));
	int T;
	scanf("%d",&T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		int x,r,c;
		scanf("%d%d%d",&x,&r,&c);
		printf("Case #%d: %s\n", testcase, solve(x,r,c) ? "GABRIEL" : "RICHARD");
	}
	return 0;
}