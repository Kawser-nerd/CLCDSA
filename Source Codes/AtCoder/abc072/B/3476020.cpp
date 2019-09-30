#include <iostream>
#include <string>
#define ll long long
#define endl '\n'
using namespace std;

int main(void)
{
  cin.tie(NULL); ios_base::sync_with_stdio(false);
  string str; cin >> str;
  for(int i = 0; i < str.size(); i++)
    {
      if(i % 2 != 0) continue;
      cout << str[i];
    }
  
  return 0;
}