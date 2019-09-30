/*
ID: Plagapong
LANG: C++
TASK: cruise
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<set>
#define INF 999999999
#define POS "Possible"
#define ABSS(X) ((X) > 0 ? (X) : (-(X)))
#define MINN(X,Y) ((X) > (Y) ? (Y) : (X))
#define MAXX(X,Y) ((X) < (Y) ? (Y) : (X))

using namespace std;
int n;
int side[505], speed[505], pos[505];

struct FTime {
  double time;
  bool isMax;
  int c1, c2;
} ftimes[5100];
int top;

int state[505];
int magic;

set<int> e[505];

bool comparez(FTime f1, FTime f2) {
  if (f1.time == f2.time) return f1.isMax > f2.isMax;
  return f1.time < f2.time;
}

void preprocess() {
  // Preprocess
  
}

void clearVars() {
  // Clear variables
  for (int i = 0; i < 55; i++) {
    e[i].clear();
  }
  magic = 10;
}

void process() {
  // Code here!
  int garbage = scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    char temp[10];
    garbage = scanf("%s%d%d", temp, &speed[i], &pos[i]);
    side[i] = (temp[0] == 'L' ? -1 : 1);
  }
  // Compute f*** up time
  top = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (speed[i] != speed[j]) {
        double temp = (pos[i] - pos[j]) * 1.0 / (speed[i] - speed[j]);
        double ftmin = - 5.0 / ABSS(speed[i] - speed[j]) - temp;
        if (ftmin >= 0) {
          ftimes[top].time = ftmin;
          ftimes[top].isMax = false;
          ftimes[top].c1 = i;
          ftimes[top].c2 = j;
          top++;
        }
        double ftmax = 5.0 / ABSS(speed[i] - speed[j]) - temp;
        if (ftmax >= 0) {
          ftimes[top].time = ftmax;
          ftimes[top].isMax = true;
          ftimes[top].c1 = i;
          ftimes[top].c2 = j;
          top++;
        }
      }
    }
  }
  // Sort f*** up times
  sort(ftimes, ftimes + top, comparez);
  /*
  for (int i = 0; i < top; i++) {
    printf("%lf %d %d %d\n", ftimes[i].time, ftimes[i].isMax, ftimes[i].c1, ftimes[i].c2);
  }
  */

  // Populate graph
  for (int i = 0; i < n; i++) {
    state[i] = magic++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (ABSS(pos[i] - pos[j]) < 5) {
        state[i] = side[i];
        state[j] = side[j];
        e[i].insert(j);
        e[j].insert(i);
      }
    }
  }
  /*
  for (int i = 0; i < n; i++) {
    printf("%d ", state[i]);
  }
  */
  
  // Traverse f*** up times
  for (int tt = 0; tt < top; tt++) {
    double time = ftimes[tt].time;
    bool isMax = ftimes[tt].isMax;
    int i = ftimes[tt].c1;
    int j = ftimes[tt].c2;
    
    if (not isMax) {
      if (state[i] == state[j]) {
        printf("%.10lf", time);
        return;
      }
      e[i].insert(j);
      e[j].insert(i);
      // Set them to be opposite!
      int uguu = state[i], nipaa = state[j];
      for (int k = 0; k < n; k++) {
        if (state[k] == uguu) {
          state[k] = -nipaa;
        } else if (state[k] == -uguu) {
          state[k] = nipaa;
        }
      }
    } else {
      e[i].erase(j);
      e[j].erase(i);
      if (e[i].empty()) {
        state[i] = magic++;
      }
      if (e[j].empty()) {
        state[j] = magic++;
      }
    }
  }

  // Survive!
  printf(POS);
}

int main() {
  preprocess();
  int times;
  cin >> times;
  for (int i = 1; i <= times; i++) {
	cout << "Case #" << i << ": ";
	clearVars();
	process();
	cout << endl;
  }
  return 0;
}
