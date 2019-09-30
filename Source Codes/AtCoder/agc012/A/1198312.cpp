#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {

  int N;
  cin >> N;

  vector<int64_t> array(3*N);
  for(int64_t i=0;i<3*N;i++)
    cin >> array[i];

  sort(array.begin(), array.end());

  int64_t ans = 0;
  for(int64_t i=N;i<3*N;i+=2)
    ans += array[i];

  cout << ans << endl;

  return 0;
}