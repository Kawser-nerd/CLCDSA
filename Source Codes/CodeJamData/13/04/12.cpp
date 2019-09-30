#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cstdlib>
#include <algorithm>
using namespace std;

int N;
bool done[200];
vector<int> keys[200];
int chests[200];
int prevArr[200];
map<int, unsigned> have;

int md = 0;
bool possible(const map<int, unsigned>& have) {
  queue<int> q;
  set<int> done2;
  for(int i = 0; i < N; ++i)
    if(have.find(chests[i]) != have.end() && have.find(chests[i])->second > 0 && !done[i] && done2.find(i) == done2.end()) {
      q.push(i);
      done2.insert(i);
    }
  int cnt = 0;
  for(int i = 0; i < N; ++i)
    if(done[i])
      ++cnt;
  while(!q.empty()) {
    int c = q.front(); q.pop();
    if(done[c]) continue;
    //if(done2.find(c) != done2.end()) continue;
    done2.insert(c);
    cnt++;
    for(int i = 0; i < keys[c].size(); ++i) {
      for(int j = 0; j < N; ++j)
	if(chests[j] == keys[c][i] && !done[j] && done2.find(j) == done2.end()) {
	  q.push(j);
	  done2.insert(j);
	}
    }
  }
  /*cerr << "done:";
  for(int i = 0; i < N; ++i)
    if(done[i])
      cerr << ' ' << (i+1);
  cerr << endl << "have:";
  for(const auto v : have)
    cerr << ' ' << v.first << ":" << v.second;
    cerr << endl << cnt << " " << N << endl;*/
  return cnt == N;
}
int st[100];
bool dfs(const map<int, unsigned>& have, unsigned depth) {

  if(depth > md) {
    md = depth;
    //    cerr << md << endl;
  }
  if(depth == N)
    return true;
  if(depth < 10 && !possible(have)) return false;
  int li = -1;
  for(int i = 0; i < N; ++i) {
    if(done[i] || have.find(chests[i]) == have.end() || have.find(chests[i])->second == 0) continue;
    if(prevArr[i] >= 0 && !done[prevArr[i]]) continue;
    if(li >= 0 && chests[i] != li) continue;
    li = chests[i];
    st[depth] = i;
    done[i] = true;
    auto h = have;
    h[chests[i]]--;
    for(int k : keys[i])
      h[k]++;
    if(dfs(h, depth+1)) return true;
    done[i] = false;
  }
  return false;
}
void testcase(int t) {
  md = 0;
  int K;
  cin >> K >> N;
  have.clear();
  map<int, unsigned> count;
  for(int i = 0; i < K; ++i) {
    int k;
    cin >> k;
    have[k]++;
    count[k]++;
  }
  for(int i = 0; i < N; ++i) {
    int t, k;
    cin >> t >> k;
    count[t]--;
    done[i] = false; keys[i].resize(k); chests[i] = t;
    for(int j = 0; j < k; ++j) {
      cin >> keys[i][j];
      count[keys[i][j]]++;
    }
    sort(keys[i].begin(), keys[i].end());
    prevArr[i] = -1;
    for(int j = 0; j < i; ++j) {
      if(chests[i] != chests[j]) continue;
      if(keys[i].size() != keys[j].size()) continue;
      bool b = true;
      for(int k = 0; k < keys[i].size(); ++k)
	if(keys[i][k] != keys[j][k])
	  b = false;
      if(b) prevArr[i] = j;
    }
  }
  bool enoughKeys = true;
  for(auto v : count)
    if(v.second < 0)
      enoughKeys = false;

  if(!possible(have) || !enoughKeys) {
    cout << "Case #" << t << ": IMPOSSIBLE" << endl;
    return;
  }
  //bool d = dfs(have,0);
  //cout << d << endl;
  for(int i = 0; i < 100; ++i)
    done[i] = false;
  vector<int> m;
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      if(!done[j] && have[chests[j]] > 0) {
	auto have2 = have;
	have2[chests[j]]--;
	done[j] = true;
	for(int k : keys[j])
	  have2[k]++;
	if(possible(have2)) {
	  //cerr << ' ' << (j+1) << endl;
	  m.push_back(j);
	  have = have2;
	  break;
	}
	done[j] = false;
      }
    }
    if(m.size() != i+1)
      break;
  }
  if(m.size() != N) {
    cout <<"Case #" << t <<": IMPOSSIBLE" << endl;
    return;
  }
  cout << "Case #" << t <<":";
  for(int i = 0; i < N; ++i)
    cout << ' ' << (m[i] + 1);
  cout << endl;
}

int main() {
  int T;
  cin >> T;
  for(int t = 1; t <= T; ++t)
    testcase(t);
  return 0;
}
