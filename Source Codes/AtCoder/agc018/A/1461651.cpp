#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
typedef long long ll;

ll INF = 10000000000;

ll gcd(ll a, ll b){
  ll na = 0, nb = 0;
  if(a < b){
    na = b;
    nb = a;
  }
  else{
    na = a;
    nb = b;
  }
  ll c = na % nb;
  ll ans = 0;
  if(c != 0) ans = gcd(nb, c);
  else ans = nb;
  return ans;
}

void show(vector<ll> vec){
  for(int i = 0; i < vec.size(); i++){
    cout << vec[i] << " ";
  }
  cout << endl;
}

ll getMaxGcd(vector<ll> vec){
  ll maxGcd = 0;
  if(vec.size() == 1) maxGcd = vec[0]; 
  else  maxGcd = gcd(vec[0], vec[1]);
  for(int i = 2; i < vec.size(); i++){
    maxGcd = gcd(vec[i], maxGcd);
  }
  
  return maxGcd;
}

ll getMax(vector<ll> vec){
  ll max = 0;
  for(int i = 0; i < vec.size(); i++){
    if(max < vec[i]) max = vec[i];
  }
  return max;
}

int main(){
  ll N, K;
  cin >> N >> K;
  vector<ll> vec;
  
  for(int i = 0; i < N; i++){
    ll tmp;
    cin >> tmp;
    vec.push_back(tmp);
  }

  ll max = getMax(vec);
  ll maxGcd = getMaxGcd(vec);
  if(K <= max && K % maxGcd == 0) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
  
  return 0;
}