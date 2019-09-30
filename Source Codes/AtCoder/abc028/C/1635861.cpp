#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

int main(){
  int a[5];
  vector<int> v;

  for(int i = 0; i < 5; i++)
    scanf("%d", &a[i]);

  for(int i = 0; i < 3; i++){
    for(int j = i + 1; j < 4; j++){
      for(int k = j + 1; k < 5; k++){
        v.push_back(a[i] + a[j] + a[k]);
      }
    }
  }


  sort(v.begin(), v.end(), greater<int>());

  auto itr = unique(v.begin(), v.end());
  v.erase(itr, v.end());

  printf("%d\n", v[2]);

  return 0;
  
}