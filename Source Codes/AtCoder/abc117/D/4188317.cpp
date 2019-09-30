#include <iostream>
#include <algorithm> 
#include <vector>
#include <string>
#include <map>
#include <math.h>
 
using namespace std;
using ll = long long int;
 
ll n, k;
 
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
 
void dfs(vector<vector<ll>> &dp, vector<vector<bool>> &flag, vector<ll> x, ll index, int smaller)
{
  /*
   * ?DP??DFS??
   * smaller=0???k??????
   * samller=1?????????????
   * index???
   */
  //??????????
  //??????dp[index][smaller]?????
  if(flag[index][smaller]) return;
  flag[index][smaller] = true; 
  //0,1???????
  ll count0 = calcCount(x, index, 0);
  ll count1 = calcCount(x, index, 1);
  ll plus0 = count1 << index;
  ll plus1 = count0 << index;
  //index == 0????dfs??????????
  ll result = 0; 
  if(index == 0){
    if(smaller == 0)
    {
      //???????????????????
      if(k & (1ll << index))
      {
        result = max(plus1, plus0);
      }else{
        result = plus0;
      }
    }else{
      //?????plus0?plus1????????
      result = max(plus0, plus1);
    }
    dp[index][smaller] = result;
    //cout << "index = " << index << " smaller = " << smaller << " result = " << result << endl;
    return;
  }
  //????????????????????????????
  dfs(dp, flag, x, index - 1, 0);
  dfs(dp, flag, x, index - 1, 1); 
  //dp??? 
  if(smaller == 0)
  {
    //exactly -> smaller
    //?????????1????smaller????????????????????
    if(k & (1ll << index))
    {
      result = max(result, dp[index - 1][1] + plus0);
    }
    //exactly -> exactly
    //?????????1????exactly????????????????????
    if(k & (1ll << index))
    {
      result = max(result, dp[index - 1][0] + plus1);
    }else{
      result = max(result, dp[index - 1][0] + plus0);
    }
  }else{
    //smaller -> smaller
    //??????????1????smaller?plus0?plus1????????
    result = max(result, dp[index - 1][1] + max(plus0, plus1));
  }
  dp[index][smaller] = result;
  //cout << "index = " << index << " smaller = " << smaller << " result = " << result << endl;
}
 
int main()
{
  cin >> n >> k;
  vector<ll> x(n);
  for(int i = 0; i < n; i++)
  {
    cin >> x[i];
  }
  //??DFS?????????
  ll bits = calcBit(k);
  vector<vector<ll>> dp(41, vector<ll>(2, 0));
  vector<vector<bool>> flag(41, vector<bool>(2, false));
  dfs(dp, flag, x, 40, 0);
  cout << dp[40][0] << endl;
}