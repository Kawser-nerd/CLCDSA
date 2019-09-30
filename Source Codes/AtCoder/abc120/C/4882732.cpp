#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[]) {
  string S;
  std::cin >> S;
  int count = 0;
  deque<char> Q;
  for(int i=0;i<S.size();i++){
    if(Q.empty()){
      Q.push_back(S[i]);
    }else if(S[i] == Q.back()){
      Q.push_back(S[i]);
    }else{
      Q.pop_back();
      count+=2;
    }
  }
  std::cout << count << '\n';
  return 0;
}