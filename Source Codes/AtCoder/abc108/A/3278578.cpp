#include<iostream>
using namespace std;

int main()
{
  int k,c=0;
  cin>>k;
  for (int i=1;i<=k;i++)
  {
      for(int j=k;j>=1;j--)
      {
           if(i%2 == 0&& j%2!=0)
        {
          c++;
         }
      }

  }
  cout<<c;
}