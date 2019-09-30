#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> build_fail(const string &s){
  vector<int> fail(s.size()+1);
  int j = fail[0] = -1;
  for(int i=1;i<=(int)s.size();i++){
    while(j>=0&&s[j]!=s[i-1])j=fail[j];
    fail[i]=++j;
  }
  return fail;
}
string w;
int main() {
  cin >> w;
  vector<int> fail_w = build_fail(w);
  if(w == string(w.size(), w[0])) {
    cout << w.size() << endl;
    cout << 1 << endl;
    return 0;
  }
  string rev_w = w;
  reverse(rev_w.begin(), rev_w.end());
  vector<int> fail_rev_w = build_fail(rev_w);
  if(w.size() - fail_w[w.size()] == w.size() || w.size() % (w.size() - fail_w[w.size()]) != 0) {
    cout << 1 << endl;
    cout << 1 << endl;
  }else{
    cout << 2 << endl;
    int answer = 0;
    for(int i = 1; i < w.size(); i++) {
      int revi = w.size() - i;
      if(i - fail_w[i] == i || i % (i - fail_w[i]) != 0) {
        if(revi - fail_rev_w[revi] == revi || revi % (revi - fail_rev_w[revi]) != 0) {
          answer++;
        }
      }
    }
    cout << answer << endl;
  }
}