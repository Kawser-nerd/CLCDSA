#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(vector<int> a){


  vector<int> b;
  b.push_back(0);
  
  for(int l = 0; l < a.size() - 1; l++){
    if(a[l + 1] <= a[l]){
      b.push_back(l + 1);
    }
  }

  b.push_back(a.size());
  
  long long okCount = 0;
  for(int i = 0; i < b.size() - 1; i++){
    int temp = b[i + 1] - b[i];
    okCount += (long long)temp * (temp + 1) / 2;
  }

  cout << okCount << endl;
}

int main(){
  int n;

  // ?????
  cin >> n;

  vector<int> a(n);

  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  
  solve(a);
}