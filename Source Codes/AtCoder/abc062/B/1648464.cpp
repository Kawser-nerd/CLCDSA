#include<iostream>
using namespace std;

int main()
{
  int h,w;
  cin>>h>>w;
  char name[h][w];
  for(int i=0;i<h;i++)
  {
    for (int j=0;j<w;j++)
    {
    cin>>name[i][j];
    }
  }
  for(int k=0;k<w+2;k++)
  {
    cout<<"#";
  }
  cout<<"\n";
    for(int i=0;i<h;i++)
  {
    cout<<'#';
    for (int j=0;j<w;j++)
    {
    cout<<name[i][j];
    }
    cout<<"#\n";
  }
    for(int k=0;k<w+2;k++)
  {
    cout<<"#";
  }
}