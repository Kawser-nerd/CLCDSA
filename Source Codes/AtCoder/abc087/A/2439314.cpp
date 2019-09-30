#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<climits>
#include<cstdlib>
#include<map>
#include<math.h>
#include<utility>
using namespace std;
typedef long long ll;

int main(){
  int x, a, b;
  cin >> x >> a >> b;
  x -= a;
  while(x>=b){
    x -= b;
  }
  cout << x << endl;
  return 0;
}