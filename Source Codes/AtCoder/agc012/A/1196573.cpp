#include<iostream>
#include<vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(3*n);
  for(int i = 0; i < 3*n; i++) {
    cin >> a[i];
  }

  sort(a.begin() , a.end());
  //int init = 3*n/2;
  long long sum = 0;
  int cnt = n;
  for(int i = 3*n - 2; i >= 0; i-= 2) {
    sum += (long long)a[i];
    cnt--;
    if(cnt <= 0) break;
  }
  cout << sum << endl;
}