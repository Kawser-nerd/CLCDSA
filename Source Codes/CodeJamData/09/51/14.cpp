#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <numeric>
#include <complex>

using namespace std;

set < vector <short> > states;
queue < vector <short> > q_states;
queue <int> q_moves;
queue <bool> q_dangerous;
int n;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

void push(const vector <short> &state, int moves, bool danger) {
  if (states.find(state) == states.end()) {
    states.insert(state);
    q_states.push(state);
    q_moves.push(moves);
    q_dangerous.push(danger);
  }
}

char visited[16][16];

bool check_danger(const vector <short> &state, int i, int j) {
  queue <int> qx, qy; qx.push(i); qy.push(j);
  memset(visited, 0, sizeof(visited));
  visited[i][j] = 1;
  int num = 0;
  while (!qx.empty()) {
    int x = qx.front(), y = qy.front(); qx.pop(); qy.pop();
    num++;
    for (int k = 0; k < 4; k++)
      if ((state[x+dx[k]]>>(y+dy[k]))&1)
	if (!visited[x+dx[k]][y+dy[k]]) {
	  visited[x+dx[k]][y+dy[k]] = 1;
	  qx.push(x+dx[k]); qy.push(y+dy[k]);
	}
  }
  return num != n;
}

void print_state(const vector <short> &state, int R, int C) {
  for (int i = 0; i <= R+1; i++) {
    for (int j = 0; j <= C+1; j++) {
      if ((state[i]>>j)&1)
	cout << 'o';
      else
	cout << '.';
    }
    cout << endl;
  }
  cout << endl;
}

int main(void)
{
  int T; cin >> T;
  for (int c = 1; c <= T; c++) {
    int R, C; cin >> R >> C;
    vector <string> board(R+2);
    vector <short> start(R+2), end(R+2), walls(R+2);
    walls[0] = walls[R+1] = -1;
    n = 0;
    for (int i = 1; i <= R; i++) {
      cin >> board[i];
      walls[i] |= 1|(1<<(C+1));
      for (int j = 1; j <= C; j++) {
	if (board[i][j-1] == '#')
	  walls[i] |= 1<<j;
	else if (board[i][j-1] == 'x') {
	  end[i] |= 1<<j;
	  n++;
	}
	else if (board[i][j-1] == 'o')
	  start[i] |= 1<<j;
	else if (board[i][j-1] == 'w') {
	  start[i] |= 1<<j;
	  end[i] |= 1<<j;
	  n++;
	}
      }
    }
    states.clear(); states.insert(start);
    q_states = queue < vector <short> > (); q_states.push(start);
    q_moves = queue <int> (); q_moves.push(0);
    q_dangerous = queue <bool> (); q_dangerous.push(false);
    int ans = -1;
    while (!q_states.empty()) {
      vector <short> state = q_states.front(); q_states.pop();
      int moves = q_moves.front(); q_moves.pop();
      bool dangerous = q_dangerous.front(); q_dangerous.pop();
      //print_state(state, R, C);
      if (state == end) {
	ans = moves;
	break;
      }
      for (int i = 1; i <= R; i++)
	for (int j = 1; j <= C; j++) {
	  if ((state[i]>>j)&1) {
	    for (int k = 0; k < 2; k++) {
	      int i_behind = i-dx[k], j_behind = j-dy[k];
	      int i_ahead = i+dx[k], j_ahead = j+dy[k];
	      if ((((state[i_behind]|walls[i_behind])>>j_behind)&1) == 0 &&
		  (((state[i_ahead]|walls[i_ahead])>>j_ahead)&1) == 0) {
		if (!dangerous) {
		  state[i] ^= 1<<j;
		  state[i_behind] ^= 1<<j_behind;
		  bool danger2 = check_danger(state, i_behind, j_behind);
		  push(state, moves+1, danger2);
		  
		  state[i_behind] ^= 1<<j_behind;
		  state[i_ahead] ^= 1<<j_ahead;
		  danger2 = check_danger(state, i_ahead, j_ahead);
		  push(state, moves+1, danger2);

		  state[i_ahead] ^= 1<<j_ahead;
		  state[i] ^= 1<<j;
		}
		else {
		  state[i] ^= 1<<j;
		  state[i_behind] ^= 1<<j_behind;
		  bool danger2 = check_danger(state, i_behind, j_behind);
		  if (!danger2) push(state, moves+1, danger2);
		  
		  state[i_behind] ^= 1<<j_behind;
		  state[i_ahead] ^= 1<<j_ahead;
		  danger2 = check_danger(state, i_ahead, j_ahead);
		  if (!danger2) push(state, moves+1, danger2);

		  state[i_ahead] ^= 1<<j_ahead;
		  state[i] ^= 1<<j;
		}
	      }
	    }
	  }
	}
    }
    printf("Case #%d: %d\n", c, ans);
  }
  return 0;
}
