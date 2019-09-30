#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <functional>
#include <numeric>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define v_exists(elem, v) find(v.begin(),v.end(),elem)!=v.end()

using namespace std;

long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main(){

  int N;
  long X;
  cin >> N;
  cin >> X;

  std::vector<long> distances;

  rep(i,N){
    long city;
    cin >> city;
    distances.push_back(abs(X-city));
  }

  cout << accumulate(distances.begin(), distances.end(), distances[0], gcd) << endl;

}