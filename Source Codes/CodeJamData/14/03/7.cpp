// C.cpp

#include <algorithm>
#include <iostream>

using namespace std;

int r, c;
int m, s;

// -1 is click
// 0 is clear
// 1 is bomb
int graph[100][100];

void greed_fill() {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (i == 0 && j ==0) {
        graph[i][j] = -1;
      } else if (i*c + j < s) {
        graph[i][j] = 0;
      } else {
        graph[i][j] = 1;
      }
    }
  }
}

// true on success
bool greed() {
  if (s == 1) {
    greed_fill();
    return true;
  }

  if (c == 1) {
    graph[0][0] = -1;
    for (int i = 1; i < s; ++i) {
      graph[i][0] = 0;
    }
    for (int i = s; i < r; ++i) {
      graph[i][0] = 1;
    }
    return true;
  }

  if (c == 2) {
    if (s % 2 == 1 || s == 2)
      return false;

    greed_fill();
    return true;
  }

  if (c == 3) {
    switch (s) {
      case 2: case 3: case 5: case 7: return false;
    }
    greed_fill();
    if (s % 3 == 1) {
      swap(graph[s / 3][s % 3], graph[s/3 - 1][2]);
    }
    return true;
  }
  // c >= 4
  switch (s) {
    case 2: case 3: case 5: case 7: return false;
  }
  if (s <= 2*c + 1) {
    if (s % 2 == 0) { // even, 2x
      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          if (i < 2 && j < s/2) {
            graph[i][j] = 0;
          } else {
            graph[i][j] = 1;
          }
        }
      }
      graph[0][0] = -1;
    } else { // odd, 2x + 3
      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          if (i < 2 && j < (s-3)/2) {
            graph[i][j] = 0;
          } else if (i == 2 && j < 3) {
            graph[i][j] = 0;
          } else {
            graph[i][j] = 1;
          }
        }
      }
      graph[0][0] = -1;
    }
    return true;
  }
  
  greed_fill();
  if (s % c == 1) {
    swap(graph[s / c][s % c], graph[s/c - 1][c-1]);
  }
  
  return true;
}

void print_graph() {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      switch(graph[i][j]) {
        case -1:
          cout << "c";
          break;
        case 0:
          cout << ".";
          break;
        case 1:
          cout << "*";
          break;
      }
    }
    cout << endl;
  }
}
void flip_graph() {
  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < i; ++j) {
      swap(graph[i][j], graph[j][i]);
    }
  }
}

int main() {
  int t; cin >> t;
  for (int test = 1; test <= t; ++test) {
    cin >> r >> c >> m;
    s = r*c - m;

    bool swapped = false;
    if (r < c) {
      swap(r, c);
      swapped = true;
    }

    cout << "Case #" << test << ":" << endl;

    if (!greed()) {
      cout << "Impossible" << endl;
      continue;
    }
    if (swapped) {
      flip_graph();
      swap(r, c);
    }
    print_graph();
  }
  return 0;
}