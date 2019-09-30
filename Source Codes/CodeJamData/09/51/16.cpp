#include <stdio.h>
#include <math.h>
#include <queue>
#include <set>
using namespace std;

struct Box {
	char x, y;
};

struct State {
	int moves;
	Box box[5];
	bool operator<(const State &s) const;
};

struct {
	bool wall[16][16];
	bool goal[16][16];
	char rows, cols;
	int boxCount;
} board;

bool State::operator<(const State &s) const {
	for (int i=0; i<board.boxCount; i++) {
		if (box[i].x!=s.box[i].x)
			return box[i].x<s.box[i].x;
		if (box[i].y!=s.box[i].y)
			return box[i].y<s.box[i].y;
	}
	return false;
}

static bool conn(Box a, Box b) {
	return abs(a.x-b.x)+abs(a.y-b.y)<=1;
}

static bool stable(const State &state) {
	bool found[5] = {false};
	found[0] = true;
	int count = 1;
	bool done;
	do {
		done = true;
		for (int i=0; i<board.boxCount; i++)
			if (found[i])
				for (int j=0; j<board.boxCount; j++)
					if ((!found[j]) && conn(state.box[i], state.box[j])) {
						found[j] = true;
						done = false;
						count++;
					}
	} while (!done);
	return count==board.boxCount;
}

static bool final(const State &state) {
	for (int i=0; i<board.boxCount; i++)
		if (!board.goal[state.box[i].y][state.box[i].x])
			return false;
	return true;
}

static bool checkBounds(int x, int y) {
	return (unsigned int)x<(unsigned int)board.cols &&
		(unsigned int)y<(unsigned int)board.rows;
}

static bool empty(int x, int y, const State &state) {
	if (!checkBounds(x,y) || board.wall[y][x])
		return false;
	for (int i=0; i<board.boxCount; i++)
		if (state.box[i].x==x && state.box[i].y==y)
			return false;
	return true;
}

static bool canMove(Box box, int dx, int dy, const State &state) {
	return empty(box.x+dx, box.y+dy, state) && empty(box.x-dx, box.y-dy, state);
}

queue<State> q;
std::set<State> checked;

const char dx[4] = {1, 0, -1, 0};
const char dy[4] = {0, 1, 0, -1};
static int runTest() {
	int rows, cols;
	scanf("%d%d", &rows, &cols);
	board.rows = (char)rows;
	board.cols = (char)cols;
	char line[16];
	fgets(line, 16, stdin);
	State state;
	board.boxCount = 0;
	for (int y=0; y<rows; y++) {
		fgets(line, 16, stdin);
		for (int x=0; x<cols; x++) {
			board.wall[y][x] = false;
			board.goal[y][x] = false;
			switch (line[x]) {
				case '#': board.wall[y][x] = true; break;
				case 'x': board.goal[y][x] = true; break;
				case 'w': board.goal[y][x] = true;
				case 'o':
					state.box[board.boxCount].x = (char)x;
					state.box[board.boxCount].y = (char)y;
					board.boxCount++;
			}
		}
	}
	while (!q.empty())
		q.pop();
	state.moves = 0;
	q.push(state);
	State newState;
	checked.clear();
	checked.insert(state);
	for (;;) {
		if (q.empty())
			return -1;
		state = q.front();
		if (final(state))
			return state.moves;
		q.pop();
		bool fstable = stable(state);
		for (int i=0; i<board.boxCount; i++)
			for (int dir=0; dir<4; dir++)
				if (canMove(state.box[i], dx[dir], dy[dir], state)) {
					newState = state;
					newState.box[i].x = state.box[i].x+dx[dir];
					newState.box[i].y = state.box[i].y+dy[dir];
					if (fstable || stable(newState)) {
						newState.moves = state.moves+1;
						if (checked.find(newState)==checked.end()) {
							q.push(newState);
							checked.insert(newState);
						}
					}
				}
	}
}

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i=1; i<=t; i++) {
		printf("Case #%d: %d\n", i, runTest());
		fflush(stdout);
	}
	return 0;
}
