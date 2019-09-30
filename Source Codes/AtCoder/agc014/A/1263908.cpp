#include <iostream>

using namespace std;

template<typename T>
bool is_even(T const& val){
  return val % 2 == 0;
}
template<typename T>
bool is_odd(T const& val){
  return !is_even(val);
}

int main(void)
{
  int A, B, C;
  cin >> A >> B >> C;
  if(is_odd(A) || is_odd(B) || is_odd(C)){
    cout << 0 << endl;
    return 0;
  }

  int a = (B+C)/2, b = (A+C)/2, c = (A+B)/2;
  int ans = 1;
  while(is_even(a) && is_even(b) && is_even(c)){
    int aa = (b+c)/2, bb = (a+c)/2, cc = (a+b)/2;
    ans++;
    if(aa == A && bb == B && cc == C){
      ans = -1;
      break;
    }
    a = aa, b = bb, c = cc;
  }
  cout << ans << endl;
  return 0;
}