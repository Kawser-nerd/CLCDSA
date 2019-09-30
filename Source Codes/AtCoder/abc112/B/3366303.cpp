#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
  int N, T; cin >> N >> T;
  vector<int> c(N), t(N);
  for (int i = 0; i <N; ++i){
    cin >> c[i] >> t[i];
  }
  vector<int> filtered_c;
  for(int i = 0;i < N; ++i){
    if (t[i] <=T){
      filtered_c.push_back(c[i]);
    }
  }
  if(filtered_c.size() == 0){
    cout << "TLE" << endl;
  }
  else {
    cout << *min_element(filtered_c.begin(), filtered_c.end()) << endl;
  }
}