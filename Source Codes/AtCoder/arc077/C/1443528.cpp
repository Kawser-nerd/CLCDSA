#include <iostream>
using namespace std;

typedef long long ll;

const int MAX_M = 100005;
const int MAX_N = 100005;
int a[MAX_N];
int m[2*MAX_M];
ll additional_push[MAX_M];

int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    int ai;
    cin >> ai;
    a[i] = ai-1;
  }
  // count separation that satisfies a_i < x < a_i+1
  ll count = 0; // count when x = 1
  for (int i = 1; i < N; i++) {
    int begin = a[i-1] + 1;
    int end = a[i];
    if (begin > end) {
      end += M;
    }
    m[begin]++;
    m[end]--;

    if (a[i-1] < a[i]) {
      count += a[i] - a[i-1] ;
    }
    else {
      count += a[i] + 1;
    }

    additional_push[a[i]] +=  (M + a[i] - a[i-1]) % M - 1;
  }

  for (int i = 1; i < 2*M; i++) {
    m[i] += m[i-1];
    if (i >= M) {
      m[i-M] += m[i];
    }
  }
  // for (int i = 0; i < M; i++) {
  //   cout << m[i] << " ";
  // }
  // cout << endl;

  // cout << "x = 0: " << count << endl;
  ll ans = count;
  for (int i = 1; i < M; i++) {
    ll cx = count - m[i-1] + additional_push[i-1];
    // cout << "x = " << i << ": " << cx << endl;
    ans = min(ans, cx);
    count = cx;
  }
  cout << ans << endl;
}