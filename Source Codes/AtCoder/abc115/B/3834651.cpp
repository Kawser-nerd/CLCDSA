#include<iostream>
using namespace std;

int main() {
  int N = 0;
  cin >> N;
  
  int pi[N];
  int max = 0;
  for (int i = 0; i < N; i++) {
  	int p = 0;
    cin >> p;
    if (max < p) {
      max = p;
    }
    pi[i] = p;
  }
  
  int sum = 0;
  bool f = true;
  for (int p: pi) {
    if (p == max && f) {
      sum += p / 2;
      f = false;
    } else {
      sum += p;
    }
  }
  
  cout << sum << endl;
  
  return 0;
}