#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <complex>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;


#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 100010

int numsum(ll x){
  int sum = 0;
  while(x){
    sum += x%10;
    x/=10;
  }
  return sum;
}

int check(ll x, ll y){
  cerr << x << " " << y << endl;
  cerr << numsum(x)*y << " " << numsum(y)*x << endl;
  return numsum(y)*x <= numsum(x)*y;
}

int check(ll x){
  int sx = numsum(x);
  
  for(ll i=x;i<10000000;i++){
    int si = numsum(i);
    if(x*si > i*sx){
      return false;
    }
  }

  return true;
}

int di(ll x){
  for(int i=0;x;i++){
    if(x) x/=10;
    else return i;
  }
  return 0;
}

int main(){

  if(false){
    for(int i=1;i<10000000;i++){
      if(check(i)) printf("%d\n", i);
    }
    return 0;
  }
  
  
  int k;

  scanf("%d",&k);

  int maxt = 9;

  vector<string> ans;
  
  set<string> ss;

  for(int i=1;i<10;i++) ss.insert(to_string(i));

  string prev = "";
  
  for(int i=1;;i++){
    for(auto s: ss){
      if(k == 0) return 0;

      string t = s;
      int l = i - s.size();
      for(int i=0;i<l;i++) t += "9";

      if(prev.size() && check(stoll(prev), stoll(t))){
        cout << prev << endl;
        k--;
      }
      prev = t;
    }

    if(i >= 3){
      for(int i=0;i<10;i++){
        string t = to_string(maxt + i + 1);
        ss.insert(t);
        t = t.substr(0, t.size()-1);
        auto it = ss.find(t);
        if(it != ss.end()) ss.erase(it);
      }
      maxt += 10;
    }
  }
  
  return 0;
}