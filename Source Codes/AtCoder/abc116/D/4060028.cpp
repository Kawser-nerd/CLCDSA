#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

using ll = long long int;

int main()
{
  int n, k;
  cin >> n >> k;
  vector<pair<ll, int>> sushi(n);
  for(int i = 0; i < n; i++)
  {
    int t;
    ll d;
    cin >> t >> d;
    sushi[i] = {d, t - 1};
  }
  sort(sushi.begin(), sushi.end());
  reverse(sushi.begin(), sushi.end());

  //?????????
  vector<ll> memo_oishi(n + 1, 0);
  vector<int> memo_kind(n, 0);
  
  //k??????
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pqsmall;
  ll total = 0;
  int kind = 0;
  for(int i = 0; i < k; i++)
  {
    pair<ll, int> current = sushi[i];
    if(memo_kind[current.second] == 0)
    {
      kind++;
    }
    memo_kind[current.second]++;
    total += current.first;
    pqsmall.push(current);
  }

  //???priority_queue???
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, less<pair<ll, int>>> pqlarge;
  for(int i = k; i < n; i++)
  {
    pqlarge.push(sushi[i]);
  }

  memo_oishi[kind] = total;


  //N?????????
  for(int i = kind; i < k; i++)
  {
    //pqsmall???????????????????????????
    ll temp = memo_oishi[i];
    ll minus = 0;
    while(true)
    {
      if(pqsmall.empty())
      {
        break;
      }
      pair<ll, int> current = pqsmall.top();
      pqsmall.pop();
      if(memo_kind[current.second] > 1)
      {
        minus = current.first;
        memo_kind[current.second]--;
        break;
      }
    }
    //pqlarge?????????????????????????
    ll plus = 0;
    while(true)
    {
      if(pqlarge.empty())
      {
        break;
      }
      pair<ll, int> current = pqlarge.top();
      pqlarge.pop();
      if(memo_kind[current.second] == 0)
      {
        plus = current.first;
        memo_kind[current.second] = 1;
        break;
      }
    }
    if(minus == 0 || plus == 0) break;
    temp = temp - minus + plus;
    memo_oishi[i + 1] = temp;
  }
  ll max_oishi = 0;
  for(ll i = 0; i < n + 1; i++)
  {
    if(memo_oishi[i] == 0) continue;
    max_oishi = max(max_oishi, memo_oishi[i] + i * i);
  }
  cout << max_oishi << endl;
}