#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void print_n_alphabet(vector<int> v){ for(int i=0; i<v.size(); ++i){cout << v[i] << endl; }}
bool exists_alphabet(vector<int> v){ for(int i=0; i<v.size(); ++i){ if(v[i]>0){return true;}} return false;}
int search_alphabet(vector<int> v){for(int i=0; i<v.size();++i){if(v[i]>0){return i;}} return 27;}

int main()
{
  string s;
  cin >> s;
  int i;
  vector<int> alphabet(26);
  for(auto x:s)
  {
    i = int(x)-97;
    alphabet[i]++;
  }
  int num_odd=0;
  bool all_even=false;
  for(int i=0; i<alphabet.size();++i){ if(alphabet[i]!=0 and alphabet[i]%2==1){num_odd++; alphabet[i]--;}}
  if(num_odd==0){num_odd++;all_even=true;}
  vector<int> size_string(num_odd);
  int size_string_iter=0;
  if(not all_even){ for(int i=0; i<size_string.size();++i){size_string[i]++;} }
  while(exists_alphabet(alphabet))
  {
    int x = search_alphabet(alphabet);
    alphabet[x]-=2;
    size_string[size_string_iter]+=2;
    size_string_iter++;
    size_string_iter%=num_odd;
  }
  int res=size_string[0];
  for(int i=1; i<num_odd; ++i){ res=min(res,size_string[i]);}
  cout << res << endl;
  return 0;
}