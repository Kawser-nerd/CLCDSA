#include <iostream>
#include <ccomplex>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>
#include <string>
#include <deque>
#include <queue>
#include <functional>
#include <cmath>
#include <iomanip>
#include <map>
#include <numeric>
#include <list>
#include <assert.h>
#include <math.h>
#include <valarray>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <complex>
#include <list>
#include <time.h>
#include <stack>
#include <locale>
#include <clocale>
#include <ctype.h>
#include <wchar.h>
#include <random>
#include <vector>
#include <unordered_map>
#include <bitset>

using namespace std;
typedef long long int LL;
typedef long long int ll;
typedef pair<long long int, long long int> pii;
typedef pair<double, double> pdd;

#define SORT(c) sort((c).begin(),(c).end())
#define BACKSORT(c) sort((c).begin(),(c).end(),std::greater<LL>())
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N, M;
  cin >> N >> M;

  vector<LL> v(N, 0);
  vector<vector<LL>> g(N);
  REP(i, M)
  {
    LL a, b;
    cin >> a >> b;
    a--;b--;
    v[a]++;
    v[b]++;

    g[a].push_back(b);
    g[b].push_back(a);
  }

  if(N+2<=M){
    bool flag = true;
    REP(i, v.size())
    {
      if(v[i]%2!=0){
        flag = false;
      }
    }
    if(flag){
      LL cnt = 0;
      REP(i, v.size())
      {
        if(v[i]>=4){
          cnt++;
        }
        if(v[i]>=6){
          cnt += 3;
        }
      }
      if(cnt>=3){
        cout << "Yes" << endl;
      }else
      if(cnt<=1){
        cout << "No" << endl;
      }else{
        LL start = -1;
        LL goal = -1;
        REP(i, v.size())
        {
          if(v[i]==4){
            if(start==-1){
              start = i;
            }else{
              goal = i;
            }
          }
        }
        bool flag = false;
        REP(i, g[start].size())
        {
          LL old = start;
          LL now = g[start][i];
          while(true){
            if(now==start){
              flag=true;
              break;
            }
            if(now==goal){
              break;
            }
            LL next = -1;
            REP(j, g[now].size())
            {
              if(g[now][j]!=old){
                next = g[now][j];
              }
            }
            old = now;
            now = next;
          }
        }
        if(flag){
          cout << "Yes" << endl;
        }else{
          cout << "No" << endl;
        }
      }
    }
    else
    {
      cout << "No" << endl;
    }
  }else{
    cout << "No" << endl;
  }
}