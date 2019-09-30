#include <iostream>
#include <set>

int main(){
  std::string s;
  std::cin >> s;
  
  
  auto validate = [](const char* begin,const char* end){
  std::set<char> m = 
  {
    'A','T','C','G'
  };
    while(begin != end){
      if(m.count(*begin) == 0){
        return false;
      }
      begin++;
    }
    return true;
  };
  int max = 0;
  for(int st = 0;st<s.size();++st){
    for(int e = s.size();e >= 0;--e){
  		if(validate(s.c_str() + st,s.c_str() + e)){
          max = std::max(max,e-st);
        }
    }
  }
  
    std::cout << max << std::endl;
}