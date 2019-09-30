#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <map>
#include <limits>
#include <algorithm>
#include <numeric>

using namespace std;

struct DDMY{ ostringstream o; template<class T>DDMY& operator,(const T &t){o<<t<<",";return *this;} string operator*(){ return o.str().substr(0,o.str().size()-1); } };
#define debug(args...) cout<<"("#args")=("<< *(DDMY(),args)<<") (L"<<__LINE__<<")"<<endl
template<class T> std::ostream &operator<<(std::ostream &o,const std::vector<T> &v)
{ o << "["; for(std::size_t i=0;i<v.size();i++) o << v[i] << (i < v.size()-1 ? ",":""); return o << "]"; }
template<class T,class U> std::ostream &operator<<(std::ostream &o,const std::pair<T,U> &v)
{ return o << v.first << ":" << v.second; }
template<class T,class U> std::ostream &operator<<(std::ostream &o,const std::map<T,U> &v)
{ o << "{"; typename std::map<T,U>::const_iterator i=v.begin(),j=i;++j;for(;i!=v.end();++i,++j) o << *i << (j!=v.end()? ",":""); return o << "}"; }
template<class T> std::ostream &operator<<(std::ostream &o,const std::set<T> &v)
{ o << "{"; typename std::set<T>::const_iterator i=v.begin(),j=i;++j;for(;i!=v.end();++i,++j) o << *i << (j!=v.end()? ",":""); return o << "}"; }



long _main(int n, vector<long> pile){
  long all = accumulate(pile.begin(), pile.end(), 0LL);
  long culm = 0;
  long min_value = numeric_limits<long>::max();
  for(int i = 0; i < pile.size() - 1; i++){
    culm += pile[i];
    long diff = abs(culm - (all - culm));
    if(min_value > diff){
      min_value = diff;
    }
  }
  return min_value;
}


int main(int argc, char *argv[])
{
  string line;
  getline(cin, line);
  int n = strtol(line.c_str(), NULL, 10);
  getline(cin, line);
  istringstream iss(line);
  vector<long> pile;
  for(int i = 0; i < n; i++){
    long k = 0;
    iss >> k;
    pile.push_back(k);
  }
  cout << _main(n, pile) << endl;
  return 0;
}