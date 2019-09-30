#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  int ret=0;
  for(int i=0; i<n; i++){
    int l, r;
    cin >> l >> r;
    ret+=r-l+1;
  }
  cout << ret;
  return 0;
}