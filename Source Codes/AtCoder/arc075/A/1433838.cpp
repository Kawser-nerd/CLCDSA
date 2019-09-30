#include <iostream>
#include <vector>
#include<utility>

using namespace std;

int getMax(vector<int> s, int Max, int &index, int N){
  int tmp = 0;
  bool flag = false;
  for(int i = index; i < s.size(); i++){
    tmp = Max - s[i];
    if(tmp % 10 != 0){
      flag = true;
      break;
    }
  }
  if(flag) return tmp;
  else if(index != N){
    index++;
    tmp = getMax(s, Max - s[index], index, N);
    return tmp;
  }
  else{
    return 0;
  }
  
}

int main(){
  int N;
  vector<int> s;
  cin >> N;
  int Max = 0;
  for(int i = 0; i < N; i++){
    int tmp;
    cin >> tmp;
    s.push_back(tmp);
    Max += tmp;
  }
  sort(s.begin(), s.end());
  if(Max % 10 != 0) cout << Max << endl;
  else{
    int index = 0;
    int ans = getMax(s, Max, index, N);
    cout << ans << endl;
  }
  
}