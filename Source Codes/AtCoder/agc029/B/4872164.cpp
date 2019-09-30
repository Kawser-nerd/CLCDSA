#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <deque>
#include <list>

#define N 100000

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll leastMaxPow2(ll n)
{
    // n?0?????0????
    if (n <= 0) return 0;

    // (n & (n - 1)) == 0 ????n?2?????????????n????
    if ((n & (n - 1)) == 0) return (ll)n;

    // bit????????2????????
    ll ret = 1;
    while (n > 0) { ret <<= 1; n >>= 1; }
    return ret;
}

int main() {
  ll i, j;
  ll temp;
  int n;
  int n_check = 0;

  // vector<ll> test = {3};
  // vector<ll>::iterator temp_lb;
  // temp_lb = lower_bound(test.begin(), test.end(), 1);
  // cout << "find 1: "<< *temp_lb << endl;
  // // cout << "find 1: " << temp_lb << *temp_lb << endl;
  
  // temp_lb = lower_bound(test.begin(), test.end(), 3);
  // cout << "find 3: "  << *temp_lb << endl;
  // temp_lb = lower_bound(test.begin(), test.end(), 5);
  // cout << "find 5: "  << *temp_lb << endl;

  // cout << "end: " << *(test.end()) << endl;
  // cout << (temp_lb == test.end()) << endl;

  // test.erase(test.begin());
  // cout << test.size() << endl;

  // return 0;

  scanf("%d", &n);
  // array<ll, N> ar;
  // vector<ll> ar(n);
  vector<ll> v(n);
  // list<ll> ar;
  for (i = 0; i < n; i++) {
    scanf(" %lld", &v[i]);
    // scanf(" %lld", &temp);
    // ar.push_back(temp);
    n_check++;
  }
  // printf("%d", n_check);

  // for (i = 0; i < n; i++) {
  //   printf("%lld\n", ar[i]);
  // }
  // printf("end\n");

  sort(v.begin(), v.end());
  // ar.sort();
  // list<ll> ar(v.begin(), v.end());
  // vector<ll> ar = v;
  // vector<ll>::iterator lb, tend;
  deque<ll> ar(v.begin(), v.end());
  deque<ll>::iterator lb, tend;
  // tend = ar.end();
  // cout << *tend << endl;

  int count = 0;
  ll last, lm, fn;
  while (ar.size()>1) {
    last = ar.back();
    // cout << "last: " << last << endl;
    ar.pop_back();
    lm = leastMaxPow2(last);
    if(lm==last){
      lm <<= 1;
    }
    fn = lm - last;
    lb = lower_bound(ar.begin(), ar.end(), fn);  // binary search
    // if(lb == ar.end()){
    //   break;
    // }
    if(*lb==fn && lb != ar.end()){
      count++;
      ar.erase(lb);
    }

    // for (auto x = ar.begin(); x != ar.end(); ++x) {
    //   temp = *x + last;
    //   if (!(temp & (temp - 1))) {
    //     count++;
    //     ar.erase(x);
    //     break;
    //   }
    // }
  }

  printf("%d", count);

  
  return 0;
}