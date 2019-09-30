#include<iostream>
#include<algorithm>

using namespace std;
typedef long long Int;

Int top(Int x){
  if(x == 0)return 0;
  Int res = 1;
  while(x >= res*2)res *= 2;
  return res;
}

Int solve(Int a, Int b){
  if (a == b)return 1;
  Int ta = top(a), tb = top(b);
  if(ta == tb)return solve(a - ta, b- tb);
  Int lower = a;
  Int upper = b - tb;
  Int hoge = top(upper) * 2;
  if(upper == 0)hoge = 1;
  return (tb - lower) + min(tb, tb - lower + hoge);
}

int main(){
  Int a, b;
  cin >> a >> b;
  cout << solve(a, b) << endl;
  
}