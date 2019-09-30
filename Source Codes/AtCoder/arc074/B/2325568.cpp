#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>
#include <memory.h>

using namespace std;

typedef long long ll;

const ll MININF = -1e15;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N; cin >> N;
  ll a[3*N+1];
  for(int i=1;i<=3*N;i++) cin >> a[i];
  priority_queue<ll, vector<ll>, greater<ll> > prePQ;
  priority_queue<ll> sufPQ;
  ll preSum[N+1], sufSum[N+1];
  preSum[0] = 0, sufSum[N] = 0;
  for(int i=1;i<=N;i++){
    prePQ.push(a[i]);
    preSum[0] += a[i];
  }
  for(int i=2*N+1;i<=3*N;i++){
    sufPQ.push(a[i]);
    sufSum[N] += a[i];
  }
  for(int i=N+1;i<=2*N;i++){
    prePQ.push(a[i]);
    ll tmp = prePQ.top(); prePQ.pop();
    preSum[i-N] = preSum[i-N-1] + (a[i] - tmp);
  }
  for(int i=2*N;i>=N+1;i--){
    sufPQ.push(a[i]);
    ll tmp = sufPQ.top(); sufPQ.pop();
    sufSum[i-N-1] = sufSum[i-N] + (a[i] - tmp);
  }
  /*
  for(int i=0;i<=N;i++){
    cout << preSum[i] << " " << sufSum[i] << endl;
  }
  */
  ll maxVal = MININF;
  for(int i=0;i<=N;i++){
    maxVal = max(maxVal, preSum[i] - sufSum[i]);
  }
  cout << maxVal << endl;
}