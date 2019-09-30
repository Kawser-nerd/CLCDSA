#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;

int main()
{
  int n, q;
  cin >> n >> q;
  using P = pair<int, int>;
  vector<P> query(q);
  for(int i = 0; i < q; i++)
  {
    int l, r;
    cin >> l >> r;
    query[i] = {l - 1, r};
  }
  vector<int> result(n + 1, 0);
  for(int i = 0; i < q; i++)
  {
    int l = query[i].first;
    int r = query[i].second;
    if(result[l] == 0)
    {
      result[l] = 1;
    }else{
      result[l] = 0;
    }
    if(result[r] == 0)
    {
      result[r] = 1;
    }else{
      result[r] = 0;
    }
  } 
  bool flag = true;
  for(int i = 0; i < n; i++)
  {
    if(result[i] == 1)
    { 
      flag = !flag;
    }
    if(flag)
    {
      cout << 0;
    }else{
      cout << 1;
    } 
  }
  cout << endl;
	return 0;
}