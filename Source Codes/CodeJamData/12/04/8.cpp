#include <iostream>
#include <cstdlib>

using namespace std;

const int DIM_MAX = 35, D_MAX = 55;
int H, W, D;
int h_scale, w_scale;
int you_x, you_y;

bool base_grid[DIM_MAX][DIM_MAX];
bool nav_info[3][3];


bool direct_reflection(int dx, int dy) {
  int cur_x = you_x, cur_y = you_y;
  int dist = -1;
  while (!base_grid[cur_x][cur_y]) {
    cur_x += dx;
    cur_y += dy;
    dist += 2;
  }
  return (dist <= D);
}

void prepare_nav_info(int x, int y) {
  nav_info[0][0] = base_grid[(x - 1) / h_scale][(y - 1) / w_scale];
  nav_info[0][2] = base_grid[(x - 1) / h_scale][y / w_scale];
  nav_info[2][0] = base_grid[x / h_scale][(y - 1) / w_scale];
  nav_info[2][2] = base_grid[x / h_scale][y / w_scale];
}

bool is_obstacle(int dx, int dy) {
  return nav_info[dx + 1][dy + 1];
}

bool test_dest(int x, int y) {
  //  cout << "Testing " << x << ", " << y << endl;

  int dir_x = (x > 0 ? 1 : -1);
  int dir_y = (y > 0 ? 1 : -1);
  x = abs(x); y = abs(y);

  h_scale = 2 * y; w_scale = 2 * x;
  int start_x = y * (2 * you_x + 1);
  int start_y = x * (2 * you_y + 1);
  int num_steps = h_scale * w_scale / 2;

  int cur_x = start_x, cur_y = start_y;

  for (int i = 0; i < num_steps; i++) {
    //    cout << "(" << cur_x << ", " << cur_y << ")\n";

    if (i > 0 && cur_x == start_x && cur_y == start_y)
      return false;

    // WILL THIS WORK!?!?!
    prepare_nav_info(cur_x, cur_y);
    if (is_obstacle(dir_x, dir_y)) {
      bool obstacle_x = is_obstacle(-dir_x, dir_y);
      bool obstacle_y = is_obstacle(dir_x, -dir_y);
      if ((!obstacle_x) && (!obstacle_y))
	return false;
      if (obstacle_x)
	dir_y = -dir_y;
      if (obstacle_y)
	dir_x = -dir_x;
    }

    cur_x += dir_x; cur_y += dir_y;
  }
  
  return (cur_x == start_x && cur_y == start_y);
}


void solve_case(int case_num) {
  cin >> H >> W >> D;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      char c;
      cin >> c;
      base_grid[i][j] = (c == '#');
      if (c == 'X') {
	you_x = i; you_y = j;
      }
    }
  }

  int num_reflections = 0;
  for (int i = -D_MAX; i <= D_MAX; i++) {
    for (int j = -D_MAX; j <= D_MAX; j++) {
      if (i == 0 || j == 0 || i * i + j * j > D * D)
	continue;
      num_reflections += (test_dest(i, j) ? 1 : 0);
    }
  }
  
  num_reflections += (direct_reflection(0, 1) ? 1 : 0);
  num_reflections += (direct_reflection(0, -1) ? 1 : 0);
  num_reflections += (direct_reflection(1, 0) ? 1 : 0);
  num_reflections += (direct_reflection(-1, 0) ? 1 : 0);

  cout << "Case #" << case_num + 1 << ": " << num_reflections << '\n';
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    solve_case(i);      
  }
}
