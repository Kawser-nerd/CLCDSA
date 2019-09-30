#include <iostream>
#include <vector>
using namespace std;

int n;
int diag1(int r, int c) {
  return n+r-c-1;
}
int diag2(int r, int c) {
  return r+c;
}

vector<vector<int> > graph;
vector<int> match;
vector<int> revmatch;
vector<bool> visited;

bool augment(int n) {
  if (n == -1)
    return true;
  if (visited[n])
    return false;
  visited[n] = true;
  for (int i=0; i<graph[n].size(); ++i) {
    int j = graph[n][i];
    if (augment(revmatch[j])) {
      match[n] = j;
      revmatch[j] = n;
      return true;
    }
  }
  return false;
}

void bipartiteMatch() {
  match.assign(graph.size(), -1);
  revmatch.assign(graph.size(), -1);
  for (int i=0; i<graph.size(); ++i) {
    if (match[i] == -1) {
      visited.assign(graph.size(), false);
      augment(i);
    }
  }
}

int main() {
  int numCases;
  cin >> numCases;
  for (int testCase=1; testCase<=numCases; ++testCase) {
    cout << "Case #" << testCase << ": ";
    int m;
    cin >> n >> m;
    vector<vector<char> > input(n, vector<char>(n, '.'));
    for (int i=0; i<m; ++i) {
      char s;
      int r,c;
      cin >> s >> r >> c;
      input[r-1][c-1] = s;
    }
    vector<bool> rowmatched(n, false), colmatched(n, false), diag1matched(2*n-1, false), diag2matched(2*n-1, false);
    for (int r=0; r<n; ++r)
      for (int c=0; c<n; ++c) {
        if (input[r][c] == 'x' || input[r][c] == 'o') {
          rowmatched[r] = true;
          colmatched[c] = true;
        }
        if (input[r][c] == '+' || input[r][c] == 'o') {
          diag1matched[diag1(r, c)] = true;
          diag2matched[diag2(r, c)] = true;
        }
      }
    
    vector<vector<char> > ans = input;
    for (int r=0; r<n; ++r)
      for (int c=0; c<n; ++c)
        if (!rowmatched[r] && !colmatched[c]) {
          rowmatched[r] = true;
          colmatched[c] = true;
          if (ans[r][c] == '+')
            ans[r][c] = 'o';
          else
            ans[r][c] = 'x';
        }
    graph.clear();
    graph.resize(2*n-1);
    for (int r=0; r<n; ++r)
      for (int c=0; c<n; ++c) {
        if (!diag1matched[diag1(r,c)] && !diag2matched[diag2(r,c)]) {
          graph[diag1(r,c)].push_back(diag2(r,c));
        }
      }
    bipartiteMatch();
    for (int r=0; r<n; ++r)
      for (int c=0; c<n; ++c)  {
        if (match[diag1(r,c)] == diag2(r,c)) {
          if (ans[r][c] == 'x')
            ans[r][c] = 'o';
          else
            ans[r][c] = '+';
        }
      }
    
    int y=0, z=0;
    for (int r=0; r<n; ++r)
      for (int c=0; c<n; ++c) {
        if (ans[r][c] != input[r][c])
          z++;
        if (ans[r][c] == 'o')
          y+=2;
        else if (ans[r][c] != '.')
          y++;
      }
    cout << y << ' ' << z << endl;
    for (int r=0; r<n; ++r)
      for (int c=0; c<n; ++c) {
        if (ans[r][c] != input[r][c])
          cout << ans[r][c] << ' ' << r+1 << ' ' << c+1 << endl;
      }
  }
}