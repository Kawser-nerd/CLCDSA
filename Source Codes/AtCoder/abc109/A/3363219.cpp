#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <functional>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define v_exists(elem, v) find(v.begin(),v.end(),elem)!=v.end()

using namespace std;

int main(){
  int A,B;
  cin >> A;
  cin >> B;

  if(A%2==1 && B%2==1){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}