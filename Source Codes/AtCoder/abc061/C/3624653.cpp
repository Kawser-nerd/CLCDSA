#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#define ll long long
#define endl '\n'
using namespace std;
ll arr[100001];

int main(void)
{
  cin.tie(NULL); ios_base::sync_with_stdio(false);

  ll N, K; cin >> N >> K;
  while(N--)
    {
      ll a, b; cin >> a >> b;
      arr[a] += b;
    }
  ll acc = 0;
  for(int i = 1; i <= 100000; i++)
    {
      acc += arr[i];
      if(acc >= K)
	{
	  cout << i << endl;
	  return 0;
	}
    }
  
  
  return 0;
}