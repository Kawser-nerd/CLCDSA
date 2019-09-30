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
  int n,k;
  cin >> n >> k;
  if(n%k == 0) {
    cout << 0 << endl;
  } else {
    cout << 1 << endl;
  }
}