#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
bool is_even(T const& val){
  return val % 2 == 0;
}
template<typename T>
bool is_odd(T const& val){
  return !is_even(val);
}

int main(void)
{
  int N, M;
  cin >> N >> M;
  vector<int> verts(N+1);
  for(int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    verts[a]++;
    verts[b]++;
  }
  if(count_if(verts.begin(), verts.end(), &is_odd<int>) > 0) cout << "NO";
  else cout << "YES";
  cout << endl;

  return 0;
}