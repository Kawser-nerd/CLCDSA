#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int N;
  cin>>N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  map<int, int> a_all;
  for (int i = 0; i < N; i++) {
    a_all[a[i]]++;
    a_all[a[i] + 1]++;
    a_all[a[i] - 1]++;
  }
  int ans=0;
  for (auto itr = a_all.begin(); itr != a_all.end(); ++itr) {
    if(ans<itr->second){
      ans=itr->second;
    }
  }
  cout<<ans<<endl;

  return 0;
}