#include <iostream>
#include <vector>
#include <algorithm>

int main(){
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int> > red(n), blue(n);
  bool pair[101];
  int cnt = 0, max, hoge = 100;

  for(int i = 0; i < n; i++){
    pair[i] = false;
    std::cin >> red[i].first >> red[i].second;
  }
  for(int i = 0; i < n; i++){
    std::cin >> blue[i].first >> blue[i].second;
  }
  std::sort(red.begin(), red.end());
  std::sort(blue.begin(), blue.end());

  for(int i = 0; i < n; i++){
    max = -1;
    for(int j = 0; red[j].first < blue[i].first && j < n; j++){
      if(pair[j] == false && red[j].second < blue[i].second && red[j].second > max){
        max = red[j].second;
        hoge = j;
      }
    }
    pair[hoge] = true;
  }

  for(int i = 0; i < n; i++){
    if(pair[i]) cnt++;
  }
  std::cout << cnt << std::endl;
}