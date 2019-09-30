#include<iostream>
#include<unordered_set>
#include<vector>

int main(){
   int n;
  std::vector<int> an;
  std::unordered_set<int> selected;
 std::cin >> n;
  for(int i=0;i<n;++i){
    int t;
	std::cin >> t;
    an.push_back(t);
  }
  int s = 0;
  int count = 0;
  while (true){
    if(selected.count(s) ){
      count = -1;
      break;
    }
    selected.insert(s);
  	s = an[s] - 1;
    count += 1;
    if (s == 1){
      break;
    }
  }
  std::cout << count << std::endl;
}