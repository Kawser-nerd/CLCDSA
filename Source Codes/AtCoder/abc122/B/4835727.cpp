#include <iostream>
using namespace std;
int main()
{
  string S;
  cin >> S;
  int max = 0;
  int count = 0;
  for (int i = 0; i < S.size(); i++)
  {
    if (S[i] == 'A' || S[i] == 'T' || S[i] == 'G' || S[i] == 'C') 
    {
      count++;
      if (max < count) max = count;
    }
    else count = 0; 
  }
  cout << max;
}