#include<iostream>
using namespace std;
int main()
{
  int m;
  cin>>m;
  if(m<100)
    {
      cout<<0<<0<<endl;
    }
  if(100<=m && m<=5000)
    {
      if(m<1000)
	{
	  cout<<0<<m/100<<endl;
	}else{
	cout<<m/100<<endl;
      }
    }
  if(6000<=m && m<=30000)
    {
      cout<<m/1000+50<<endl;
    }
  if(35000<=m && m<=70000)
    {
      cout<<(m/1000-30)/5+80<<endl;
    }
  if(m>70000)
    {
      cout<<89<<endl;
    }
  return 0;
}