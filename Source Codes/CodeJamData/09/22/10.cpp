#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

void next(string& s)
{
  s="0000"+s;
  next_permutation(s.begin(),s.end());
  int i;
  for(i=0;i<s.size();++i) if(s[i]!='0') break;
  s=s.substr(i);
}
int main()
{
  int ci,cn;
  cin>>cn;
  for(ci=1;ci<=cn;++ci)
  { string s;
    cin>>s;
    next(s);
    cout<<"Case #"<<ci<<": "<<s<<endl;
  }
}
