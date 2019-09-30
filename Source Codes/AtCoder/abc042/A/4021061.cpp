#include <iostream>
#include <vector>
using namespace std;

int main() 
{
  vector<int> v;
  int a, b, c;
  cin >> a >> b>> c;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  if (count(v.begin(), v.end(), 5)==2 && count(v.begin(), v.end(), 7)==1)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << """NO" << endl;
  }
}