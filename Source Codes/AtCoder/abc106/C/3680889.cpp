#include<iostream>
#include<string>

using namespace std;

int main() {
  string S;
  int K;
  cin >> S;
  cin >> K;
  if(S[0] == '1') {
    int cnt = 1;
    while(cnt < K) {
      if (S[cnt] != '1') {
        cout << S[cnt] << endl;
        exit(0);
      }
      cnt++;
    }
    cout << S[cnt-1] << endl;
    exit(0);
  } else {
    cout << S[0];
  }
  return 0;
}