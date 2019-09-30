#include<iostream>
using namespace std;
int main()
{
  char a,b;cin>>a>>b;
  if(a==b)puts("=");
  else if(a<b)puts("<");
  else puts(">");
}