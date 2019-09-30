#include<iostream>
using namespace std;
int main()
{
  int A, B;
  cin >> A >> B;
  if(A%2==0 or B%2==0)
    cout << "No";
  else 
    cout << "Yes" << endl;
}