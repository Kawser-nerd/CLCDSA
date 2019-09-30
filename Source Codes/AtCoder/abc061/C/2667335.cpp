#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main()
{
  long long int N, K;

  cin >> N >> K;

  vector< pair< int, int > > arr(N);

  for(int i = 0; i < N; i++) {
    cin >> arr[i].first >> arr[i].second;
  }

  sort(arr.begin(), arr.end());

  long long int cnt = 0;
  for(int i = 0; i < N; i++) {
    if(cnt + arr[i].second >= K) {cout << arr[i].first << endl; return 0;}
    cnt += arr[i].second;
  }

  return 0;
}