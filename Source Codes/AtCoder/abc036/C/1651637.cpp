#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int main(){
  int n;
  int a[100000], b[100000];
  map<int, int> mp;

  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
    b[i] = a[i];
  }

  sort(b, b + n);

  int rank = 0;
  for(int i = 0; i < n; i++){
    auto itr = mp.find(b[i]);
    if(itr == mp.end()){
      mp.insert(make_pair(b[i], rank));
      rank++;
    }
  }

  for(int i = 0; i < n; i++){
    printf("%d\n", mp[a[i]]);
  }

  return 0;

}