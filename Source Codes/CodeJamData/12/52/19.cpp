#include <iostream>
#include <set>

#define SMAX 6000
#define MMAX 10000

#define TO_INDEX(x, y) ((x) * SMAX + (y))
#define TO_X(index) ((index) / SMAX)
#define TO_Y(index) ((index) % SMAX)

using namespace std;

int p[SMAX * SMAX];
bool b[SMAX * SMAX];

int movex[MMAX];
int movey[MMAX];

int parent(int i) {
  return (i == p[i] ? i : p[i] = parent(p[i]));
}

void merge(int i, int j) {
  p[parent(i)] = j;
}

int s;

bool inbounds(int x, int y) {
  return (x > 0 && y > 0 && x < 2 * s && y < 2 * s && x - y < s && y - x < s);
}

bool inbounds(int i) {
  return inbounds(TO_X(i), TO_Y(i));
}

bool bridge_check() {
  int i1 = TO_INDEX(1, 1);
  int i2 = TO_INDEX(s, 1);
  int i3 = TO_INDEX(1, s);
  int i4 = TO_INDEX(s, 2*s - 1);
  int i5 = TO_INDEX(2 * s - 1, s);
  int i6 = TO_INDEX(2 * s - 1, 2 * s - 1);

  set<int> s;
  int count = 0;
  if (b[i1]) { s.insert(parent(i1)); ++count; }
  if (b[i2]) { s.insert(parent(i2)); ++count; }
  if (b[i3]) { s.insert(parent(i3)); ++count; }
  if (b[i4]) { s.insert(parent(i4)); ++count; }
  if (b[i5]) { s.insert(parent(i5)); ++count; }
  if (b[i6]) { s.insert(parent(i6)); ++count; }

  return (s.size() != count);
}

bool fork_check(int hint) {
  int matching_sides = 0;
  for (int i = 2; i < s; ++i) { // (1, 1) to (s, 1)
    if (b[TO_INDEX(i, 1)] && parent(TO_INDEX(i, 1)) == hint) {
      ++matching_sides; break;
    }
  }

  for (int i = 2; i < s; ++i) { // (1, 1) to (1, s)
    if (b[TO_INDEX(1, i)] && parent(TO_INDEX(1, i)) == hint) {
      ++matching_sides; break;
    }
  }

  for (int i = 1; i < s - 1; ++i) { // (s, 1) to (2s-1, s)
    if (b[TO_INDEX(s + i, 1 + i)] && parent(TO_INDEX(s + i, 1 + i)) == hint) {
      ++matching_sides; break;
    }
  }

  for (int i = 1; i < s - 1; ++i) { // (1, s) to (s, 2s-1)
    if (b[TO_INDEX(1 + i, s + i)] && parent(TO_INDEX(1 + i, s + i)) == hint) {
      ++matching_sides; break;
    }
  }

  for (int i = s + 1; i < 2 * s - 1; ++i) { // (2s-1, s) to (2s-1, 2s-1)
    if (b[TO_INDEX(2 * s - 1, i)] && parent(TO_INDEX(2 * s - 1, i)) == hint) {
      ++matching_sides; break;
    }
  }

  for (int i = s + 1; i < 2 * s - 1; ++i) { // (s, 2s-1) to (2s-1, 2s-1)
    if (b[TO_INDEX(i, 2 * s - 1)] && parent(TO_INDEX(i, 2 * s - 1)) == hint) {
      ++matching_sides; break;
    }
  }

  return matching_sides >= 3;
}

bool ring_check(int curr, int i1, int i2, int i3, int i4, int i5, int i6) {
  if (b[i1]) {
    if (!b[i2]) {
      if (b[i3] && parent(i3) == parent(i1)) {
        if (!b[i4] || !b[i5] || !b[i6]) return true;
      }
      if (b[i4] && parent(i4) == parent(i1)) {
        if (!b[i5] || !b[i6]) return true;
      }
      if (b[i5] && parent(i5) == parent(i1)) {
        if (!b[i6]) return true;
      }
    }
  }
  return false;
}

int main() {
  int t; cin >> t;
  for (int case_num = 1; case_num <= t; ++case_num) {
    int m; cin >> s >> m;

    for (int i = 0; i < 2 * s; ++i) { for (int j = 0; j < 2 * s; ++j) {
      p[TO_INDEX(i, j)] = TO_INDEX(i, j);
      b[TO_INDEX(i, j)] = false;
    } }

    for (int i = 0; i < m; ++i) {
      cin >> movex[i] >> movey[i];
    }

    bool ring = false, bridge = false, fork = false;
    int move = 0;
    for (int i = 0; i < m; ++i) {
      ++move;
      int x = movex[i];
      int y = movey[i];
      int curr = TO_INDEX(x, y);

      b[TO_INDEX(x, y)] = true;

      int i1 = TO_INDEX(x-1, y);
      int i2 = TO_INDEX(x-1, y-1);
      int i3 = TO_INDEX(x, y-1);
      int i4 = TO_INDEX(x+1, y);
      int i5 = TO_INDEX(x+1, y+1);
      int i6 = TO_INDEX(x, y+1);

      ring |= ring_check(curr, i1, i2, i3, i4, i5, i6);
      ring |= ring_check(curr, i2, i3, i4, i5, i6, i1);
      ring |= ring_check(curr, i3, i4, i5, i6, i1, i2);
      ring |= ring_check(curr, i4, i5, i6, i1, i2, i3);
      ring |= ring_check(curr, i5, i6, i1, i2, i3, i4);
      ring |= ring_check(curr, i6, i1, i2, i3, i4, i5);

      if (inbounds(i1) && b[i1]) merge(i1, curr);
      if (inbounds(i2) && b[i2]) merge(i2, curr);
      if (inbounds(i3) && b[i3]) merge(i3, curr);
      if (inbounds(i4) && b[i4]) merge(i4, curr);
      if (inbounds(i5) && b[i5]) merge(i5, curr);
      if (inbounds(i6) && b[i6]) merge(i6, curr);

      bridge = bridge_check();
      fork = fork_check(parent(curr));

      if (ring || bridge || fork) {
        break;
      }
    }

    cout << "Case #" << case_num << ": ";
    if (bridge && fork && ring) {
      cout << "bridge-fork-ring in move " << move;
    }
    else if (fork && ring) {
      cout << "fork-ring in move " << move;
    }
    else if (bridge && ring) {
      cout << "bridge-ring in move " << move;
    }
    else if (bridge && fork) {
      cout << "bridge-fork in move " << move;
    }
    else if (ring) {
      cout << "ring in move " << move;
    }
    else if (fork) {
      cout << "fork in move " << move;
    }
    else if (bridge) {
      cout << "bridge in move " << move;
    }
    else {
      cout << "none";
    }
    cout << endl;
  }
  return 0;
}