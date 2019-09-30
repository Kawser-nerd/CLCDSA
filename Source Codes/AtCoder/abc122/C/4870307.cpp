#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main(int argc, char const *argv[]) {
  string S;
  int N, Q;
  cin >> N >> Q;
  cin >> S;
  int count[N];
  count[0] = 0;
  vector<int> num(0);
  for(int i=1;i<N;i++){
    int add = 0;
    if(S[i] == 'C' && S[i-1] == 'A') add = 1;
    count[i] = count[i-1] + add;
  }
  for(int i=0;i<Q;i++){
    int l, r;
    cin >> l >> r;
    std::cout << count[r-1] - count[l-1] << '\n';
  }
  return 0;
}