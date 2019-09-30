#include <iostream>
#include <string>
#include <vector>
#include <deque>
#define range(i, r) for(int i=0;i<r;i++)
#define ranges(i, l, r) for(int i=l;i<r;i++)
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
#define MODn 1000000009;
typedef long long int ll;
using namespace std;

vector<int> convert(string s){
  std::vector<int> num(s.size(), 0);
  std::vector<char> lis;
  int tmp = 0;
  range(i, s.size()){
    int flag = -1;
    range(j, lis.size()){
      if(lis[j]==s[i]) flag = j;
    }
    if(flag != -1) num[i] = flag;
    else{
      num[i] = lis.size();
      lis.push_back(s[i]);
      tmp++;
    }
  }
  return num;
}

int main(int argc, char const *argv[]) {
  string S, T;
  std::cin >> S;
  std::cin >> T;
  std::vector<int> ansS = convert(S);
  std::vector<int> ansT = convert(T);
  bool ans = 0;
  if(ansS.size()!= ansT.size()){
    std::cout << "No" << '\n';
    return 0;
  }
  range(i, ansS.size()){
    if(ansS[i] != ansT[i]) ans = 1;
    //std::cout << ansS[i] << '\n';
    //std::cout << ansT[i] << '\n';
  }
  (ans == 1)?std::cout << "No" << '\n':std::cout << "Yes" << '\n';;
  return 0;
}