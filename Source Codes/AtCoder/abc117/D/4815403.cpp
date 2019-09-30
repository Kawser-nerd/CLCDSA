// https://atcoder.jp/contests/abc118/tasks/abc118_c

// http://ctylim.hatenablog.com/entry/2015/08/30/191553
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstdio>

#define ALL(a) (a).begin(), (a).end()
#define EACH(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort((c).begin(), (c).end())
#define RSORT(c) sort((c).rbegin(), (c).rend())
#define MAXINDEX(c) distance((c).begin(), max_element((c).begin(), (c).end()))
#define MININDEX(c) distance((c).begin(), min_element((c).begin(), (c).end()))
#define DEBUG(x) std::cerr << #x << " = " << (x) << " (" << __FILE__ << "::" << __LINE__ << ")" << std::endl;
#define ERROR(s) std::cerr << "Error::" << __FILE__ << "::" << __LINE__ << "::" << __FUNCTION__ << "::" << (s) << std::endl;
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)

#define repd(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) repd(i, 0, n)
typedef long long ll;

template <typename T>
T inputValue()
{
  T a;
  // std::cin >> a;
  scanf("%llu", &a);
  return a;
}

void inputArray(int *p, int a)
{
  rep(i, a)
  {
    std::cin >> p[i];
    // scanf("%d",p+i);
  }
}

template <typename T>
void inputVector(std::vector<T> *p, int a)
{
  rep(i, a)
  {
    T input;
    // std::cin >> input;
    scanf("%llu", &input);
    p->push_back(input);
  }
}

template <typename T>
void output(T a, int precision)
{
  if (precision > 0)
  {
    std::cout << std::setprecision(precision) << a << "\n";
  }
  else
  {
    std::cout << a << "\n";
  }
}

using namespace std;

int gcd(int a, int b)
{
  while (1)
  {
    if (a < b)
      swap(a, b);
    if (!b)
      break;
    a %= b;
  }
  return a;
}

typedef unsigned long long int ulli;
int main(int argc, char **argv)
{

  ulli N = inputValue<ulli>();
  ulli K = inputValue<ulli>();
  vector<ulli> v;
  inputVector<ulli>(&v, N);


  vector<ulli> bitSum(64,0);

  EACH(k, v)
  {
    ulli t = *k;
    for(int i=0; i<64&&t!=0; i++){
      bitSum[i] = bitSum[i] + (t&1) ;
      t = t >> 1;
    }
  }

  // ulli d = 0;

  int flag = 0;

  ulli sum0 = 0;
  for (int i = 63; i >= 0; i--)
  {

    ulli K_bit = (K >> i) & 1ll;
    ulli A_bit = (bitSum[i] > N / 2 ? 0 : 1);
    ulli D_bit = A_bit;
    if (!flag)
    {
      D_bit = K_bit && A_bit;
      flag = K_bit && (!A_bit);
    } 
    // K: kkkkkk1kkkkk 
    // A: aaaaaa0aaaaa
    // D: dddddddddddd
    // 1-0???????? D=K&A
    // ?? D=A

    if (!D_bit)
    {
      sum0 = sum0 + (bitSum[i] << i);
    }else{
      sum0 = sum0 + ((N-bitSum[i]) << i);
    }
  }
  cout << sum0 << endl;

}