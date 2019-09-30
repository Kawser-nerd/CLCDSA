#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>



using namespace std;

long long n, m;
long long a[11];
long long dp[10005];
vector<int> V;
vector<pair<int,int> >pd;
string s;
int k;



int num(int k){
  int answer = 0;
  if(k == 1){
    answer = 2;
  }else if(k == 2){
    answer = 5;
  }else if(k == 3){
    answer = 5;
  }else if(k == 4){
    answer = 4;
  }else if(k == 5){
    answer = 5;
  }else if(k == 6){
    answer = 6;
  }else if(k == 7){
    answer = 3;
  }else if(k == 8){
    answer = 7;
  }else if(k == 9){
    answer = 6;
  }
  return answer;
}

string solver(int n){
  for(int i = 1; i < n + 1; ++i){
    dp[i] = -10;
  }
  for(int i = 1; i < n + 1; ++i){
    for(int j = 0; j < m; ++j){
      if(i >= num(a[j])){
        dp[i] = max(dp[i - num(a[j])] + 1, dp[i]);
      }
    }
  }
  while(n > 0){
    //for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        if(dp[n] == dp[n - num(a[j])] + 1 && n >= num(a[j])){
          if(dp[n] == 1){
            if(n != num(a[j])){
              continue;
            }
          }
          n -= num(a[j]);
          s += to_string(a[j]);
          break;
        }
      }
    //}
  }
  return s;
  
}



int main(){
  cin >> n >> m;
  for(int i = 0; i < m; ++i){
    cin >> a[i];
    //cout << num(a[i]) << endl;
    V.push_back(a[i]);
  }
  sort(V.begin(), V.end(), greater<int>());
  for(int i = 0; i < m; ++i){
    a[i] = V[i];
    //cout << a[i] << endl;
  }
  cout << solver(n) << endl;
}