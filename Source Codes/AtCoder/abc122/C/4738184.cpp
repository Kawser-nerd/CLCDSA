//https://atcoder.jp/contests/abc122/tasks/abc122_c
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  int N,Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  int t[N+1];
  t[0] = 0;
  for(int i=0; i<N; i++){
    t[i+1] = t[i] + ((S[i] == 'A'&&S[i+1]=='C') ? 1:0);
  }

  for (int i=0; i<Q; i++){
    int l,r;
    cin >> l >> r;
    cout << t[r-1]-t[l-1] << endl;
  }

  return 0;
}