#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int s;
int a[1000001];
vector<pair<int, int> > pd;
long long answer;

int main(){
  cin >> s;
  for(int i = 1; i < 1000001; ++i){
    if(i == 1){
      a[i] = s;
    }else if(a[i - 1] % 2 == 0){
      a[i] = a[i - 1] / 2;
    }else{
      a[i] = a[i - 1] * 3 + 1;
    }
    //gg[i] = 1000003;
    //pd.push_back(make_pair(a[i], i));
  }
  //sort(pd.begin(), pd.end());
  
  //a[1] = 0;
  //int cnt = 0;
  
  for(int i = 1; i < 1000001; ++i){
    for(int j = i + 1; j < 1000001; ++j){
      if(a[j] == a[i]){
        cout << j << endl;
        return 0;
      }
    }
    
  }
  
  
}