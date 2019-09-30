/*
ID: Plagapong
LANG: C++
TASK: kingdom
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#define INF 999999999
#define TOOBAD "Too Bad"

using namespace std;
int n;
struct Level {
  int a, b;
} levels[1005];
int conquered[1005];

bool comparez (Level i, Level j) {
  if (i.b == j.b) return i.a < j.a;
  return i.b < j.b;
}

void preprocess() {
  // Preprocess
  
}

void clearVars() {
  // Clear variables

}

void process() {
  // Code here!
  int garbage = scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    garbage = scanf("%d%d", &levels[i].a, &levels[i].b);
    conquered[i] = 0;
  }
  sort(levels, levels + n, comparez);
  // Try greedy
  int stars = 0, now = 0, noobcnt = 0;
  while (now < n) {
    // Check if can defeat now
    while (levels[now].b > stars) {
      int i;
      for (i = n-1; i >= now; i--) {
        if (!conquered[i] && levels[i].a <= stars) {
          conquered[i] = 1;
          noobcnt++;
          stars++;
          break;
        }
      }
      if (i < now) {
        printf(TOOBAD);
        return;
      }
    }
    if (conquered[now]) {
      stars += 1;
    } else {
      stars += 2;
    }
    conquered[now] = 1;
    now += 1;
  }
  printf("%d", noobcnt + n);
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
