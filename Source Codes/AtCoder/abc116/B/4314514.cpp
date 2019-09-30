#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1000000;

vector<int> a(MAX_N,0);

int f(int n){
  if(n % 2 == 0) return n / 2;
  else return 3*n + 1;
}

int main(){
  int s,ans;
  cin >> s;
  a[0]=s;

  //init
  for(int i=1;i<=MAX_N;++i){
    a[i] = f(a[i-1]);
  }

  //search
  for(int i=0;i<=MAX_N;++i){
    for(int j=i+1;j<=MAX_N;++j){
      if(a[i] == a[j]) {
        ans = j+1;
        cout << ans << endl;
        return 0;
      }
    }
    }

  return 0;
}