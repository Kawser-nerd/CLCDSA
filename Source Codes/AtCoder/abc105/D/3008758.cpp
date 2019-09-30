#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main () {
  long long N, M;
  cin >> N >> M;
  vector<long long> A(N);
  long long sub = 0;
  vector<long long> sum;
  long long answer = 0;
  map<long long, long long> last;
  for (long long i = 0; i < N; i++) {
    cin >> sub; 
    A[i] = sub % M;   
    if (i == 0) {
      sum.push_back(A[0]);  
      last[A[0]] = 1;
      answer = answer + last[0];
    }
    else {
      sub = A[i] + sum[i-1];
      sub = sub % M;
      sum.push_back(sub);
      answer = answer + last[sub];
      last[sub]++;
      if (sub == 0) {
        answer++;  
      }
    }
  }
  cout << answer << endl;

}