#include <iostream>
#include <string>


using namespace std;

using int64 = long long;
bool bit[200001];

int main() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;

  for(int i = 0; i < N; i++) bit[i] = S[i] == 'A';

  int last = N;
  while(K--) {
    while(last >= 2 && bit[last - 1] && !bit[last - 2]) {
      last -= 2;
    }
    if(last == 0) break;
    if(last == 1) K %= 2;
    if(bit[0]) {
      bit[0] = false;
    } else {
      for(int i = 0; i < last; i++) bit[i] = !bit[i + 1];
    }
  }

  for(int i = 0; i < N; i++) cout << "BA"[bit[i]];
  cout << endl;

}