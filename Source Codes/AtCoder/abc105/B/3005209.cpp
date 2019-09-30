#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<functional>
#include<cmath>

#define REP(i,n) for(int i=0;i<n;i++)
#define ll long long int

using namespace std;

int to_int(string s) {
  return atoi(s.c_str());
}

int main() {
  int n;
  cin >> n;
  if(n < 4) {
    cout << "No" << endl;
    return 0;
  }
  for(int i = 0; 7*i <= n; i++) {
    if((n-7*i)%4 == 0) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;

}