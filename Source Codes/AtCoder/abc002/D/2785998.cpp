#include <iostream>
#include <vector>
#include <utility>

using namespace std;

bool is_habatsu(const int n, vector<int> h,const vector< pair<int, int> > &a) {

  for(auto member: h) {
    bool ok = false;
    for(auto l: a) {
      if(l.first == member || l.second == member) {
        if(l.first == n || l.second == n) {
          ok = true;
          break;
        }
      }
    }
    if(ok == false) return false;
  }

  return true;
}

int main() {
  int N, M;
  cin >> N >> M;
  if(M == 0) {
    cout << 1 << endl;
    return 0;
  }
  vector<pair<int, int> > a(M);

  for(auto& x: a) {
    cin >> x.first >> x.second;
  }

  sort(a.begin(), a.end());

  vector< vector<int> > habatsu;

  for(int i = 0; i < M; i++) {
    bool exist = false;
    for(auto ha: habatsu) {
      bool f,s;
      f = s = false;
     for(auto hh: ha) {
        if(hh == a[i].first) {
          f = true;
        }
        if(hh == a[i].second) {
          s = true;
        }
      }
      if(f == true && s == true) {
        exist = true;
        break;
      }
    }
    if(exist) continue;

    //?????
    vector<int> h = {a[i].first, a[i].second};
    for(int mem = 1; mem <= N; mem++) {
      for(auto hh: h) {
        if(hh == mem) goto next_mem;
      }
      if(is_habatsu(mem, h, a)) {
        h.push_back(mem);
        mem = 1;
      }
    next_mem:
      ;
    }
    habatsu.push_back(h);
  }

  //created habatsu
  sort(habatsu.begin(), habatsu.end(), [](const vector<int> &first, const vector<int> &second){return first.size() > second.size();});

  cout << habatsu[0].size() << endl;
}