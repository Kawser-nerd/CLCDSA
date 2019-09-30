#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#define INF_INT (INT_MAX / 2)
#define INF_LONG (LONG_MAX / 2)
//#define DEBUG true
#define DEBUG false
#define MAX_N 26
using namespace std;

typedef long long ll;

vector< int > graph[MAX_N];
bool appeared[MAX_N];
int a[MAX_N];

void dfs(int v, bool visited[]){
  if(visited[v]) return;
  visited[v] = true;
  for(int w: graph[v]){
    dfs(w, visited);
  }
}

int number_of_component(){
  bool visited[MAX_N];
  fill(visited, visited + MAX_N, false);
  int count = 0;
  for(int s = 0; s < MAX_N; s++){
    if(appeared[s] && a[s] == -1 && !visited[s]){
      dfs(s, visited);
      ++count;
    }
  }
  return count;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;

  fill(appeared, appeared + MAX_N, false);
  for(int i = 0; i < n; i++){
    if(!isdigit(s1[i])) appeared[s1[i] - 'A'] = true;
    if(!isdigit(s2[i])) appeared[s2[i] - 'A'] = true;
  }

  fill(a, a + MAX_N, -1);

  bool fail = false;
  while(true){
    for(int i = 0; i < n; i++){
      if((isdigit(s1[i]) && isdigit(s2[i])) && s1[i] != s2[i]){
        fail = true;
        break;
      }
    }
    if(fail) break;
    bool updated = false;
    for(int i = 0; i < n; i++){
      if(isdigit(s1[i]) && !isdigit(s2[i])){
        if(a[s2[i] - 'A'] != -1 && a[s2[i] - 'A'] != s1[i]){
          fail = true;
          break;
        }
        a[s2[i] - 'A'] = s1[i];
        updated = true;
      }
      else if(!isdigit(s1[i]) && isdigit(s2[i])){
        if(a[s1[i] - 'A'] != -1 && a[s1[i] - 'A'] != s2[i]){
          fail = true;
          break;
        }
        a[s1[i] - 'A'] = s2[i];
        updated = true;
      }
    }
    if(fail) break;
    for(int i = 0; i < n; i++){
      if(!isdigit(s1[i]) && a[s1[i] - 'A'] != -1) s1[i] = a[s1[i] - 'A'];
      if(!isdigit(s2[i]) && a[s2[i] - 'A'] != -1) s2[i] = a[s2[i] - 'A'];
    }
    if(!updated) break;
  }

  if(fail){
    cout << 0 << endl;
    return 0;
  }

  for(int i = 0; i < n; i++){
    if(!isdigit(s1[i]) && !isdigit(s2[i])){
      graph[s1[i] - 'A'].push_back(s2[i] - 'A');
      graph[s2[i] - 'A'].push_back(s1[i] - 'A');
    }
  }

  int c = number_of_component();
  ll ans = 1;
  for(int i = 0; i < c; i++){
    ans *= 10l;
  }

  if(!isdigit(s1[0]) && !isdigit(s2[0])) ans = (ans / 10l) * 9l;

  cout << ans << endl;

  return 0;
}