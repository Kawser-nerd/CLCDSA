#include <iostream>
using namespace std;
char moji[8][8], stand[8][8];
int h, w;

void dfs(int i, int j) {
  stand[i][j] = 1;
  // right
  if (j + 1 < w) {
    if (moji[i][j + 1] == '#') {
      dfs(i, j + 1);
      return ;
    }
  }
  if (i + 1 < h) {
    if (moji[i + 1][j] == '#') {
      dfs(i + 1, j);
      return;
    }
  }
}

int main () {
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> moji[i][j];
      stand[i][j] = 0;
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (moji[i][j] == '#') {
        // dfs start
        dfs(i, j);
        for (int p = 0; p < h; p++) {
          for (int q = 0; q < w; q++) {
            if (moji[p][q] == '#') {
              if (stand[p][q] == 0) {
                cout << "Impossible" << endl;
                return 0;
              }  
            }
          }
        }
        cout << "Possible" << endl;
        return 0;
      }
    }
  }
}