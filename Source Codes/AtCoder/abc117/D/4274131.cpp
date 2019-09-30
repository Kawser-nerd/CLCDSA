#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long fx(long long x, vector<long long> &a){
  long long sum = 0;
  for(long long i=0; i<(long long)a.size(); i++)
    sum += a[i] ^ x;
  return sum;
}

int main(){
  long long N,K;
  cin >> N >> K;
  vector<long long> A(N);
  vector<int> bit_nums(64);
  vector<int> x_vec(64);
  
  for(int i=0; i<N; i++) cin >> A[i];
  
  for(long long a: A){
    long long t = 0;
    for(int i=0; i<64; i++){
      t = a >> i;
      bit_nums[i] += (int)(t & (long long)1);
    }
  }
  
  for(int i=0; i<64; i++){
    if(N%2!=0){
      if(bit_nums[i]>(N/2)) x_vec[i] = 0;
      else x_vec[i] = 1;
    }else{
      if(bit_nums[i]>=(N/2)) x_vec[i] = 0;
      else x_vec[i] = 1;
    }
  }
  
  long long x = 0;
  for(int i=62; i>=0; i--){
    long long temp = x;
    temp += x_vec[i]*((long long)1<<i);
    if(temp > K) continue;
    else x = temp;
  }
  
  long long ans = fx(x,A);
  
  // cout << "x: " << x << ", ans: "<< ans << endl;
  cout << ans << endl;
}