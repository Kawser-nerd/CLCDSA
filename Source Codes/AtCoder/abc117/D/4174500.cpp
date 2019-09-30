#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;
using ll = long long int;

ll k;

ll calcBit(ll target)
{
  ll count = 1;
  while(target > 1)
  {
    target /= 2;
    count++;
  }
  return count;
}

ll calcCount(vector<ll> &x, ll offset, ll target)
{
  ll count = 0;
  ll index = 1ll << offset;
  for(ll i = 0; i < x.size(); i++)
  {
    if(x[i] & index)
    {
      count++;
    }
  }
  if(target == 0)
  {
    return x.size() - count;
  }else{
    return count;
  }
}

int main()
{
  ll n;
  cin >> n >> k;
  vector<ll> x(n);
  for(ll i = 0; i < n; i++)
  {
    cin >> x[i];
  }  
  ll maxLen = calcBit(k);
  /*
   * X < K ?????Xi < Ki???i?????
   * Xi+1 ????????
   * ????Ki=1?i????Xi=0??????????????
   * ??????????
   * */
  vector<ll> memoCount(maxLen, 0);
  for(ll i = 0; i < maxLen; i++)
  {
    ll count0 = calcCount(x, i, 0);
    ll count1 = calcCount(x, i, 1);
    //cout << count0 << " " << count1 << endl;
    if(count0 < count1)
    {
      memoCount[i] = 0;
    }else{
      memoCount[i] = 1;
    }
  } 
  ll result = 0;
  for(ll i = 0; i < n; i++)
  {
    result += (k ^ x[i]);
  }
  for(ll i = 0; i < maxLen; i++)
  {
    if(!(k & (1ll << i))) continue;
    /*
     * Ki?0????????
     * Ki=1???
     * Ki=0??X0??Xi-1???memoCount?????
     * ???f???
     * */
    ll tempx = k;
    for(ll j = i; j >= 0; j--)
    {
      if(k & (1ll << j))
      {
        tempx -= 1ll << j;
      }
    }
    for(ll j = 0; j < i; j++)
    {
      tempx += memoCount[j] << j;
    }
    ll temp = 0;
    for(ll i = 0; i < n; i++)
    {
      temp += (tempx^x[i]);
      //cout << (tempx^x[i]) << endl;
    }
    result = max(result, temp);
    //cout << i << " " << tempx << " "<< result << endl;
  }
  cout << result << endl;
}