#include <iostream>
#include <vector>
#include <algorithm>

int main(){
  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int, int> > battle(m);
  int brk = 0, cnt = 0;
  for(int i = 0; i < m; i++){
    std::cin >> battle[i].second >> battle[i].first;
  }
  std::sort(battle.begin(), battle.end());

  for(int i = 0; i < m; i++){
    if(battle[i].second > brk){
      brk = battle[i].first - 1;
      cnt++;
    }
  }
  std::cout << cnt << std::endl;
}