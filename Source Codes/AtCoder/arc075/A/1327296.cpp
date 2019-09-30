#include <iostream>
#include <vector>

using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, ss = 0;
  vector<int> s;
  cin >> n;
  while (n--){
    int v;
    cin >> v;
    s.push_back(v);
    ss += v;
    
  }
  
  sort(s.begin(), s.end());

  if (ss % 10) {
    cout << ss << endl;
    return 0;
  }
  
  for (int i = 0; i < s.size(); i++) {
    if (s[i] % 10) {
      ss -= s[i];
      break;
    }
  }

  if (ss % 10) {
    cout << ss << endl;
  } else {
    cout << 0 << endl;
  }

  return 0;
}