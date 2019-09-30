#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){

  int A, B, K;
  cin >> A >> B >> K;

  int cnt = 0; //?????????
  for (int i = min(A, B); i >= 1; i--){
    if (A % i == 0 && B % i ==0){
      cnt++;  //cnt?1???
      if (cnt == K){
        cout << i << endl;
        return 0;
      }
    }
  }
}