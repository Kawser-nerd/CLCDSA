#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
#define QMAX 100010
#define NMAX 100010

int N, Q;
string S;

int main(){
  cin >> N >> Q >> S;
  int a[NMAX] = {};
  for(int i = 0;i < N - 1; ++i){
    a[i+1] = a[i];
    if(S[i]=='A' && S[i+1] == 'C'){
      a[i+1]++;
    }
  }
  for (int i = 0;i < Q; ++i){
    int l, r;
    cin >> l >> r;
    cout << a[r-1] - a[l-1]<< endl;
  }
}