#include <iostream>
#include <set>
#include <map>
#include <vector>

int main(){
  int n,q;
  std::cin >> n >> q;
  std::string s;
  std::cin >> s;
  std::vector<std::pair<int,int>> qarray;
  for(int i=0;i<q;++i){
  int l,r;
  std::cin >> l >> r;
     qarray.push_back({l - 1,r - 1});
   }
  
  std::vector<size_t> acpos;
    size_t c = 0;
    while(1){
    	c = s.find("AC",c);
    	if(c >= s.size()){
    		break;
    	}
        acpos.push_back(c);
       c = c+1;
    }
  
  
  for(auto q:qarray){
    auto a = std::lower_bound(acpos.begin(),acpos.end(),q.first);
    auto b = std::upper_bound(acpos.begin(),acpos.end(),q.second - 1);
    std::cout << (b - a) << std::endl;
  }
}